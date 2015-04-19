# use two stacks (implemented with singly-linked list) to realize a queue

class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList(object):
    def __init__(self, node=None):
        self.head = node
        self.count = 0
        if node is not None:
            self.count = 1

    def insert_front(self, data):
        if data is not None:
            node = Node(data)
            node.next = self.head
            self.head = node
            self.count += 1
        else:
            print("skip adding empty node")

    def traverse(self):
        if self.head is not None:
            print self.head.data
            node = self.head.next
            while node is not None:
                print node.data
                node = node.next
        else:
            print "linked list is empty"

    def delete_front(self):
        if self.head is not None:
            if self.head.next is not None:
                self.head = self.head.next
            else:
                self.head = None
                print "just deleted the last node"
            self.count -= 1
        else:
            print "nothing to delete"

    def isempty(self):
        if self.count == 0:
            return True
        else:
            return False


class Queue(object):
    def __init__(self):
        self.count = 0
        self.s1 = LinkedList()
        self.s2 = LinkedList()

    def push_back(self, data):
        if data is not None:
            if self.s1.isempty():
                while self.s2.head is not None:
                    self.s1.insert_front(self.s2.head.data)
                    self.s2.delete_front()
                self.s1.insert_front(data)
            else:
                self.s1.insert_front(data)
            self.count += 1

    def pop_front(self):
        if self.s2.isempty():
            while self.s1.head is not None:
                self.s2.insert_front(self.s1.head.data)
                self.s1.delete_front()
            self.s2.delete_front()
        else:
            self.s2.delete_front()
        self.count -= 1

    def traverse(self):
        if self.s1.isempty():
            self.s2.traverse()
        else:
            while self.s1.head is not None:
                self.s2.insert_front(self.s1.head.data)
                self.s1.delete_front()
            self.s2.traverse()

if __name__ == "__main__":
    # ll = LinkedList()
    # for i in range(10):
    #     ll.insert_front(i)
    # ll.traverse()
    # for i in range(15):
    #     ll.delete_front()

    myque = Queue()
    for i in range(10):
        myque.push_back(i)

    myque.traverse()

    myque.pop_front()
    myque.pop_front()
    for i in range(5):
        myque.push_back(i)

    myque.traverse()


