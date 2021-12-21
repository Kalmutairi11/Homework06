#ifndef G_STACK_H
#define G_STACK_H

#include <iostream>
#include <list>

template <typename T>
class Stack {
        private:
                std::list<T> _data;
                size_t _size;

        public:
                //Default constructor
                Stack() : _size{0} , _data{} {
                        std::cout<<"Default Constructor:\n";
                }

                //Default copy constructor
                Stack(const Stack &s) {
                        std::cout<<"Copy Constructor:\n";
                        if(s.empty()) {
                                _size = 0;
                                _data = {};
                        }
                        else {
                                size_t s_size = s.size();
                                if (s_size == 1) {
                                        push(s.top());
                                        _size = 1;
                                }
                                else {

                                _data.resize(s_size);
                                std::copy(s._data.begin(), s._data.end(), _data.begin());
                                }
                                _size = s_size;
                        }

                }

                //Getters-> gets the last element of the stack added recently
                T top() const {
                        if(!_data.empty())
                                return _data.back();
                        else {
                                std::cout<<"The Stack is empty!\n";
                                return T();
                        }

                }
		
		//returns the number of elements present in the Stack
                size_t size() const {
                        return _size;
                }

                //Adding data to the data structure
                void push(T value) {
                        if(empty()) {
                                _size = 1;
                                _data.push_back(value);
                        }
                        else {
                                _data.push_back(value);
                                _size++;
                        }
                }

                //Removing data from the data structure
                void pop() {
                        if(empty()) {
                                std::cout<<"The Stack is empty!\n";
                                return;
                        }
                        else if (size() == 1) {
                                _size = 0;
                                _data.pop_back();
                        }
                        else {
                                _data.pop_back();
                                _size--;
                        }
                }
		
		//return true if Stack is empty, else false
                bool empty() const {
                        return ((_size == 0) && (_data.empty()));
                }

		//prints all the elements of a Stack as a comma seperated list
                void print() const {
                        typename std::list<T>::iterator it;
                        std::cout<< "[";
                        char comma[3] = {'\0', ' ', '\0'};
                        for (auto it=_data.begin(); it!=_data.end(); it++) {
                                std::cout<<comma<< *it;
                                comma[0] = ',';
                        }
                        std::cout << "]"<<"\n";

                }
		
		//overloads the equals operator so that two different stacks  can be made equal to each 
		//other
                Stack<T> &operator=(const Stack<T> &s) {
                        if(s.empty()){
                                if(size() == 1){
                                        //removes the only element from Stack
                                        pop();
                                }
                                else {
                                        _data.clear(); //erases all elements from stack
                                }
                                _size = 0;
                                return *this;
                        }
                        if (s.size() == 1) {
                                if(size() < 2) {
                                        pop();
                                }
                                else {
                                        _data.clear();
                                }
                                //For Stack with only one element, front() and back() method returns same
                                push(s.top());
                                _size = 1;
                        }
                        else {
                                size_t s_size = s.size();
                                if(size() < 2) {
                                        pop();
                                }
                                else {
                                        _data.clear();
                                }
                                _data.resize(s_size);
                                //copy all elements of Stack s into internal stack
                                std::copy(s._data.begin(), s._data.end(), _data.begin());
                                _size = s_size;
                        }
                        return *this;
                }

		//A friend function for overloading the << operator in order to print the stack with
		//std::cout 
                template <typename S>
                friend std::ostream &operator<<(std::ostream &out, const Stack<S> &s);
                   
};

//implementation of friend function outside the class.
template <typename S>
std::ostream &operator<<(std::ostream &out, const Stack<S> &s) {
	typename std::list<S>::iterator it;
        out.put('[');
      	char comma[3] = {'\0', ' ', '\0'};
        for (auto it=s._data.begin(); it!=s._data.end(); it++) {
		out <<comma<< *it;
                comma[0] = ',';
        }
        return out<< "]"<<"\n";

}


#endif
