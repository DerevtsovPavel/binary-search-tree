#include "tree_node.h"
#pragma once
using namespace std;

namespace func {
	///измерение глубины дерева(поддерева) - node
	template<typename e>
	int depth(tree_node<e>* node) {
		if (node == nullptr)
			return -1;
		else
			return max(depth(node->left), depth(node->right)) + 1;
	}

	///вернёт кол-во элементов в бинарном дереве
	template <typename e>
	size_t size(tree_node<e>* node) {
		
		if (node == nullptr) // на случай пустого дерева
			return 0;
		else if ((node->left == nullptr) && (node->right == nullptr)) //если на листе
			return 1;
		else
			return size(node->left) + size(node->right) + 1;
	}

	///поиск элемента в дереве с указат на голову - node, по значению - а
	template <typename e>
	tree_node<e>* find(tree_node<e>* node,const e& a) {
		if (node == nullptr)
			return nullptr;
		else if (node->inf == a)
			return node;
		else if (node->inf < a)
			find(node->right, a);
		else
			find(node->left, a);
		
	}
}

///ф-ция печати узла - а
template<typename e>
void print_inf(tree_node<e>* a) {
	cout << a->inf << endl;
}

///ф-ция удаления узла - а
template<typename e>
void del_node(tree_node<e>* a) {
	cout << "Удалили " << a->inf << endl;
	delete a;

}

///обход дерева - действие, влево, действие, если слева нет, то вправо, действие. Node - корень, f - действие с узлом
template<typename e>
void NLR(tree_node<e>* node, void (*f)(tree_node<e>*)) {
	if (node != nullptr) {
		f(node);
		NLR(node->left, f);
		NLR(node->right, f);
	}
}

///обход дерева - действие, влево, действие, если слева нет, то вправо, действие. Node - корень, f - действие с узлом
template<typename e>
void NLR(tree_node<e>* node,tree_node<e>* src, void (*f)(tree_node<e>*,tree_node<e>*)) {
	if (src != nullptr) {
		f(node,src);
		NLR(node, src->left,f);
		NLR(node, src->right,f);
	}
}

///обход дерева - сначала максимум влево, действие, затем вверх и вправо,макс влево, действие. Node - корень, f - действие с узлом
template<typename e>
void LRN(tree_node<e>* node, void(*f)(tree_node<e>*)) {
	if (node != nullptr) {
		LRN(node->left, f);
		LRN(node->right, f);
		f(node);
	}
}

///создание вектора из дерева с помощью LNR обхода
template <typename e>
void LNR_tree_to_vector(tree_node<e>* node, vector<e>& a) {
	if (node != nullptr) {
		LNR_tree_to_vector(node->left, a);
		a.push_back(node->inf);
		LNR_tree_to_vector(node->right, a);
	}
}

///ф-ция добавления узла в бинарное дерево поиска. head - корень дерева, s - добавляемый элемент
template<typename e>
void add_node(tree_node<e>* head, const e& s) {
	
		if ( head->inf > s) {
			if ( head->left == nullptr) {
				tree_node<e>* a = new tree_node<e>(s);
				 head->left = a;
			}
			else
				add_node(head->left, s);
		}
		else if (head->inf < s){
			if (head->right == nullptr) {
				tree_node<e>* a = new tree_node<e>(s);
				head->right = a;
			}
			else
				add_node(head->right, s);
		}
}

///ф-ция создания бинарного дерева поиска из вектора элементов - а
template<typename e>
tree_node<e>* create_binary_search_tree(const vector<e>& a) {
	if (a.size() == 0)
		throw "Пустой массив";

	tree_node<e>* t = new tree_node<e>(a[0]);
	for (size_t i = 1; i < a.size(); i++) {
		add_node(t, a[i]);
	}
	return t;
}

///копирование узла дерева source в дерво head
template<typename e>
void copy_node_info(tree_node<e>* head,tree_node<e>* source) {
	e a = source->inf;
	add_node(head, a);
}

template <typename e>
tree_node<e>* copy_binary_tree(tree_node<e>* a) {
	if (a == nullptr) return nullptr;
	else {
		tree_node<e>* n = new tree_node<e>(a->inf);
		n->left = copy_binary_tree(a->left);
		n->right = copy_binary_tree(a->right);
		return n;
	}
}

template <typename e>
tree_node<e>* delete_tree(tree_node<e>* a) {
	if (a != nullptr) {
		delete_tree(a->left);
		delete_tree(a->right);
		a->left = nullptr;
		a->right = nullptr;
		delete a;
	}
	else
		return nullptr;
}