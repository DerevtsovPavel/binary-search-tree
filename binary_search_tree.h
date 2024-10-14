#include "tree_node.h"
#include "functions.h"
#include "stack"
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

	class iterator {
		tree_node<e>* current;
		stack<tree_node<e>*> st;
	public:
		iterator() {
			current = nullptr;
		}
		iterator(tree_node<e>* c) {
			current = c;
			if (current->right != 0)
				st.push(current->right);
			if (current->left != 0)
				st.push(current->left);
		}

		bool operator == (const iterator& x) const {
			return current == x.current;
		}
		
		bool operator != (const iterator& x) const {
			return current != x.current;
		}

		e& operator *() {
			return current->inf;
		}

		iterator operator ++(e) {
			iterator tmp(current);
			current = st.top();
			st.pop();
			if (current->right!=nullptr){
				st.push(current->right);
			}
			if (current->left != nullptr) {
				st.push(current->left);
			}
			return current;
		}

		iterator operator ++() {

			if (st.empty())
				current = nullptr;
			else {
				current = st.top();
				st.pop();
				if (current->right != nullptr) {
					st.push(current->right);
				}
				if (current->left != nullptr) {
					st.push(current->left);
				}
			}
			return current;
		}
			
			
			
	};
	
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

	iterator begin() {
		return iterator(head);
	}

	iterator end() {
		return iterator();
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
	tree_node<e>* following_largest(const tree_node<e>* a, vector<tree_node<e>*>& road) {
		tree_node<e>* next = nullptr;
		//сначала пройдём к искомому, запоминая путь
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

		if (a->right != nullptr) {
			next = a->right;
			road.push_back(next);
			while (next->left != nullptr) {
				next = next->left;
				road.push_back(next);
			}
			return next;
		}

		else {
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
	void del(const e& a) {
		vector<tree_node<e>*> path;
		tree_node<e>* i = func::find(head, a, path);

		// удаление листа
		if (i->left == nullptr and i->right == nullptr) { 
			if (path[path.size() - 1]->left == i)
				path[path.size() - 1]->left = nullptr;
			else
				path[path.size() - 1]->right = nullptr;
			delete i;
		}

		//один левый потомок
		else if (i->left != nullptr and i->right == nullptr) {
			if (path[path.size() - 1]->left == i)
				path[path.size() - 1]->left = i->left;

			else
				path[path.size() - 1]->right = i->left;
			
			i->left = nullptr;
			delete i;

		}

		//один правый потомок
		else if (i->right != nullptr and i->left == nullptr) {
			if (path[path.size() - 1]->left == i)
				path[path.size() - 1]->left = i->right;

			else
				path[path.size() - 1]->right = i->right;

			i->right = nullptr;
			delete i;
		}

		else if (i->right != nullptr and i->left != nullptr) {
			///xnj
		}
	}

	///Перевод дерева в вектор с помощью обхода LNR
	vector<e> tree_to_vector() {
		vector<e> a;
		LNR_tree_to_vector(head, a);
		return a;
	}
};