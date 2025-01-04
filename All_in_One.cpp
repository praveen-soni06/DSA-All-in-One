#include<iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <list>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Binary Search Tree (BST) Implementation
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> stack;
int top = -1;

//stack push
void StackPush() 
{
    int element;
    cout << "Enter the Element: ";
    cin >> element;
    stack.push_back(element);
    top++;
    cout << "* Pushed " << element << " into the Stack\n\n_______________________\n\n";
}

//Stack pop
void StackPop () 
{
    if (top == -1) {
        cout << "Underflow! Stack is empty.\n\n_______________________\n\n";
        return;
    }
    cout << "* Popped " << stack[top] << " from the Stack\n\n_______________________\n\n";
    stack.pop_back();
    top--;
}

// Stack Display
void StackDisplay() 
{
    if (top == -1) {
        cout << "Stack is empty\n\n_______________________\n\n";
        return;
    }
    cout << "The present elements in Stack: \n";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << endl;
    }
    cout << "\n\n_______________________\n\n";
}

// 1D Array Insertion
void OneInsertion (int *&arr, int &size, int element, int position)
{
     if (position < 0 || position > size) {
        cout << "Invalid position!\n";
        return;
    }

    int *newArr = new int[size + 1];
    for (int i = 0; i < position; ++i) {
        newArr[i] = arr[i];
    }

    newArr[position] = element;

    for (int i = position; i < size; ++i) {
        newArr[i + 1] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    size++;
    cout << "Element inserted successfully!\n";
}

// 1D Array Deletion
void OneDeletion (int *&arr, int &size, int position)
{
     if (position < 0 || position >= size) {
        cout << "Invalid position!\n";
        return;
    }

    int *newArr = new int[size - 1];
    for (int i = 0, j = 0; i < size; ++i) {
        if (i != position) {
            newArr[j++] = arr[i];
        }
    }

    delete[] arr;
    arr = newArr;
    size--;
    cout << "Element deleted successfully!\n";
}

// 1D Array Rotation
void OneRotation (int *&arr, int size)
{
    if (size == 0) return;
    int temp = arr[0];
    for (int i = 0; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = temp;
    cout << "Array rotated successfully!\n";
}

// 1D Array Reverse
void OneReverse (int *&arr, int size)
{
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    cout << "Array reversed successfully!\n";
}

//1D ARRAY SEARCH
int OneSearch(int *arr, int size, int element)
{
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

//1D Array Display
void OneDispay(int *arr, int size) 
{
    cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// 2D Array Insertion
void TwoInsertion (int **&arr, int &rows, int &cols, int element, int row, int col)
{
    if (row >= rows || col >= cols || row < 0 || col < 0) {
        cout << "Invalid position!\n";
        return;
    }
    arr[row][col] = element;
    cout << "Element inserted successfully!\n";
}

// 2D Array Deletion
void TwoDeletion (int **&arr, int &rows, int &cols, int row, int col)
{
    if (row >= rows || col >= cols || row < 0 || col < 0) {
        cout << "Invalid position!\n";
        return;
    }
    arr[row][col] = 0;
    cout << "Element deleted successfully!\n";
}

// 2D Array Rotation
void TwoRotation (int **&arr, int rows, int cols)
{
        cout << "Matrix rotation not implemented for non-square matrices yet.\n";
}

// 2D Array Reverse
void TwoReverse (int **&arr, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols / 2; ++j)
            swap(arr[i][j], arr[i][cols - j - 1]);

    cout << "Matrix reversed successfully!\n";
}

//2D search
int TwoSearch(int **arr, int rows, int cols, int element) 
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (arr[i][j] == element)
                return i * cols + j;
    return -1;
}

//2D display
void TwoDisplay(int **arr, int rows, int cols) 
{
    cout << "Matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

// 1D Array operation menu
void OneDArray() 
{

    int size = 0;
    int *arr = new int[size];
    int choice, element, position;

    cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**   Enter The 1D ARRAY OPERATION   **"<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**            1.INSERTION           **"<<endl;
    cout<<"**            2.DELETION            **"<<endl;
    cout<<"**            3.ROTATION            **"<<endl;
    cout<<"**            4.REVERSE             **"<<endl;
    cout<<"**            5.SEARCHING           **"<<endl;
    cout<<"**            6.DISPLAY             **"<<endl;
    cout<<"**            7.BACK                **"<<endl;
    cout<<"**************************************"<<endl;

    cin>>choice;

        while (1) 
        {
            switch (choice)
            {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position to insert: ";
                cin >> position;
                OneInsertion(arr, size, element, position);
                break;

            case 2:
                cout << "Enter position to delete: ";
                cin >> position;
                OneDeletion(arr, size, position);
                break;

            case 3:
                OneRotation(arr, size);
                break;

            case 4:
                OneReverse(arr, size);
                break;

            case 5:
                cout << "Enter element to search: ";
                cin >> element;
                position = OneSearch(arr, size, element);
                if (position != -1)
                    cout << "Element found at position " << position << "\n";
                else
                    cout << "Element not found!\n";
                break;

            case 6:
                OneDispay(arr, size);  
                break;

            case 7:
                break;
            
            default:
                cout<<"You Choose Invalid Option "<<endl;
                break;

            }
        }
        delete[] arr;

}

// 2D Array operation menu
void TwoDArray() 
{
    int rows = 0, cols = 0;
    cout << " Enter number of rows "<<endl;
    cin >> rows;
    cout << " Enter number of column "<<endl;
    cin >> cols;

    int **arr = new int*[rows];
    for (int i = 0; i < rows; ++i)
        arr[i] = new int[cols]{};

    int choice, element, row, col;

    cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**   Enter The 2D ARRAY OPERATION   **"<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**            1.INSERTION           **"<<endl;
    cout<<"**            2.DELETION            **"<<endl;
    cout<<"**            3.ROTATION            **"<<endl;
    cout<<"**            4.REVERSE             **"<<endl;
    cout<<"**            5.SEARCH              **"<<endl;
    cout<<"**            6.DISPLAY             **"<<endl;
    cout<<"**            7.BACK                **"<<endl;
    cout<<"**************************************"<<endl;
    
    cin>>choice;
    while (1) 
    {
        switch (choice)
        {
        case 1:
            cout << "Enter element to insert: ";
            cin >> element;
            cout << "Enter row and column to insert: ";
            cin >> row >> col;
            TwoInsertion(arr, rows, cols, element, row, col);
            break;

        case 2:
            cout << "Enter row and column to delete: ";
            cin >> row >> col;
            TwoDeletion(arr, rows, cols, row, col);
            break;

        case 3:
            TwoRotation(arr, rows, cols);
            break;

        case 4:
            TwoReverse(arr, rows, cols);
            break;

        case 5:
            cout << "Enter element to search: ";
            cin >> element;
            if (TwoSearch(arr, rows, cols, element) != -1)
                cout << "Element found!\n";
            else
                cout << "Element not found!\n";
            break;

        case 6:
            TwoDisplay(arr, rows, cols);;
            break;

        case 7:
            break;
        
        default:
            cout<<"You Chose Invalid Option "<<endl;
            break;

        }

    }

        for (int i = 0; i < rows; ++i)
        delete[] arr[i];
    delete[] arr;

}

//Array types
void Array()
{
    cout<<"**************************************"<<endl;
    cout<<"**       ENTER THE ARRAY TYPE       **"<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**            1.1D ARRAY            **"<<endl;
    cout<<"**            2.2D ARRAY            **"<<endl;
    cout<<"**************************************"<<endl;

    int choice;
    cin>>choice;

    switch (choice)
    {
    case 1:
        OneDArray();
        break;

    case 2:
        TwoDArray();
        break;
    
    default:
        cout<<" You Chose Invalid Option "<<endl;
        break;
    }

}

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtPosition(int data, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }
        if (position == 1) {
            insertAtBeginning(data);
            return;
        }
        Node* newNode = new Node();
        newNode->data = data;
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of range." << endl;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (position == 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range." << endl;
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

private:
    Node* head;
};

void insertList(LinkedList& list) {

    cout << endl;
    cout << "**************************************" << endl;
    cout << "**     ENTER THE INSERTION TYPE     **" << endl;
    cout << "**************************************" << endl;
    cout << "**         1.INSERT AT BEGINNING    **" << endl;
    cout << "**         2.INSERT AT END          **" << endl;
    cout << "**         3.INSERT AT POSITION     **" << endl;
    cout << "**         4.BACK                   **" << endl;
    cout << "**************************************" << endl;

    int choice, data, position;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter data to insert at beginning: ";
            cin >> data;
            list.insertAtBeginning(data);
            break;
        case 2:
            cout << "Enter data to insert at end: ";
            cin >> data;
            list.insertAtEnd(data);
            break;
        case 3:
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Enter position to insert: ";
            cin >> position;
            list.insertAtPosition(data, position);
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}
void deleteList(LinkedList& list) {
    cout << endl;
    cout << "**************************************" << endl;
    cout << "**     ENTER THE DELETION TYPE      **" << endl;
    cout << "**************************************" << endl;
    cout << "**         1.DELETE FROM BEGINNING  **" << endl;
    cout << "**         2.DELETE FROM END        **" << endl;
    cout << "**         3.DELETE FROM POSITION   **" << endl;
    cout << "**         4.BACK                   **" << endl;
    cout << "**************************************" << endl;

    int choice, position;
    cin >> choice;

    switch (choice) {
        case 1:
            list.deleteFromBeginning();
            break;
        case 2:
            list.deleteFromEnd();
            break;
        case 3:
            cout << "Enter position to delete: ";
            cin >> position;
            list.deleteFromPosition(position);
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

// All types of linked list
void LinkList()
{
    LinkedList list;
    int choice;

    cout<<endl;
    while (true) {
    cout<<"**************************************"<<endl;
    cout<<"**     ENTER THE LINKED LIST TYPE   **"<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**         1.INSERTION             **"<<endl;
    cout<<"**         2.DELETION              **"<<endl;
    cout<<"**         3.TRAVERSAL             **"<<endl;
    cout<<"**         4.BACK                  **"<<endl;
    cout<<"**************************************"<<endl;
    
    cin>>choice;

        switch (choice) {
            case 1:
                insertList(list);
                break;
            case 2:
                deleteList(list);
                break;
            case 3:
                list.display();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

}


void Stack()
{
    cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**    ENTER THE STACK OPERATION     **"<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**        1.PUSH ELEMENT           **"<<endl;
    cout<<"**        2.POP ELEMENT          **"<<endl;
    cout<<"**        3.DISPLAY                 **"<<endl;
    cout<<"**        4.BACK                    **"<<endl;
    cout<<"**************************************"<<endl;
    
    int choice;
    cin>>choice;
    while (1)
    {
        switch (choice)
        {
        case 1:
            StackPush();
            break;

        case 2:
            StackPop();
            break;

        case 3:
            StackDisplay();
            break;

        case 4:
            break;
        
        default:
            cout<<"You Chose Invalid Option "<<endl;
            break;

        }
    }
}

// Linear Queue implementation
class LinearQueue {
private:
    int front, rear, size;
    int* queue;
public:
    LinearQueue(int s) {
        front = rear = -1;
        size = s;
        queue = new int[s];
    }

    ~LinearQueue() {
        delete[] queue;
    }

    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) front = 0;
        queue[++rear] = value;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued: " << queue[front++] << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

// Circular Queue implementation
class CircularQueue {
private:
    int front, rear, size;
    int* queue;
public:
    CircularQueue(int s) {
        front = rear = -1;
        size = s;
        queue = new int[s];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    void enqueue(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = value;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued: " << queue[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        } else {
            for (int i = front; i < size; i++) {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
};

// Double-ended Queue (Deque) implementation
class Deque {
private:
    int front, rear, size;
    int* deque;
public:
    Deque(int s) {
        front = -1;
        rear = 0;
        size = s;
        deque = new int[s];
    }

    ~Deque() {
        delete[] deque;
    }

    void insertFront(int value) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            cout << "Deque is full" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        deque[front] = value;
    }

    void insertRear(int value) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            cout << "Deque is full" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = value;
    }

    void deleteFront() {
        if (front == -1) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Deleted from front: " << deque[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (front == -1) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Deleted from rear: " << deque[rear] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Deque is empty" << endl;
            return;
        }
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << deque[i] << " ";
            }
        } else {
            for (int i = front; i < size; i++) {
                cout << deque[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << deque[i] << " ";
            }
        }
        cout << endl;
    }
};

// Priority Queue implementation using STL
void priorityQueue() {
    priority_queue<int> pq;
    int choice, value;

    while (true) {
        cout << "Priority Queue Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.push(value);
                break;
            case 2:
                if (pq.empty()) {
                    cout << "Priority Queue is empty" << endl;
                } else {
                    cout << "Deleted: " << pq.top() << endl;
                    pq.pop();
                }
                break;
            case 3:
                if (pq.empty()) {
                    cout << "Priority Queue is empty" << endl;
                } else {
                    priority_queue<int> temp = pq;
                    while (!temp.empty()) {
                        cout << temp.top() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;
            case 4:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

//All types of queue 
void Queue()
{
    cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**       ENTER THE QUEUE TYPE       **"<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**        1.LINEAR QUEUE            **"<<endl;
    cout<<"**        2.CIRCULAR QUEUE          **"<<endl;
    cout<<"**        3.D-QUEUE                 **"<<endl;
    cout<<"**        4.PRIORITY QUEUE          **"<<endl;
    cout<<"**        5.BACK                    **"<<endl;
    cout<<"**************************************"<<endl;
    
    int choice;
    cin>>choice;

        switch (choice) {
        case 1: {
            int size;
            cout << "Enter size of Linear Queue: ";
            cin >> size;
            LinearQueue lq(size);
            int lqChoice, value;
            while (true) {
                cout << "Linear Queue Menu:\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Display\n";
                cout << "4. Back\n";
                cout << "Enter your choice: ";
                cin >> lqChoice;
                switch (lqChoice) {
                    case 1:
                        cout << "Enter value to enqueue: ";
                        cin >> value;
                        lq.enqueue(value);
                        break;
                    case 2:
                        lq.dequeue();
                        break;
                    case 3:
                        lq.display();
                        break;
                    case 4:
                        return;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        }
        case 2: {
            int size;
            cout << "Enter size of Circular Queue: ";
            cin >> size;
            CircularQueue cq(size);
            int cqChoice, value;
            while (true) {
                cout << "Circular Queue Menu:\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Display\n";
                cout << "4. Back\n";
                cout << "Enter your choice: ";
                cin >> cqChoice;
                switch (cqChoice) {
                    case 1:
                        cout << "Enter value to enqueue: ";
                        cin >> value;
                        cq.enqueue(value);
                        break;
                    case 2:
                        cq.dequeue();
                        break;
                    case 3:
                        cq.display();
                        break;
                    case 4:
                        return;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        }
        case 3: {
            int size;
            cout << "Enter size of Deque: ";
            cin >> size;
            Deque dq(size);
            int dqChoice, value;
            while (true) {
                cout << "Deque Menu:\n";
                cout << "1. Insert Front\n";
                cout << "2. Insert Rear\n";
                cout << "3. Delete Front\n";
                cout << "4. Delete Rear\n";
                cout << "5. Display\n";
                cout << "6. Back\n";
                cout << "Enter your choice: ";
                cin >> dqChoice;
                switch (dqChoice) {
                    case 1:
                        cout << "Enter value to insert at front: ";
                        cin >> value;
                        dq.insertFront(value);
                        break;
                    case 2:
                        cout << "Enter value to insert at rear: ";
                        cin >> value;
                        dq.insertRear(value);
                        break;
                    case 3:
                        dq.deleteFront();
                        break;
                    case 4:
                        dq.deleteRear();
                        break;
                    case 5:
                        dq.display();
                        break;
                    case 6:
                        return;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;
        }
        case 4:
            priorityQueue();
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}


// Binary Search Tree (BST) Implementation
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void insert(int data) {
        root = insertRec(root, data);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    void postorder() {
        postorderRec(root);
        cout << endl;
    }

private:
    TreeNode* root;

    TreeNode* insertRec(TreeNode* node, int data) {
        if (node == nullptr) {
            return new TreeNode(data);
        }
        if (data < node->data) {
            node->left = insertRec(node->left, data);
        } else {
            node->right = insertRec(node->right, data);
        }
        return node;
    }

    void inorderRec(TreeNode* node) {
        if (node == nullptr) return;
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

    void preorderRec(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    void postorderRec(TreeNode* node) {
        if (node == nullptr) return;
        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->data << " ";
    }
};

// AVL Tree Implementation
class AVLTree {
public:
    AVLTree() : root(nullptr) {}

    void insert(int data) {
        root = insertRec(root, data);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

private:
    struct AVLNode {
        int data;
        AVLNode* left;
        AVLNode* right;
        int height;
        AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
    };

    AVLNode* root;

    int height(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    AVLNode* insertRec(AVLNode* node, int data) {
        if (!node) return new AVLNode(data);
        if (data < node->data) node->left = insertRec(node->left, data);
        else if (data > node->data) node->right = insertRec(node->right, data);
        else return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && data < node->left->data) return rightRotate(node);
        if (balance < -1 && data > node->right->data) return leftRotate(node);
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void inorderRec(AVLNode* node) {
        if (!node) return;
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }
};

// Red-Black Tree Implementation
class RedBlackTree {
public:
    RedBlackTree() : root(nullptr) {}

    void insert(int data) {
        // Simplified insertion for demonstration purposes
        root = insertRec(root, data);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

private:
    enum Color { RED, BLACK };

    struct RBNode {
        int data;
        RBNode* left;
        RBNode* right;
        Color color;
        RBNode(int val) : data(val), left(nullptr), right(nullptr), color(RED) {}
    };

    RBNode* root;

    RBNode* insertRec(RBNode* node, int data) {
        if (!node) return new RBNode(data);
        if (data < node->data) node->left = insertRec(node->left, data);
        else if (data > node->data) node->right = insertRec(node->right, data);
        return node;
    }

    void inorderRec(RBNode* node) {
        if (!node) return;
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }
};

// B-Tree Implementation
class BTree {
public:
    BTree(int t) : t(t), root(nullptr) {}

    void insert(int data) {
        // Simplified insertion for demonstration purposes
        if (!root) {
            root = new BTreeNode(t, true);
            root->keys[0] = data;
            root->n = 1;
        } else {
            if (root->n == 2 * t - 1) {
                BTreeNode* s = new BTreeNode(t, false);
                s->C[0] = root;
                s->splitChild(0, root);
                int i = 0;
                if (s->keys[0] < data) i++;
                s->C[i]->insertNonFull(data);
                root = s;
            } else {
                root->insertNonFull(data);
            }
        }
    }

    void inorder() {
        if (root) root->traverse();
        cout << endl;
    }

private:
    struct BTreeNode {
        int* keys;
        int t;
        BTreeNode** C;
        int n;
        bool leaf;

        BTreeNode(int t, bool leaf) : t(t), leaf(leaf) {
            keys = new int[2 * t - 1];
            C = new BTreeNode * [2 * t];
            n = 0;
        }

        void insertNonFull(int k) {
            int i = n - 1;
            if (leaf) {
                while (i >= 0 && keys[i] > k) {
                    keys[i + 1] = keys[i];
                    i--;
                }
                keys[i + 1] = k;
                n++;
            } else {
                while (i >= 0 && keys[i] > k) i--;
                if (C[i + 1]->n == 2 * t - 1) {
                    splitChild(i + 1, C[i + 1]);
                    if (keys[i + 1] < k) i++;
                }
                C[i + 1]->insertNonFull(k);
            }
        }

        void splitChild(int i, BTreeNode* y) {
            BTreeNode* z = new BTreeNode(y->t, y->leaf);
            z->n = t - 1;
            for (int j = 0; j < t - 1; j++) z->keys[j] = y->keys[j + t];
            if (!y->leaf) {
                for (int j = 0; j < t; j++) z->C[j] = y->C[j + t];
            }
            y->n = t - 1;
            for (int j = n; j >= i + 1; j--) C[j + 1] = C[j];
            C[i + 1] = z;
            for (int j = n - 1; j >= i; j--) keys[j + 1] = keys[j];
            keys[i] = y->keys[t - 1];
            n++;
        }

        void traverse() {
            int i;
            for (i = 0; i < n; i++) {
                if (!leaf) C[i]->traverse();
                cout << keys[i] << " ";
            }
            if (!leaf) C[i]->traverse();
        }
    };

    BTreeNode* root;
    int t;
};

// Menu Functions for Different Trees
void Bst() {
    BinaryTree tree;
    int choice, data;

    while (true) {
        cout << "BST Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                tree.insert(data);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 3:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void AvlTree() {
    AVLTree tree;
    int choice, data;

    while (true) {
        cout << "AVL Tree Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                tree.insert(data);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void RedBlackTreeMenu() {
    RedBlackTree tree;
    int choice, data;

    while (true) {
        cout << "Red-Black Tree Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                tree.insert(data);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void Btree() {
    int t;
    cout << "Enter the minimum degree of B-Tree: ";
    cin >> t;
    BTree tree(t);
    int choice, data;

    while (true) {
        cout << "B-Tree Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                tree.insert(data);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

//All types of tree
void Trees()
{
    cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**       ENTER THE TREE TYPE       **"<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**            1.BST                 **"<<endl;
    cout<<"**            2.AVL TREE            **"<<endl;
    cout<<"**            3.RED BLACK TREE      **"<<endl;
    cout<<"**            4.B-TREE              **"<<endl;
    cout<<"**            5.BACK                **"<<endl;
    cout<<"**************************************"<<endl;
    
    int choice;
    cin>>choice;

        switch (choice)
        {
        case 1:
            Bst();
            break;

        case 2:
            AvlTree();
            break;

        case 3:
            RedBlackTree();
            break;

        case 4:
            Btree();
            break;

        case 5:
            break;
        
        default:
            cout<<"You Chose Invalid Option "<<endl;
            break;

        }

}

class Graph {
    int V; // Number of vertices
    list<int>* adj; // Adjacency list

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void DFS(int s);
    void DFSUtil(int v, bool visited[]);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    queue<int> queue;
    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop();

        for (auto adjecent : adj[s]) {
            if (!visited[adjecent]) {
                visited[adjecent] = true;
                queue.push(adjecent);
            }
        }
    }
    delete[] visited;
}

void Graph::DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";

    for (auto adjecent : adj[v]) {
        if (!visited[adjecent]) {
            DFSUtil(adjecent, visited);
        }
    }
}

void Graph::DFS(int s) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(s, visited);
    delete[] visited;
}

void GraphMenu() {
    int V, choice, v, w, start;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;
    Graph g(V);

    while (true) {
    cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**              GRAPH MENU          **"<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**             1.ADD EDGE           **"<<endl;
    cout<<"**             2.BFS TRAVERSAL      **"<<endl;
    cout<<"**             3.DFS TRAVERSAL      **"<<endl;
    cout<<"**             5.BACK               **"<<endl;
    cout<<"**************************************"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the vertices (v w) to add an edge: ";
                cin >> v >> w;
                g.addEdge(v, w);
                break;
            case 2:
                cout << "Enter the starting vertex for BFS: ";
                cin >> start;
                cout << "BFS Traversal: ";
                g.BFS(start);
                cout << endl;
                break;
            case 3:
                cout << "Enter the starting vertex for DFS: ";
                cin >> start;
                cout << "DFS Traversal: ";
                g.DFS(start);
                cout << endl;
                break;
            case 4:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

//Graph traversal algorithm
void Graphs()
{
    cout<<endl;
    cout<<"***************************************"<<endl;
    cout<<"** ENTER THE TYPE OF GRAPH SEARCHING **"<<endl;
    cout<<"***************************************"<<endl;
    cout<<"**        1.GRAPH                    **"<<endl;
    cout<<"**        2.BACK                     **"<<endl;
    cout<<"***************************************"<<endl;
    
    int choice;
    cin>>choice;

    switch (choice) {
        case 1:
            GraphMenu();
            break;
        case 2:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }

}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

// All sorting algorithams
void Sorting()
{
    vector<int> a;
    int choice, n, element;

    cout<<endl;
    cout<<"***************************************"<<endl;
    cout<<"**    CHOOSE THE SORTIN ALGORITHM    **"<<endl;
    cout<<"***************************************"<<endl;
    cout<<"**           1.ENTER ARRAY ELEMENTS  **"<<endl;
    cout<<"**           1.BUBBLE SORT           **"<<endl;
    cout<<"**           2.INSERTION SORT        **"<<endl;
    cout<<"**           3.SELECTION SORT        **"<<endl;
    cout<<"**           4.QUICK SORT            **"<<endl;
    cout<<"**           5.MERGE SORT            **"<<endl;
    cout<<"**           6.RADIX SORT            **"<<endl;
    cout<<"**           7.BUCKET SORT           **"<<endl;
    cout<<"**           8.BACK                  **"<<endl;
    cout<<"***************************************"<<endl;
    
        cin>>choice;

        switch (choice) {
            case 1:
                a.clear();
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> element;
                    a.push_back(element);
                }
                break;
            case 2:
                bubbleSort(a);
                cout << "Array sorted using Bubble Sort.\n";
                break;
            case 3:
                selectionSort(a);
                cout << "Array sorted using Selection Sort.\n";
                break;
            case 4:
                insertionSort(a);
                cout << "Array sorted using Insertion Sort.\n";
                break;
            case 5:
                mergeSort(a, 0, a.size() - 1);
                cout << "Array sorted using Merge Sort.\n";
                break;
            case 6:
                quickSort(a, 0, a.size() - 1);
                cout << "Array sorted using Quick Sort.\n";
                break;
            case 7:
                displayArray(a);
                break;
            case 8:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }


        

}


//DSA MENU
void menu() 
{
    cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**  Enter The Number What You Want  **"<<endl;
    cout<<"**************************************"<<endl;
    cout<<"**            1.ARRAY               **"<<endl;
    cout<<"**            2.LINKED LIST         **"<<endl;
    cout<<"**            3.STACK               **"<<endl;
    cout<<"**            4.QUEUE               **"<<endl;
    cout<<"**            5.TREE                **"<<endl;
    cout<<"**            6.GRAPH               **"<<endl;
    cout<<"**            7.SORTING             **"<<endl;
    cout<<"**            8.EXIT                **"<<endl;
    cout<<"**************************************"<<endl;
    
    int choice; 
    cin>>choice;

        switch (choice)
        {
        case 1:
            Array();
            break;

        case 2:
            LinkList();
            break;

        case 3:
            // Stack();
            break;

        case 4:
            // Queue();
            break;

        case 5:
            // Trees();
            break;

        case 6:
            // Graphs();
            break;

        case 7:
            // Sorting();
            break;
        
        case 8:
            cout<<"EXITING......";  
            exit(0); // For exit the program   
            break;
        
        default:
            cout<<"You Chose Invalid Option "<<endl;
            break;

        } 
}

int main () 
{
    cout<<"**************************************"<<endl;
    cout<<"**          ALL IN ONE DSA          **"<<endl;
    cout<<"**************************************"<<endl;

    //Call menu option
    menu();
}