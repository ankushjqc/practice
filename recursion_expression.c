#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eval_helper(char * expr, int *index) {
        char c=expr[*index];
        char op='\0';
        int r=0,l=0;
printf("eval_helper \"%s\"\n",expr+*index);
        if ('('==c){
          //start of complex expression
          (*index)++;
          printf("pointing to left value \"%s\"\n",expr+*index);
          l=eval_helper(expr,index);
          printf("l=%d\n",l);
          (*index)++;
          printf("pointing to operator \"%s\"\n",expr+*index);
          op=expr[*index];
          printf("operator is %c\n",op);
          (*index)++;
          printf("pointing to right value \"%s\"\n",expr+*index);
          r=eval_helper(expr,index);
          printf("r=%d\n",r);
          (*index)++;
          printf("pointing to right bracket \"%s\"\n",expr+*index);
//          (*index)++;//closing bracket
          printf("pointing to next expression \"%s\"\n",expr+*index);
          return ('+'==op) ? (r+l):(r*l);

        }
        else{
           printf("digit is %d\n",c-'0');
           return (c-'0');
           }
}

int eval(char * e){
  int i=0;
return eval_helper(e,&i);
}

int main (void) {
char e2[]="((1+3)+((1+2)*5))";
//char e2[]="((1+1)+(2*3))";
//char e3[]="(2+3)";

printf("%s=%d\n",e2,eval(e2));

return 0;
}
