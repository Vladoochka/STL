#include <iostream>
#include <forward_list>

using namespace std;

int main() {
	double max, min;
	double numb;
	int n;
	forward_list<double> lst;
	cout << "Enter kol-vo: ";
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter: \n";
		cin >> numb;
		lst.push_front(numb);
	}
	for (double i : lst)
		cout << i << " ";
	cout << '\n';
	forward_list<double>::iterator it;
	max = min = lst.front();
	for (it = lst.begin(); it != lst.end(); ++it) {
		if (*it > max)
			max = *it;
		else if (*it < min)
			min = *it;
	}
	it = lst.begin();
	for (int i = 0; i < n - 1; ++i)
		++it;
	lst.remove(min);
	lst.remove(max);

	lst.push_front(max);
	lst.insert_after(it, min);
	for (double i : lst)
		cout << i << " ";

}