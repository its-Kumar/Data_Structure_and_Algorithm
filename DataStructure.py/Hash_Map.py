class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class HashMap:
    def __init__(self):
        self.store = [None for _ in range(16)]
    def get(self, key):
        index = hash(key) & 15
        if self.store[index] is None:
            return None
        n = self.store[index]
        while True:
            if n.key == key:
                return n.value
            else:
                if n.next:
                    n = n.next
                else:
                    return None
    def put(self, key, value):
        nd = Node(key, value)
        index = hash(key) & 15
        n = self.store[index]
        if n is None:
            self.store[index] = nd
        else:
            if n.key == key:
                n.value = value
            else:
                while n.next:
                    if n.key == key:
                        n.value = value
                        return
                    else:
                        n = n.next
                n.next = nd

hm = HashMap()
hm.put("1", "sachin")
hm.put("2", "sehwag")
hm.put("3", "ganguly")
hm.put("4", "srinath")
hm.put("5", "kumble")
hm.put("6", "dhoni")
hm.put("7", "kohli")
hm.put("8", "pandya")
hm.put("9", "rohit")
hm.put("10", "dhawan")
hm.put("11", "shastri")
hm.put("12", "manjarekar")
hm.put("13", "gupta")
hm.put("14", "agarkar")
hm.put("15", "nehra")
hm.put("16", "gawaskar")
hm.put("17", "vengsarkar")
print(hm.get("1"))
print(hm.get("2"))
print(hm.get("3"))
print(hm.get("4"))
print(hm.get("5"))
print(hm.get("6"))
print(hm.get("7"))
print(hm.get("8"))
print(hm.get("9"))
print(hm.get("10"))
print(hm.get("11"))
print(hm.get("12"))
print(hm.get("13"))
print(hm.get("14"))
print(hm.get("15"))
print(hm.get("16"))
print(hm.get("17"))