#include "calc.h"
#include "iostream"
#include <cmath>
#include <gtest\gtest.h>
//черный ящик
TEST(libapp, searchReverse)//поиск по узлам заданным не по возрастанию списка вершин
{
	Spisok TestA;
	std::vector<int> myvec = { 1, 2, 2, 3, 3, 4, 1, 3, 1, 5, 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> ResExp = {};//ошибка
	std::vector<int> Res = TestA.Path_Depth_First_Search(4, 2);
	EXPECT_EQ(Res, ResExp);
}

TEST(libapp, AddNormal)
{
	Spisok TestA;
	std::vector<int> myvec = { 1, 2, 2, 3, 3, 4, 1, 3, 1, 5, 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> ResExp = {4,3,2};
	std::vector<int> Res = TestA.Path_Depth_First_Search(2, 4);
	EXPECT_EQ(Res, ResExp);
}

TEST(libapp, addOne)//одна вершина в графе
{
	Spisok TestA;
	std::vector<int> myvec = { 1, 1, 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> Res = { 1 };
	EXPECT_EQ(TestA.Path_Depth_First_Search(1, 1), Res);

}
TEST(libapp, addNotW)//несвязная вершина
{
	Spisok TestA;
	std::vector<int> myvec = { 1, 2, 2, 3, 3, 4, 1, 3, 1, 5,6,6, 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> Res = { 6 };
	EXPECT_EQ(TestA.Path_Depth_First_Search(6, 6), Res);
}
TEST(libapp, addNotWP)//путь до несвязной вершины
{
	Spisok TestA;
	std::vector<int> myvec = { 1, 2, 2, 3, 3, 4, 1, 3, 1, 5, 6, 6, 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> Res = {  };
	EXPECT_EQ(TestA.Path_Depth_First_Search(1, 6), Res);

}

TEST(libapp, NoHead) //нет графа
{
	Spisok TestA;
	std::vector<int> myvec = { 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> Res = {  };//ошибка
	EXPECT_EQ(TestA.Path_Depth_First_Search(0, 0), Res);
	}

TEST(libapp, NoHeadEl)//нет точки в  графе
{
	Spisok TestA;
	std::vector<int> myvec = { 1, 2, 2, 3, 3, 4, 1, 3, 1, 5, 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> Res = {  };//ошибка
	EXPECT_EQ(TestA.Path_Depth_First_Search(6, 6), Res);

}
TEST(libapp, AddChar)//пытаемся найти символ в графе чисел
{
	Spisok TestA;
	std::vector<int> myvec = { 1, 2, 2, 3, 3, 4, 1, 3, 1, 5, 6, 6, 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> Res = { };
	EXPECT_EQ(TestA.Path_Depth_First_Search(1, '3'), Res);
}
TEST(libapp, addOtr)//ищем отр.
{
	Spisok TestA;
	std::vector<int> myvec = { -1,1, 1, 2, 2, 3, 3, 4, 1, 3, 1, 5, 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> Res = { 2,1,-1 };
	EXPECT_EQ(TestA.Path_Depth_First_Search(-1, 2), Res);
}
TEST(libapp, addMax)//ищем max
{
	Spisok TestA;
	
	std::vector<int> myvec = { 1, 2, 2, std::numeric_limits<int>::max(), 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> Res = { std::numeric_limits<int>::max(),2, 1};
	EXPECT_EQ(TestA.Path_Depth_First_Search(1, std::numeric_limits<int>::max()), Res);
}
TEST(libapp, addMin)//ищем min
{
	Spisok TestA;

	std::vector<int> myvec = { std::numeric_limits<int>::min(), 1, 2, 2, 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> Res = {1, std::numeric_limits<int>::min() };
	EXPECT_EQ(TestA.Path_Depth_First_Search(std::numeric_limits<int>::min(), 1), Res);
}
TEST(libapp, addMin_Max)//ищем путь min - max
{
	Spisok TestA;

	std::vector<int> myvec = { std::numeric_limits<int>::min(), 1, 1, std::numeric_limits<int>::max(), 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> Res = { std::numeric_limits<int>::max(),1, std::numeric_limits<int>::min() };
	EXPECT_EQ(TestA.Path_Depth_First_Search(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()), Res);
}

//белый ящик
TEST(libapp, WayNorm)//1 4 5 6 9 11 12 13 14 15 17
{
	Spisok TestA;
	std::vector<int> myvec = { 1, 2, 2, 3, 3, 5, 1, 5, 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> ResExp = { 3, 2, 1 };
	std::vector<int> Res = TestA.Path_Depth_First_Search(1, 3);
	EXPECT_EQ(Res, ResExp);
}

TEST(libapp, WayOneH)//2,4,5,9
{
	Spisok TestA;
	std::vector<int> myvec = { 8, 8, 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> Res = { 8 };
	EXPECT_EQ(TestA.Path_Depth_First_Search(8, 8), Res);
}
TEST(libapp, WayNotWP)//1,4,5,6,7,9,10,11,12,13,16,17
{
	Spisok TestA;
	std::vector<int> myvec = { 1, 2, 2, 3, 3, 4, 1, 3, 1, 5, 6, 6, 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> Res = {};
	EXPECT_EQ(TestA.Path_Depth_First_Search(1, 6), Res);
}
TEST(libapp, NotWP)//4,5,6,9,10,11
{
	Spisok TestA;
	std::vector<int> myvec = { 1, 1, 2, 2, 3, 3, 4, 4, 1, 4, 0 };
	TestA.MakeGraph(myvec);
	std::vector<int> Res = {};
	EXPECT_EQ(TestA.Path_Depth_First_Search(1, 3), Res);
}