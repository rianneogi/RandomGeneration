#pragma once
#include <vector>
#include "CRandom.h"

#define _USE_MATH_DEFINES

#include "math.h"

#include <iostream>
#include <conio.h>

using namespace std;

extern CRandom Random;
extern int random(int a,int b);

class PerlinNoise
{
public:
	double* Gradient;
	int length;
	int height;

	PerlinNoise();
	PerlinNoise(int x,int y);
	~PerlinNoise();

	void computeGradient();
	double dotGridGradient(int ix, int iy, double x, double y);
	double lerp(double a0, double a1, double w);
	double perlin(double x,double y);
};

class WeightedRandom
{
public:
	vector<int> weights;

	WeightedRandom();
	~WeightedRandom();
	
	void addWeight(int w);
	int get();
};