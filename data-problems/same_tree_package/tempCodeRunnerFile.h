#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

class Tree{
    class Node{
        public:
            friend class Tree;
            Node() {data = -1; left = NULL; right = NULL;}
            Node(const int x, Node* left, Node* right) : data(x), left(left), right(right) {}

        protected:
            int data;
            Node* left;
            Node* right;
    };
public:

    Tree() {
        mRoot = NULL;
        mSize = 0;
    }

    ~Tree() {
        clear(mRoot);
    }

    void clear(Node*& r) {
        if (!r) return;
        clear(r->left);
        clear(r->right);
        delete r;
    }

    void insert(int x) {
        insertAt(mRoot, x);
    }

    bool process(Node* n, Node* m){

        if(n == NULL && m == NULL)return 1;

        else if(n->data == m->data){

            return process(n->left,m->left) & process(n->right,m->right);
        }
        return 0;
;    }

    bool isSameBinaryTree(Tree& t) {
        bool lf = 1,rt = 1;
        if(mRoot->left != NULL && t.mRoot->left != NULL) lf = (lf & process(mRoot->left, t.mRoot->left));
        if(mRoot->right != NULL && t.mRoot->right != NULL) rt = (rt & process(mRoot->right, t.mRoot->right));
        return  lf && rt;
        // Insert your code here
    }
    // You can also put your code here

protected:
    void insertAt(Node*& r, int x) {
        if (!r) {
           r = new Node(x, NULL, NULL);
           mSize++;
           return;
        }
        if (r->data == x) return; // Do nothing
        if (x < r->data) insertAt(r->left, x); else
        insertAt(r->right, x);
    }
    Node* mRoot;
    int mSize;

};

#endif // TREE_H_INCLUDED
