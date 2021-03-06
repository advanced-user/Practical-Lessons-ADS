#include <iostream>
using namespace std;

#pragma region 1-2

int F(int n)
{
    if(n == 0)
        return 3;
    else if(n > 0)
        return 4 * F(n - 1) + 2 * F(n / 2) + 7;
}

int Prod(int a, int b)
{
    if(b == 0)
        return 0;

    if(b < 0)
    {
        b = -b;
        a = -a;
    }

    return a + Prod(a, b-1);
}

#pragma endregion


#pragma region LinkedList

template<typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void pop_front();
    void clear();
    void push_back(T data);
    void PrintList();
    void PrintListReverse();
    int Sum();

    T& operator[](const int index);
private:

    template<typename T>
    class Node
    {
    public:
        Node *pNext;
        T data;

        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    Node<T> *Head;

    void push_back(Node<T> *currentNode, T data);
    void PrintList(Node<T> *currentNode);
    void PrintListReverse(Node<T> *currentNode);
    int Sum(Node<T> *currentNode);
};

template<typename T>
LinkedList<T>::LinkedList()
{
    Head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<typename T>
void LinkedList<T>::pop_front()
{
    Node<T> *temp = Head;

    Head = Head->pNext;

    delete temp;
}

template<typename T>
void LinkedList<T>::clear()
{
    while(Head != nullptr)
    {
        pop_front();
    }
}

template<typename T>
T &LinkedList<T>::operator[](const int index)
{
    int counter = 0;
    Node<T> *currentNode = Head;

    while(currentNode != nullptr)
    {
        if(counter == index)
            return currentNode->data;

        currentNode = currentNode->pNext;
        counter++;
    }
}

template<typename T>
void LinkedList<T>::push_back(T data)
{
    if(Head == nullptr)
        Head = new Node<T>(data);
    else
        push_back(Head, data);
}

template<typename T>
void LinkedList<T>::push_back(LinkedList::Node<T> *currentNode, T data)
{
    if(currentNode->pNext == nullptr)
    {
        currentNode->pNext = new Node<T>(data);
        return;
    }
    else
    {
        push_back(currentNode->pNext, data);
    }
}

template<typename T>
int LinkedList<T>::Sum()
{
    return Sum(Head);
}

template<typename T>
int LinkedList<T>::Sum(LinkedList::Node<T> *currentNode) {
    if(currentNode == nullptr)
        return 0;

    return currentNode->data + Sum(currentNode->pNext);
}

template<typename T>
void LinkedList<T>::PrintList()
{
    PrintList(Head);
    cout << endl;
}

template<typename T>
void LinkedList<T>::PrintList(LinkedList::Node<T> *currentNode)
{
    if(currentNode == nullptr)
        return;

    cout << currentNode->data << " ";
    PrintList(currentNode->pNext);
}

template<typename T>
void LinkedList<T>::PrintListReverse()
{
    PrintListReverse(Head);
    cout << endl;
}

template<typename T>
void LinkedList<T>::PrintListReverse(LinkedList::Node<T> *currentNode)
{
    if(currentNode == nullptr)
        return;

    PrintListReverse(currentNode->pNext);

    cout << currentNode->data << " ";
}

#pragma endregion comment


#pragma region BinarySearchTree

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void push_back(T data);
    void BST_print_asc();
    void BST_print_desc();
    int BST_sum();
    bool isEqual(BinarySearchTree<T> *binarySearchTree2);
    bool sameData(BinarySearchTree<T> *binarySearchTree2);
    void BST_List(LinkedList<T> *linkedList);
    void makeEmpty();
    int getSize() { return size; }
    bool isBalanced();
private:
    template<typename T>
    class Node
    {
    public:
        Node<T> *parent;
        Node<T> *leftNode;
        Node<T> *rightNode;
        T data;
        int leftSubtreeHeight;
        int rightSubtreeHeight;

        Node(T data = T(), Node *parent = nullptr)
        {
            this->data = data;
            this->parent = parent;
            this->leftNode = nullptr;
            this->rightNode = nullptr;
        }
    };

    Node<T> *Root;
    int size;
    int sum;
    bool is_balanced;

    void push_back(Node<T> *currentNode, T data);
    void BST_print_asc(Node<T> *currentNode);
    void BST_print_desc(Node<T> *currentNode);
    void BST_sum(Node<T> *currentNode);
    void BST_List(Node<T> *currentNode, LinkedList<T> *linkedList);
    void makeEmpty(Node<T> *currentNode);
    void calculateSubtreeHeights(Node<T> *currentNode);
    void isBalanced(Node<T> *currentNode);
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    Root = nullptr;
    size = 0;
    sum = 0;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    makeEmpty();
}

template<typename T>
void BinarySearchTree<T>::push_back(T data)
{
    if(Root == nullptr)
    {
        Root = new Node<T>(data);
    }
    else
        push_back(Root, data);
    size++;
}

template<typename T>
void BinarySearchTree<T>::push_back(BinarySearchTree::Node<T> *currentNode, T data)
{
    if(currentNode->data >= data)
    {
        if(currentNode->leftNode == nullptr)
            currentNode->leftNode = new Node<T>(data, currentNode);
        else
            push_back(currentNode->leftNode, data);
    }
    else
    {
        if(currentNode->rightNode == nullptr)
            currentNode->rightNode = new Node<T>(data, currentNode);
        else
            push_back(currentNode->rightNode, data);
    }
}

template<typename T>
void BinarySearchTree<T>::BST_print_asc()
{
    BST_print_asc(Root);
    cout << endl;
}

template<typename T>
void BinarySearchTree<T>::BST_print_asc(Node<T> *currentNode)
{
    if(currentNode == nullptr)
        return;

    BST_print_asc(currentNode->leftNode);
    cout << currentNode->data << " ";
    BST_print_asc(currentNode->rightNode);
}

template<typename T>
void BinarySearchTree<T>::BST_print_desc()
{
    BST_print_desc(Root);
    cout << endl;
}

template<typename T>
void BinarySearchTree<T>::BST_print_desc(BinarySearchTree::Node<T> *currentNode)
{
    if(currentNode == nullptr)
        return;

    BST_print_desc(currentNode->rightNode);
    cout << currentNode->data << " ";
    BST_print_desc(currentNode->leftNode);
}

template<typename T>
int BinarySearchTree<T>::BST_sum()
{
    BST_sum(Root);

    return sum;
}

template<typename T>
void BinarySearchTree<T>::BST_sum(BinarySearchTree::Node<T> *currentNode)
{
    if(currentNode == nullptr)
        return;

    sum += currentNode->data;
    BST_sum(currentNode->leftNode);
    BST_sum(currentNode->rightNode);
}

template<typename T>
void BinarySearchTree<T>::BST_List(LinkedList<T> *linkedList)
{
    BST_List(Root, linkedList);
}

template<typename T>
void BinarySearchTree<T>::BST_List(BinarySearchTree::Node<T> *currentNode, LinkedList<T> *linkedList)
{
    if(currentNode == nullptr)
        return;

    BST_List(currentNode->leftNode, linkedList);
    linkedList->push_back(currentNode->data);
    BST_List(currentNode->rightNode, linkedList);
}

template<typename T>
bool BinarySearchTree<T>::isEqual(BinarySearchTree<T> *binarySearchTree2)
{
    if(this->size != binarySearchTree2->size)
        return false;

    LinkedList<T> linkedList1;
    this->BST_List(&linkedList1);

    LinkedList<T> linkedList2;
    binarySearchTree2->BST_List(&linkedList2);

    for(int i = 0; i < this->size; i++)
    {
        if(linkedList1[i] != linkedList2[i])
            return false;
    }

    return true;
}

template<typename T>
bool BinarySearchTree<T>::sameData(BinarySearchTree<T> *binarySearchTree2)
{
    LinkedList<T> linkedList1;
    this->BST_List(&linkedList1);

    LinkedList<T> linkedList2;
    binarySearchTree2->BST_List(&linkedList2);

    bool isFound;
    for(int i = 0; i < this->size; i++)
    {
        isFound = false;

        for(int j = 0; j < binarySearchTree2->size; j++)
        {
            if(linkedList1[i] == linkedList2[j])
            {
                isFound = true;
                break;
            }
        }

        if(!isFound)
            return false;
    }

    return true;
}

template<typename T>
void BinarySearchTree<T>::makeEmpty()
{
    makeEmpty(Root);
}

template<typename T>
void BinarySearchTree<T>::makeEmpty(Node<T> *currentNode)
{
    if(currentNode == nullptr)
        return;

    makeEmpty(currentNode->leftNode);
    makeEmpty(currentNode->rightNode);

    if(currentNode->parent == nullptr)
    {
        Root = nullptr;
        delete Root;
    }
    else if(currentNode->parent->leftNode != nullptr)
    {
        currentNode->parent->leftNode = NULL;
        currentNode->parent = NULL;
        delete currentNode;
    }
    else
    {
        currentNode->parent->rightNode = NULL;
        currentNode->parent = NULL;
        delete currentNode;
    }

    size--;
}

template<typename T>
bool BinarySearchTree<T>::isBalanced()
{
    is_balanced = true;

    calculateSubtreeHeights(Root);
    isBalanced(Root);

    return is_balanced;
}

template<typename T>
void BinarySearchTree<T>::calculateSubtreeHeights(BinarySearchTree::Node<T> *currentNode)
{
    if(currentNode == nullptr)
        return;

    calculateSubtreeHeights(currentNode->leftNode);

    if(currentNode->leftNode == nullptr)
        currentNode->leftSubtreeHeight = 0;
    else
    {
        if(currentNode->leftNode->leftSubtreeHeight >= currentNode->leftNode->rightSubtreeHeight)
            currentNode->leftSubtreeHeight = currentNode->leftNode->leftSubtreeHeight + 1;
        else
            currentNode->leftSubtreeHeight = currentNode->leftNode->rightSubtreeHeight + 1;
    }

    calculateSubtreeHeights(currentNode->rightNode);


    if(currentNode->rightNode == nullptr)
        currentNode->rightSubtreeHeight = 0;
    else
    {
        if(currentNode->rightNode->leftSubtreeHeight >= currentNode->rightNode->rightSubtreeHeight)
            currentNode->rightSubtreeHeight = currentNode->rightNode->leftSubtreeHeight + 1;
        else
            currentNode->rightSubtreeHeight = currentNode->rightNode->rightSubtreeHeight + 1;
    }
}

template<typename T>
void BinarySearchTree<T>::isBalanced(BinarySearchTree::Node<T> *currentNode)
{
    if(currentNode == nullptr)
        return;

    if(currentNode->leftSubtreeHeight > currentNode->rightSubtreeHeight + 1
    || currentNode->rightSubtreeHeight > currentNode->leftSubtreeHeight + 1)
        is_balanced = false;

    isBalanced(currentNode->leftNode);
    isBalanced(currentNode->rightNode);
}


#pragma endregion


int main() {
    cout << F(3) << endl;
    cout << Prod(-26, 25) << endl;

    LinkedList<int> linkedList;
    for(int i = 0; i < 10; i++)
    {
        linkedList.push_back(i);
    }

    cout << linkedList.Sum() << endl;

    linkedList.PrintList();
    linkedList.PrintListReverse();

    BinarySearchTree<int> binarySearchTree;
    binarySearchTree.push_back(5);
    binarySearchTree.push_back(25);
    binarySearchTree.push_back(2);
    binarySearchTree.push_back(1);
    binarySearchTree.push_back(3);
    binarySearchTree.push_back(24);
    binarySearchTree.push_back(26);

    binarySearchTree.BST_print_asc();
    binarySearchTree.BST_print_desc();

    cout << binarySearchTree.BST_sum() << endl;

    BinarySearchTree<int> binarySearchTree2;
    binarySearchTree2.push_back(5);
    binarySearchTree2.push_back(25);
    binarySearchTree2.push_back(2);
    binarySearchTree2.push_back(1);
    binarySearchTree2.push_back(3);
    binarySearchTree2.push_back(24);
    binarySearchTree2.push_back(26);
    binarySearchTree2.push_back(26);
    binarySearchTree2.push_back(28);
    binarySearchTree2.push_back(29);

    binarySearchTree2.BST_print_desc();

    cout << binarySearchTree.isEqual(&binarySearchTree2) << endl;
    cout << binarySearchTree.sameData(&binarySearchTree2) << endl;

    LinkedList<int> L;
    binarySearchTree.BST_List(&L);

    L.PrintList();

    binarySearchTree.BST_print_asc();
    cout << binarySearchTree.getSize() << endl;
    binarySearchTree.makeEmpty();
    cout << binarySearchTree.getSize() << endl;
    binarySearchTree.BST_print_asc();

    cout << binarySearchTree2.isBalanced() << endl;

    return 0;
}
