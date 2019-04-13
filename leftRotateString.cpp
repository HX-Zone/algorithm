#include <iostream>
#include <string.h>

void swap(char* str1,char* str2){
  if(str1 == NULL || str2 == NULL)
    return;
  char temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}


void reverseString(char* str, int start, int end){
  if(str == NULL || start < 0 || start > end)
    return;
  int left = start,right = end;
  while(left < right){
    swap(&str[left], &str[right]);
    ++ left;
    -- right;
  }
}

void leftRotateString(char* str, int start, int end, int k){
  if(str == NULL || start < 0 || start > end || k <= 0)
    return;
  if((end - start + 1) <= k )
    return;
  reverseString(str, start, k-1);
  reverseString(str, k, end);
  reverseString(str, start, end); 
}

int main(){
  char str[20] = "Hello world!";
  int l = strlen(str);
  std::cout << "length:" << l << std::endl;
  //reverseString(str, 0, l-1);
  //std::cout << "str:" << str << std::endl;
  int k = 5;
  leftRotateString(str, 0, l - 1, k);
  std::cout << "str:" << str << std::endl;

  return 0;
}
