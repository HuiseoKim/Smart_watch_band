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

double inverse(double hall,double constant)
{
    double cc=hall/constant;
    if(cc>10.3333&&cc<450)
    {
        return -9*pow(10,-7)*pow(cc,3)+0.0007*cc*cc-0.1886*cc+19.83;
    }
    else if(cc<10.3333)
    {
        return 0.3023*cc*cc-5.3941*cc+43.462;
    }
    else if (cc>450)
        return 4;
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

int main(void)
{
    double a,b,p,q,x1,y1,r[1000],rafter,magnet;
    int num=0;
    printf("a,b,p,q,x1,y1을 순서대로 입력하시오.");
    scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&p,&q,&x1,&y1);
    double st,ct,sp,cp,constant;
    st=sintheta(p,q,x1,y1);
    ct=costheta(p,q,x1,y1);
    sp=sinpi(a,b,x1,y1,st,ct);
    cp=cospi(a,b,x1,y1,st,ct);
    constant=c(sp,st,cp,st,a,b,p,q);
    for(int i=0 ; i<=400 ; i+=10)
    {
        num+=1;
        r[num]=inverse(i,constant);
    }
    num=0;
    for(int i=0 ; i<=400 ; i+=10)
    {
        num+=1;
        printf("%lf %d\n",r[num],i);
    }
    ///magnet=magneticfield(constant,r);
    ///printf("%lf \n",magnet);


}

/// 데이터 26.03 -10.93 30 22 22.74 -14.34 234
/// 데이터 8.594 -21.078 30 22 3.008 -21.889
