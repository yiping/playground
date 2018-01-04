#include <iostream>

using namespace std;

class Node
{
    public:
        int Data;
        Node* Next;
};

class LinkedList
{
    private:
        Node* Head;
        Node* Tail;
    public:
        LinkedList()
        {
            Head = NULL;
            Tail = NULL;
        }
        void addNode(int value)
        {
            Node* nd = new Node;
            nd->Next = NULL;
            nd->Data = value;
            if (Head == NULL)
            {
                Head = nd;
                Tail = nd;
            }
            else
            {
                Tail->Next = nd;
                Tail = nd;
            }
        }
        void display()
        {
            Node* nd = Head;
            while (nd != NULL)
            {
                cout << "->" << nd->Data;
                nd = nd->Next;
            }
            cout << endl;
        }
        
        void reverse()
        {
            reverseInternal(Head);
            //cout << Tail->Data <<endl;
            Node* tmp = Head;
            Head = Tail; 
            Tail = tmp;
        }
        
        void reverseInternal(Node* nd)
        {
            if (nd->Next->Next != NULL)
            {
                reverseInternal(nd->Next);
                
            }
            
            nd->Next->Next = nd;
            nd->Next = NULL;
        }
};

int main()
{
    cout<<"Hello World"<<endl;
    cout << "------"<<endl;

    LinkedList lst;
    for (int i = 0; i<10; i++)
    {
        lst.addNode(i);
    }
    
    lst.display();
    
    lst.reverse();
    lst.display();

    lst.reverse();
    lst.display();
    return 0;    
}
