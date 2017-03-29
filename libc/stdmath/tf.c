#include <trigonometric_functions.h>

static int tf_err = 0;

int tf_geterr()
{
	return tf_err;
}

double cos(double ang)
{
	return sin(90-ang);
}

double tan(double ang)
{
	double angsin = sin(ang);
	double angcos = cos(ang);
	if (angcos <= EPS && angcos >= -EPS)
	{
		tf_err = 1;
		return 0.0;
	}
	else
	{
		return angsin / angcos;
	}
}

double cotan(double ang)
{
	double angsin = sin(ang);
	double angcos = cos(ang);
	if (angsin <= EPS && angsin >= -EPS)
	{
		tf_err = 1;
		return 0.0;
	}
	else
	{
		return angcos / angsin;
	}
}
