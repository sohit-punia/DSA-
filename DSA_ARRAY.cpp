#include<iostream>
using namespace std;
#include<math.h>
#include<vector>

int main(){
  /*
//Q1:- FIBONACCI SERIES:-
int a = 0;
int b = 1;

int n;
cin>>n;

cout << a <<" "<<b <<" ";
for(int i = 0; i<n-2; i++){
  int c = a+b;
  cout<< c <<" ";
  a =b;
  b = c;
}

*/

//PRIME NUMBER :-A NUMBER IS GIVEN CHCEK IT IT IS PRIME OR NOT 
/*
int n;
cin>>n;

bool isPrime = 1 ; // 1 means yes 

for(int i =2;  i<n; i++){
   if(n%i == 0){
    isPrime = 0;
    break;
   }
}
if(isPrime == 0){
  cout<<"Not Prime";
}
else{
  cout<<"Prime Hai";
}
*/

//Q3:- A NUMBER IS GIVEN WE HAVE TO FIND OUT SUM AND PRODUCT OF THE DIGITTS
/*
int num;
cout<<"Enter the number"<<" ";
cin>>num;

int sum = 0;
int p =1;

while(num>0){
  int R = num%10;
  num = num/10;
  sum = sum + R;
  p = p*R ;
}
cout<<"Sum of digits is "<<sum<<endl;
cout<<"Products of digits is "<<p<<endl;
*/

//Q4:- CONVERT BINARY TO DECIMAL 
/*
int num;
cout<<"Enter Binary Number ";
cin>>num;
int i =0;
int s =0;

while(num!=0){
  int r = num % 10;
  if(r == 1){
  s = s + pow(2,i);
  }
  num = num/10;
  i++;

}
cout<<"Decimal number is "<<s<<endl;
*/

//Q5:- CONVERT DECIMAL TO BINARY
//NHI HUA YE AACHE SE

//Q6 COMPLIMENT OF A NUMBER :-
/*
int n;
cin>> n;
int m = n;
int mask = 0;

//edge case 
if(n==0){
  cout<<"not number";
}
while(m!=0){
  mask = (mask<<1)|1;
  m = m>>1;
}
int ans  = (~n) & mask;
cout<<ans;
*/

//Q7 GIVEN INTEGER IS POWER OF 2 OR NOT RETURN TRYE OR FALSE:-
/*
int n;
cin>>n;

int ans =0;
bool answer;

for(int i =0; i<n; i++){
  ans = pow(2,i);
  if(ans == n){
    answer = true;
  }
}
if(answer == true){
  cout<<"Yes this number is power of 2";
}
else{
  cout<<"Not in power of 2";
}
*/


//Q8 nCr:- 
//this is function 
/*
int factorial(int n){
  int fact =1;
  for(int i=1; i<=n ;i++){
    fact = fact *i;
  }
  return fact;
}

int nCr(int n, int r){
  int num = factorial(n);

  int denom = factorial(r)*factorial(n-r);
  return num/denom;
}

int n ,r;
cin>>n >>r;

cout<<"Answer is "<< nCr(n,r);
*/

//Q9 A ARRAY IS GIVEN FIND MINIMUM AND MAXIMUM ELELMENT OF THE ARRAY:-
/*
int arr[10] = {2,3,4,1,6,8,100,12,14,90};
int min = 0;
int max = 0;

for(int i=0; i<10; i++){
   if(arr[i]>arr[max]){
    max = i;
   }
}

for(int i=0; i<10; i++){
  if(arr[i]<arr[min]){
   min = i;
  }
}
cout<<"Largest elemnt is "<<arr[max]<<endl;;

cout<<"Minimun elemnt is "<<arr[min]<<endl;
*/

//Q10 LINEAR SEARCH :-

/*
bool search(int arr[] , int size , int key){
  for(int i =0; i<size; i++){
     if(arr[i]==key){
      return true;
     }
  }
  return false;
}


int arr[10] = {1,2,5,6,78,9,98,66,5,54};
int size = 10;
int key;

cout<<"enter the elemnt to be searched ";
cin>>key;

bool found = search(arr , 10 ,key);
if(found){
  cout<<"yes elemnet is found";
}
else{
  cout<<"not found";
}
*/

//Q11 REVERSE AN ARRAY :-
/*
void reverseArray(int arr[] , int size){
  int start =0;
  int end = size-1;
  while(start<end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    start++;
    end--;

  }
}

int arr[10] = {1,2,5,6,78,9,98,66,5,54};
int size = 10;

reverseArray(arr,10);

for(int i=0 ;i<10;i++){
  cout<<arr[i]<<" ";
}
*/

//Q12 SWAP ALTERNATE NUMBERS IN ARRAY:-
/*
void swapArray(int arr[],int size){
  for(int i=0; i<size; i= i+2){
    int temp = arr[i];
    arr[i] = arr[i+1];
    arr[i+1] = temp;
  }
}
int arr[10] = {1,2,5,6,78,9,98,66,5,5};
int size = 9;

swapArray(arr ,9);

for(int i=0 ;i<10;i++){
  cout<<arr[i]<<" ";
}
*/


//Q13 ARRAY HAS (2M+1) IN WHICH M ELEMENTS ARE TWICE ONLY SINGLE ELEMENT IS ONCE TIME RETURN THE SINLE ONE 
/*
int findUnique(int *arr , int size){
  int ans =0;
  for(int i =0; i<size ; i++){
    ans = ans ^ arr[i];
  }
  return ans;
}

int arr[7] = {1,2,3,8,3,2,1};
int size = 7;

int ans = findUnique(arr , 7);
cout<<"unique element is "<<ans;
*/

//Q14 DUBLICATE NYMBER IN AN ARRAY ONE ELEMENT IS REPAETED IN LAST INDEX WE HAVE TO RETURN IT:-
/*
int arr[7] = {1,2,3,4,5,6,6};
int size = 7;

int ans = 0;
for(int i =0; i<6;i++){
  ans = ans ^ arr[i];
}
for(int i= 0; i<7;i++){
  ans =  ans^ arr[i];
}
 cout<< ans <<endl;
*/



//Q15 PAIR SUM IN AN ARRAY A NUMBER IS GIVEN WE WILL RETURN TWO NUMBER WHOSE PAIR SUM WILL BE THAT NUMBER:- 
/*
int arr[7] = {1,2,3,4,5,6,8};
int size = 7;
int sum ;
cout<<"The required Sum ";
cin>>sum;

for(int i =0 ;i<7;i++){
  for(int j = i+1; j<7; j++){
    if(arr[i] + arr[j] == sum ){
        cout<< arr[i] <<" "<< arr[j]<<endl;
    }
  }
}
*/

//Q16 BINARY SEARCH :-
/*
int binarySearch(int arr[] , int size , int key){
  int start = 0;
  int end  = size - 1;
  //int mid = start + (end - start)/2;
  int mid = (start + end )/2;
 
  while(start<=end){
  if(key == arr[mid]){
    return mid;
  }

  if(key > arr[mid]){
    start = mid +1;
  }

  else{
    end =  mid-1;
  }

  // mid = start + (end - start)/2;
  mid = (start + end )/2;
}
return -1;

}
int arr[7] = {1,2,3,4,5,6,8};
int size = 7;
int index = binarySearch(arr ,7,2);

cout<<"Index of key is "<<index;
*/

//Q17 FIRST AND LAST OCCURANCE OF ANY NUMBER IN AN ARRAY:-
// arr = {1,2,3,3,5,10};  FIRST OCC OF '3' IS 2 INDEX AND LAST AT '3' SORTED ARRAY SHOLUD BE THERE

/*
int firstOcc(int arr[] , int size , int key){
  int start = 0;
  int end  = size - 1;
  int mid = start + (end - start)/2;
  //int mid  = (start + end)/2;
 
  int ans = -1;
  while(start<=end){
  if(key == arr[mid]){
    ans = mid;
    end = mid -1;
  }

  else if(key > arr[mid]){
    start = mid +1;
  }

  else{
    end =  mid-1;
  }

   mid = start + (end - start)/2;
   //mid  = (start + end)/2;
 
}
return ans;

}


int lastOcc(int arr[] , int size , int key){
  int start = 0;
  int end  = size - 1;
  int mid = start + (end - start)/2;
  //int mid  = (start + end)/2;
 
  int ans = -1;
  while(start<=end){
  if(key == arr[mid]){
    ans = mid;
    start = mid +1 ;
  }

  else if(key > arr[mid]){
    start = mid +1;
  }

  else{
    end =  mid-1;
  }

   mid = start + (end - start)/2;
   //mid  = (start + end)/2;
}
return ans;

}

int arr[6] = {1,2,3,3,3,5};
int size = 6;
cout<<"first occurenec is at "<<firstOcc(arr, 6 ,3)<<endl;

cout<<"last occurenec is at "<<lastOcc(arr, 6 ,3)<<endl;
*/



//Q18 PEAK INDEX IN MOUNTAIN ARRAY:-
//NHI HUA **


//Q19 PIVOT ELEMENT OF THE ARRAY:-
/*
int getPivot(int arr[] , int size){
  int start = 0;
  int end  = size - 1;
  int mid = start + (end - start)/2;
  //int mid  = (start + end)/2;
 
  while(start<end){
  if(arr[mid] >= arr[0]){
    start = mid +1 ;
  }
  else{
    end =  mid;
  }

   mid = start + (end - start)/2;
   //mid  = (start + end)/2;
}
return arr[start];
}

int arr[5] = {3,8,10,2,0};
cout<<"pivot elemnet is "<<getPivot(arr , 5)<<endl;
*/


//Q20 SELECTION SORT :-
/*
void selectionSort(int arr[] , int size){

  for(int i =0; i<size-1; i++){
    int minIndex = i;
    for(int j =i+1; j<size; j++){
       if(arr[j] < arr[minIndex]){
            minIndex = j;
       }
    }
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
  }
}
int arr[9] = {5,7,8,2,3,1,6,9,0};
int size = 9;

selectionSort(arr , 9);

for(int i =0 ;i<9;i++){
  cout<<arr[i]<<" ";
}
*/


//Q21 BUBBLE SORT :-
/*
void bubbleSort(int arr[] , int size){
  for(int i=0;i<size ;i++){
   //for 1 to n-1 round
   for(int j=0 ;j<size-i; j++){
    if(arr[j] > arr[j+1]){
      //swap 
          int temp = arr[j];
          arr[j]  =arr[j+1];
          arr[j+1] = temp;
    }
   }
  
  }
}
int arr[9] = {5,7,8,2,3,1,6,9,0};
int size = 9;

bubbleSort(arr , 9);

for(int i =0 ;i<9;i++){
  cout<<arr[i]<<" ";
}
*/


//Q22 INSERTION SORT :-
/*
void insertionSort(int arr[] , int n ){
  for(int i =0; i<n; i++){
   int temp = arr[i];
   int j = i-1;
 
  for( ; j>=0; j--){
   if(arr[j] > temp){
     arr[j+1] = arr[j];
   }
   else{
     break;
   }
  }
  //j=-1 
  arr[j+1] = temp;
  }
 }
int arr[9] = {5,7,8,2,3,1,6,9,0};
int size = 9;

insertionSort(arr , 9);

for(int i =0 ;i<9;i++){
  cout<<arr[i]<<" ";
}
*/

//Q23 REVERSE THE ARRAY AFTER A GIVEN M POSITION :-
/*
void  reverseArray(int arr[] , int size , int postion){
  int start = postion;
  int end = size -1 ;

  while(start <=end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    start++;
    end--;
  }

}
int arr[8] = {1,2,3,4,5,6,7,8};
int size = 8;

int m ;//postion after which array is reversed
cout<<"give the postion after which you want to reverse array:- ";
cin>>m;
 
reverseArray(arr ,8 ,m);

for(int i =0 ;i<8;i++){
  cout<<arr[i]<<" ";
}
*/

//Q24 MERGE SORTED ARRAY TWO SORTED ARRAY AREA GIEVEN WE HAVE TO MERGE TWO AND MAKE A THIRD ONE SORTED ARRAY:-
/*
void selectionSort(int arr[] , int size){

  for(int i =0; i<size-1; i++){
    int minIndex = i;
    for(int j =i+1; j<size; j++){
       if(arr[j] < arr[minIndex]){
            minIndex = j;
       }
    }
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
  }
}

void mergeArray(int arr1[] , int size1 , int arr2[] ,int size2 , int arr3[]){
 
  arr3[size1 + size2];
  for(int i=0; i<size1; i++){
    arr3[i] = arr1[i];
  }
  for(int i =0; i<size2; i++){
    arr3[size1 + i] = arr2[i];
  }
  for(int i =0 ;i<size1 + size2 ; i++){
    cout<<arr3[i]<<" ";
  }
 
  selectionSort(arr3 , size1 + size2);
}

int main(){
   int arr1[3] ={1,2,5};

int arr2[3] ={3,4,7};

int arr3[5];

mergeArray(arr1 , 3 ,arr2, 3 , arr3);
cout<<endl;

for(int i= 0; i<6;i++){
   cout<<arr3[i]<<" ";
}
}
*/

//Q25 MOVE ALL ZERO TO ONE SIDE IN AN ARRAY AND REST ARRAY IN ONE SIDE :-
/*
void moveZerosToEnd(int arr[], int n) {
  int nonZeroIndex = 0; // Pointer to place non-zero elements

  // Move non-zero elements forward
  for (int i = 0; i < n; i++) {
      if (arr[i] != 0) {
          swap(arr[i], arr[nonZeroIndex]);
          nonZeroIndex++;
      }
  }
}

int main() {
  int arr[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Before Moving Zeros: ";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;

  moveZerosToEnd(arr, n);

  cout << "After Moving Zeros: ";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;

  return 0;
}
*/

//Q26 ROTATE ARRAY : A VALUE WILL BE GIVEN LIKE K =2 EX ARR = {1,7,9,11} AFTER ROTAING {9,11,1,7};
/*
// Function to reverse an array from start to end index
void reverseArray(int arr[], int start, int end) {
  while (start < end) {
      swap(arr[start], arr[end]);
      start++;
      end--;
  }
}

// Function to rotate the array by K positions
void rotateArray(int arr[], int n, int k) {
  k = k % n; // Handle cases where K > N

  // Step 1: Reverse the whole array
  reverseArray(arr, 0, n - 1);
  // Step 2: Reverse the first K elements
  reverseArray(arr, 0, k - 1);
  // Step 3: Reverse the remaining elements
  reverseArray(arr, k, n - 1);
}

int main() {
  int arr[] = {1, 7, 9, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 2;

  cout << "Before Rotation: ";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;

  rotateArray(arr, n, k);

  cout << "After Rotation: ";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;

  return 0;
}
*/


}