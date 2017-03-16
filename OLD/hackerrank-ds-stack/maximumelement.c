// reference - geeksforgeeks

#include<iostream>
#include<stdlib.h>
 
using namespace std;
 
class Stack
{
private:
    static const int max = 1000000;
    int arr[max];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty();
    bool isFull();
    int pop();
    void push(int x);
};

bool Stack::isEmpty()
{
    if(top == -1)
        return true;
    return false;
}

bool Stack::isFull()
{
    if(top == max - 1)
        return true;
    return false;
}
 
int Stack::pop()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow";
        abort();
    }
    int x = arr[top];
    top--;
    return x;
}
 
void Stack::push(int x)
{
    if(isFull())
    {
        cout<<"Stack Overflow";
        abort();
    }
    top++;
    arr[top] = x;
}

class SpecialStack: public Stack
{
    Stack max;
public:
    int pop();
    void push(int x);
    int getMax();
};
 
void SpecialStack::push(int x)
{
    if(isEmpty()==true)
    {
        Stack::push(x);
        max.push(x);
    }
    else
    {
        Stack::push(x);
        int y = max.pop();
        max.push(y);
        if( x > y )
          max.push(x);
        else
          max.push(y);
    }
}

int SpecialStack::pop()
{
    int x = Stack::pop();
    max.pop();
    return x;
}

int SpecialStack::getMax()
{
    int x = max.pop();
    max.push(x);
    return x;
}

int main()
{
	int N, x, type, data;
	SpecialStack s;
	cin >> N;
	while(N--){
		cin >> x;
		if(x == 1){
			cin >> data;
			s.push(data);
		}
		if(x == 2){
			s.pop();
		} 
		if(x == 3){
			cout << s.getMax() << endl;
		}
	}
}