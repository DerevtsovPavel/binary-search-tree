#include <iostream>
#include <chrono>
#include "n_node.h"
#include "binary_search_tree.h"
#include "for_vector.h"
#include <random>
#pragma once
using namespace std;
using namespace func;
using namespace std::chrono;




/*	  a
	b	 c
 d	       e*/
int main() {
	
	// Инициализировать генератор случайных чисел
	random_device rd;
	mt19937 gen(rd());
	setlocale(0, "Russian");
	tree_node<int>* a = new tree_node<int>(10);
	tree_node<int>* b = new tree_node<int>(-5);
	tree_node<int>* c = new tree_node<int>(8);
	tree_node<int>* d = new tree_node<int>(2);
	tree_node<int>* e = new tree_node<int>(1);
	

	a->left = b;
	a->right = c;

	b->left = d;
	c->right = e;

	//cout << d->inf << endl;
	cout <<"Глубина узла: "<< depth(a) << endl;
	cout << "Элементов: " << size(a) << endl;
	cout << "Вывод дерева" << endl;
	NLR(a, print_inf);

	tree_node<int>* h = copy_binary_tree(a);
	cout << "Дерево h:" << endl;
	NLR(h, print_inf);
	cout << "Удаление дерева" << endl;
	LRN(a, del_node);
	

	/*		f		
		 g h i
		   |
		   j*/	
/*	n_node<int>* f = new n_node<int>(5);
	n_node<int>* g = new n_node<int>(6);
	n_node<int>* h = new n_node<int>(7);
	n_node<int>* i = new n_node<int>(8);
	n_node<int>* j = new n_node<int>(-2);

	f->next.push_back(g);
	f->next.push_back(h);
	f->next.push_back(i);
	f->next[1]->next.push_back(j);
	cout << f->next[1]->next[0]->inf << endl;

	delete j;
	delete i;
	delete h;
	delete g;
	delete f;*/
	cout << "-----------------" << endl;
	vector<int> j{ 1,-1,3,4,2 };
	tree_node<int>* m = create_binary_search_tree(j);
	cout << "Глубина узла: " << depth(m) << endl;
	cout << "Элементов: " << size(m) << endl;
	cout << "Вывод дерева" << endl;
	NLR(m, print_inf);

	cout << "---------------" << endl;

	vector<int> nm;
	LNR_tree_to_vector(m, nm);
	LRN(m, del_node);
	for (size_t i=0;i<nm.size();i++)
		cout << nm[i] << endl;
	cout << "------------------" << endl;

	bst<int> bt(j);
	bt.print();

	cout << "Глубина Дерева:  "<<bt.depth() << endl;
	cout << "Кол-во элементов в дереве: " << bt.size() << endl;

	bt.add(0);
	cout << "Глубина Дерева:  " << bt.depth() << endl;
	cout << "Кол-во элементов в дереве: " << bt.size() << endl;
	

	cout << "-------------------" << endl;
	vector<int> l{ 8,3,1,6,4,7,10,14,13 };
	bst<int> et(l);
	et.print();
	tree_node<int>* cc = et.find(1);
	vector<tree_node<int>*> bb;
	cc = et.following_largest(cc,bb);
	cout << cc->inf << endl;
	cout << "-------------------" << endl;

	
	bst<int> qq = et;

	et.add(2);
	qq.print();

	qq.del(13);
	qq.print();

	cout << qq.size();
	cout << "-------------------\n" << endl;

	cout << "Введите размер массива: ";
	size_t n;
	cin >> n;

	
	auto dv = duration_cast<milliseconds>(steady_clock::now()- steady_clock::now());
	auto t0 = steady_clock::now();
	for (int i = 0; i < 100; i++) {
		vector<int> mv;
		auto t4 = steady_clock::now();
		random_vector(mv, n, gen);
		bst<int> mt(mv);

		int min = -1'000'000;
		int max = 1'000'000;
		uniform_int_distribution<> distrib(min, max);

		auto t5 = steady_clock::now();
		dv = dv + duration_cast<milliseconds>(t5 - t4);

		for (int j = 0; j < 10'000; j++) {
			int b = distrib(gen);

			tree_node<int>* x = mt.find(b);

		}
		
	}
	auto t1 = steady_clock::now();
	auto delta = duration_cast<milliseconds>(t1- t0);
	delta = delta - dv;
	double mid_time = 1.0 * delta.count() / 100;

	cout << "Время: " << mid_time << endl;

	vector<int> hj{ 6,1,8,2,4,9,0,3 };
	bst u(hj);

	for (int i:u) {
		cout << i << endl;
	}
}