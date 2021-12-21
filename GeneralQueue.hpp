#ifndef G_QUEUE_H
#define G_QUEUE_H

#include <iostream>
#include <list>

template <typename T>
class Queue {
	private:
		std::list<T> _data;
		size_t _size;
	public:
		//Default constructor
		Queue() : _size{0} , _data{} {
			std::cout<<"Default Constructor:\n";
		}

		//Copy constructor
		Queue(const Queue &q) {
			std::cout<<"Copy Constructor:\n";
			if(q.empty()) {
				_size = 0;
				_data = {};
			}
			else {
				size_t q_size = q.size();
				if(q_size == 1) {
					enqueue(q.front());
					_size = 1;
				}
				else {
					_data.resize(q_size);
					std::copy(q._data.begin(), q._data.end(), _data.begin());
				}
				_size = q_size;
				
			}

		}

		//Getters-> returns the number of elements present in the Queue
		size_t size() const {
			return _size;
		}

		//returns the 1st element of queue that was added in Queue
		T front() const {
			if(!_data.empty()) {
				return _data.front();
			}
			else {
				std::cout<<"The Queue is empty!\n";
				return T();
			}
		}
		//returns the last element of queue that is added recently
		T back() const {
			if(!_data.empty()) {
                                return _data.back();
                        }
                        else {
                                std::cout<<"The Queue is empty!\n";
                                return T();
                        }

		}

		//Push to queue-> adds the element to the back of the queue
		//just like Stack
		void enqueue(T value) {
			if(empty()) {
				_size = 1;
				_data.push_back(value);
			}
			else {
				_size+=1;
				_data.push_back(value);
			}
		}


		//Pop from queue->removes the first element from the queue(FIFO)
		void dequeue() {
			if(empty()) {
				std::cout << "The Queue is empty!\n";
				return;
			}
			else if (size() == 1) {
				_size = 0;
				_data.pop_front();
			}
			else {
				_data.pop_front();
				_size -= 1;
			}
		}
		
		//prints the Queue elements as a comma seperated list
		void print() const { 
			typename std::list<T>::iterator it;
			std::cout << "[";
			char comma[3] = {'\0', ' ', '\0'};
			for(auto it = _data.begin(); it != _data.end(); it++) {
				std::cout << comma<< *it;
				comma[0] = ',';
			}
			std::cout<< "]\n";
		
		}
		
		//return true if Queue is empty, else returns false
		bool empty() const {
			return ((_size == 0) && (_data.empty()));
		}

		//overloading the equals operator so that two different Queues can be made equal to each
		//other
		Queue<T> &operator=(const Queue<T> &q) {
			if(q.empty()) {
				if(size() == 1){
					dequeue();
				}
				else {
					_data.clear();
				}
				_size = 0;
				return *this;
			}
			if (q.size() == 1){
				//first empty our internal stack 
				if(size() < 2) {
				       dequeue();	
				}
				else {
					_data.clear();
				}
				//then copy the only element
				enqueue(q.back());
				_size = 1;
			}
			else {
				size_t q_size = q.size();
				if(size() < 2) {
                                       dequeue();
                                }
                                else {
                                        _data.clear();
                                }
				_data.resize(q_size);
				std::copy(q._data.begin(), q._data.end(), _data.begin());
                                _size = q_size;
			}
			return *this;
		}

		//A friend function overloading the << operator in order to print the Queue with
		//std::cout
		template <typename Q>
		friend std::ostream &operator<<(std::ostream &out, const Queue<Q> &q);


};

//implementation of friend function outside the class.
template <typename Q>
std::ostream &operator<<(std::ostream &out, const Queue<Q> &q) {
	typename std::list<Q>::iterator it;
        out.put('[');
        char comma[3] = {'\0', ' ', '\0'};
        for (auto it=q._data.begin(); it!=q._data.end(); it++) {
		out <<comma<< *it;
                comma[0] = ',';
        }
        return out<< "]"<<"\n";
}


#endif
