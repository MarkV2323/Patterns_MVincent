"""
Builder implemention:
1) Encapsulate creating and assembling the parts of a 
   complex object in a separate Builder Object. Simple,
   an object is dedicated to creating another object &
   returns it.

2) A class delegates object creation to a Builder object
   instead of creating the objects directly. This is simply
   using the Builder Object to return the 'built' complex object.

"""
# Allows for abstract base classes in python
from abc import ABC, abstractmethod
from typing import TypeVar, Generic

# Our Complex Object
class Car:
  def __init__(self) -> None:
    self._make: str | None = None
    self._year: str | None = None

  def __str__(self) -> str:
    return (f"Make: {self._make} | Year: {self._year}")

# Our Builder interface
T = TypeVar("T", bound="BuilderInterface")
class BuilderInterface(ABC, Generic[T]): # ABC makes it an Abstract Base Class, 
                                         # Generic[T] makes this arg Generic
  def __init__(self):
    self._Car = Car()

  @abstractmethod
  def add_make(self) -> T: ...

  @abstractmethod
  def add_year(self) -> T: ...

  def build(self) -> Car:
    return self._Car

# Our Builder (uses fluent interfaces to resolve method chain type hints)
#             (this requires making BuilderInterface Generic...)
class FordBuilder(BuilderInterface["FordBuilder"]):
  def __init__(self):
    super().__init__()

  def add_make(self) -> "FordBuilder":
    self._Car._make = "Ford"
    return self # By returning self, add_* function chanining can be used

  def add_year(self) -> "FordBuilder":
    self._Car._year = "1990"
    return self

# Our Delegator
class Delegator:
  # Allows us to use any class that implements the BuilderInterface
  def __init__(self, builder: BuilderInterface) -> None:
    self._builder = builder

  # Example of how easy the chaining is
  def constructFord(self) -> Car:
    return (self._builder.add_make().add_year().build())

# Setup our delegator with FordBuilder because it implements the API
delegator = Delegator(FordBuilder())
ford_car = delegator.constructFord()

print(ford_car)
