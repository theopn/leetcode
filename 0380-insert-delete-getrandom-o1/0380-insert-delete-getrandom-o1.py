class RandomizedSet:

    def __init__(self):
        self.arr = []
        self.hsh = {}
        self.lng = 0
        

    def insert(self, val: int) -> bool:
        if val not in self.hsh:
            self.arr.append(val)
            self.hsh[val] = self.lng
            self.lng += 1
            return True
    
        return False


    def remove(self, val: int) -> bool:
        if val in self.hsh:
            # Swap the element with the last elem
            self.hsh[self.arr[-1]] = self.hsh[val]
            self.arr[self.hsh[val]] = self.arr[-1]

            # Remove last elem
            self.arr.pop()
            self.lng -= 1
            self.hsh.pop(val)

            return True

        return False
    
    def getRandom(self) -> int:
        #return self.arr[random.randint(0, self.lng - 1)]
        return random.choice(self.arr)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()