#include <iostream>
#include <queue>
using namespace std;

struct HuffmanNode {
    int data;
    char c;
    HuffmanNode *left, *right;
};

struct MyComparator {
    bool operator()(HuffmanNode* x, HuffmanNode* y) {
        return x->data > y->data;
    }
};

void printCode(HuffmanNode* root, string s) {
    if (root->left == nullptr && root->right == nullptr && isalpha(root->c)) {
        cout << root->c << ":" << s << endl;
        return;
    }
    printCode(root->left, s + "0");
    printCode(root->right, s + "1");
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    char charArray[n];
    int charfreq[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter character " << (i + 1) << ": ";
        cin >> charArray[i];
        cout << "Enter frequency for character " << charArray[i] << ": ";
        cin >> charfreq[i];
    }

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, MyComparator> q;

    for (int i = 0; i < n; i++) {
        HuffmanNode* hn = new HuffmanNode();
        hn->c = charArray[i];
        hn->data = charfreq[i];
        hn->left = nullptr;
        hn->right = nullptr;
        q.push(hn);
    }

    HuffmanNode* root = nullptr;

    while (q.size() > 1) {
        HuffmanNode* x = q.top();
        q.pop();
        HuffmanNode* y = q.top();
        q.pop();

        HuffmanNode* f = new HuffmanNode();
        f->data = x->data + y->data;
        f->c = '-';
        f->left = x;
        f->right = y;
        root = f;
        q.push(f);
    }

    printCode(root, "");

    return 0;
}
