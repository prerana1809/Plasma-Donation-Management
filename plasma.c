#include<stdio.h>
#include<string.h>
void info()
{
    int age, weight;
    char ans, anss, name[20];
    char email, bt;
    double ph;

    printf("Blood Donation\n");
    printf("Name: ");
    scanf("%s",&name);
    printf("Age: ");
    scanf("%d",&age);
    if(age<18 || age>65){
        printf("Not eligible to donate blood\n");
        return ;
    }
    printf("Weight(in kg): ");
    scanf("%d", &weight);
    if(weight<50){
        printf("Not eligible to donate blood\n");
        return ;
    }
    printf("Have you had a prior diagnosis of COVID-19?(Y/N) ");
    scanf("%s",&ans);
    if(ans=='Y')
    {   printf("Have you recovered with complete resolution of symptoms at least 28 days before donation? (Y/N) ");
        scanf("%s",&anss);
        if(anss=='N') {
            printf("Not eligible to donate blood\n");
            return ;
        }
    }

    printf("Phone no.: ");
    scanf("%lf", &ph);
    printf("Email address: ");
    scanf("%s", &email);
    printf("Blood type: ");
    scanf("%s", &bt);

}
int main()
{
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1: 
        info();
        break;
    }

    return 0;
    
}
