#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<cmath>
using namespace std;
/*create a class in which 
•  Add item at end
• Add item at any position
• Remove item from end
• Remove item from any position
• Empty list
• Check number of items in list
• Replace item at any position
• Interchange items at any positions
• Sort the list
• Search item from the list*/
class list 
{
	
private:
	static const int num;
	int listA[100];
	int numele;
public:
	list();
	bool add(int);
	bool addanypos(int, int);
	bool remove();
	int removeat(int);
	int get(int);
	int getall();
	bool swap(int, int);
	int check();
	int replace(int,int);
	bool interchange(int, int);
	void sort();
	void display();
	int search(int);

};
const int list::num = 100;
// use for empty list
list::list() {
	numele = 0;

}
//use for display data in list each line
void list::display(){
	for (int i = 0; i < numele; i++)
	{
		cout << listA[i] << endl;
	}
}

//add an item in list at end
//return ture mean task is done
bool list::add(int a) {
	if (numele + 1 != num) {
		listA[numele] = a;
		numele++;
		return true;
	}
	else
		return false;
}
//add at any position
//return true mean task is done
bool list::addanypos(int a, int b) {
	if (a >= 0 && a < numele) { //check capacity of list
		listA[a] = b;


		return true;

	}
	else
		return false;

}
// remove item at the end of list
// return ture mean task is done
bool list::remove() {
	if (numele != 0) {
		numele--;
		return true;

	}
	else {
		return false;
	}


}
int list::removeat(int a) {
	if (a >= 0 && a < numele) {
		if (a == numele-1) {
			remove();
			return true;
		}
		else {
			int temp = 0;
			for (int i = a; i <= numele; i++) {
				//temp = listA[i];
				listA[i] = listA[i+1];
				//listA[i++] = temp;
				//return true;
			}
			numele--;
			return true;
		}
	}
	else
		return false;


}
// show the number in list
int list::get(int a) {
	if (a >= 0 && a < numele) {
		return listA[a];
	}
	else
		return false;

}
// swap the two number
bool list::swap(int a, int b) {
	if (a >= 0 && a < numele&&b >= 0 && b < numele) {
		int temp;
		temp = listA[a];
		listA[a] = listA[b];
		listA[b] = temp;
		return true;
	}
	else
		return false;
}
//return all element
int list::getall() {

	return numele;
}
void main() {
	list a;
	srand(time(0));
	int x, i = 0, score = 0;
	while (i < 10) {
		x = 1 + rand() % 15;
		a.add(x*x);

		i++;
	}
	//display the number
	a.display();

	cout << endl;
	int q, y = 0; cout << "(-9 if he do not know, -1 to end game" << endl;
	do {
		cout << "Enter the squre root of first element " << endl;
		cin >> q;


		if (q == -9) {
			a.swap(0, a.getall() - 1);
			a.display();
		}
		else if (q == -1) {
			cout << "your score is " << score << endl;
			cout << "your remaning ans is" << endl;
			for (int i = 0; i < 10; i++) {
				cout << sqrt(a.get(i)) << endl;

			}
		}


		//if number is same check the number 
		else if
			(q == sqrt(a.get(0))) {
			score = score + 5;
			a.removeat(0);
			if (y == 10) {
				cout << "your score is " << score << endl;
				break;
			}
		}
		else
		{
			score = score - 3;
			cout << "Ans is wrong" << endl;
			if (y == 10) {
				cout << "your score is " << score << endl;
				break;
			}
		}
	

		y++;
	} while (q != -1&&y!=10);
	_getch();
}


