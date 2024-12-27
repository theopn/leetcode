class MyCircularDeque:

    def __init__(self, k: int):
        self.k = k
        self.arr = [None] * k
        self.size = 0
        self.head = 0
        self.tail = k - 1

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False

        self.head = (self.head - 1 + self.k) % self.k
        self.arr[self.head] = value
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False

        self.tail = (self.tail + 1) % self.k
        self.arr[self.tail] = value
        self.size += 1
        return True
        
    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False

        self.arr[self.head] = None
        self.head = (self.head + 1) % self.k
        self.size -= 1
        return True
        
    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False

        self.arr[self.tail] = None
        self.tail = (self.tail - 1 + self.k) % self.k
        self.size -= 1
        return True
        
    def getFront(self) -> int:
        return -1 if self.isEmpty() else self.arr[self.head]

    def getRear(self) -> int:
        return -1 if self.isEmpty() else self.arr[self.tail]

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.k


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()