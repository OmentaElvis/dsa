#include <iostream>

using namespace std;

struct Node{
    Node *prev = nullptr;
    char value;
    // constructor
    Node(char c){
        value = c;
    }
};

struct Stack{
    Node *last = nullptr;

    void push(char c){
        Node *node = new Node(c);
        if(last == nullptr){
            // first element
            last = node;
        }else{
            // there is already an element in the stack
            node->prev = last;
            last = node;
        }
    }
    char pop(){
        if(last == nullptr){
            return 0;
        }else{
            Node *node = last;
            last = node->prev;
            char c = node->value;

            delete node;
            return c;
        }
    }
    void empty(){
        while (last != nullptr)
        {
            pop();
        }
        
    }
    
};


int main(){
    Stack s;
    string str;
    
    cout<<"Input string: ";
    cin>>str;
    
    for (int i = 0; i < str.length(); i++){
        s.push(tolower(str[i]));
    }

    bool is_palindrome = true;

    char c;
    int i = 0;

    
    while( c = s.pop()){
        if(c != tolower(str[i])){
            is_palindrome = false;
        }
        i++;
    }
    if(is_palindrome){
        cout<<str<<" is palindrome\n";
    }else{
        cout<<str<<" is not a palindrome\n";
    }
    
    // free memory used by stack
    s.empty();
    

}