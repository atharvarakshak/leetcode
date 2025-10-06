class LRUCache:
   
    def __init__(self, capacity: int):
        # self.heap = []
        self.freq= OrderedDict()
        self.capacity=capacity

    def get(self, key: int) -> int:
        if(key not in self.freq):
            return -1
        
        self.freq.move_to_end(key)
        return self.freq[key]

    def put(self, key: int, value: int) -> None:
        if(key in self.freq):
            self.freq.move_to_end(key)

        self.freq[key] = value

        if(len(self.freq)> self.capacity):

            self.freq.popitem(last=False)


        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)