#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class BST
{
    node *root;
    node *find(node *, int);
    node *findMin(node *);
    node *findMax(node *);
    node *remove(node *, int);
    void insert(node *, int);
    void destroyTree(node *);
    void inOrder(node *);
    void preOrder(node *);
    void postOrder(node *);
    void evenNode(node *);
    void oddNode(node *);
    void levelOrder(node *);
    bool isLeafNode(node *);

public:
    BST();
    ~BST();
    void insert(int);
    void destroyTree();
    void display();
    node *remove(int);
    node *find(int);
    node *getRoot();
    int maxdepth();
};

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    destroyTree();
}

void BST::insert(int key)
{
    if (root != NULL)
    {
        insert(root, key);
    }
    else
    {
        root = new node;
        root->data = key;
        root->left = NULL;
        root->right = NULL;
    }
}

void BST::insert(node *leaf, int key)
{
    if (key < leaf->data)
    {
        if (leaf->left != NULL)
        {
            insert(leaf->left, key);
        }
        else
        {
            leaf->left = new node;
            leaf->left->data = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else
    {
        if (leaf->right != NULL)
        {
            insert(leaf->right, key);
        }
        else
        {
            leaf->right = new node;
            leaf->right->data = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

node *BST::find(int key)
{
    // Bat dau tu root
    return find(root, key);
}

node *BST::find(node *leaf, int key)
{
    if (leaf == NULL)
    {
        return NULL;
    }
    else if (key == leaf->data)
    {
        return leaf;
    }
    else if (key < leaf->data)
    {
        return find(leaf->left, key);
    }
    else
        return find(leaf->right, key);
}

node *BST::remove(int key)
{
    return remove(root, key);
}

node *BST::remove(node *node_t, int key)
{
    node *temp;

    // Truong hop empty node
    if (node_t == NULL)
        return NULL;

    if (key < node_t->data)
    {
        node_t->left = remove(node_t->left, key); // Cay con trai
    }
    else if (key > node_t->data)
    {
        node_t->right = remove(node_t->right, key); // Cay con phai
    }
    else
    {
        // Tim duoc key.
        if (isLeafNode(node_t))
        {
            delete node_t;
            node_t = NULL;
        }
        else if (node_t->right && node_t->left)
        {
            // Dau tien tim minimum leaf o phia ben trai cua node ma ta dang xoa.
            // Sao chep data tu minimum node sang node ma ta dang xoa.
            // Cuoi cung xoa minimum node trong cay con ben phai.
            node *temp = findMin(node_t->right);
            node_t->data = temp->data;
            node_t->right = remove(node_t->right, node_t->data);
        }
        else
        {
            temp = node_t;
            if (node_t->right == NULL)
                node_t = node_t->left;
            else if (node_t->left == NULL)
                node_t = node_t->right;
            delete temp;
        }
    }
    // Tra ve node goc sau khi qua trinh xoa node hoan thanh
    return node_t;
}

bool BST::isLeafNode(node *t)
{
    if (t != NULL && t->left == NULL && t->right == NULL)
        return true;
    else
        return false;
}

// Tim minimum
node *BST::findMin(node *t)
{
    if (t == NULL)
        return t;
    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

//Tim max
node *BST::findMax(node *t)
{
    if (t == NULL)
        return t;
    else if (t->right == NULL)
        return t;
    else
        return findMax(t->right);
}

void BST::destroyTree()
{
    destroyTree(root);
}

void BST::destroyTree(node *leaf)
{
    if (leaf != NULL)
    {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
    }

    delete leaf;
}

void BST::inOrder(node *t)
{
    if (t != NULL)
    {
        inOrder(t->left);
        cout << t->data << " ";
        inOrder(t->right);
    }
}

void BST::preOrder(node *t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
}

void BST::postOrder(node *t)
{
    if (t != NULL)
    {
        postOrder(t->left);
        postOrder(t->right);
        cout << t->data << " ";
    }
}

void BST::evenNode(node *t){
    if (t != NULL)
    {
        evenNode(t->left);
        //Neu la even node thi in ra
        if(t->data % 2 == 0)
        cout << t->data << " ";
        
        evenNode(t->right);
    }
}

void BST::oddNode(node *t){
    if (t != NULL)
    {
        oddNode(t->left);
        //Neu la odd node thi in ra
        if (t->data % 2 != 0)
        cout << t->data << " ";
        
        oddNode(t->right);
    }
}

void BST::display()
{
    cout << "1. PreOrder: ";
    preOrder(root);
    cout << "\n2. InOrder: ";
    inOrder(root);
    cout << "\n3. PostOrder: ";
    postOrder(root);
    cout << "\n4. EvenNode: ";
    evenNode(root);
    cout << "\n5. OddNode: ";
    oddNode(root);
    cout << "\n6. LevelOrder: ";
    levelOrder(root);
}

// Do phuc tap luon luon la O(n). Do phuc tap trung binh la O(n) cho worst case. O(1) cho best casevoid BST::levelOrder(node* t)
void BST::levelOrder(node *t)
{
    if (t != NULL)
    {
        queue<node *> q;

        // enqueue node goc
        q.push(t);

        // deque node goc, enque trai va phai node con, thoat loop khi queue trong
        while (!q.empty())
        {
            node *current = q.front();
            cout << current->data << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
            q.pop(); //remove element phia truoc
        }
    }
}

int findMax(node *t){
    //Base case
    if ( t == NULL){
        return INT_MIN;
    }
    //
    int result = t->data;
    int lResult = findMax(t->left);
    int rResult = findMax(t->right);
    if (lResult > result){
        result = lResult;
    }
    if (rResult > result){
        result = rResult;
    }
    return result;
}

int findMin(node *t){
    //Base case
    if (t == NULL){
        return INT_MAX;
    }
    //
    int result = t->data;
    int lResult = findMin(t->left);
    int rResult = findMin(t->right);
    if (lResult < result){
        result = lResult;
    }
    if (rResult < result){
        result = rResult;
    }
    return result;
}

// Tra ve do sau toi da root-to-leaf cua cay.
// O(n)
int maxDepth(node *t)
{
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        int ld = maxDepth(t->left);
        int rd = maxDepth(t->right);

        return (max(ld, rd) + 1);
    }
}

node *BST::getRoot()
{
    return root;
}

int main()
{
    BST *tree = new BST();
    tree->insert(41);
    tree->insert(10);
    tree->insert(23);
    tree->insert(30);
    tree->insert(65);
    tree->insert(70);
    tree->insert(57);
    tree->insert(90);
    tree->insert(109);
    tree->insert(80);
    tree->display();

    cout << "\n7. Tree depth is: " << maxDepth(tree->getRoot());
    cout << "\n8. Maximum element is: " << findMax(tree->getRoot()) << endl;
    cout << "\n9. Minimum element is: " << findMin(tree->getRoot()) << endl;

    delete tree;
    return 0;
}
