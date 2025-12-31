/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void f(Node* root) {

        queue<Node*>q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size(); // size of the current level
            Node* curr = q.front();

            for (int i = 0; i < size; i++) { // for loop to access the elements of the current level

                if (i != 0) { 
                    curr->next = q.front();
                    curr = q.front();
                }

                Node* temp = q.front();
                q.pop();

                //pushing the children to build the next level
                if (temp->left != nullptr) {
                     q.push(temp->left);
                }
                if (temp->right != nullptr) {
                     q.push(temp->right);
                }

            }
        }
    }
    Node* connect(Node* root) {

        if (root == NULL) {
            return root;
        }

        f(root); //function call

        return root;
    }
};