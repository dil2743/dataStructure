#include "stdio.h"
#include "string.h"

#define MAX_STR_LEN 100000
/*
> if there is no element inside the queue and there is no element in the input array then "Success"
> if there is no element inside the queue and next element is closing bracket -> Failure INDEX
> if the queue top is not a matching element with the next element -> Failure, return INDEX 
> if first element is a closing bracket -> Failure, return INDEX 
> if there is no element is the input but queue is not empty -> Failure, return QueueTOP+1

*/



int main(void)
{

    int stack_top = 0;
    int i = 0;
    char stack[MAX_STR_LEN] = { 0 };
    int index_tracker[MAX_STR_LEN] = {0};
    char input[MAX_STR_LEN];
    memset(input,0,MAX_STR_LEN);
    // input[0] = ']';
    // input[1] = '[';
    // input[2] = ']';
    // input[3] = '\0';
    scanf("%s",input);
    int position = 0 ;

    while('\0' != input[i]) {
        if ( i == 0 && ('}' == input[i] || ')' == input[i] || ']' == input[i])){
            position = 1;
            break;
        }
        else if(('[' == input[i]) || ( '{' == input[i]) || ( '(' == input[i]) ) {
            stack_top++;
            stack[stack_top] = input[i];
            index_tracker[stack_top] = i;
            if(MAX_STR_LEN == (stack_top - 1) ){
                // stack overflow 
                printf("STACK overflow\n");
            }
        }
        else if( stack_top >= 0 && (']' == input[i]) || ( '}' == input[i]) || ( ')' == input[i])  ) {
            if( ( ((']' == input[i]) && ( '[' == stack[stack_top])) ||
                  (('}' == input[i]) && ( '{' == stack[stack_top])) ||
                  ((')' == input[i]) && ( '(' == stack[stack_top])) )) {
                stack[stack_top] = 0 ;
                index_tracker[stack_top] = 0;
                stack_top--;
                if(0 > stack_top){
                    //stack under flow 
                    stack_top = 0;
                }
            }
            else{
                position = i+1;
                break;
            }
        }
        else{
            // do nothing 
        }
        i++;
    }

    ((0 == stack_top) && i ==  strlen(input)) ? printf("Success\n") :
    position > 1 ? printf("%d\n",position) : printf("%d\n",index_tracker[stack_top]+1);
    return 0;

}