#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) {
        this->data = data;
    }
};

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data: ";
    if (!(cin >> rootData)) {
        cerr << "Invalid input or EOF. Exiting.\n";
        exit(1);
    }

    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* f = q.front();
        q.pop();

        cout << "Enter number of children of " << f->data << ": ";
        int n;
        if (!(cin >> n)) {
            cerr << "Invalid number of children. Exiting.\n";
            exit(1);
        }

        for (int i = 0; i < n; i++) {
            int childData;
            cout << "Enter " << i << "th child of " << f->data << ": ";
            if (!(cin >> childData)) {
                cerr << "Invalid child input. Exiting.\n";
                exit(1);
            }
            TreeNode<int>* child = new TreeNode<int>(childData);
            f->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}


void printTree(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<": ";
    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
}

int countNodes(TreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    int count = 1; // Count the current node
    for (int i = 0; i < root->children.size(); i++) {
        count += countNodes(root->children[i]); // Add the count of child nodes
    }
    return count;
}

int height(TreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    int maxHeight = 0;
    for (int i = 0; i < root->children.size(); i++) {
        int childHeight = height(root->children[i]);
        if (childHeight > maxHeight) {
            maxHeight = childHeight;
        }
    }
    return maxHeight + 1; // Add 1 for the current node
}   

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printTree(root);

    return 0;
}

