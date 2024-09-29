#include <vector>
#pragma once

/*Шаблонный класс узла n дерева*/
template <typename e>
class n_node {
public:
	e inf; //информация
	///конструктор с параметром. а - хранящаяся информация
	n_node(e a) {
		inf = a;
	}
	std::vector<n_node*> next;
	
};