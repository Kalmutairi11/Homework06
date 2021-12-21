#include <iostream>
#include <list>

// Prints the contents of any std::list no matter the datatype
template <typename T>
void print_list(const std::list<T> &l) {
	for (const auto &x : l) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

int main() {
	// Creating an int linked list with { ... }
	std::list<int> x = {3, 2, 9, 12};

	// Printing the contents of the linked list
	print_list(x);

	// Adding to the front of the linked list
	x.push_front(7);

	// Adding to the back of the linked list
	x.push_back(5);

	// Printing the contents of the linked list
	print_list(x);

	// Creating a string linked list
	std::list<std::string> y {"What's", "is", "it", "up"};

	// Removing the last element
	y.pop_back();

	// Removing the first element
	y.pop_front();

	// Adding to the front
	y.push_front("How");
	// Adding to the back
	y.push_back("going");
	y.push_back("?");

	print_list(y);

	return 0;
}
