#include <vector>
#pragma once

///���������� ������� � �������� n ���� ������� 
template <typename el>
void random_vector(std::vector<el>& a, size_t n)
{
		for (size_t i = 0; i < n; i++)
			a.push_back((int)(rand() % 10));//��������� ���� �������

}