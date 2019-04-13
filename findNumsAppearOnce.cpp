#include <iostream>

int findFirstBitIs1(int num){
  int indexBit = 0;
  while((num & 1) == 0 && (indexBit <= 8* sizeof(int))){
    num = num >> 1;
    ++ indexBit;
  }
  return indexBit;
}

bool bitIs1(int num, int indexBit){
  num = num >> indexBit;
  return (num & 1);
}

void findNumsAppearOnce(int* arr, int length, int* num1, int* num2){
  if(arr == NULL || length <= 2)
    return;
  int result = 0;//任何数和0异或的结果都为他本身
  for(int i=0;i < length; i++){
    result ^= arr[i];
  }
  int indexBit = findFirstBitIs1(result);
  for(int i=0;i < length; i++){
    if(bitIs1(arr[i], indexBit)){
      *num1 ^= arr[i];
    }else{
      *num2 ^= arr[i];
    }
  }
}

int main(){
  int arr[] = {2,4,3,6,3,2,5,5};
  int length = 8;
  int num1 = 0,num2 = 0;
  findNumsAppearOnce(arr, 8, &num1, &num2);

  std::cout << "num1:" << num1 << ",num2:" << num2 << std::endl;
  
  return 0;
}
