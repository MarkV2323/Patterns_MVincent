"""
Singletons implemention:
1) Declare all constructors of the class private. 
(Do not allow instantation)

2) Provide static method that returns a reference to the instance 
(Ensures 1 instance)

Python does not have normal "private" methods, it uses '_'
for data encapsulation. "Dunder" methods like __new__ and __init__
are invoked at different moments, look them up for specifics.

https://www.geeksforgeeks.org/python/dunder-magic-methods-python/
https://www.geeksforgeeks.org/python/__new__-in-python/

"""
class Singleton:
  _singleton = None

  # Where we implement part 1 & 2.
  def __new__(cls):
    if cls._singleton is None:
      print('Creating singleton!')
      # This part is a mouth full, lookup if need be.
      cls._singleton = super(Singleton, cls).__new__(cls)
    return cls._singleton

  def __init__(self):
    self.name = "Mark"

  # Singleton functions are created as "normally" as other
  # instance functions are.
  def setName(self, name: str):
    self.name = name

  @staticmethod
  def getInstance():
    pass


# Small demo
s1 = Singleton()
print(s1.name)
s2 = Singleton()
print(s2.name)
s2.setName('I changed the name!')
print(s1.name)
