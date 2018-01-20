#include <stdio.h>
#include <map>

class Node
{
    public:
        double Data;
        Node* Left;
        Node* Right;
        
        Node(double d)
        {
            Data = d;
            Left = NULL;
            Right = NULL;
        }
};

class BinarySearchTree
{
    public:
        Node* Root;
    
        BinarySearchTree(double d)
        {
            Root = new Node(d);
        }
        
        void insert(double d)
        {
           insertInternal(Root, d);    
        }
    
    private:
        void insertInternal(Node* nodePtr, double d)
        {
            if (d < nodePtr->Data)
            {
                if (nodePtr -> Left == NULL)
                {
                    nodePtr -> Left = new Node(d);
                }
                else
                {
                    insertInternal(nodePtr -> Left, d);
                }
            }
            
            if (d >= nodePtr->Data)
            {
                if (nodePtr -> Right == NULL)
                {
                    nodePtr -> Right = new Node(d);
                }
                else
                {
                    insertInternal(nodePtr -> Right, d);
                }
            }            
        }
        
};

int main()
{
    printf("Hello World\n");

    BinarySearchTree* bst = new BinarySearchTree(5);
    bst -> insert(3);
    bst -> insert(8);
    bst -> insert(2);
    bst -> insert(6);
    bst -> insert(2.5);
    bst -> insert(12);
    bst -> insert(9);
    bst -> insert(15);
    
    printf("%f\n", bst -> Root -> Left-> Left -> Right -> Data);
    printf("%f\n", bst -> Root -> Right-> Right -> Left -> Data);
    return 0;
}