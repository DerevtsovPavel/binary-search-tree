#include <vector>
#include <random>
#pragma once
using namespace std;

///���������� ������� � �������� n ���� ������� 
template <typename el>
void random_vector(vector<el>& a, size_t n, mt19937 gen)
{	
    // ���������� ��������
    int min = -1'000'000;
    int max = 1'000'000;

    
    uniform_int_distribution<> distrib(min, max);

    
    for (size_t i = 0; i < n; i++) {
        int randomValue = distrib(gen);
        a.push_back(randomValue);//��������� ���� �������
    }

}