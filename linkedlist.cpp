#include<iostream>
using namespace std;
class dd {
  private:
  struct Node {
    int value;
    Node * next;
    Node * prev;
    Node(int v) ;
    Node(int v,Node *n,Node *p);
    };
  Node * head;
  public:
  dd():head(nullptr){};
  void add(int v);
  void print(void);
  void add(int v,Node * n);
  void rev(void);
};
dd::Node::Node(int v) {
  value=v;
  next=nullptr;
  prev=nullptr;
  }
dd::Node::Node(int v,Node *n,Node *p) {
  value=v;
  next=n;
  prev=nullptr;
  }
void dd::add(int v){
  
  if(nullptr==head){
      head=new Node(v,nullptr,nullptr);
    }
  else {
      auto temp=head;
      head=new Node(v,head,nullptr);
      temp->prev=head;
    }

}
void dd::rev() {
  
  if(nullptr==head||nullptr==head->next) 
    return;
    auto last=head;
    auto curr=head;
    auto save=curr->next;
    last=nullptr;
    auto i=0;
    while(nullptr!=curr->next && i++ < 10) {

      curr->next=last;
      last=curr;
      curr=save;
      save=curr->next;
      }
      head=curr;
      curr->next=save;
  }
void dd::print(){
  auto curr=head;
  auto prev=head;
  if(nullptr==head)
    return;
  while(nullptr!=curr) {
    cout << curr->value << endl;
    prev=curr;
    curr=curr->next;
    }
  #if 0
  while(head!=prev)
  {
    cout << prev->value << endl;
    prev=prev->prev;
  }
  cout << prev->value << endl;
#endif
}



int main() {
  dd dl;
  for (auto i=1;i<5;i++)
  dl.add(i);
  dl.print();
  dl.rev();
  return 0;
}
