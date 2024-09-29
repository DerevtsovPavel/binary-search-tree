#include "tree_node.h"
#pragma once
using namespace std;

namespace func {
	///��������� ������� ������(���������) - node
	template<typename e>
	int depth(tree_node<e>* node) {
		if (node == nullptr)
			return -1;
		else
			return max(depth(node->left), depth(node->right)) + 1;
	}

	///����� ���-�� ��������� � �������� ������
	template <typename e>
	size_t size(tree_node<e>* node) {
		
		if (node == nullptr) // �� ������ ������� ������
			return 0;
		else if ((node->left == nullptr) && (node->right == nullptr)) //���� �� �����
			return 1;
		else
			return size(node->left) + size(node->right) + 1;
	}

	///����� �������� � ������ � ������ �� ������ - node, �� �������� - �
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

///�-��� ������ ���� - �
template<typename e>
void print_inf(tree_node<e>* a) {
	cout << a->inf << endl;
}

///�-��� �������� ���� - �
template<typename e>
void del_node(tree_node<e>* a) {
	cout << "������� " << a->inf << endl;
	delete a;

}

///����� ������ - ��������, �����, ��������, ���� ����� ���, �� ������, ��������. Node - ������, f - �������� � �����
template<typename e>
void NLR(tree_node<e>* node, void (*f)(tree_node<e>*)) {
	if (node != nullptr) {
		f(node);
		NLR(node->left, f);
		NLR(node->right, f);
	}
}

///����� ������ - ��������, �����, ��������, ���� ����� ���, �� ������, ��������. Node - ������, f - �������� � �����
template<typename e>
void NLR(tree_node<e>* node,tree_node<e>* src, void (*f)(tree_node<e>*,tree_node<e>*)) {
	if (src != nullptr) {
		f(node,src);
		NLR(node, src->left,f);
		NLR(node, src->right,f);
	}
}

///����� ������ - ������� �������� �����, ��������, ����� ����� � ������,���� �����, ��������. Node - ������, f - �������� � �����
template<typename e>
void LRN(tree_node<e>* node, void(*f)(tree_node<e>*)) {
	if (node != nullptr) {
		LRN(node->left, f);
		LRN(node->right, f);
		f(node);
	}
}

///�������� ������� �� ������ � ������� LNR ������
template <typename e>
void LNR_tree_to_vector(tree_node<e>* node, vector<e>& a) {
	if (node != nullptr) {
		LNR_tree_to_vector(node->left, a);
		a.push_back(node->inf);
		LNR_tree_to_vector(node->right, a);
	}
}

///�-��� ���������� ���� � �������� ������ ������. head - ������ ������, s - ����������� �������
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

///�-��� �������� ��������� ������ ������ �� ������� ��������� - �
template<typename e>
tree_node<e>* create_binary_search_tree(const vector<e>& a) {
	if (a.size() == 0)
		throw "������ ������";

	tree_node<e>* t = new tree_node<e>(a[0]);
	for (size_t i = 1; i < a.size(); i++) {
		add_node(t, a[i]);
	}
	return t;
}

///����������� ���� ������ source � ����� head
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