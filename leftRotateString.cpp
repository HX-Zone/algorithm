#include <iostream>
#include <string.h>

void swap(char* str1,char* str2){
  if(str1 == NULL || str2 == NULL)
    return;
  char temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}


void reverseString(char* str){
  if(str == NULL || str[0] == '\0')
    return;
  int right = strlen(str) - 1;
  int left = 0;
  while(left < right){
    swap(&str[left], &str[right]);
    ++ left;
    -- right;
  }
}

int main(){
  char str[20] = "Hello world!";
  int l = strlen(str);
  std::cout << "length:" << l << std::endl;
  reverseString(str);
  std::cout << "str:" << str << std::endl;

  return 0;
}
