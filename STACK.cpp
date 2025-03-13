/*
//Q1 FUNCTION TO PRINT THE STACK :-

void printStack(std::stack<int> s) { // Pass stack by value (copy)
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop(); // Remove top element
    }
    std::cout << std::endl;
}

//Q2 IMPLEMENTATION USING ARRAY:-

class stack{
  //properties 
  public:
  int* arr;
  int top;
  int size;

  //behavior
  stack(int size){
    this->size = size;
    arr = new int[size];
    top = -1;
  }


void push(int element){
    if(size - top >1){
        top++;
        arr[top] = element;
    }
    else{
        cout<<"stack overflow"<<endl;
    }
}

void pop(){
    if(top >= 0){
        top--;
    }
    else{
        cout<<"stack underflow"<<endl;
    }
}

int peek(){
    if(top > 0){
        return arr[top];
    }
    else{
        cout<<"stack is empty"<<endl;
    }
}

bool isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}


};

//Q3 REVERSE A STRING USING A STACK:-

void printStack(std::stack<char> s) { // Pass stack by value (copy)
    while (!s.empty()) {
        std::cout << s.top();
        s.pop(); // Remove top element
    }
    std::cout << std::endl;
}

int main(){
    string str = "punia";
    int l = str.length();

    std :: stack <char> s;

    for(int i = 0; i<l; i++){
        s.push(str[i]);
    }

    std::cout << " reverse string: ";
    printStack(s);  

 return 0; 
 }

 //Q4 DELETE MIDDLE ELEMENT FROM STACK :-

 #include <stack>
using namespace std;

void solve(stack<int> &inputStack, int count, int size) {
    // Base case: If count reaches the middle index, pop the element
    if (count == size / 2) {  
        inputStack.pop();  // Remove the middle element
        return;
    }

    // Store the top element before popping
    int num = inputStack.top();
    inputStack.pop();

    // Recursive call to reach the middle element
    solve(inputStack, count + 1, size);

    // Push the stored element back after the middle is removed
    inputStack.push(num);
}

void deleteMiddleElement(stack<int> &inputStack, int N) {
    if (N == 0) return;  // Edge case: If stack is empty, do nothing
    solve(inputStack, 0, N);
}

//Q5 VALID PARENTHEIS:- 
NOT DONE BAAD ME KARU GA 

//Q6 INSERT AN ELEMNT AT BOTTAM PF A STACK :-

void solve(stack<int>& s , int x){
    //base case
    if(s.empty()){
        s.push(x);
        return ;
    }

    int num = s.top();
    s.pop();

    //recurive call
    solve( s , x);
    s.push(num);
}

stack<int> pushAtBottam(stack <int> &myStack , int x){
    solve(myStack , x);
    return myStack;
}

void printStack(std::stack<int> s) { // Pass stack by value (copy)
    while (!s.empty()) {
        std::cout << s.top()<<" ";
        s.pop(); // Remove top element
    }
    std::cout << std::endl;
}

int main(){
    
    std :: stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
   
    std::cout << "stack elements: ";
    printStack(s);  

    int x;
    cout<<"elemnt to push at start ";
    cin>>x;

    pushAtBottam(s ,x);
    std::cout << "stack elements: ";
    printStack(s);  
}

//Q7 REVERSE STACK USING RECURSION :-

void  insertAtBottom(stack<int>& s , int element){
    //base case
    if(s.empty()){
        s.push(element);
        return ;
    }

    int num = s.top();
    s.pop();

    //recurive call
    insertAtBottom( s , element);
    s.push(num);
}


void reverseStack(stack <int> &stack){
    //base case
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();

    //recurve call
    reverseStack(stack);
    insertAtBottom(stack , num);
}

//Q8 SORT A STACK :-

void sortedInsert(stack <int> &stack , int num){
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() <num)){
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();

    //recursive call
    sortedInsert(stack , num);
    stack.push(n);
}

void sortStack(stack<int> &stack){
    //base case
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();

    //recurive call
    sortStack(stack);
    sortedInsert(stack , num);
}
    








*/