#include "tree_node.h"
#include "functions.h"
#pragma once
using namespace std;

template <typename e>
class bst {
private:
	tree_node<e>* head;//������ ������

	tree_node<e>* get_head() {
		return head;
	}
	
public:
	///����������� �� ���������
	bst() {
		head = nullptr;
	}

	///����������� � ����������
	bst(const vector<e>& a) {
		if (a.size() == 0)
			throw "������ ������";

		head = new tree_node<e>(a[0]);
		for (size_t i = 1; i < a.size(); i++) {
			add_node(head, a[i]);
		}
	}

	///����������
	~bst() {
		if (head != nullptr)
			head = delete_tree(head);
	}
	
	///����������� ����������� 
	bst(bst<e>& a) {
		//�-��� ������
		tree_node<e>* n = new tree_node<e>(a.get_head()->inf);
		head = n;
		NLR(head, a.head->left, copy_node_info);
		NLR(head, a.head->right, copy_node_info);
	}

	///�������� ������������ ������������
	bst<e>& operator = (bst<e>& a) {
		tree_node<e>* n = new tree_node<e>(a.get_head()->inf);
		head = n;
		NLR(head, a.head->left, copy_node_info);
		NLR(head, a.head->right, copy_node_info);
	}

	///������ �����������
	bst(bst<e>&& a) {
		head = a.head;
	}

	///�������� ������������ ������������
	bst<e>& operator = (bst<e>&& a) {
		head = a.head;
	}
	
	///����� ������ � ������� ������ NLR
	void print() const {
		NLR(head, print_inf);
	}
	
	///������� ������
	int depth() const {
		return func::depth(head);
	}
	
	///���-�� ��������� � ������
	size_t size() const {
		return func::size(head);
	}
	
	///����� �������� � � ������, ����� ��������� �� ��������� ����
	tree_node<e>* find(const e& a) const {
		return func::find(head, a);
	}
	
	///���������� �������� � � ������
	void add(const e& a) {
		add_node(head, a);
	}

	///����� ���������� ����������� ��� ���� �, ����� ��������� �� ����
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
			vector<tree_node<e>*> road; //������� ������ � ��������, ��������� ����
			if (head == a) return nullptr;

			road.push_back(head);
			if (head->inf < a->inf) { //������� �� ������
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

			road.pop_back(); //������� �������
			while (road[road.size() - 1]->left != next) { //���� ��� ���� �� ����� ����� �������� �����������
				next = road[road.size()-1];
				road.pop_back();
				if (road.size() == 0)
					return nullptr;
			}
			return road[road.size()-1];
		}

		return nullptr;
	}


	///�������� ����� ������
	void del_tree() {
		if (head != nullptr)
			head = delete_tree(head);
	}

	///�������� ���� �� �������� - �
	void del(const e& a) {
		tree_node<e>* i = find(a);
		if (i == nullptr)
			return;
		//�������� �����
		if (i->left == 0 and i->right == 0) {
			vector<tree_node<e>*> road; //������� ������ � ��������, ��������� ����
			tree_node<e>* next;

			road.push_back(head);
			if (head->inf < i->inf) { //������� �� ������
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

			road.pop_back(); //������� �������

			tree_node<e>* p = road[road.size() - 1];
			if (p->right == i)
				p->right = nullptr;
			if (p->left == i)
				p->left = nullptr;
			delete i;
			return;
		}

		//�������� ���� � ����� ��������
		if ((i->left != 0 and i->right == 0) or (i->left == 0 and i->right != 0)) {
			vector<tree_node<e>*> road; //������� ������ � ��������, ��������� ����
			tree_node<e>* next;

			road.push_back(head);
			if (head->inf < i->inf) { //������� �� ������
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

			road.pop_back(); //������� �������

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

		///�������� ���� � ����� ���������
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