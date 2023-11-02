#include <iostream>

using namespace std;

struct Node {
    int v;
    Node* next;
};

Node* CreateCircle(int num) {
    Node* head = new Node();
    head->v    = 1;
    Node* prev = head;
    Node* curr = nullptr;

    for (int i = 2; i <= num; i++) {
        curr       = new Node();
        curr->v    = i;
        prev->next = curr;
        prev       = curr;
    }
    prev->next = head;
    return head;
}

int main() {
    int n;
    cin >> n;

    Node* node = CreateCircle(n);

    while (node != node->next) {
        cout << node->next->v << " ";

        node->next = node->next->next;
        node       = node->next;
    }

    cout << node->v << endl;

    return 0;
}