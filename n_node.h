#include <vector>
#pragma once

/*��������� ����� ���� n ������*/
template <typename e>
class n_node {
public:
	e inf; //����������
	///����������� � ����������. � - ���������� ����������
	n_node(e a) {
		inf = a;
	}
	std::vector<n_node*> next;
	
};