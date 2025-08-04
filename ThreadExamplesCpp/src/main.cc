#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <future>

/**
* <thread>              -> for threads 
* <jthread>             -> for threads that atuomatically rejoin on destruction
*                          and stoped / cancelled in certain situations
* <mutex>               -> for locking and synchronization
* <condition_variable>  -> for thread communication
* <future>              -> for async results
* <atomic>              -> for low-level atomic operations
**/

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

// Why Atomics? Write safe, lock-free multithreaded code, share vars
// between threads without a mutex and avoid data races!

// std::atomic<T> guarantees atomic (thread-safe) operations without
// the need for manual locking... you faster speed (no kernel calls),
// though only use for simple counters or flags
std::atomic<int> counter(0);
void increment() {
  int length = 100;
  for (size_t i = 0; i < length; i++) {
    ++counter;
  }
}

void worker() {
  std::unique_lock<std::mutex> lock(mtx);
  cv.wait(lock, [] { return ready; });
  // Time to actually do things....
  std::cout << "I am working so hard right now!@#!" << '\n';
}

void safe_print(const std::string& msg) {
  // lock_guard is simple RAII; auto releases the mutex on exit...
  // unique_lock gives more flexibility
  std::lock_guard<std::mutex> lock(mtx);
  std::cout << msg << '\n';
}

void example(std::string id) {
  int i = 0;
  int amt = 0;
  while (true) {
    if (i % 5'000'000'000 == 0) {
      std::cout << "T" << id << " -> hit 5_000_000_000!" << "\n";
      i = 0;
      amt++;
    }
    i++;
    if (amt == 1) {
      return;
    }
  }
}

int compute() {
  return 42;
}

int main(int argc, char const* argv[]) {
  std::cout << "Hello world!" << std::endl;

  // Launch a few threads
  std::thread t1(example, "a");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  // C++ auto copies arguements by val UNLESS you wrap with std::ref()
  // or std::move()
  std::thread t2(example, "b");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::thread t3(example, "c");

  // Wait fort the thread to finish and rejoin
  t1.join();
  // Always call join() or detach() otherwise you will crash
  // at runtime...
  t2.join();
  // You can call detach() to run in background, prob use async rather...
  t3.join();

  std::thread t4(safe_print, "hello from t4!");
  std::thread t5(safe_print, "hello from t5!");
  t4.join();
  t5.join();

  // simple async example
  std::future<int> result = std::async(compute);
  // get() will "wait" until done, unless it already completes...
  std::cout << result.get() << '\n';

  std::thread t6(increment);
  std::cout << "Counter: " << counter << '\n';
  std::thread t7(increment);
  std::cout << "Counter: " << counter << '\n';
  t6.join();
  t7.join();
  std::cout << "Counter: " << counter << '\n';

  return 0;
}
