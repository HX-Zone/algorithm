#include <iostream>
#include <stdlib.h>
#include <time.h>

bool boolTest(){
  return false;
}

bool CheckInvalidArray(int* numbers,int length)
{
  bool g_bInputInvalid = false;
  if(numbers==NULL && length<=0){
    g_bInputInvalid = true;
  }
  return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers,int length,int number){
  int times = 0;
  for(int i=0;i<length;++i){
    if(numbers[i] == number){
      times++;
    }
  }
  bool isMoreThanHalf = true;
  if(times*2<=length){
    isMoreThanHalf = false;
  }
  return isMoreThanHalf;
}

void Swap(int* num1,int* num2){
  int temp = *num1;  
  *num1 = *num2;
  *num2 = temp;
}

int RandomInRange(int min, int max) {
  int r = rand() % (max-min+1) + min;
  return r;
}

int partition(int* data,int length,int start,int end){
  if(data==NULL || length<=0 || start<0 || end>=length)
    exit;
  int index = RandomInRange(start,end);
  //std::cout << "index:" << index << std::endl;
  //int index = (end-start)/2;
  //int index = end;
  Swap(&data[index],&data[end]);
  for(int i=0;i<20;i++){
     std::cout << data[i]<< "," ;
  }
  std::cout << std::endl;
  std::cout << "标杆：" << data[end] << std::endl;
  int small = start-1;
  for(index=start;index<end;++index){
    std::cout << "small: " << small << " index: " << index << std::endl;
    if(data[index]<data[end]){
      ++small;
      if(small!=index){
        Swap(&data[small],&data[index]);
      }
    }
  }
  ++small;
  Swap(&data[small],&data[end]);
  return small;
}

int moreThanHalf(int* numbers,int length){
  if(CheckInvalidArray(numbers,length)){
      return 0;
  }
  int middle = length >> 1;
  int start = 0;
  int end = length-1;
  int index = partition(numbers,length,start,end);
  std::cout << "index:" << index << std::endl;
  while(index!=middle){
    if(index>middle){
      end = index-1;
      index = partition(numbers,length,start,end);
    }else{
      start = index+1;
      index = partition(numbers,length,start,end);
    }
  }
  std::cout << "index:" << index << std::endl;
  int result = numbers[index];
  if(!CheckMoreThanHalf(numbers,length,result))
    result = 0;
  
  return result;
}

int main(){
  int arr[] = {1,2,7,3,8,4,5,3,8,8,8,8,8,8,8,8,8,6,8,8};
  //partition(arr,20,0,19);
  //int r = rand();
  //std::cout << r << std::endl;
  for(int i=0;i<20;i++){
    std::cout << arr[i]<< "," ;
  }
  std::cout << std::endl;

  int m = moreThanHalf(arr,20);

  for(int i=0;i<20;i++){
     std::cout << arr[i]<< "," ;
  }
  std::cout << std::endl;
  std::cout << "m:" << m << std::endl;
  return 0;
}
