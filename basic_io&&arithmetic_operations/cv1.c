/* klymenchuk yevhenii cislo */
/* cvicenie 1 */
/* 20.09.2024 */

#include <stdio.h>
#include <math.h>

 int cv1_uvodny()
 {
    printf("Hello, world!\n");
    return 0;
 }

 int cv1_prvy()
 {
    printf("Su vsetky tieto [*, &, /, \\, $, %%, '] znaky specialne");
    return 0;
 }

int cv1_druhy()
 {
    int a,b,c; // a - length    b - width   c - height
    printf("Zadajte 3 cele cisla oddelene medzerou:\n");

    scanf("%d %d %d", &a, &b, &c);

    int objem = a*b*c;
    int povrh = 2*(a*b)+2*(a*c)+2*(b*c);

    printf("Objem: %d * %d * %d je %d\n", a, b, c, objem);
    printf("Povrh: 2 * %d * %d + 2 * %d * %d + 2 * %d * %d je %d\n",a, b, a, c, b, c, povrh);


    return 0;
 }

 int cv1_treti()
 {
    double r, obvod, obsah;
    printf("Zadaj polomer kruhu (realne cislo): ");
    scanf("%lf", &r);

    obvod = 2*M_PI*r;
    obsah = M_PI*r*r;

    printf("Kruh s polomerom %.2lf: obvod = %.2lf, obsah = %.2lf\n", r, obvod, obsah);

    return 0;
 }

 int cv1_treri_1()
 {
     double num1, num2, num3, avg;

     printf("Zadaj 3 realne cisla: ");
     scanf("%lf %lf %lf", &num1, &num2, &num3);

     avg = (num1+num2+num3)/3;

     printf("Priemer cisel %.2lf %.2lf %.2lf je: %lf", num1, num2, num3, avg);
 }


 int cv1_treri_2()
 {
    int cena;

    printf("Zadaj cenu bez dane: ");
    scanf("%d", &cena);


    printf("Cena bez dane: %d\n", cena);
    printf("Predajna cena s danou 20%%: %.2f\n", cena * 1.2);

    return 0;
 }

 int cv1_treti_3()
 {
     int weight, height;
     printf("Zadajte vysku v centimetroch: ");
     scanf("%d", &height);
     printf("Zadajte hmotnost v kilogramoch: ");
     scanf("%d", &weight);



     double heightInMeters = height / 100.0;
     double BMI = weight/(heightInMeters*heightInMeters);

     printf("BMI: %.2lf\n", BMI);
 }


int main()
{
    cv1_treti_3();
  return 0;
}

