#include "BibliotecaPasages.h"
int PasageACelcius(int gradosF)
{
	int resultadoPasage;
	resultadoPasage = (gradosF - 32)*(5)/9;
	return resultadoPasage;
}
int PasageAFahrenheit(int gradosC)
{
	int resultadoPasage;
	resultadoPasage = gradosC*9/5+ 32;
	return resultadoPasage;
}


