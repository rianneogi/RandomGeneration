#include "RandomFunctions.h"

CRandom Random;

int random(int a,int b)
{
	return (Random.Random(b-a)+a);
}

PerlinNoise::PerlinNoise()
{
}

PerlinNoise::PerlinNoise(int x,int y) : length(x),height(y)
{
	Gradient = new double[length*height*2];
}

PerlinNoise::~PerlinNoise()
{
}

void PerlinNoise::computeGradient()
{
	for(int i = 0;i<height;i++)
	{
		for(int j = 0;j<length;j++)
		{
			Gradient[2*(i*length+j)] = cos(Random.Random(10000)*(2*M_PI/10000));
			Gradient[2*(i*length+j)+1] = sin(Random.Random(10000)*(2*M_PI/10000));
			//cout << "grad " << i << " " << j << " is " << Gradient[2*(i*length+j)] << " " << Gradient[2*(i*length+j)+1];
		}
	}
}

// Function to linearly interpolate between a0 and a1
// Weight w should be in the range [0.0, 1.0]
double PerlinNoise::lerp(double a0, double a1, double w) {
    return ((1.0 - w)*a0 + w*a1);
}

// Computes the dot product of the distance and gradient vectors.
double PerlinNoise::dotGridGradient(int ix, int iy, double x, double y) {
 
    // Precomputed (or otherwise) gradient vectors at each grid point X,Y
    //extern float Gradient[Y][X][2];
 
    // Compute the distance vector
    double dx = x - (double)ix;
    double dy = y - (double)iy;
 
	//cout << "      dvec " << dx << " " << dy << "  grad " << Gradient[2*(iy*length+ix)] << " " << Gradient[2*(iy*length+ix)+1] << endl;
    // Compute the dot-product
    return (dx*Gradient[2*(iy*length+ix)] + dy*Gradient[2*(iy*length+ix)+1]);
}

// Compute Perlin noise at coordinates x, y
double PerlinNoise::perlin(double x, double y) {
 
    // Determine grid cell coordinates
    int x0 = (x > 0.0 ? (int)x : (int)x - 1);
    int x1 = x0 + 1;
    int y0 = (y > 0.0 ? (int)y : (int)y - 1);
    int y1 = y0 + 1;
 
    // Determine interpolation weights
    // Could also use higher order polynomial/s-curve here
    double sx = x - (double)x0;
    double sy = y - (double)y0;
 
    // Interpolate between grid point gradients
    double n0, n1, ix0, ix1, value;
    n0 = dotGridGradient(x0, y0, x, y);
    n1 = dotGridGradient(x1, y0, x, y);
    ix0 = lerp(n0, n1, sx);
	//cout << "1> n0: " << n0 << " n1: " << n1 << endl;
    n0 = dotGridGradient(x0, y1, x, y);
    n1 = dotGridGradient(x1, y1, x, y);
    ix1 = lerp(n0, n1, sx);
	//cout << "2> n00: " << n0 << " n1: " << n1 << endl;
	//cout << "   ix0: " << ix0 << " ix1: " << ix1 << " sy: " << sy << endl;
    value = lerp(ix0, ix1, sy);
 
    return value;
}

WeightedRandom::WeightedRandom()
{
}

WeightedRandom::~WeightedRandom()
{
}

void WeightedRandom::addWeight(int w)
{
	weights.push_back(w);
}

int WeightedRandom::get()
{
	int sum = 0;
	for(int i = 0;i<weights.size();i++)
	{
		sum += weights.at(i);
	}
	int r = random(0,sum);
	int it;
	for(int i = 0;i<weights.size();i++)
	{
		it += weights.at(i);
		if(r<it)
			return i;
	}
	return -1;
}

