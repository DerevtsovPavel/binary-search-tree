#pragma once
/*Шаблонный класс узла бинарного дерева*/
template <typename e>
class tree_node {
public:
	e inf; //информация
	///конструктор с параметром. а - хранящаяся информация
	tree_node(e a) {
		inf = a;
	}
	tree_node* left = nullptr; //указатель на левый узел
	tree_node* right = nullptr; //указатель на правый узел
	
};