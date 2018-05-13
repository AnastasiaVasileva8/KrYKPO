#include "calc.h"

#include <cmath>
#include <gtest\gtest.h>

TEST(libapp, plus)
{
	MC mas_t(3);
	MC mas2_t(3);
	MC res_t(6);
	double **mas1;
	mas1 = new double*[2];
	for (int i = 0; i < 2; i++)
	{
		mas1[i] = new double[3];
	}
	mas1[0][0] = 3;
	mas1[1][0] = 2;
	mas1[0][1] = 2;
	mas1[1][1] = 4;
	mas1[0][2] = 0;
	mas1[1][2] = 3;
	mas_t.SetArr(mas1, 3);
	double **mas2;
	mas2 = new double*[2];
	for (int i = 0; i < 2; i++)
	{
		mas2[i] = new double[3];
	}
	mas2[0][0] = 5;
	mas2[1][0] = 7;
	mas2[0][1] = 3;
	mas2[1][1] = 2;
	mas2[0][2] = 2;
	mas2[1][2] = 3;
	mas2_t.SetArr(mas2, 3);
	double **res;
	res = new double*[2];
	for (int i = 0; i < 2; i++)
	{
		res[i] = new double[6];
	}
	res[0][0] = 3;
	res[1][0] = 4;
	res[0][1] = 2;
	res[1][1] = 7;
	res[0][2] = 0;
	res[1][2] = 3;
	res[0][3] = 5;
	res[1][3] = 7;
	res_t.SetArr(res, 4);

	//cout << "Res cpp";
	//res_t.OutPut();
	EXPECT_EQ(mas_t + mas2_t, res_t);

}
