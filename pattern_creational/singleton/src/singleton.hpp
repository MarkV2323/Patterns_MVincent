#include <fmt/color.h>
#include <memory>
#include <mutex>
#include <string>
class Singleton {
public:
  // Because our instance is a raw static pointer,
  // we can allow the OS to reclaim the static memory.
  // (technically I have it as a unique_ptr, so it's memory
  //  is already automagiclly taken care of...)
  ~Singleton() {}

  // Copy and Move are NOT deleted
  // Singleton(Singleton &&) = delete;
  // Singleton(const Singleton &) = delete;
  // Singleton &operator=(Singleton &&) = delete;
  // Singleton &operator=(const Singleton &) = delete;

  // ToString Member Function
  std::string ToString() {
    std::string s = "";
    s += fmt::format("{:<6}", "Age:");
    s += fmt::format("{:<6.2}\n", std::to_string(age_));
    s += fmt::format("{:<6}", "Data:");
    s += fmt::format("{:<6.2}\n", std::to_string(data_));
    return s;
  }

  // SetData Member Function
  void SetData(int d) { data_ = d; }

  // Access the Singleton
  static Singleton &GetSingleton() {
    // Meyers Singleton would simply be
    // static Singleton instance;
    // return instance; // This is thread safe in C++ 11+

    // This is a thread safe version that only allows the init
    // to happen once...
    std::call_once(flag_, []() { instance_.reset(new Singleton()); });
    return *instance_;
  }

private:
  Singleton(){};

  int data_{0};
  int age_{25};

  // inline Allows for statics to be declared and inizlized from
  // within a header file
  inline static std::unique_ptr<Singleton> instance_ = nullptr;
  inline static std::once_flag flag_;
};
