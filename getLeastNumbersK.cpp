#include <iostream>
#include <stdlib.h>
#include <time.h>
#define LEN 14
#define K 5

void swap(int* num1,int* num2){
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

int randomInRange(int min,int max){
    srand(time(NULL));
    int r = rand() % (max-min+1) + min;
    return r;
}

int partition(int*data,int length,int start,int end){
  if(data==NULL || length<=0 || start<0 || end>=length)
    return 0;
  
  int small = start - 1;
  int index = randomInRange(start,end);
  swap(&data[index],&data[end]);
  for(int i=0;i<6;i++){
    std::cout << data[i] << ",";
  }
  std::cout << std::endl;
  std::cout << "标杆：" << data[end] << std::endl;
  for(index=start;index<end;index++){
    if(data[index] < data[end]){
      ++ small;
      if(small != index){
        swap(&data[small],&data[index]);
      }
    }
  }
  ++ small;
  swap(&data[small],&data[end]);

  return small;
}

int getLeastNumbers(int* data,int length,int k,int* result){
  if(data==NULL || length<=0 || k<=0)
    return 0;
  
  int start = 0;
  int end = length - 1;
  int index = partition(data,length,start,end);
  while(index != (k-1)){
    if(index < (k-1)){
      start = index + 1;
      index = partition(data,length,start,end);
    }else{
      end = index - 1;
      partition(data,length,start,end);
    }
  }
  for(int i=0;i<k;i++){
    result[i] = data[i];
  }
  
  return 0;
}

int main(){
 // int r = randomInRange(1,10);
 // std::cout << "r:" << r << std::endl;

  int arr[] = {3,7,2,4,6,1,13,16,9,8,15,17,5,12};
  
  for(int i=0;i<LEN;i++){
    std::cout << arr[i] << ",";
  }
  std::cout << std::endl;
  
 // partition(arr,LEN,0,LEN-1);
  
  int result[LEN];
  getLeastNumbers(arr,LEN,K,result);

  for(int i=0;i<LEN;i++){
    std::cout << arr[i] << ",";
  }
  std::cout << std::endl;

 // std::cout << "TheKLeastNumbers:";
 // for(int i=0;i<K;i++){
 //   std::cout << result[i] << ","; 
 // }
 // std::cout << std::endl;

  return 0;
}
