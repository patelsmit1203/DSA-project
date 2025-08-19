#include <iostream>
using namespace std;
#include <stack>


int main(){
    stack <int> value;
    
    int size,i,choice,a;
    do{
    cout<<"press 1 for push \npress 2 for pop\npress 3 for Display top the Element\npress 4 for empty\npress 5 for fullstack\npress 0 for exit";
    cin>>choice;
    switch(choice){
        case 1:
           cout<<"How many enter value for stack";
           cin>>size;
           for(i = 0; i < size; i++){
               cout<<"Enter "<<i+1<<" value";
               cin>>a;
               
               value.push(a);
           }
           cout<<endl;
           
           break;
        case 2:
        if(!value.empty()){
            cout<<"Popped value form stack"<<value.top();
            value.pop();
        }
        else{
            cout<<"Stack is empty";
            cout<<endl;
        }
        break;
        cout<<endl;
        
        case 3:
        if(!value.empty()){
            cout<<"top value from stack"<<value.top();
        }
        else{
            cout<<"Stack is empty";
        }
        cout<<endl;
        break;
        cout<<endl;
        
        case 4:
          if(value.empty()){
              cout<<"Stack is empty";
          }
          else{
              cout<<"Stack is not empty";
          }
          cout<<endl;
          break;
          cout<<endl;
          
         case 5:
         if(!value.empty()){
             cout<<"Stack is Almost Full";
         }
         else{
             cout<<"Stack is not full";
         }
         break;
         
         case 0: 
         cout<<"Exit";
         break;
         
         cout<<endl;
         default:
         cout<<"invalid choice";
         
    }
    }while(choice != 0);
    
    while(!value.empty()){
        cout<<value.top()<<" ";
        value.pop();
    }
    
    
    return 0;
}