#include <iostream>
#include <vector>
using namespace std;

// Estrutura do nó da árvore
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Função para inserir um novo nó na árvore
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Função de travessia pré-ordem
void preOrder(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    result.push_back(root->val); // push_back é um método proveniente da biblioteca vector, insere um elemento no final do vetor
    preOrder(root->left, result);
    preOrder(root->right, result);
}

// Função de travessia em-ordem
void inOrder(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    inOrder(root->left, result);
    result.push_back(root->val);
    inOrder(root->right, result);
}

// Função de travessia pós-ordem
void postOrder(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    postOrder(root->left, result);
    postOrder(root->right, result);
    result.push_back(root->val);
}

// Função principal
int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    TreeNode* root = NULL;
    for (int val : data) {
        root = insert(root, val);
    }

    vector<int> preOrderResult, inOrderResult, postOrderResult;

    preOrder(root, preOrderResult);
    inOrder(root, inOrderResult);
    postOrder(root, postOrderResult);

    cout << "Pre order :";
    for (int val : preOrderResult) {
        cout << " " << val;
    }
    cout << endl;

    cout << "In order  :";
    for (int val : inOrderResult) {
        cout << " " << val;
    }
    cout << endl;

    cout << "Post order:";
    for (int val : postOrderResult) {
        cout << " " << val;
    }
    cout << endl;

    return 0;
}
