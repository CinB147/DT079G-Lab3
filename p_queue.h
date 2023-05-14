#pragma once
#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <iostream>
#include <vector>

template <typename Tn, typename comp = std::less<>> //using std::less stl to compare

class p_queue {
public:
	Tn pop();
	void push(const Tn val);
	int size();
	bool empty();

private:
	std::vector<Tn> list;

};

template <typename Tn, typename comp>
Tn p_queue<Tn,comp>::pop() {
	Tn value = list.front();
	list.erase(list.begin());
	return value;
}

template <typename Tn, typename comp>
void  p_queue<Tn, comp>::push(const Tn val) {
	comp cmp;
	auto it_pos = std::find_if(list.begin(), list.end(), [&](const Tn e) {return (cmp(e, val)); }); //lamda expression[] referecees all of function const template type e return &e, &val
	list.insert(it_pos, val);
}

template <typename Tn, typename comp>
int  p_queue<Tn, comp>::size() {
	return list.size();
}

template <typename Tn, typename comp>
bool  p_queue<Tn, comp>::empty() {
	return list.empty();
}

#endif
