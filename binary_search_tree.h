#include "tree_node.h"
#include "functions.h"
#pragma once
using namespace std;

///класс бинарного дерева поиска
template <typename e>
class bst {
private:
	tree_node<e>* head;//корень дерева

	tree_node<e>* get_head() {
		return head;
	}
	
public:
	///конструктор по умолчанию
	bst() {
		head = nullptr;
	}

	///конструктор с параметром
	bst(const vector<e>& a) {
		if (a.size() == 0)
			throw "Пустой массив";

		head = new tree_node<e>(a[0]);
		for (size_t i = 1; i < a.size(); i++) {
			add_node(head, a[i]);
		}
	}

	///деструктор
	~bst() {
		if (head != nullptr)
			head = delete_tree(head);
	}
	
	///конструктор копирования 
	bst(bst<e>& a) {
		//ф-цию напиши
		tree_node<e>* n = new tree_node<e>(a.get_head()->inf);
		head = n;
		NLR(head, a.head->left, copy_node_info);
		NLR(head, a.head->right, copy_node_info);
	}

	///оператор присваивания копированием
	bst<e>& operator = (bst<e>& a) {
		tree_node<e>* n = new tree_node<e>(a.get_head()->inf);
		head = n;
		NLR(head, a.head->left, copy_node_info);
		NLR(head, a.head->right, copy_node_info);
	}

	///констр перемещения
	bst(bst<e>&& a) {
		head = a.head;
	}

	///оператор присваивания перемещением
	bst<e>& operator = (bst<e>&& a) {
		head = a.head;
	}
	
	///вывод дерева с помощью обхода NLR
	void print() const {
		NLR(head, print_inf);
	}
	
	///глубина дерева
	int depth() const {
		return func::depth(head);
	}
	
	///кол-во элементов в дереве
	size_t size() const {
		return func::size(head);
	}
	
	///поиск элемента а в дереве, вернёт указатель на найденный узел
	tree_node<e>* find(const e& a) const {
		return func::find(head, a);
	}
	
	///добавление элемента а в дерево
	void add(const e& a) {
		if (head == nullptr) {
			tree_node<e>* t = new tree_node<e>(a);
			head = t;
		}
		add_node(head, a);
	}

	///поиск следующего наибольшего для узла а, вернёт указатель на него
	template<typename e>
	tree_node<e>* following_largest(const tree_node<e>* a) {
		tree_node<e>* next = nullptr;
		if (a->right != nullptr) {
			next = a->right;
			while (next->left != nullptr)
				next = next->left;
			return next;
		}

		else {
			vector<tree_node<e>*> road; //сначала пройдём к искомому, запоминая путь
			if (head == a) return nullptr;

			road.push_back(head);
			if (head->inf < a->inf) { //отходим от головы
				next = head->right;
				road.push_back(next);
			}
			else {
				next = head->left;
				road.push_back(next);
			}

			while (next != a) {
				if (next->inf < a->inf)
					next = next->right;

				else
					next = next->left;
				road.push_back(next);

			}

			road.pop_back(); //убираем искомое
			while (road[road.size() - 1]->left != next) { //пока тек узел не будет левым потомком предыдущего
				next = road[road.size()-1];
				road.pop_back();
				if (road.size() == 0)
					return nullptr;
			}
			return road[road.size()-1];
		}

		return nullptr;
	}


	///удаление всего дерева
	void del_tree() {
		if (head != nullptr)
			head = delete_tree(head);
	}

	///удаления узла по значению - а
	void del(const e& a,tree_node<e>* i = nullptr) {
		tree_node<e>* h;
		if (i == nullptr) {
			i = find(a);
			 h = head;
		}
		else
			 h = i;
		if (i == nullptr)
			return;
		//удаление листа
		if (i->left == 0 and i->right == 0) {
			vector<tree_node<e>*> road; //сначала пройдём к искомому, запоминая путь
			tree_node<e>* next;

			road.push_back(h);
			if (h->inf < i->inf) { //отходим от головы
				next = h->right;
				road.push_back(next);
			}
			else {
				next = h->left;
				road.push_back(next);
			}

			while (next != i) {
				if (next->inf < i->inf)
					next = next->right;

				else
					next = next->left;
				road.push_back(next);

			}

			road.pop_back(); //убираем искомое

			tree_node<e>* p = road[road.size() - 1];
			if (p->right == i)
				p->right = nullptr;
			if (p->left == i)
				p->left = nullptr;
			delete i;
			return;
		}

		//удаление узла с одним потомком
		if ((i->left != 0 and i->right == 0) or (i->left == 0 and i->right != 0)) {
			vector<tree_node<e>*> road; //сначала пройдём к искомому, запоминая путь
			tree_node<e>* next;

			if (h->inf == i->inf) {
				if (h->right != nullptr)
					next = h->right;
				else
					next = h->left;
				e w = h->inf;
				h->inf = next->inf;
				next->inf = w;
				del(a, next);
			}

			road.push_back(h);
			if (h->inf < i->inf) { //отходим от головы
				next = h->right;
				road.push_back(next);
			}
			else {
				next = h->left;
				road.push_back(next);
			}

			while (next != i) {
				if (next->inf < i->inf)
					next = next->right;

				else
					next = next->left;
				road.push_back(next);

			}

			road.pop_back(); //убираем искомое

			tree_node<e>* p = road[road.size() - 1];

			if (p->right == i) {
				if (i->right != 0) {
					p->right = i->right;
					i->right = nullptr;
				}
				else {
					p->right = i->left;
					i->left = nullptr;
				}

			}
			else {
				if (i->right != 0) {
					p->left = i->right;
					i->right = nullptr;
				}
				else {
					p->left = i->left;
					i->left = nullptr;
				}
			}
			delete i;
			return;
		}

		///удаление узла с двумя потомками
		else
		{
			tree_node<e>* n = following_largest(i);
			if (n != 0) {
				e w = n->inf;
				n->inf = i->inf;
				i->inf = w;
				if (n->left != nullptr or n->right != nullptr)
					del(a,n);
				else {
					if (i->left == n)
						i->left = nullptr;
					if (i->right == n)
						i->right = nullptr;
					delete n;
				}
			}

			
		}
	}

	///Перевод дерева в вектор с помощью обхода LNR
	vector<e> tree_to_vector() {
		vector<e> a;
		LNR_tree_to_vector(head, a);
		return a;
	}
};