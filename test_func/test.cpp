#include "pch.h"
#include "../functions.h"
#include "../binary_search_tree.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

///depth O(n)
TEST(depth, balance_tree) { //сбалансированное дерево
	tree_node<int>* a = new tree_node<int>(10);
	tree_node<int>* b = new tree_node<int>(-5);
	tree_node<int>* c = new tree_node<int>(8);
	tree_node<int>* d = new tree_node<int>(2);
	tree_node<int>* e = new tree_node<int>(1);
	tree_node<int>* f = new tree_node<int>(1);
	tree_node<int>* g = new tree_node<int>(1);

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	
	EXPECT_TRUE(func::depth(a) == 2);
	EXPECT_TRUE(func::depth(g) == 0);
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
}

TEST(depth, non_balance_tree) { //не сбалансированное дерево
	tree_node<int>* a = new tree_node<int>(10);
	tree_node<int>* b = new tree_node<int>(-5);
	tree_node<int>* c = new tree_node<int>(8);
	tree_node<int>* d = new tree_node<int>(2);
	tree_node<int>* e = new tree_node<int>(1);
	tree_node<int>* f = new tree_node<int>(1);
	tree_node<int>* g = new tree_node<int>(1);			/*	a
														b		c
													d	   e
													     f
														   g*/

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	e->left = f;
	f->right = g;

	EXPECT_TRUE(func::depth(a) == 4);
	EXPECT_TRUE(func::depth(g) == 0);
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
}

TEST(depth, death_tree) {//вырожденное дерево
	tree_node<int>* a = new tree_node<int>(10);
	tree_node<int>* b = new tree_node<int>(-5);
	tree_node<int>* c = new tree_node<int>(8);
	tree_node<int>* d = new tree_node<int>(2);
	tree_node<int>* e = new tree_node<int>(1);
	tree_node<int>* f = new tree_node<int>(1);
	tree_node<int>* g = new tree_node<int>(1);		

	a->right = b;
	b->right = c;
	c->right = d;
	d->right = e;
	e->right = f;
	f->right = g;

	EXPECT_TRUE(func::depth(a) == 6);
	EXPECT_TRUE(func::depth(g) == 0);
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
}

TEST(depth, root_tree) { //дерево из одного корня
	tree_node<int>* a = new tree_node<int>(10);
	EXPECT_TRUE(func::depth(a) == 0);
	delete a;
}

TEST(depth,no_tree) { //указатель на пустой адресс
	tree_node<int>* a = new tree_node<int>(10);
	a = delete_tree(a);
	EXPECT_TRUE(func::depth(a) == -1);
	
}




///кол-во элементов в дереве O(n)
TEST(size, balance_tree) {//сбалансированное дерево
	tree_node<int>* a = new tree_node<int>(10);
	tree_node<int>* b = new tree_node<int>(-5);
	tree_node<int>* c = new tree_node<int>(8);
	tree_node<int>* d = new tree_node<int>(2);
	tree_node<int>* e = new tree_node<int>(1);
	tree_node<int>* f = new tree_node<int>(1);
	tree_node<int>* g = new tree_node<int>(1);

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;

	EXPECT_TRUE(func::size(a) == 7);
	EXPECT_TRUE(func::size(g) == 1);
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
}

TEST(size, non_balance_tree) {//не сбалансированное дерево
	tree_node<int>* a = new tree_node<int>(10);
	tree_node<int>* b = new tree_node<int>(-5);
	tree_node<int>* c = new tree_node<int>(8);
	tree_node<int>* d = new tree_node<int>(2);
	tree_node<int>* e = new tree_node<int>(1);
	tree_node<int>* f = new tree_node<int>(1);
	tree_node<int>* g = new tree_node<int>(1);			/*	a
														b		c
													d	   e
														 f
														   g*/

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	e->left = f;
	f->right = g;

	EXPECT_TRUE(func::size(a) == 7);
	EXPECT_TRUE(func::size(g) == 1);
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
}

TEST(size, death_tree) {//вырожденное дерево
	tree_node<int>* a = new tree_node<int>(10);
	tree_node<int>* b = new tree_node<int>(-5);
	tree_node<int>* c = new tree_node<int>(8);
	tree_node<int>* d = new tree_node<int>(2);
	tree_node<int>* e = new tree_node<int>(1);
	tree_node<int>* f = new tree_node<int>(1);
	tree_node<int>* g = new tree_node<int>(1);

	a->right = b;
	b->right = c;
	c->right = d;
	d->right = e;
	e->right = f;
	f->right = g;

	EXPECT_TRUE(func::size(a) == 7);
	EXPECT_TRUE(func::size(g) == 1);
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
}

TEST(size, root_tree) {//дерево из одного корня
	tree_node<int>* a = new tree_node<int>(10);
	EXPECT_TRUE(func::size(a) == 1);
	delete a;
}

TEST(size, no_tree) {//указатель на пустой адресс
	tree_node<int>* a = new tree_node<int>(10);
	a = delete_tree(a);
	EXPECT_TRUE(func::size(a) == 0);

}


///Поиск O(log n)
TEST(find, balance_tree) {//сбалансированное дерево
	
	vector<int> v{ 8,4,12,2,5,9,14 };
	tree_node<int>* a = create_binary_search_tree(v);
	EXPECT_TRUE(func::find(a,8)->inf == 8);
	EXPECT_TRUE(func::find(a, 9)->inf == 9);
	EXPECT_TRUE(func::find(a,89) == nullptr);
	
}

TEST(find, non_balance_tree) {//не сбалансированное дерево
				
	vector<int> v{4,1,2,12,8,5,9,14 };
	tree_node<int>* a = create_binary_search_tree(v);
	EXPECT_TRUE(func::find(a,14)->inf == 14);
	EXPECT_TRUE(func::find(a,0) == nullptr);
	
}

TEST(find, death_tree) {//вырожденное дерево
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	tree_node<int>* a = create_binary_search_tree(v);
	EXPECT_TRUE(func::find(a,10)->inf == 10);
	EXPECT_TRUE(func::find(a, 5)->inf == 5);
	EXPECT_TRUE(func::find(a,0) == nullptr);
	
}

TEST(find, root_tree) {//дерево из одного корня
	tree_node<int>* a = new tree_node<int>(10);
	EXPECT_TRUE(func::find(a,10)->inf == 10);
	EXPECT_TRUE(func::find(a, 0) == nullptr);
	delete a;
}

TEST(find, no_tree) {//указатель на пустой адресс
	tree_node<int>* a = new tree_node<int>(10);
	a = delete_tree(a);
	EXPECT_TRUE(func::find(a,10) == nullptr);

}



///LNR обход O(n)
TEST(LNR, balance_tree) {//сбалансированное дерево
	tree_node<int>* a = new tree_node<int>(10);
	tree_node<int>* b = new tree_node<int>(-5);
	tree_node<int>* c = new tree_node<int>(8);
	tree_node<int>* d = new tree_node<int>(2);
	tree_node<int>* e = new tree_node<int>(1);
	tree_node<int>* f = new tree_node<int>(1);
	tree_node<int>* g = new tree_node<int>(1);

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	vector<int> o{ 2,-5,1,10,1,8,1 };
	vector<int> v;
	LNR_tree_to_vector(a, v);

	EXPECT_TRUE(o==v);
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
}

TEST(LNR, non_balance_tree) {//не сбалансированное дерево
	tree_node<int>* a = new tree_node<int>(10);
	tree_node<int>* b = new tree_node<int>(-5);
	tree_node<int>* c = new tree_node<int>(8);
	tree_node<int>* d = new tree_node<int>(2);
	tree_node<int>* e = new tree_node<int>(1);
	tree_node<int>* f = new tree_node<int>(1);
	tree_node<int>* g = new tree_node<int>(1);			/*	a
														b		c
													d	   e
														 f
														   g*/

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	e->left = f;
	f->right = g;

	vector<int> o{ 2,-5,1,1,1,10,8 };
	vector<int> v;
	LNR_tree_to_vector(a, v);

	EXPECT_TRUE(o == v);
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
}

TEST(LNR, death_tree) {//вырожденное дерево
	tree_node<int>* a = new tree_node<int>(10);
	tree_node<int>* b = new tree_node<int>(-5);
	tree_node<int>* c = new tree_node<int>(8);
	tree_node<int>* d = new tree_node<int>(2);
	tree_node<int>* e = new tree_node<int>(1);
	tree_node<int>* f = new tree_node<int>(1);
	tree_node<int>* g = new tree_node<int>(1);

	a->right = b;
	b->right = c;
	c->right = d;
	d->right = e;
	e->right = f;
	f->right = g;

	vector<int> o{ 10,-5,8,2,1,1,1 };
	vector<int> v;
	LNR_tree_to_vector(a, v);
	EXPECT_TRUE(o == v);
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
}

TEST(LNR, root_tree) {//дерево из одного корня
	tree_node<int>* a = new tree_node<int>(10);
	vector<int> o{ 10 };
	vector<int> v;
	LNR_tree_to_vector(a, v);
	EXPECT_TRUE(o == v);
	delete a;
}

TEST(LNR, no_tree) {//указатель на пустой адресс
	tree_node<int>* a = new tree_node<int>(10);
	a = delete_tree(a);
	vector<int> o;
	vector<int> v;
	LNR_tree_to_vector(a, v);
	EXPECT_TRUE(o == v);

}


///коприрование O(n)
TEST(copy, balance_tree) {//сбалансированное дерево
	tree_node<int>* a = new tree_node<int>(10);
	tree_node<int>* b = new tree_node<int>(-5);
	tree_node<int>* c = new tree_node<int>(8);
	tree_node<int>* d = new tree_node<int>(2);
	tree_node<int>* e = new tree_node<int>(1);
	tree_node<int>* f = new tree_node<int>(1);
	tree_node<int>* g = new tree_node<int>(1);

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;

	vector<int> l;
	vector<int> v;

	LNR_tree_to_vector(a, l);

	tree_node<int>* p = copy_binary_tree(a);

	LNR_tree_to_vector(p, v);

	EXPECT_TRUE(l == v);
	delete_tree(a);
	delete_tree(p);
}

TEST(copy, non_balance_tree) {//не сбалансированное дерево
	tree_node<int>* a = new tree_node<int>(10);
	tree_node<int>* b = new tree_node<int>(-5);
	tree_node<int>* c = new tree_node<int>(8);
	tree_node<int>* d = new tree_node<int>(2);
	tree_node<int>* e = new tree_node<int>(1);
	tree_node<int>* f = new tree_node<int>(1);
	tree_node<int>* g = new tree_node<int>(1);			/*	a
														b		c
													d	   e
														 f
														   g*/

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	e->left = f;
	f->right = g;

	vector<int> l;
	vector<int> v;

	LNR_tree_to_vector(a, l);

	tree_node<int>* p = copy_binary_tree(a);

	LNR_tree_to_vector(p, v);

	EXPECT_TRUE(l == v);
	delete_tree(a);
	delete_tree(p);
}

TEST(copy, death_tree) {//вырожденное дерево
	tree_node<int>* a = new tree_node<int>(10);
	tree_node<int>* b = new tree_node<int>(-5);
	tree_node<int>* c = new tree_node<int>(8);
	tree_node<int>* d = new tree_node<int>(2);
	tree_node<int>* e = new tree_node<int>(1);
	tree_node<int>* f = new tree_node<int>(1);
	tree_node<int>* g = new tree_node<int>(1);

	a->right = b;
	b->right = c;
	c->right = d;
	d->right = e;
	e->right = f;
	f->right = g;

	vector<int> l;
	vector<int> v;

	LNR_tree_to_vector(a, l);

	tree_node<int>* p = copy_binary_tree(a);

	LNR_tree_to_vector(p, v);

	EXPECT_TRUE(l == v);
	delete_tree(a);
	delete_tree(p);
}

TEST(copy, root_tree) {//дерево из одного корня
	tree_node<int>* a = new tree_node<int>(10);
	vector<int> l;
	vector<int> v;

	LNR_tree_to_vector(a, l);

	tree_node<int>* p = copy_binary_tree(a);

	LNR_tree_to_vector(p, v);

	EXPECT_TRUE(l == v);
	delete_tree(a);
	delete_tree(p);
}

TEST(copy, no_tree) {//указатель на пустой адресс
	tree_node<int>* a = new tree_node<int>(10);
	a = delete_tree(a);
	vector<int> l;
	vector<int> v;

	LNR_tree_to_vector(a, l);

	tree_node<int>* p = copy_binary_tree(a);

	LNR_tree_to_vector(p, v);

	EXPECT_TRUE(l == v);

}

TEST(del_element,leave) {
	vector<int> f{ 3,1,4,2,7,5,6,0 };
	bst<int> t(f);
	vector<int> b = t.tree_to_vector();//0,1,2,3,4,5,6,7

	t.del(6);

	vector<int> a = t.tree_to_vector();
	b.erase(b.begin() + 6); 

	EXPECT_TRUE(b == a);
}

TEST(del_element, one_child) {
	vector<int> f{ 3,1,4,2,7,5,6,0 };
	bst<int> t(f);
	vector<int> b = t.tree_to_vector(); //0,1,2,3,4,5,6,7

	t.del(5);

	vector<int> a = t.tree_to_vector();
	b.erase(b.begin() + 5); 

	EXPECT_TRUE(b == a);
}

TEST(del_element, two_child) {
	vector<int> f{ 3,1,4,2,7,5,6,0 };
	bst<int> t(f);
	vector<int> b = t.tree_to_vector(); //0,1,2,3,4,5,6,7

	t.del(1);

	vector<int> a = t.tree_to_vector();
	b.erase(b.begin() + 1);

	EXPECT_TRUE(b == a);
}
/*
TEST(del_element, two_child2) {
	vector<int> f{ 3,1,4,2,7,5,6,0 };
	bst<int> t(f);
	vector<int> b = t.tree_to_vector(); //0,1,2,3,4,5,6,7

	t.del(3);

	vector<int> a = t.tree_to_vector();
	b.erase(b.begin() + 3);

	EXPECT_TRUE(b == a);
}*/

///добавление элемента O(log n)
TEST(add_element, death_tree) { //продолжим вырожденное дерево
	vector<int> f{ 1,2,3,4,5,6,7 }; 
	bst t(f);

	f.push_back(8);

	t.add(8);

	vector<int> b = t.tree_to_vector();

	EXPECT_TRUE(f == b);
}

TEST(add_element, death_tree2) { //нарушим вырожденность
	vector<int> f{ 1,2,3,4,5,6,7 };
	bst t(f);

	t.add(-1);
	t.add(0);

	vector<int> b = t.tree_to_vector();

	f.insert(f.begin(), 0);
	f.insert(f.begin(), -1);

	EXPECT_TRUE(f == b);
}

TEST(add_element, normal_tree) {
	vector<int> f{ 3,1,4,2,7,5,6,0 };
	bst t(f);

	t.add(-1);
	t.add(8);
	vector<int> b = t.tree_to_vector(); //-1,0,1,2,3,4,5,6,7,8

	vector<int> g{ -1,0,1,2,3,4,5,6,7,8 };
	EXPECT_TRUE(g == b);



}

TEST(add_elemnt, one_element) {
	vector<int> a{ 9 };

	bst t(a);

	t.add(0);
	t.add(10);

	vector<int> b = t.tree_to_vector();

	a.insert(a.begin(), 0);
	a.push_back(10);

	EXPECT_TRUE(a == b);
}

TEST(add_element, empty_tree) {
	bst<int> t;

	t.add(0);

	vector<int> a = t.tree_to_vector();

	EXPECT_TRUE(a[0] == 0);

	t.add(-1);
	t.add(1);

	a = t.tree_to_vector();

	EXPECT_TRUE(a[0] == -1);
	EXPECT_TRUE(a[1] == 0);
	EXPECT_TRUE(a[2] == 1);
}