#include <stdio.h>
#include <math.h>


// Fonction pour calculer la virgule fixe
double VirFixe(double a)
{
	int integer = a ;
	double fract = a-integer , c = 0.000000;
    int j = 0;

    while(integer!=0)
        {
            c=c+(integer%2)*pow(10,j);
            j++;
            integer=integer/2;
        }
        j=-1;

    while(fract!=0)
        {
            int p = fract*2;
            fract=fract*2;
            c=c+p*pow(10,j);
            j--;
            fract=fract-p;
        }
	return c;
}

void printBinary(int n, int i)
{
    // Affichage du representation binaire 
    // d'un nombre n a i-bits.

    int k;
    for (k = i - 1; k >= 0; k--) {
 
        if ((n >> k) & 1)
            printf("1");
        else
            printf("0");
    }
}
 
typedef union {

    // En utilisons l'union pour initialiser
    // la forme de 32 bits

    float f;
    struct
    {
        unsigned long mantisse : 23;
        unsigned int exponent : 8;
        unsigned int signe : 1;

    } brute;

} 
myfloat;
 

void printIEEE(myfloat var)                
{
 
    // Affichage de la representation IEEE 754
    // pour un nombre flottante (32 bits)
 
    printf("%d | ", var.brute.signe);
    printBinary(var.brute.exponent, 8);
    printf(" | ");
    printBinary(var.brute.mantisse, 23);
    printf("\n");
}
 

int main (){
    
    double a ;
    printf("Entrer un nombre : ");
    scanf ("%lf",&a);
    printf("La convertion binaire du nombre %lf est: %lf\n",a,VirFixe(a));

    // Union
    myfloat var;
    var.f = a ;

    // Representation avec virgule floattant IEEE 754
    printf("La representation de %f par virgule flottante : \n",var.f);      
    printIEEE(var);
 
    return 0;
}