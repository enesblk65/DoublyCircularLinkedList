#include <iostream>

using namespace std;

struct node {
    int data;
    struct node* next;  //this pointer saves the next node's address.
    struct node* previus;  //this pointer saves the previus node's address.
};

struct node* head; 
int listLenght = 0; 

//This function outputs the list.
void outputList(node* head) {

    struct node* temp = head;

    cout << temp->data << " ";  
    temp = temp->next;

    while (temp != head) {

        cout << temp->data << " ";
        temp = temp->next;
    }
}

//This function is used to add a new node to the first row.
void insertAtFirst() {

    struct node* newNode, * temp;
    newNode = (struct node*)malloc(sizeof(struct node));

    cout << "\nEnter New Data : ";
    cin >> newNode->data;

    cout << newNode->data << " Added to the List.\n\n";

    if (head == 0) {

        head = newNode;
        head->next = newNode;
        head->previus = newNode;
        listLenght = 1;
    }
    else {

        temp = head->previus;

        newNode->previus = head->previus;
        newNode->next = head;
        head->previus = newNode;
        head = newNode;
        temp->next = newNode;
        listLenght++;
    }

    cout << "List : ";
    outputList(head);
}

//This function is used to add a new node to the last row.
void insertAtEnd() {

    struct node* newNode, * temp;
    newNode = (struct node*)malloc(sizeof(struct node));

    cout << "\nEnter New Data : ";
    cin >> newNode->data;

    cout << newNode->data << "Added to the List.\n\n";

    if (head == 0) {

        head = newNode;
        head->next = newNode;
        head->previus = newNode;
        listLenght = 1;
    }
    else {

        temp = head->previus;
        temp->next = newNode;
        newNode->previus = temp;
        newNode->next = head;
        head->previus = newNode;
        listLenght++;
    }

    cout << "List : ";
    outputList(head);
}

//This function adds after the selected node.
void insertAfterNode() {

    struct node* newNode, * temp;
    newNode = (struct node*)malloc(sizeof(struct node));

    int i = 1, position = 0;

    cout << "\Enter the Location to be added (If you are going to add between the 2nd node and the 3rd node, enter 2) : ";
    cin >> position;

    if (position < 0 || position > listLenght) {  

        cout << "Please Enter Current Location.";
        return;
    }

    cout << "Enter New Data : ";
    cin >> newNode->data;

    cout << newNode->data << " Added to the List.\n\n";

    if (head == 0) {

        head = newNode;
        head->next = newNode;
        head->previus = newNode;
        listLenght = 1;
    }
    else {
        temp = head;

        while (i < position) {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        newNode->previus = temp;
        newNode->next->previus = newNode;
        temp->next = newNode;
        listLenght++;
    }

    cout << "List : ";
    outputList(head);
}

//This function deletes the first node.
void deleteAtFirst() {

    if (head == 0) {

        cout << "List Already Empty. First, add a new Node.";
        return;
    }
    else {
        struct node* temp = head->previus;

        cout << endl << head->data << " Deleted.\n";

        if (head == head->next) {

            cout << "List : -";
            head = 0;
            listLenght = 0;
        }
        else {

            head = head->next;
            temp->next = head;
            head->previus = temp;
            listLenght--;

            cout << "List : ";
            outputList(head);
        }
    }
}

//This function deletes the last node.
void deleteAtLast() {

    if (head == 0) {

        cout << "List Already Empty. First, add a new Node.";
        return;
    }
    else {

        struct node* temp = head->previus->previus;

        cout << endl << temp->next->data << " Deleted.\n";

        if (head == head->next) {

            cout << "List : -";
            head = 0;
            listLenght = 0;
        }
        else {

            temp->next = head;
            head->previus = temp;

            cout << "List : ";
            outputList(head);
        }
    }
}

//This function deletes the selected node.
void deleteAtIndex() {

    if (head == 0) {

        cout << "List Already Empty. First, add a new Node.";
        return;
    }
    else {

        struct node* temp1, * temp2, * deleted;
        int position = 0, i = 1;

        deleted = head;

        cout << "Enter the Location of the node to be deleted : ";
        cin >> position;

        if (position < 0 || position > listLenght) {

            cout << "Please Enter Current Location.";
            return;
        }

        while (i < position) {

            deleted = deleted->next;
            i++;
        }

        cout << deleted->data << " Deleted.\n";

        if (head == head->next) {

            cout << "List : -";
            head = 0;
            listLenght = 0;
        }
        else {

            temp1 = deleted->previus;
            temp2 = deleted->next;

            temp1->next = deleted->next;
            temp2->previus = deleted->previus;

            if (deleted == head)
                head = temp2;

            cout << "List : ";

            outputList(head);
        }
    }
}

//This function builds the list from scratch by creating new nodes.
void createNode() {

    struct node* temp, * newNode;
    head = 0;
    int choose = 1;

    while (true) {
        if (choose == 1) {

            newNode = (struct node*)malloc(sizeof(struct node));
            cout << "Enter Data : ";
            cin >> newNode->data;

            if (head == 0) {
                head = newNode;
                head->next = newNode;
                head->previus = newNode;
            }
            else {

                temp = head->previus;
                temp->next = newNode;
                newNode->previus = temp;
                newNode->next = head;
                head->previus = newNode;
            }
            listLenght++;
        }
        else if (!choose)
            break;
        else
            cout << "Please Enter Current Value\n";

        cout << "Press 1 to add a node, press 0 to proceed with transactions : ";
        cin >> choose;
    }

    cout << "\n---Created Nodes---\n";
    outputList(head);
}


int main()
{
    int operation = 0, choose = 0;  

    cout << "---DOUBLY CIRCULAR LINKED LIST---" << endl << endl;
    cout << "Welcome to the Program. You must create a node to continue adding and deleting operations.\n";

    createNode();

    while (true) {

        cout << "\n\n---OPERATIONS---\n";
        cout << "1-)Insert at First\n2-)Insert at Last\n3-)Insert at After Node\n";
        cout << "4-)Delete at First\n5-)Delete at Last\n6-)Delete a Node \n";
        cout << "\nChoose a Operation : ";
        cin >> operation;

        switch (operation) {

        case 1:
            insertAtFirst();
            break;

        case 2:
            insertAtEnd();
            break;

        case 3:
            insertAfterNode();
            break;

        case 4:
            deleteAtFirst();
            break;

        case 5:
            deleteAtLast();
            break;

        case 6:
            deleteAtIndex();
            break;

        default:
            cout << "Please Enter Correct Value.";
        }

        cout << "\nPress 1 to continue operations, press 0 to exit : ";
        cin >> choose;

        if (choose == 1)
            continue;
        else if (choose == 0)
            break;
        else {
            while (choose != 1 && choose != 0) {

                cout << "Please Enter Correct Value.";
                cout << "\n\nPress 1 to continue operations, press 0 to exit : ";
                cin >> choose;
            }
        }
    }
}

