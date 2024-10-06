#include "pch.h"
#include "../functions.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

///depth O(n)
TEST(depth, balance_tree) { //���������������� ������
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

TEST(depth, non_balance_tree) { //�� ���������������� ������
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

TEST(depth, death_tree) {//����������� ������
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

TEST(depth, root_tree) { //������ �� ������ �����
	tree_node<int>* a = new tree_node<int>(10);
	EXPECT_TRUE(func::depth(a) == 0);
	delete a;
}

TEST(depth,no_tree) { //��������� �� ������ ������
	tree_node<int>* a = new tree_node<int>(10);
	a = delete_tree(a);
	EXPECT_TRUE(func::depth(a) == -1);
	
}




///���-�� ��������� � ������ O(n)
TEST(size, balance_tree) {//���������������� ������
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

TEST(size, non_balance_tree) {//�� ���������������� ������
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

TEST(size, death_tree) {//����������� ������
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

TEST(size, root_tree) {//������ �� ������ �����
	tree_node<int>* a = new tree_node<int>(10);
	EXPECT_TRUE(func::size(a) == 1);
	delete a;
}

TEST(size, no_tree) {//��������� �� ������ ������
	tree_node<int>* a = new tree_node<int>(10);
	a = delete_tree(a);
	EXPECT_TRUE(func::size(a) == 0);

}


///����� O(log n)
TEST(find, balance_tree) {//���������������� ������
	
	vector<int> v{ 8,4,12,2,5,9,14 };
	tree_node<int>* a = create_binary_search_tree(v);
	EXPECT_TRUE(func::find(a,8)->inf == 8);
	EXPECT_TRUE(func::find(a, 9)->inf == 9);
	EXPECT_TRUE(func::find(a,89) == nullptr);
	
}

TEST(find, non_balance_tree) {//�� ���������������� ������
				
	vector<int> v{4,1,2,12,8,5,9,14 };
	tree_node<int>* a = create_binary_search_tree(v);
	EXPECT_TRUE(func::find(a,14)->inf == 14);
	EXPECT_TRUE(func::find(a,0) == nullptr);
	
}

TEST(find, death_tree) {//����������� ������
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	tree_node<int>* a = create_binary_search_tree(v);
	EXPECT_TRUE(func::find(a,10)->inf == 10);
	EXPECT_TRUE(func::find(a, 5)->inf == 5);
	EXPECT_TRUE(func::find(a,0) == nullptr);
	
}

TEST(find, root_tree) {//������ �� ������ �����
	tree_node<int>* a = new tree_node<int>(10);
	EXPECT_TRUE(func::find(a,10)->inf == 10);
	EXPECT_TRUE(func::find(a, 0) == nullptr);
	delete a;
}

TEST(find, no_tree) {//��������� �� ������ ������
	tree_node<int>* a = new tree_node<int>(10);
	a = delete_tree(a);
	EXPECT_TRUE(func::find(a,10) == nullptr);

}



///LNR ����� O(n)
TEST(LNR, balance_tree) {//���������������� ������
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

TEST(LNR, non_balance_tree) {//�� ���������������� ������
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

TEST(LNR, death_tree) {//����������� ������
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

TEST(LNR, root_tree) {//������ �� ������ �����
	tree_node<int>* a = new tree_node<int>(10);
	vector<int> o{ 10 };
	vector<int> v;
	LNR_tree_to_vector(a, v);
	EXPECT_TRUE(o == v);
	delete a;
}

TEST(LNR, no_tree) {//��������� �� ������ ������
	tree_node<int>* a = new tree_node<int>(10);
	a = delete_tree(a);
	vector<int> o;
	vector<int> v;
	LNR_tree_to_vector(a, v);
	EXPECT_TRUE(o == v);

}


///������������ O(n)
TEST(copy, balance_tree) {//���������������� ������
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

TEST(copy, non_balance_tree) {//�� ���������������� ������
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

TEST(copy, death_tree) {//����������� ������
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

TEST(copy, root_tree) {//������ �� ������ �����
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

TEST(copy, no_tree) {//��������� �� ������ ������
	tree_node<int>* a = new tree_node<int>(10);
	a = delete_tree(a);
	vector<int> l;
	vector<int> v;

	LNR_tree_to_vector(a, l);

	tree_node<int>* p = copy_binary_tree(a);

	LNR_tree_to_vector(p, v);

	EXPECT_TRUE(l == v);

}