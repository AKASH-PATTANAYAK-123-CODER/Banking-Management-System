#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
void CreateAccount(void);
void showDetails(void);
void updateDetails(void);
void TranSaction_Withdraw_Deposit(void);
void About_Bank(void);
struct passbook{
    char name[100];
    char address[100];
    char phone_No[11];
    char adhaar_card_no[14];
    char pan_card_no [12];
    char type[20];
    long int Account_No;
    int age;
    double balance;
};
struct bankdetails{
    char bankname[28];
    char ifsc[15];
    char brunch[10];
    long int ac_no;
};
int main()
{
    system("cls");
    char str[]="bankcustomer";
    char pass[]="user@123";
    char ch[4];
    char usr[24],pa[25];
    int a,pr;
    printf("\t\t\t BANK OF KOLAGHAT\n\n\n");
    printf("\t\t\t BANK ADMIN LOGIN SECTION\n\n");
    printf("PLEASE ENTER USER ID :");
    scanf("%s",&usr);
    fflush(stdin);
    printf("PLEASE ENTER PASSWORD :");
    scanf("%s",&pa);
    if(strcmp(str,usr)==0 && strcmp(pass,pa)==0)
    {
    struct bankdetails b;
    FILE *f3=fopen("bank.txt","r");
    if(f3==0)
    {
    strcpy(b.bankname,"BANK OF KOLAGHAT");
    strcpy(b.ifsc,"BOK002028");
    strcpy(b.brunch,"KOLAGHAT");
    b.ac_no=16700000;
    f3=fopen("bank.txt","w");
    fwrite(&b,sizeof(b),1,f3);
    fclose(f3);
    }
    do
    {
    printf("\n\n\n");
    printf("\t\t\tMAIN MENU\n\n\n");
    printf("\t\tPress [1] for create account\n");
    printf("\t\tPress [2] for show datails of account\n");
    printf("\t\tPress [3] for update the account\n");
    printf("\t\tPress [4] for Transaction\n");
    printf("\t\tPress [5] for show About  Bank\n");
    printf("\t\tPress [6] for Log out\n");
    printf("Enter Your Choice :");
    scanf("%d",&a);
    system("cls");
    switch(a)
    {
        case 1:
        CreateAccount();
        break;
        case 2:
        showDetails();
        break;
        case 3:
        updateDetails();
        break;
        case 4:
        TranSaction_Withdraw_Deposit();
        break;
        case 5:
        About_Bank();
        break;
        case 6:
        exit(0);
        default:
        printf("You,Enter Inavalid option\n");

    }
    printf("\t\t\tPress 1 for back to Main Menu :");
        scanf("%d",&pr);
        if(pr==1)
         system("cls");
    }while(1);
    }

    else{
        printf("Please enter wright user id and password,Just Wait a moment..........\n");
        sleep(2);
        main();
    }
    return 0;
}
void About_Bank(void)
{
    struct bankdetails b;
     printf("\t\t*******ABOUT BANK DETAILS*******\n\n");
     FILE *f2=fopen("bank.txt","r");
     fread(&b,sizeof(b),1,f2);
     printf("\tBANK NAME : %s\n\n",b.bankname);
     printf("\tBRUNCH : %s\n\n",b.brunch);
     printf("\tIFSC CODE : %s\n\n",b.ifsc);
     fclose(f2);
     printf("\n\n");
}
void CreateAccount(void)
{
     printf("\t\t*******ACCOUNT CREATE SECTION*******\n\n");
    struct passbook p1;
    struct bankdetails ba;
     fflush(stdin);
    printf("Enter Name :");
    gets(p1.name);
    fflush(stdin);
    printf("Enter Age :");
    scanf("%d",&p1.age);
    fflush(stdin);
    printf("Enter Address :");
    scanf("%s",p1.address);
    fflush(stdin);
    printf("Enter Phone No :");
    scanf("%s",p1.phone_No);
    fflush(stdin);
    printf("Enter Addhar_Card_No :");
    scanf("%s",p1.adhaar_card_no);
    fflush(stdin);
    printf("Enter pancardno :");
    scanf("%s",p1.pan_card_no);
    fflush(stdin);
    printf("Enter account type :");
    scanf("%s",p1.type);
    fflush(stdin);
    printf("Enter minimum 2000 to open account :");
    scanf("%lf",&p1.balance);
    if(p1.balance>=2000)
     {
    FILE *f4=fopen("bank.txt","r");
    fread(&ba,sizeof(ba),1,f4);
    ba.ac_no++;
    p1.Account_No=ba.ac_no;
    fclose(f4);
    char user[30];
    sprintf(user,"%ld",ba.ac_no);
    f4=fopen("bank.txt","w");
    fwrite(&ba,sizeof(ba),1,f4);
    fclose(f4);
    FILE *f1=fopen(user,"w");
    fwrite(&p1,sizeof(p1),1,f1);
    fclose(f1);
    printf("\t\tAccount is Under Process.........\n");
    sleep(2);
    printf("\t\tAccount is created successfully\n\n");
    printf("\t\tYour Account No is: %ld\n\n",p1.Account_No);
    printf("\t\tPLEASE NOTE YOUR ACCOUNT_NO VERY CAREFULLY , FOR FURTHER OPERATION  THIS NO IS REQUIRED\n\n");
     }
     else
      printf("Sorrey,please deposit minimum 2000 to open account\n");
      printf("\n\n\n");
}

void showDetails(void)
{
    printf("\t\t*******ABOUT THE ACCOUNT SECTION*******\n\n\n");
    char s[25];
    printf("Enter Your Account No:");
    scanf("%s",&s);
    printf("\t\tWait,Fetching Your Details........\n\n");
    sleep(1);
    printf("\t\t*******ACCONT DETALIS*******\n\n");
    struct passbook u2;
    FILE *f2=fopen(s,"r");
    if(f2!=0)
    {
    fread(&u2,sizeof(u2),1,f2);
    printf("NAME:%s\n\n",u2.name);
    printf("AGE:%d\n\n",u2.age);
    printf("ADDRESS:%s\n\n",u2.address);
    printf("Phone No:%s\n\n",u2.phone_No);
    printf("Account No: %ld\n\n",u2.Account_No);
    printf("ADHAAR CARD NO: %s\n\n",u2.adhaar_card_no);
    printf("PAN CARD NO: %s\n\n",u2.pan_card_no);
    printf("ACCONT TYPE:%s\n\n",u2.type);
    printf("BALANCE :%lf\n\n",u2.balance);
    }
    else
    {
        printf("Sorrey,This account no is not available\n");
    }
     fclose(f2);

}

void updateDetails(void)
{
    char s[25],phNo[20],add[45],Actype[20];
    int a;
    struct passbook p2;
    printf("\t\t*******UPDATE SECTION*******\n\n");
    printf("Enter Your Account No:");
    scanf("%s",&s);
    FILE *f5=fopen(s,"r");
    fread(&p2,sizeof(p2),1,f5);
    fclose(f5);
    printf("\n\n");
    printf("\t\tPress [1] for update Mobile No\n");
    printf("\t\tPress [2] for update Address\n");
    printf("\t\tPress [3] for update Account Type\n");
    printf("\t\tPress [4] for update all three feilds\n\n");
    printf("\t\tEnter your Choice :");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
         printf("Enter updated Mobile No :");
         scanf("%s",phNo);
         strcpy(p2.phone_No,phNo);
         f5=fopen(s,"w");
         fwrite(&p2,sizeof(p2),1,f5);
         fclose(f5);
         break;

         case 2:
         printf("Enter updated Address :");
         scanf("%s",add);
         strcpy(p2.address,add);
         f5=fopen(s,"w");
         fwrite(&p2,sizeof(p2),1,f5);
         fclose(f5);
         break;

        case 3:
         printf("Enter updated Account Type :");
         scanf("%s",Actype);
         strcpy(p2.type,Actype);
         f5=fopen(s,"w");
         fwrite(&p2,sizeof(p2),1,f5);
         fclose(f5);
         break;

         default:
         printf("Enter updated Mobile No :");
         scanf("%s",phNo);
         fflush(stdin);
         printf("Enter updated Address :");
         scanf("%s",add);
         fflush(stdin);
         printf("Enter updated Account Type :");
         scanf("%s",Actype);
         fflush(stdin);
         strcpy(p2.phone_No,phNo);
         strcpy(p2.address,add);
         strcpy(p2.type,Actype);
         f5=fopen(s,"w");
         fwrite(&p2,sizeof(p2),1,f5);
         fclose(f5);
    }
    sleep(1);
     printf("\t\t*******UPDATE SUCCESFULLY*******\n\n");

}

void TranSaction_Withdraw_Deposit(void)
{
    double rup;
    char nm[19];
    int fu=0;
    int a;
    struct passbook p;
    printf("\t\t*******TRANSACTION SECTION*******\n\n");
    printf("\t\tPress [1] for Deposit Money\n");
    printf("\t\tPress [2] for Withdraw Money\n\n");
    printf("Enter Your Choice :");
    scanf("%d",&a);
    printf("Please Enter The Account No :");
    scanf("%s",&nm);
    FILE *f1=fopen(nm,"r");
    if(f1!=0)
    {
    printf("Please Enter The Amount :");
    scanf("%lf",&rup);
    fread(&p,sizeof(p),1,f1);
    fclose(f1);
    switch(a)
    {
        case 1:
        p.balance+=rup;
        f1=fopen(nm,"w");
        fwrite(&p,sizeof(p),1,f1);
        fclose(f1);
        break;

        case 2:
        if(p.balance-rup<0)
        {
            printf("Sorrey,Withdraw is Not possib;e for shortage of Money\n\n");
            fu=3;
            break;
        }
        p.balance-=rup;
        f1=fopen(nm,"w");
        fwrite(&p,sizeof(p),1,f1);
        fclose(f1);
        break;

        default:
         printf("Sorrey,You press false Key\n");
         fu=1;

    }
    if(fu==0)
     {
     printf("\t\t *******TRANSACTION SUCCESSFULL*******\n");
     if(a==1)
      printf("\t%lf is deposit in your Account,Your current balance is :%lf\n\n",rup,p.balance);
     else
        printf("\t%lf is withdraw from your Account,Your current balance is :%lf\n\n",rup,p.balance);
     }
    }
    else
    {
        printf("Sorrey,The Account No is Not Available\n\n");
    }
   
     
}