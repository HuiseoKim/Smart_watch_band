#include <stdio.h>
#include <math.h>

double sintheta(double p,double q,double x1,double y1)
{
    double up,down;
    up=y1*p*p;
    down=sqrt(pow(y1,2)*pow(p,4)+pow(x1,2)*pow(q,4));

    if((x1*y1)>=0)
    {
        printf("%lf sinth \n",up/down);
        return up/down;
    }
    if((x1*y1)<0)
    {
        printf("%lf sinth \n",-1*up/down);
        return -1*up/down;
    }
}

double costheta(double p,double q,double x1,double y1)
{
    double up,down;
    up=x1*q*q;
    down=sqrt(pow(y1,2)*pow(p,4)+pow(x1,2)*pow(q,4));
    printf("%lf costh \n",up/down);
    return up/down;
}

double sinpi(double a, double b, double x1, double y1, double sinth, double costh)
{
    double up,down;
    up=(a-x1)*costh+(b-y1)*sinth;
    down=sqrt(pow((a-x1),2)+pow((b-y1),2));
    printf("%lf sinpi \n",up/down);
    return up/down;
}

double cospi(double a, double b, double x1, double y1, double sinth, double costh)
{
    double up,down;
    up=(b-y1)*costh-(a-x1)*sinth;
    down=sqrt(pow((a-x1),2)+pow((b-y1),2));
    printf("%lf cospi \n",up/down);
    return up/down;
}

double c(double sp,double st,double cp,double ct,double a,double b,double p,double q)
{
    double up,down;
    if (a>0&&b>0)
    {
        up=(3*cp*sp*ct-st*(3*cp*cp-1))*b*p*p-(3*cp*sp*st+ct*(3*cp*cp-1))*a*q*q;
        down=sqrt(pow(a*q*q,2)+pow(b*p*p,2));
    }
    else if(a<0&&b>0)
    {
        up=(3*cp*sp*ct-st*(3*cp*cp-1))*b*p*p-(3*cp*sp*st+ct*(3*cp*cp-1))*a*q*q;
        down=sqrt(pow(a*q*q,2)+pow(b*p*p,2));
    }
    else if(a>0&&b<0)
    {
        up=(3*cp*sp*ct-st*(3*cp*cp-1))*b*p*p-(3*cp*sp*st+ct*(3*cp*cp-1))*a*q*q;
        down=sqrt(pow(a*q*q,2)+pow(b*p*p,2));
    }
    else if(a<0&&b<0)
    {
        up=(3*cp*sp*ct-st*(3*cp*cp-1))*b*p*p-(3*cp*sp*st+ct*(3*cp*cp-1))*a*q*q;
        down=sqrt(pow(a*q*q,2)+pow(b*p*p,2));
    }
    printf("%lf const \n",up/down);
    return up/down;
}

double magneticfield(double constant, double r)
{
    if (r<=20)
    {
        return (0.017*pow(r,4)-1.0533*pow(r,3)+24.042*pow(r,2)-243.87*r+975.88)*constant;
    }
    else if(r>20)
    {
        return (-0.4833*r+19.167)*constant;
    }
}

double yyy(double p,double q, double s)
{
    return q*cos(s/(sqrt((q*q+p*p)/2)));
}

double xxx(double p,double q, double s)
{
    return p*sin(s/(sqrt((p*p+q*q)/2)));
}
/// 데이터 26.03 -10.93 30 22 22.74 -14.34 234
/// 데이터 8.594 -21.078 30 22 3.008 -21.889 234

int main(void)
{
    double a,b,p,q,x1,y1,hall,r[5][5],magnet[5]={0,0,0,0,0};
    double xhall[5],xmag[5],yhall[5],ymag[5];
    printf("a,b,p,q,x1,y1,hall을 순서대로 입력하시오.");
    scanf("%lf %lf %lf %lf %lf %lf %lf",&a,&b,&p,&q,&x1,&y1,&hall);
    double st,ct,sp,cp,constant;
    st=sintheta(p,q,x1,y1);
    ct=costheta(p,q,x1,y1);
    sp=sinpi(a,b,x1,y1,st,ct);
    cp=cospi(a,b,x1,y1,st,ct);
    constant=c(sp,st,cp,st,a,b,p,q);
    for(int i=1;i<=5 ;i++)
    {
        xhall[i]=xxx(p,q,35+20*i);
        yhall[i]=yyy(p,q,35+20*i);
        xmag[i]=xxx(p,q,40+20*i);
        ymag[i]=yyy(p,q,40+20*i);
    }
    for(int i=1 ; i<=5 ; i++)
    {
        for(int j=1 ; j<=5 ; j++)
        {
            r[i][j]=sqrt((xhall[i]-xmag[j])*(xhall[i]-xmag[j])+(yhall[i]-ymag[j])*(yhall[i]-ymag[j]));
        }
    }
    for(int i=1;i<=5 ; i++)
    {
        for(int j=1 ; j<=5 ; j++)
        {
            magnet[i]+=magneticfield(constant,r[i][j]);
        }
    }
    for(int i=1;i<=5 ; i++)
    {
        printf("%d번째 홀센서의 5개 자석에 의한 자기장 : %f\n",i,magnet[i]);
    }
}
