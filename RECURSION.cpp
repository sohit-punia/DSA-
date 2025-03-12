/*
//HERE ALL QUESTIONS ARE SOLVED USING RECURSION :-

// Q1 FACTORIAL OF A NUMBER :-
int factorial(int n){
 //base case 
 if(n == 0){
    return 1;
 }

 int smaller = factorial(n-1);
 int bigger = n*smaller;

 return bigger;

}

//Q2 (2) ki power n :- 
int power(int n){
    //base case 
    if(n == 0){
        return 1;
    }
    
    int ans =  2 * power(n-1);
    return ans;

}

//Q3 FIBONNACI SERIES:- N'th TERM OF THE SERIES 

int fib(int n){
    //base case
    if( n ==0 ){
        return 0;
    }
    if( n ==1){
        return 1;
    }

    int ans  = fib(n-1) + fib(n-2);
    return ans;
}


//Q4 COUNT WAYS TO REACH THE N'th STAIR :- YOU ARE ON 0TH STAIR AND WE CAN EITHER STEP ONE STEP OR TWO STEP SO FIND THW WAYS 

int countStairs(int n){
    //base case
    if( n < 0 ){
        return 0;
    }
    if( n == 0){
        return 1;
    }

    int ans  = countStairs(n-1) + countStairs(n-2);
    return ans;
}

///Q5 SAY DIGIT:- EX INPUT 412 , O/P IS FOUR ONE TWO :

void  sayDigit(int n , string arr[]){
    if(n == 0){
        return;
    }
    //processing
    int digit = n % 10;
    n =n/10;
    //recurive call
    sayDigit( n, arr);
    cout<<arr[digit] <<" "; 
}

int main(){
string arr[10] = {"zero" , "one" ,"two" ,"three" ,"four" ,"five" ,"six" ,"seven" ,"eight" ,"nine"};

int n;
cout<<"Enter the number of stairs "<<endl;
cin>>n;
sayDigit(n, arr);
}

//Q6 A ARRAY IS GIVEN MAKE A FUNCTION WHICH TELLS IT IS SORTED OR NOT (BY RECURION):-
bool isSorted(int *arr , int size){
 //base case :
 if(size == 0 || size ==1){
    return true;
 }
 if(arr[0] > arr[1]){
    return false;
 }
 else{
    bool remaningPart = isSorted(arr + 1 , size -1 );
    return remaningPart;
 }
}

int mian(){
int arr[5] = {2,4,6,8,10};
int size = 5;
bool ans = isSorted(arr , size);

if(ans){
    cout<<"array is sorted"<<endl;
}
else{
    cout<<"array is not sorted"<<endl;
}
}


//Q7 FIND SUM OF ALL ELEMENTS USING RECURSION OF ARRAY:-
int findSum(int *arr , int size){
    int sum = 0;
    //base case 
    if(size ==0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }

   int remainingPart = findSum(arr + 1, size -1);
    
    sum  = arr[0] + remainingPart ;
     return sum;
}

int main(){
int arr[5] = {2,4,6,8,10};
int size = 5;

cout<<findSum(arr , 5);
}


//Q8 LINEAR SEARCH BY RECURSION:-

bool linerSearch(int *arr , int size, int key){
    //base case
    if(size == 0){
      return false;  
    }
    if(arr[0] ==key){
        return true;
    }
    else{
        bool remainingPart = linerSearch(arr +1 ,size- 1,key);
        return remainingPart;
    }
}

//Q9 BINARY SEARCH USING RECURSION:-
bool binarySeach(int *arr , int s , int e , int key){
    //base case 
    if(s>e){
        return false;
    }
    int mid = s +(e-s)/2;
    if(arr[mid] == key){
        return true;
    }
    if(arr[mid] < key){
        return binarySeach( arr , mid +1  , e , key);
    }
    else{
    return binarySeach( arr , s , mid -1 , key);
    } 

}

//Q10 REVERSE A STRING :-
void reverseString(string& str , int i , int j){
    //base case 
    if(i>j){
        return;
    }
    swap(str[i] , str[j]);
    i++;
    j--;
    //recursive call
    reverseString(str , i ,j);
}

/Q11 CHECK PALINDROME :-


bool checkPalindrome(string& str , int i , int j ){
    //base case 
    if(i > j){
        return true;
    }
    if(str[i] != str[j]){
        return false;
    }
    else{
        i++;
        j--;
         return checkPalindrome(str , i , j );
    }

}

//Q11 BUBBLE SORT :-
void sortArry(int *arr , int n ){
    //base case 
    if(n ==0 || n==1){
          return ;
    }
    //1 case solve kar do 
    for(int i =0 ; i<n-1 ; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i] , arr[i+1]);
        }
    }
    sortArry(arr , n-1);
}

//Q12 SELECTION SORT:-
void selectionSort(int *arr, int n) {
    // Base case: If the array has 0 or 1 element, it's already sorted
    if (n == 0 || n == 1) {
        return;
    }

    // Find the index of the minimum element
    int minIndex = 0;
    for (int i = 1; i < n; i++) {  // Start from index 1
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap the smallest element with the first element
    swap(arr[0], arr[minIndex]);

    // Recursively call selection sort on the remaining part
    selectionSort(arr + 1, n - 1);
}

//Q13 INSERTION SORT :-

void insertionSortRecursive(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    // Sort the first (n-1) elements
    insertionSortRecursive(arr, n - 1);

    // Insert the last element into its correct position
    int last = arr[n - 1]; // Last element of current subarray
    int j = n - 2; // Index of the previous element

    // Move elements of arr[0..n-2] that are greater than last
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j]; // Shift element to the right
        j--;
    }
    arr[j + 1] = last; // Place the last element in its correct position
}

int main(){

int arr[] = {5, 3, 8, 4, 2};
int n = sizeof(arr) / sizeof(arr[0]);

insertionSortRecursive(arr, n);

// Print sorted array
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
return 0;

}


//Q14 MERGE SORT :-

#include <iostream>
using namespace std;

void merge(int *arr, int s, int e) {
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    
    int *first = new int[len1];
    int *second = new int[len2];

    // Copy values to first array
    int mainArrayindex = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayindex++];
    }

    // Copy values to second array
    mainArrayindex = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayindex++];
    }

    // Merge two sorted arrays
    int index1 = 0, index2 = 0;
    mainArrayindex = s;

    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[mainArrayindex++] = first[index1++];
        } else {
            arr[mainArrayindex++] = second[index2++];
        }
    }

    // Copy remaining elements of first[] if any
    while (index1 < len1) {
        arr[mainArrayindex++] = first[index1++];
    }

    // Copy remaining elements of second[] if any
    while (index2 < len2) {
        arr[mainArrayindex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s, int e) {
    // Base case: if only one element or no element
    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;

    // Sort left part
    mergeSort(arr, s, mid);

    // Sort right part
    mergeSort(arr, mid + 1, e);

    // Merge sorted parts
    merge(arr, s, e);
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, n - 1);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


/Q15 QUICK SORT :-
int partition(int *arr , int s ,int e){
      int pivot = arr[s];
      int cnt = 0;

      for(int i = s +1; i<=e; i++){
        if(arr[i] <= pivot){
            cnt++;
        }
      }
      //place pivot at right position 
      int pivotIndex = s + cnt;
      swap(arr[pivotIndex] , arr[s]);
      
      //left right vala part sambhal lete h 
      int i = s;
      int j = e;
      while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] >= pivot){
            j--;
        }

        if(i< pivotIndex && j > pivotIndex){
            swap(arr[i++] , arr[j--]);
        }
      }
      return pivotIndex;

}

void quickSort(int *arr , int s, int e){
      //base case 
      if(s >= e){
        return;
      }
      //partion karenge
      int p = partition(arr , s , e);

      //left part sort karna h
      quickSort(arr , s , p-1);

      //right part sort karna h
      quickSort(arr , p+1 , e);
}

int main(){


    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s =0;
    int e = n-1;
   
    quickSort(arr , s , e);
    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;

}



*/
