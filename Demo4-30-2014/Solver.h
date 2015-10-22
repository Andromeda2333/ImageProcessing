#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>
#include <iostream>
#include <math.h>

class Solver
{
public:
	Solver(void);
	~Solver(void);

	static std::vector<double> Compute(std::vector<std::vector<double>>& matQ,
		std::vector<double>& vecB,double alpha,double sigma);
	static std::vector<std::vector<double>> GenerateMat(int dim);
	static std::vector<double> GenerateB(int dim);
	static double f(std::vector<std::vector<double>>& matQ,
		std::vector<double>& vecB,std::vector<double> &vecX);

	static void PrintMat(std::vector<std::vector<double>>& mat);
private:
	static double VecMul(std::vector<double>&lhs,std::vector<double>&rhs);
	static std::vector<double> GradientF(std::vector<std::vector<double>>& matQ,
		std::vector<double>& vecB,std::vector<double> &vecX);
	static std::vector<double> SubVector(std::vector<double>&lhs,std::vector<double>&rhs);
};

