#pragma once
/*��������� ����� ���� ��������� ������*/
template <typename e>
class tree_node {
public:
	e inf; //����������
	///����������� � ����������. � - ���������� ����������
	tree_node(e a) {
		inf = a;
	}
	tree_node* left = nullptr; //��������� �� ����� ����
	tree_node* right = nullptr; //��������� �� ������ ����
	
};