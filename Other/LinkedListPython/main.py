from typing import TypeVar, Generic, Union
from typing_extensions import Self

T = TypeVar('T')
class Node(Generic[T]):
    datum: T
    next: Self
    def __init__(self: Self, datum: T, next: Union[Self, None], /):
        self.datum = datum
        self.next = next

class LinkedList(Generic[T]):
    head: Node[T]
    def __init__(self: Self, datum: T, /):
        self.head = Node(datum, None)
    def get(self: Self, index: int, /):
        i = 0
        next_item = self.head
        while (next_item != None and i < index):
            next_item = next_item.next
            i += 1
        return next_item if i == index else None
    def add_start(self: Self, datum: T, /):
        self.head = Node(datum, self.head)
    def remove_start(self: Self, /):
        self.head = self.head.next
    def add(self: Self, datum: T, index: int, /):
        if index <= 0:
            return self.add_start(datum)
        current: Node[T] = self.get(index - 1)
        current.next = Node(datum, current.next)
    def remove(self: Self, index: int):
        if index <= 0:
            return self.remove_start()
        current: Node[T] = self.get(index - 1)
        current.next = current.next.next
    def print(self: Self, /):
        next_item = self.head
        while (next_item != None):
            print(next_item.datum)
            next_item = next_item.next

test: LinkedList[int] = LinkedList(1)
test.add_start(2)
test.add_start(3)
test.add_start(4)
test.print()