#include<stdio.h>
#include<math.h>

int main()
{
    double p,q,s;
    printf("p,q,s�� �Է��ϼ���\n");
    scanf("%lf %lf %lf",&p,&q,&s);
    double x,y;
    x=p*sin(s/(sqrt((p*p+q*q)/2)));
    y=q*cos(s/(sqrt((q*q+p*p)/2)));
    printf("%f %f",x,y);
}
