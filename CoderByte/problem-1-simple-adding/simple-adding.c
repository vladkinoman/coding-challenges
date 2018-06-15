/**
  Have the function SimpleAdding(num) add up all the numbers from 1 to num.
For example: if the input is 4 then your program should return 10 
because 1 + 2 + 3 + 4 = 10. For the test cases, the parameter num will be 
any number from 1 to 1000. 

Use the Parameter Testing feature in the box below to test your code 
with different arguments.
*/


#include <stdio.h> 

void SimpleAdding(int num[]) {
  int sum = 0;
  for(int i = num; i > 0; i--)
    sum += i;
  printf("%d", sum); 
}

int main(void) { 

  // disable stdout buffering
  setvbuf(stdout, NULL, _IONBF, 0);
  
  // keep this function call here
  SimpleAdding(gets(stdin));
  return 0;
    
}