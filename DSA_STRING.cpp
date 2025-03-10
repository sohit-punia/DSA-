
/*

Q1 CHECK PALINDROME :-

bool checkPalindrome(char str[] , int size){

  int s = 0;//start
  int e = size-1;// end
   
  while(s<=e){
   if(str[s] != str[e]){
       return 0;
   }
   else{
     s++;
     e--;
  }

 }
  return 1;
}
int main(){
  char str[] = "puniinup";
  int n = strlen(str);
  bool ans = checkPalindrome(str , n);
  if(ans){
   cout<<"yes string is palindrome";
  }
  else{
   cout<<"not palindrome";
  }

}

//Q2 UPPER CASE TO LOWER CASE :-
char toLowerCase(char ch){
   if(ch >='a' && ch <='z'){
      return ch;
   }
   else{
      char temp = ch - 'A' + 'a';
      return temp;
   }
}

int main(){
  char ch = 'T'; 
 char ans = toLowerCase(ch);
 cout<<ans<<endl;

}

//Q3 VALID PARLINDROME :- LEET CODE QUESTION :-A valid palindrome is a string that reads the same forward and backward, ignoring non-alphanumeric characters and case differences


//SAMAJ NHI AAYA 


//Q4 MAXIMUM OCCURING CHARACTER :-
//create an array of  count of characters 
char getMaxOccCharacter(string s){
  int arr[26] = {0};


  for(int i =0; i <s.length(); i++){
    char ch = s[i];
    //lower case 
    int number = 0;
    if(ch >= 'a' && ch <='z'){
      number = ch -'a';
    }
    else{
      //upper case 
      number = ch -'A';
    }
    arr[number]++;
  }
  int maxi = -1 , ans = 0;
  for(int i =0; i< 26; i++){
   if(maxi < arr[i]){
      ans = i;
      maxi = arr[i];
   }
  }

  char finalAns = 'a' + ans;
  return finalAns;


}

int main(){
   string s;
   getline(cin, s);
   cout<<getMaxOccCharacter(s)<<endl;
}

//Q5 PRINT ROW WISE SUM OD A 2D ARRAY:-
NOTE :-
In C++, you cannot declare a 2D array using variables (rows and cols).
Array sizes must be constants or use dynamic memory allocation.

CODE :- 
#include <iostream>
using namespace std;


void printSum(int arr[][3] , int rows , int cols){
    
     for(int row  = 0 ;row <3; row++){
      int sum =0 ;
      for(int col=0; col<3; col++){
         sum = sum + arr[row][col];

      }
      cout<<sum<<" ";
     }
     cout<<endl;
}

int main() {
    int rows, cols;
    
   //  cout << "Enter number of rows and columns: ";
   //  cin >> rows >> cols;
   rows = 3;
   cols = 3;

    int arr[3][3]; 
    // Input for 2D array
    cout << "Enter " << rows * cols << " elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j]; // Taking input for each element
        }
    }
     
    // Output the 2D array
    cout << "The 2D Array is:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " "; // Print each element
        }
        cout << endl; // New line after each row
    }

    printSum(arr ,3,3);
    return 0;
}

//Q6 COLUMN WISE SUM PRINT IN A 2D ARRAY:- 

SAME AS UPPER QUESTION ON ROWS AND COLS ARE INTERCHANGED IN PRINTSUM FUNCTION 

void printSum(int arr[][3] , int rows , int cols){
    
     for( int col=0; col<3; col++){
      int sum =0 ;
      for(int row  = 0 ;row <3; row++){
         sum = sum + arr[row][col];

      }
      cout<<sum<<" ";
     }
     cout<<endl;
}



//Q7 PRINT LIKE A WAVE :- 
//Q8 SPIRAL PRINT :-

THESE QUESTION ARE LEFT BAAD ME KAR LUNGA 



*/
