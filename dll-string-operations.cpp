#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    char info;         // data
    Node *next, *prev; // pointers to the next & prev nodes

    Node()
    {
        next = 0;
        prev = 0;
    } // Initialize the pointers to null
    Node(char n, Node *nxt = 0, Node *prv = 0)
    {
        info = n;
        next = nxt;
        prev = prv;
    } // Initialize the data, next, prev pointers
};

class LinkedList
{
    Node *head, *tail; // pointers to the head and tail nodes
public:
    LinkedList()
    {
        head = tail = 0; // empty list
    }

    int listLength()
    {
        int length = 0;
        Node *ctr = head; // pointer starts from the head
        while (ctr != 0)  // iterate until it reaches the tail
        {
            length++;
            ctr = ctr->next;
        }
        return length;
    }

    void createList(string value)
    {
        for (int i = 0; i < value.length(); i++)
        {
            Node *newNode = new Node(value[i]);
            if (head == 0) // if the list is empty
            {
                head = tail = newNode;
            }
            else // add new node to the end of the list
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode; // current tail is now the new node
            }
        }
    }

    void insertChar(int position, char value)
    {
        Node *newNode = new Node(value);
        // Empty list check
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        // Out-of-bound check
        if (position < 0 || position > listLength())
        {
            delete newNode; // prevents memory leak
            return;
        }
        // Insertion before head
        if (position == 0)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }
        Node *ptr = head;
        // Traverse to the node before the position
        for (int i = 0; i < position - 1; i++)
        {
            ptr = ptr->next;
        }
        // Insertion at the end
        if (ptr == tail)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            return;
        }
        // Insertion in the middle
        newNode->next = ptr->next;
        newNode->prev = ptr;
        ptr->next = newNode;
        newNode->next->prev = newNode;
    }

    void deleteAt(int index)
    {
        // empty list or Out-of-bound
        if (head == 0 || index >= listLength() || index < 0)
        {
            return;
        }
        // if there is only one node
        if (head == tail)
        {
            delete head;
            head = tail = 0;
            return;
        }
        Node *ptr = head; // pointer starts from the head
        // delete the head
        if (index == 0)
        {
            head = head->next;
            if (head != 0) // if list is not empty
            {
                head->prev = 0;
            }
            else // if list is empty
            {
                tail = 0; // tail and head are null
            }
            delete ptr;
            return;
        }
        // delete the tail
        if (index == listLength() - 1)
        {
            ptr = tail;
            if (head == tail) // if there is only one node
            {
                head = tail = 0;
            }
            else
            {
                tail = tail->prev; // new tail is the prev node
                tail->next = 0;    // new tail points to null
            }
            delete ptr;
            return;
        }
        // delete at any position in the middle
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        Node *del = ptr;
        ptr->prev->next = ptr->next; // links the previous node to the next node
        if (ptr->next != 0)
        {
            ptr->next->prev = ptr->prev; // links the next node to the previous node
        }
        delete del;
    }

    void concatenate(LinkedList &other)
    {
        if (other.head == 0)
        {
            return;
        } // if the other list is empty
        if (head == 0) // if the current list is empty
        {
            head = other.head;
            tail = other.tail;
            return;
        }
        tail->next = other.head;
        other.head->prev = tail; // links the two lists
        tail = other.tail;       // update tail
    }

    string extract(int startIndex, int length)
    {
        if (head == 0) // empty list
        {
            cout << "List is empty!" << endl;
            return "";
        }
        // out-of-bound check "invalid index or length"
        if (startIndex < 0 || length <= 0 || startIndex >= listLength() || startIndex + length > listLength())
        {
            cout << "Out of bound!" << endl;
            return "";
        }
        Node *ptr = head;
        int i = 0;
        string subString = "";
        while (i < startIndex + length) // Traverse till end of subString
        {
            if (i >= startIndex) // begin extraction after reaching startIndex
            {
                subString += ptr->info;
            }
            ptr = ptr->next;
            i++;
        }
        return subString;
    }

    int search(string word)
    {
        int listlen = listLength(), wordlen = word.length();
        if (head == 0 || wordlen > listlen)
        {
            return -1;
        } // empty list or word is longer than list
        Node *searchPtr = head; // pointer iterates over list
        for (int i = 0; i < listlen; i++, searchPtr = searchPtr->next)
        {
            Node *matchPtr = searchPtr; // pointer to check matching nodes
            int j = 0;                  // number of matched characters
            while (j < wordlen && matchPtr != 0 && matchPtr->info == word[j])
            {
                matchPtr = matchPtr->next;
                j++;
            }
            if (j == wordlen)
            {
                return i;
            }
        }
        return -1;
    }

    void replace(string Old, string New)
    {
        int index = search(Old);
        while (index != -1)
        {
            for (int i = 0; i < Old.length(); i++)
            {
                deleteAt(index);
            }
            for (int i = 0; i < New.length(); i++)
            {
                insertChar(index + i, New[i]);
            }
            index = search(Old); // for multiple occurrences
        }
    }

    void display()
    {
        Node *temp = head; // pointer starts from the head
        while (temp != 0)  // iterate until it reaches the tail
        {
            cout << temp->info; // prints the data
            temp = temp->next;  // moves to the next node
        }
        cout << endl;
    }
};
// code test
int main()
{
    LinkedList list1, list2;
    string value1, value2;
    cout << "Enter string to add to list 1: ";
    cin >> value1;
    list1.createList(value1);
    cout << "Enter string to add to list 2: ";
    cin >> value2;
    list2.createList(value2);
    list1.concatenate(list2);
    cout << "Concatenated Lists: ";
    list1.display();
    int index;
    cout << "Choose a character by index to remove: ";
    cin >> index;
    list1.deleteAt(index);
    cout << "List after removal: ";
    list1.display();
    int start, length;
    cout << "Enter index and length to get substring: ";
    cin >> start >> length;
    cout << "Substring: " << list1.extract(start, length) << endl;
    string searchWord;
    cout << "Search for a string in the list: ";
    cin >> searchWord;
    int foundIdx = list1.search(searchWord);
    if (foundIdx != -1)
        cout << "Found at index " << foundIdx << endl;
    else
        cout << "Not found" << endl;
    string oldSubstr, newSubstr;
    cout << "Enter 2 substrings to replace one with another: ";
    cin >> oldSubstr >> newSubstr;
    list1.replace(oldSubstr, newSubstr);
    cout << "List after replacement: ";
    list1.display();

    return 0;
}