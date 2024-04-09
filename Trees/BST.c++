#include <iostream>
#include <queue>
#include <cmath>
#include <stack>
#include <cassert>
using namespace std;

template<typename T>
struct node
{
    T data;
    node<T> *left {};
    node<T> *right {};
    node(T data) 
    {
        this->data = data;
        left = right = NULL;
    }
};

template<typename T>
class BST
{
    
private:
    int         Height_diameter(node<T> * root, int& diameter);
    node<T> *   ancestor_search(node<T> * root, T element);
public:
    node<T> *   root{}; // point to the root node of the tree
    node<T> *   insert(node<T>* root, T element);
    node<T> *   Delete(node<T> * root, T element);
    void        preOrder(node<T>* root);
    void        inOrder(node<T>* root);
    void        postOrder(node<T>* root);
    void        LevelOrderTraversal(node<T> * root);
    void        reverse_level_order(node<T> * root);
    node<T> *   search_recursive(node<T>* root, T element);
    bool        search_iterative(T element);
    node<T> *   Min(node<T> * root);
    node<T> *   Max(node<T> * root);
    int         height(node<T> * root);
    int         count_nodes(node<T> * root);
    int         count_leaves(node<T> * root);
    bool        Perfect_tree();
    bool        Is_BST(node<T> *root, T MinValue, T MaxValue);
    bool        Is_degenerate(node<T> * root);
    bool        complete_BST(node<T> * root);
    bool        full_BST(node<T> * root);
    bool        balanced_BST(node<T> * root);
    void        clear(node<T> * root);
    int         Diameter(node<T> * root);
    vector<int> ancestors(vector<int> & ancestor);
    BST();
    ~BST();
};

template<typename T>
BST<T>::BST()
{
    root = NULL; // make tree empty
}

template <typename T>
int BST<T>::Height_diameter(node<T> *root, int &diameter)
{
    if (!root)
        return 0;
    int left_h  = Height_diameter(root->left, diameter);
    int right_h = Height_diameter(root->right, diameter);
    diameter = max(diameter, left_h + right_h);
    return 1 + max(left_h, right_h);
}

template <typename T>
node<T> *BST<T>::ancestor_search(node<T> *root, T element)
{
    if (!root)
        return NULL;
    else if (root->left->data == element)
        return root;
    return ancestor_search(root->left, element);
    return ancestor_search(root->right, element);
}

template <typename T>
node<T> *BST<T>::insert(node<T> *root, T element)
{
    if (root == NULL) 
    {
        node<T> * n = new node<T>(element);
        root = n; // here we but the root node to the root of the tree and from it we can reach to the other nodes
    }
    else if (root->data >= element)
        root->left = insert(root->left, element); // same as root->left
    else 
        root->right = insert(root->right, element);
    return root;
}

template<typename T>
node<T> *BST<T>::Delete(node<T> *root, T element)
{
    // if the tree is empty
    if (root == NULL)
        return root;
    else if (element < root->data) // go left
        root->left  = Delete(root->left, element);
    else if (element > root->data) // go right
        root->right = Delete(root->right, element);
    else // the target element
    {
        if(!root->left && !root->right) // if it leaf node
        {
            delete root;
            root = NULL;
        }
        else if (root->left && !root->right) // if has one left child
        {
            node<T> * temp = root;
            root = root->left; // go to the left child that will replace it
            delete temp;       // delete the target node
        }
        else if (!root->left && root->right) // if has one right child
        {
            node<T> * temp = root;
            root = root->right; // go to the right child that will replace it
            delete temp;        // delete the target node
        }
        else // if the node has 2 children
        {
            // in this u have 2 cases u can get the max left child (predecessor) or min right child (successor)
            node<T> * succ = Min(root->right); // get the successor
            root->data  = succ->data;       // replace the succ with the target
            root->right = Delete(root->right, succ->data); 
        }
    }
    return root;
}

template<typename T>
void BST<T>::preOrder(node<T>* root)
{
    if (root == nullptr)
        return;
    cout << root->data << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

template<typename T>
void BST<T>::inOrder(node<T>* root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}

template<typename T>
void BST<T>::postOrder(node<T>* root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ' ';
}

template<typename T>
node<T> * BST<T>::search_recursive(node<T>* root, T element)
{
    if (root == NULL)
        return NULL;
    if (root->data == element)
        return root;
    else if (root->data >= element)
        return search_recursive(root->left, element);
    return search_recursive(root->right, element);
}

template<typename T>
bool BST<T>::search_iterative(T element)
{
    node<T> * r = root;
    while (r)
    {
        if (r->data == element)
            return true;
        else if (r->data < element)
            r = r->right;
        else
            r = r->left;
    }
    return false;
}

template<typename T>
node<T> * BST<T>::Min(node<T> * root)
{
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    return Min(root->left);
}

template<typename T>
node<T> * BST<T>::Max(node<T> * root)
{
    if (root == NULL)
        return NULL;
    else if (root->right == NULL)
        return root;
    return Max(root->right);
}

template<typename T>
int BST<T>::height(node<T> *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

template<typename T>
int BST<T>::count_nodes(node<T> *root)
{
    if (!root)
        return 0;
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}

template<typename T>
int BST<T>::count_leaves(node<T> *root)
{
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 1;
    return count_leaves(root->left) + count_leaves(root->right); 
}

template<typename T>
bool BST<T>::Perfect_tree()
{
    return pow(2, height(root) + 1) - 1 == count_nodes(root);
}

template<typename T>
bool BST<T>::Is_BST(node<T> *root, T MinValue, T MaxValue)
{
    if (root == NULL)
        return true;
    else if (root->data >= MinValue
            && root->data < MaxValue
            && Is_BST(root->right, root->data, MaxValue)
            && Is_BST(root->left, MinValue, root->data))
            return true;
    return false;
}

template<typename T>
bool BST<T>::Is_degenerate(node<T> *root)
{
    if (root == NULL)
        return true;
    else if (root->left && root->right)
        return false;
    return Is_degenerate(root->left) && Is_degenerate(root->right);  // we can use also expression height == Number of node
}

template <typename T>
bool BST<T>::complete_BST(node<T> *root)
{
    // we will use level order
    if (root == NULL)
        return false;
    queue <node<T> *> Q;
    // push the root to the queue
    Q.push (root);
    
    // use to check the tree every time when you see null at left and the right has child 
    bool check = false;
    while (!Q.empty())
    {
        root = Q.front ();
        Q.pop ();
        // if there is left child
        if (root->left)
        {
            if (check)
                return false;
            Q.push (root->left);
        }
        else 
            check = true;
        // if there if right child after the left one  يعني في نفس المستوي في طفل يمين ومفيش واحد في الشمال
        if (root->right)
        {
            if (check)
                return false;
            Q.push (root->right);
        }
        else 
            check = true;
    }
    return true;
}

template <typename T>
bool BST<T>::full_BST(node<T> *root)
{
    if (root == NULL)
        return true;
    // if the sub tree has only one child in left or right it's not full 
    else if ((root->left && !root->right) || (!root->left && root->right))
        return false;
    // check for every single node on left and right
    return full_BST(root->left) && full_BST(root->right);
}

template<typename T>
void BST<T>::LevelOrderTraversal(node<T> *root)
{
    if (root == NULL)
        return;
    queue<node<T>*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        node<T>* cur = Q.front();
        cout << cur->data << ' ';
        if (cur->left)
            Q.push(cur->left);
        if (cur->right)
            Q.push(cur->right);
        Q.pop();
    }
    printf("\n");
}

template<typename T>
void BST<T>::reverse_level_order(node<T> *root)
{
    if (!root)
        return;
    queue<node<T>*> Q;
    stack<int> st;
    Q.push(root);
    while (!Q.empty())
    {
        node<T> * cur = Q.front();
        Q.pop();
        st.push(cur->data);
        if (cur->left)
            Q.push(cur->left);
        if (cur->right)
            Q.push(cur->right);
    }
    while (!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
    printf("\n");
}

template<typename T>
bool BST<T>::balanced_BST(node<T> *root)
{
    if (root == NULL)
        return true;
    //get the height of the left sub tree and right sub tree
    int left_height = height(root->left);
    int right_height = height(root->right);
    // make ur check of the balanced BST
    if (abs(left_height - right_height) > 1)
        return false;
    // make for every single node in the tree
    return balanced_BST(root->left) && balanced_BST(root->right);
}

template <typename T>
void BST<T>::clear(node<T> *root)
{
    while (root)
    {
        clear(root->left);
        clear(root->right);
        delete root;
        root = NULL;
    }
}

template <typename T>
int BST<T>::Diameter(node<T> *root)
{
    int diameter = 0;
    if (!root)
        return 0;
    Height_diameter(root, diameter);
    return diameter;
}

template <typename T>
vector<int> BST<T>::ancestors(vector<int> &ancestor)
{
    vector<int> ans;
    for (auto i : ancestor)
    {
        node<T> * temp = search_recursive(root, i);
        if (temp) 
        {
            if (temp->right)
            {
                node<T> * succ = Min(temp->right);
                ans.push_back(succ->data);
            }
            else
            {
                node<T> * succ = ancestor_search(root, i);
                ans.push_back(succ->data);
            }
        }
    }
    return ans;
}

template<typename T>
BST<T>::~BST()
{
    clear(root);
}


int main (void)
{
    BST<int> t;
    t.root = t.insert(t.root, 4);
    t.root = t.insert(t.root, 2);
    t.root = t.insert(t.root, 1);
    t.root = t.insert(t.root, 3);
    t.root = t.insert(t.root, 6);
    t.root = t.insert(t.root, 5);         
    t.root = t.insert(t.root, 7);                             
    
    cout << "Pre Order  : [ ";
    t.preOrder(t.root);
    cout << "]\n";
    cout << "In Order   : [ ";
    t.inOrder(t.root);
    cout << "]\n";
    cout << "Post Order : [ ";
    t.postOrder(t.root);
    cout << "]\n";
    cout << "-------------------------------------\n";
    cout << "\nLevel Order Traversal         : ";
    t.LevelOrderTraversal(t.root);
    cout << "Reverse Level Order Traversal : ";
    t.reverse_level_order(t.root);
    cout << "-------------------------------------\n";

    cout << "\nRecursive Search {" << 0 << "} : ";
    (t.search_recursive(t.root, 0)) ? cout << "Found !\n" : cout << "Not Found !\n";
    cout << "Iterative Search {" << 4 << "} : ";
    (t.search_iterative(4)) ? cout << "Found !\n" : cout << "Not Found !\n";
    cout << "-------------------------------------\n";

    cout << "\nMin Node   : " << t.Min(t.root)->data << '\n';
    cout << "Max Node   : " << t.Max(t.root)->data << '\n';
    cout << "Max Height : " << t.height(t.root) << '\n';
    cout << "-------------------------------------\n";

    cout << "\nNumber of Nodes      : " << t.count_nodes(t.root) << '\n';
    cout << "Number of Leaf Nodes : " << t.count_leaves(t.root) << '\n';
    cout << "Tree Diameter        : " << t.Diameter(t.root) << '\n';
    cout << "-------------------------------------\n";

    cout << "\nQueries of Ancestors for This values !!\n";
    vector<int> ancestor = {4, 2, 6};
    vector<int> v = t.ancestors(ancestor);
    for (auto i : ancestor)
        cout << i << ' ';
    cout << '\n';
    for (auto i : v)
        cout << i << ' ';
    cout << "\n-------------------------------------\n";

    cout << "\n\n";
    (t.Perfect_tree()) ? cout << "Perfect Tree !!\n" : cout << "Not Perfect Tree !!\n";
    (t.Is_BST(t.root, INT_MIN, INT_MAX)) ? cout << "It's BST Tree !!\n" : cout << "It's Not BST Tree !!\n";
    (t.Is_degenerate(t.root)) ? cout << "It's Degenerate Tree !!\n" : cout << "It's Not Degenerate Tree !!\n";
    (t.balanced_BST(t.root)) ? cout << "It's Balanced BST !!\n" : cout << "It's Not Balanced BST !!\n";
    (t.full_BST(t.root)) ? cout << "It's Full BST !!\n" : cout << "It's Not Full BST !!\n";
    (t.complete_BST(t.root)) ? cout << "It's Complete BST !!\n" : cout << "It's Not Complete BST !!\n";
    cout << "-------------------------------------\n";
    
    cout << "\nThe tree after delete {" << 4 << "} !!\n";
    t.Delete(t.root, 4);

    cout << "Pre Order  : [ ";
    t.preOrder(t.root);
    cout << "]\n";
    cout << "In Order   : [ ";
    t.inOrder(t.root);
    cout << "]\n";
    cout << "Post Order : [ ";
    t.postOrder(t.root);
    cout << "]\n";
    cout << "-------------------------------------\n";

}
