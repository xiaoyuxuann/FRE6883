#include <iostream>
#include <iomanip>
using namespace std;

class DefInt{
    private:
        double a;
        double b;
        double (*fp)(double x);
    public:
        DefInt(): a(0), b(0), fp(){}
        DefInt(double a_, double b_, double (*fp_)(double x)): a(a_), b(b_), fp(fp_){}
        DefInt(const DefInt& I): a(I.a), b(I.b), fp(I.fp){}
        ~DefInt(){}
        double ByTrapzoid(int N);
        double BySimpson(int N);
};

double DefInt::ByTrapzoid(int N)
{
    double sum = 0.0;
    double h = (b - a) / N;
    for (int k = 1; k <= N; k++)
    {
        sum += fp(a + (k-1) * h) + fp(a + k * h);
    }
    return (h / 2) * sum;
}

double DefInt::BySimpson(int N)
{
    double sum1 = 0.0;
    double sum2 = 0.0;
    double h = (b-a) / (2 * N);
    for (int k = 1; k <= N; k++)
    {
        sum1 += fp(a + (2 * k - 1) * h);
    }
    for (int k = 1; k <= N-1; k++)
    {
        sum2 += fp(a + 2 * k * h);
    }
    return (h / 3) * (fp(a) + 4 * sum1 + 2 * sum2 + fp(b));
}

double f(double x)
	{
	    return x*x*x - x*x + 1;
	}

int main()
{
	double a = 1.0;
	double b = 2.0;
	double (*fp)(double x) = f;
	
	DefInt MyInt(a,b,fp);
	
	int N = 100;
	cout << "The definite integral by Trapzoid method = " << fixed << setprecision(2) << MyInt.ByTrapzoid(N) << endl;
	cout << "The definite integral by Simpson method = " << fixed << setprecision(2) << MyInt.BySimpson(N) << endl;
	return 0;
}

/* Results:
The definite integral by Trapzoid method = 2.42
The definite integral by Simpson method = 2.42
*/