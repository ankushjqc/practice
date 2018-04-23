#include <stdio.h>


typedef struct node_ Node;
typedef struct list_ Link;
struct node_ {
  int data;
  struct node_ *next;
} ;

struct list_ {
  int size;
  struct node_ *link;
} ;

static Link my_list={0,NULL};

#define MALLOC_NODE (Node*)malloc(sizeof(Node))
#define LINK_NODE(prev,new) prev->next=new
#define ADVANCE(link) link=link->next
#define ERROR_MALLOC (-1)
#define IS_LAST(n) (NULL==n->next)
#define CHECK_NODE(node) do {\
                        if (NULL==node) \
                              return ERROR_MALLOC;\
                            }while(0)
                            
#define SET_DATA(node,d) (node->data=d)
#define GET_DATA(node) (node->data)

#define GET_NODE(n,mydata) do {\
                        n=MALLOC_NODE;\
                        CHECK_NODE(n);\
                        SET_DATA(n,mydata);\
                        LINK_NODE(n,NULL);\
                        my_list.size++;\
                       }while(0)
                       
#define APPEND_DATA(cursor,mydata) do {\
                                      GET_NODE(cursor->next,mydata);\
                                      ADVANCE(cursor);\
                                      }while(0)

#define DELETE_NEXT_NODE(cursor) do {\
                                      free(cursor->next);\
                                      LINK_NODE(cursor,NULL);\
                                    }while(0)

#define DELETE_NODE(n) do { Node *scan=my_list.link,*prev=my_list.link;\
                                      while(NULL!=scan&&scan!=n){\
                                      prev=scan;\
                                      ADVANCE(scan);\
                                      };\  
                                      LINK_NODE(prev,scan->next);\
                                      free(n);my_list.size--;\
                                      scan=n=NULL;\
                                      }while(0)
                                      
                                      
                                      
#define MOVE_BACK(node,count) move(node,\
                              my_list.size-\
                              ((my_list.size>count)?count:0))

Node * move(Node * current,int n){
  Node * ret=current;
  if (IS_LAST(ret)||0==n||my_list.size<n) 
    return ret;
  ret=move(ret->next,n-1); 
  }


int main() {
GET_NODE(my_list.link,555);

Node *mynode=NULL,*cursor=my_list.link;

for (int i = 1;i<10;i++)
    APPEND_DATA(cursor,i);
  cursor=move(my_list.link,5);
  DELETE_NODE(cursor);
  cursor=MOVE_BACK(my_list.link,2);
  DELETE_NODE(cursor);
  return 0;
}
