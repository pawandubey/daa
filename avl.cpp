#include <iostream>
#include <cmath>

using namespace std;

class Tree{
public:
  int data, balance;
  Tree* left = NULL;
  Tree* right = NULL;

  Tree(int val){
    data = val;
    balance = 0;
  }
};

class AVLTree{
public:
  Tree *root;

  AVLTree(int d){
    root = new Tree(d);
  }

  void insert(int val){
    Tree* n = new Tree(val);
    this->root = _insert(this->root, n);
  }

  void print(){
    _print(this->root);
    cout<<endl;
  }

private:
  void _heighten(Tree* root){
    root->balance = _height(root->left) - _height(root->right);
  }

  void _print(Tree* root){
    if(root == NULL) return;
    _print(root->left);
    cout<<root->data<<" ";
    _print(root->right);
  }

  int _height(Tree* root){
    if(root == NULL)
      return 0;
    return 1 + max(_height(root->left), _height(root->right));
  }

  Tree* _insert(Tree *root, Tree* n){
    if(root == NULL){
      return n;
    }

    if(n->data < root->data){
      root->left = _insert(root->left, n);
    }
    else{
      root->right = _insert(root->right, n);
    }

    _heighten(root);

    if(abs(root->balance) > 1){
      if(root->balance > 1 && root->left->data > n->data){
        return rotateRight(root);
      }
      else if(root->balance > 1 && root->left->data < n->data){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
      }
      else if(root->balance < -1 && root->right->data < n->data){
        return rotateLeft(root);
      }
      else if(root->balance < -1 && root->right->data > n->data){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
      }
    }
    return root;
  }

  Tree* rotateLeft(Tree* root){
    Tree* oldRight = root->right;
    Tree* leftofRight = oldRight->left;
    oldRight->left = root;
    root->right = leftofRight;
    _heighten(root);
    return oldRight;
  }

  Tree* rotateRight(Tree* root){
    Tree* oldLeft = root->left;
    Tree* rightOfleft = oldLeft->right;
    oldLeft->right = root;
    root->left = rightOfleft;
    _heighten(root);
    return oldLeft;
  }
};

int main(){
  int s[] = {20,5,8,2,4,7,12};
  AVLTree* tree = new AVLTree(10);
  //tree->insert(20);
  for(int i=0; i<7; i++)
    tree->insert(s[i]);
  tree->print();
  //tree->heighten();
  cout<<tree->root->balance;
  return 0;
}
