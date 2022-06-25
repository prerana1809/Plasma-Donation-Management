#include<stdio.h>
#include<string.h>
#include <conio.h>
#include <stdlib.h>

struct record
{
    char name[30], email[50], bt[3];
    int age, weight;
    char ph[10];
};
struct record r, r1;

int ReadInt(char *message)
{
    char input[10];
    printf(message);
    gets(input);
    return atoi(input);
}

void ReadString(char *message, char *str)
{
    printf(message);
    gets(str);
}

int ReadYN(char *message)
{
    char input[10];
    printf(message);
    gets(input);
    return input[0]=='Y';
}


void donate()
{
    int ans, anss, can;
    FILE *fp;
    printf("BLOOD DONATION\n");
    printf("Before you proceed, some things to note: \n");
    printf("1. Plasma donation is a voluntary act and no inducement or remuneration will be offered.\n");
    printf("2. Your blood will undergo various screening tests required to ensure safety of the unit collected.\n");
    printf("3. Your blood will most likely be given to a patient, unknown to you, who will benefit from it.\n");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
 
    r.age=ReadInt("Age: ");
    if(r.age<18 || r.age>65){
        printf("Not eligible to donate blood\n");
        return ;
    }
    r.weight=ReadInt("Weight: ");
    if(r.weight<50){
        printf("Not eligible to donate blood\n");
        return ;
    }

    ans=ReadYN("Have you had a prior diagnosis of COVID-19?(Y/N): ");
    if(ans)
    {   
        anss=ReadYN("Have you recovered with complete resolution of symptoms at least 28 days before donation? (Y/N): ");
        if(!anss) {
            printf("Not eligible to donate blood\n");
            return ;
        }
        can=ReadYN("Are you a cancer survivor?(Y/N): ");
        if(can){
            printf("Not eligible to donate blood\n");
            return; 
        }
    }

    ReadString("Name: ", r.name);
    ReadString("Phone no.: ", r.ph);
    ReadString("Email: ", r.email);
    ReadString("Blood Type: ", r.bt);
    
    fp=fopen("Record.csv","a");
    fprintf(fp,"%s,%s,%s,%s\n",r.name,r.ph,r.email,r.bt);
    fclose(fp);
    printf("Congratulations, your initialisation process is complete. You will be notified of the date and day of the donation.");

}

void request()
{
    FILE *fp;
    FILE *fp1;
    char dummy;
    int count=0;
 
    printf("PLACE A REQUEST\n");
    ReadString("Name: ", r1.name);
    ReadString("Phone no.: ", r1.ph);
    ReadString("Email: ", r1.email);
    ReadString("Blood Type: ", r1.bt);

    fp=fopen("Request.csv","a");
    fprintf(fp,"%s,%s,%s,%s\n",r1.name,r1.ph,r1.email,r1.bt);
    fclose(fp);

    printf("Your request has been placed!\n");
    printf("Matching Donors: \n");
    
    fp1=fopen("Record.csv","r");
    while(1)
    {
        
        fscanf(fp1,"%[^,]%c%[^,]%c%[^,]%c%[^\n]%c",r.name, &dummy, r.ph, &dummy, r.email, &dummy, r.bt, &dummy);
        if(feof(fp1))
        {
            break;
        }

        if(strcmpi(r.bt, r1.bt)==0)
        {
            printf("%s,%s,%s,%s\n",r.name,r.ph,r.email,r.bt);
            count++;
        }
        
    }
    fclose(fp1);

    if(count==0)
    {
        printf("No Donors\n");
    }


   
    return ;
}

void view_all()
{
    char dummy;
    FILE *fp1;
    fp1=fopen("Record.csv","r");
    while(1)
    {
        
        fscanf(fp1,"%[^,]%c%[^,]%c%[^,]%c%[^\n]%c",r.name, &dummy, r.ph, &dummy, r.email, &dummy, r.bt, &dummy);
        if(feof(fp1))
        {
            break;
        }
        printf("%s,%s,%s,%s\n",r.name,r.ph,r.email,r.bt);
    }
    fclose(fp1);
}


int main()
{
    int n;
    printf("----------------------------------------WELCOME TO PLASMA DONATION MANAGEMENT----------------------------------------\n");
    while(1)
    {
        n=ReadInt("Which category of plasma donation do you want to read about?\n 1. Donate\n 2. Request\n 3. View All Donations\n 4. Exit\n ");
        switch(n)
        {
            case 1: donate();
                    break;
            case 2: request();
                    break;
            case 3: view_all();
                    break;
            case 4: return 0;
            default: printf("Invalid Input\n");
        }
    }
    return 0;
}
