/*Reverse the Stack using cpp
Author:Neetu Kumari
Date Modified:19-10-2021
*/

#include<iostream>
#include<stack>
using namespace std;

void Insert_at_bottom(stack<int>& st, int ele) {

	if (st.empty()) {
		st.push(ele);
		return;
	}

	int topele = st.top();
	st.pop();
	Insert_at_bottom(st, ele);
	st.push(topele);
}

void reverse(stack<int>& st) {
	if (st.empty()) {
		return;
	}

	int ele = st.top();
	st.pop();
	reverse(st);
	Insert_at_bottom(st, ele);
}

int main() {
	stack<int>st;
	st.push(1);
	st.push(4);
	st.push(6);
	st.push(8);
	st.push(5);

	reverse(st);
	while (!st.empty()) {
		cout << st.top() << " " << endl;
		st.pop();
	}cout << endl;
}
