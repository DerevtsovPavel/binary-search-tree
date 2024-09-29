#include "tree_node.h"
#include "functions.h"
#pragma once
using namespace std;

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
			throw "ѕустой массив";

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
	
	///конструктор копировани€ 
	bst(bst<e>& a) {
		//ф-цию напиши
		tree_node<e>* n = new tree_node<e>(a.get_head()->inf);
		head = n;
		NLR(head, a.head->left, copy_node_info);
		NLR(head, a.head->right, copy_node_info);
	}

	///оператор присваивани€ копированием
	bst<e>& operator = (bst<e>& a) {
		tree_node<e>* n = new tree_node<e>(a.get_head()->inf);
		head = n;
		NLR(head, a.head->left, copy_node_info);
		NLR(head, a.head->right, copy_node_info);
	}

	///констр перемещени€
	bst(bst<e>&& a) {
		head = a.head;
	}

	///оператор присваивани€ перемещением
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
	
	///поиск элемента а в дереве, вернЄт указатель на найденный узел
	tree_node<e>* find(const e& a) const {
		return func::find(head, a);
	}
	
	///добавление элемента а в дерево
	void add(const e& a) {
		add_node(head, a);
	}

	///поиск следующего наибольшего дл€ узла а, вернЄт указатель на него
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
			vector<tree_node<e>*> road; //сначала пройдЄм к искомому, запомина€ путь
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

	///удалени€ узла по значению - а
	void del(const e& a) {
		tree_node<e>* i = find(a);
		if (i == nullptr)
			return;
		//удаление листа
		if (i->left == 0 and i->right == 0) {
			vector<tree_node<e>*> road; //сначала пройдЄм к искомому, запомина€ путь
			tree_node<e>* next;

			road.push_back(head);
			if (head->inf < i->inf) { //отходим от головы
				next = head->right;
				road.push_back(next);
			}
			else {
				next = head->left;
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
			vector<tree_node<e>*> road; //сначала пройдЄм к искомому, запомина€ путь
			tree_node<e>* next;

			road.push_back(head);
			if (head->inf < i->inf) { //отходим от головы
				next = head->right;
				road.push_back(next);
			}
			else {
				next = head->left;
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

		///удаление узла с двум€ потомками
		else
		{
			tree_node<e>* n = following_largest(i);
			if (n != 0) {
				e w = n->inf;
				n->inf = i->inf;
				i->inf = w;
				if (n->left != nullptr or n->right != nullptr)
					del(a);
				else
					delete n;
			}

			head = i->left;
			delete i;
		}
	}
};