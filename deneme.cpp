//    #include <iostream>
//using namespace std;
// 
//// Data structure to store a binary tree node
//struct Node
//{
//    int data;
//    Node *left, *right;
// 
//    Node(int data)
//    {
//        this->data = data;
//        this->left = this->right = nullptr;
//    }
//};
// 
//// Function to print the root-to-leaf path with a given sum in a binary tree
//bool printPath (Node *root, int sum)
//{
//    // base case
//    if (sum == 0) {
//        return true;
//    }
// 
//    // base case
//    if (root == nullptr) {
//        return false;
//    }
// 
//    // recur for the left and right subtree with reduced sum
//    bool left = printPath(root->left, sum - root->data);
//    bool right = printPath(root->right, sum - root->data);
// 
//    // print the current node if it lies on a path with a given sum
//    if (left || right) {
//        cout << root->data << " ";
//    }
// 
//    return left || right;
//}
// 
//// Function to calculate the maximum root-to-leaf sum in a binary tree
//int rootToLeafSum(Node* root)
//{
//    // base case: tree is empty
//    if (root == nullptr) {
//        return 0;
//    }
// 
//    // calculate the maximum node-to-leaf sum for the left child
//    int left = rootToLeafSum(root->left);
// 
//    // calculate the maximum node-to-leaf sum for the right child
//    int right = rootToLeafSum(root->right);
// 
//    // consider the maximum sum child
//    return (left > right? left : right) + root->data;
//}
// 
//// Function to print maximum sum root-to-leaf path in a given binary tree
//void findMaxSumPath(Node *root)
//{
//    int sum = rootToLeafSum(root);
//    cout << "Largest Branch is= " << sum << endl;
//}
// 
//int main()
//{
//    Node* root = nullptr;
//    /* Construct the following tree
//        
//          5
//         / \
//        4   8
//       /   / \
//      11  13  4
//     /  \      \
//    7    2      1 
//    */
// 
//    root = new Node(5);
//    root->left = new Node(4);
//    root->right = new Node(8);
//    root->left->left = new Node(11);
//    root->right->left = new Node(13);
//    root->right->right = new Node(4);
//    root->left->left->left = new Node(7);
//    root->left->left->right = new Node(2);
//    root->right->right->right = new Node(1);
//   
//   
//    root->right->left->left = new Node(7);
//    root->right->left->right = new Node(2);
//    
// 
//    findMaxSumPath(root);
// 
//    return 0;
//}