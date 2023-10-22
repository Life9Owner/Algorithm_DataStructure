#include<iostream>
using namespace std;
template <typename Ty>
class stack_{
	public:
		stack_()
		{
			stack=(Ty*)malloc(sizeof(Ty)*100);
		}
		bool empty();
		void push(Ty value);
		void pop();
		size_t size();
		int top();//return the top element
		int top_=-1;
		Ty* stack;	
};
int main()
{
	stack_<float> stack=stack_<float>();
	for(double i=0;i<10;i++)
	{
		stack.push(i+1.2);
	}
	for(int i=0;i<10;i++)
	{
		stack.pop();
	}
	std::cout<<stack.size();
	return 0;
}
template<typename Ty>
bool stack_<Ty>::empty()
{
	if(this->size()==0)return true;
	else return false;
}
template<typename Ty>
void stack_<Ty>::push(Ty value)
{
	top_++;
	this->stack[top_]=value;	
}
template<typename Ty>
void stack_<Ty>::pop()
{
	top_--;
}
template<typename Ty>
size_t stack_<Ty>::size()
{
	return top_+1;
}
template<>
int stack_<int>::top()
{
	
	return top_;
}