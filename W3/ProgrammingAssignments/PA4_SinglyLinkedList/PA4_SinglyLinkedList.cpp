
#include <vector>
#include "../PA1_ObkectsPool/test_runner.h"
using namespace std;

template <typename T>
class LinkedList {
public:
    struct Node {
        T value;
        Node* next = nullptr;
    };

    ~LinkedList() {
        auto headNode = head;

        if (headNode == nullptr) {
            delete headNode;
            return;
        }

        auto nextNode = headNode->next;
        if (nextNode == nullptr) {
            delete nextNode;
            delete headNode;
            return;
        }

        while (nextNode != nullptr) {
            delete headNode;
            headNode = nextNode;
            nextNode = headNode->next;
        }
        delete nextNode;
        delete headNode;
    }

    void PushFront(const T& value) {
        Node* newHead = new Node;//Creating new element
        newHead->value = value;  //Assigning value to it
        newHead->next = head;    //first element becomes second
        head = newHead;          //Current element becomes first
    }

    void InsertAfter(Node* node, const T& value) {
        if (node == nullptr) {
            PopFront();
        }

        else {
            Node* newInsert = new Node;//Create new element
            newInsert->value = value;   //Assign value to it
            newInsert->next = node->next;  //Element that went after node, now goes after InsertNode
            node->next = newInsert; //newInsert now goes after node
        }
    }

    void PopFront() {
        if (head == nullptr) {
            return;
        }
        Node* newHead = head->next;
        delete head;
        head = newHead;
    }

    void RemoveAfter(Node* node) {
        if (node == nullptr) {
            PopFront();
        }
        if (node->next == nullptr) {
            return;
        }
        Node* tmp = node->next;
        node->next = node->next->next;
        delete tmp;
    }

    Node* GetHead() { return head; }
    const Node* GetHead() const { return head; }

private:
    Node* head = nullptr;
};

template <typename T>
vector<T> ToVector(const LinkedList<T>& list) {
    vector<T> result;
    for (auto node = list.GetHead(); node; node = node->next) {
        result.push_back(node->value);
    }
    return result;
}

void TestPushFront() {
    LinkedList<int> list;

    list.PushFront(1);
    ASSERT_EQUAL(list.GetHead()->value, 1);
    list.PushFront(2);
    ASSERT_EQUAL(list.GetHead()->value, 2);
    list.PushFront(3);
    ASSERT_EQUAL(list.GetHead()->value, 3);

    const vector<int> expected = { 3, 2, 1 };
    ASSERT_EQUAL(ToVector(list), expected);
}

void TestInsertAfter() {
    LinkedList<string> list;

    list.PushFront("a");
    auto head = list.GetHead();
    ASSERT(head);
    ASSERT_EQUAL(head->value, "a");

    list.InsertAfter(head, "b");
    const vector<string> expected1 = { "a", "b" };
    ASSERT_EQUAL(ToVector(list), expected1);

    list.InsertAfter(head, "c");
    const vector<string> expected2 = { "a", "c", "b" };
    ASSERT_EQUAL(ToVector(list), expected2);
}

void TestRemoveAfter() {
    LinkedList<int> list;
    for (int i = 1; i <= 5; ++i) {
        list.PushFront(i);
    }

    const vector<int> expected = { 5, 4, 3, 2, 1 };
    ASSERT_EQUAL(ToVector(list), expected);

    auto next_to_head = list.GetHead()->next;
    list.RemoveAfter(next_to_head); // удаляем 3
    list.RemoveAfter(next_to_head); // удаляем 2

    const vector<int> expected1 = { 5, 4, 1 };
    ASSERT_EQUAL(ToVector(list), expected1);

    while (list.GetHead()->next) {
        list.RemoveAfter(list.GetHead());
    }
    ASSERT_EQUAL(list.GetHead()->value, 5);
}

void TestPopFront() {
    LinkedList<int> list;

    for (int i = 1; i <= 5; ++i) {
        list.PushFront(i);
    }
    for (int i = 1; i <= 5; ++i) {
        list.PopFront();
    }
    ASSERT(list.GetHead() == nullptr);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestPushFront);
    RUN_TEST(tr, TestInsertAfter);
    RUN_TEST(tr, TestRemoveAfter);
    RUN_TEST(tr, TestPopFront);
    return 0;
}
