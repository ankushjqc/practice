#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

class tree {

private :
  struct Node {
    int value;
    Node * leftChild;
    Node *rightChild;
     Node(int v);
     Node(int v, Node *left, Node *right);
    };
    Node * root;
    Node * vitotree(const vector<int> &input,int index,int size);
public:
   tree();
   tree(const vector<int> &vi);
  void print_tree();
  void print_tree(Node * n);
  
};
tree::Node * tree::vitotree(const vector<int> &input,int index,int size){

       auto temp = new Node(input.at(index));
       auto left= 2*index +1 ;
       auto right= 2*index +2 ;
       
       if(left<size)
       temp->leftChild=vitotree(input,left,size);
       if(right<size)
       temp->rightChild=vitotree(input,right,size);
      
      return temp;
  
  }
void tree::print_tree(Node *n){
  if(n!=nullptr) {
    cout << n->value << endl;
    print_tree(n->leftChild); 
    print_tree(n->rightChild);
    }
  }
void tree::print_tree(){
  print_tree(root);
  }
tree::tree(const vector<int> & cvi){
  root=vitotree(cvi,0,cvi.size());
  }
tree::tree(){
  root=nullptr;
  }
  
tree::Node:: Node(int v){
  value=v;
  leftChild=nullptr;
  rightChild=nullptr;
  }
tree::Node:: Node(int v, Node *l,Node *r){
  value=v;
  leftChild=l;
  rightChild=r;
  }
  
    

int main() {
  vector<int> in(8,0);
  iota(in.begin(),in.end(),100);
  tree t(in);
  t.print_tree();
  
  
  return 0;
}
