#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define M 20

//---------------------------------------------------- Struct definitions ----------------------------------------------------//
// Contains customer data
typedef struct client{

float balance;
char name[M];

}client;

//---------------------------------------------------- Signature Fuctions ----------------------------------------------------//
int register_client(char *costumer,float *balance);
int withdraw(client *data,int person);
int deposit(client *data,int person);
int check_balance(client *data,int person);
int delele_client(client *data,int *person,int *e);

// ----------------------------------------------------------- CODE ----------------------------------------------------------//
// Fuctions

int register_client(char *costumer,float *balance){
/*
Receives space from the “date” vector for the customer's name and balance, and enters it in the “date” vector.
*/
    char name_true[4];

    do{
        system ("cls");
        printf("|-------------------------------- Register Costumers --------------------------------|\n\n");
        printf("What will be the name of the account holder? ");
        gets(costumer);
        printf("\n\nYour name really is %s(yes or no)? ",costumer);
        gets(name_true);
    }while(strcmp(name_true,"yes")!=0);
    *balance=0.0;

     printf("\nHello %s, we have successfully created your account!\nYour current balance is R$ %.2f\n", costumer,*balance);
     printf("Press any key to continue...");
     getche();

     return 0;

}

int withdraw(client *data,int person){
/*
Receives the customer's name and searches the database for its existence; if it exists,
it executes the action; if not, it informs and cancels the action.
*/
    char name_client[M];
    char really[4];
    system("cls");
    printf("|-------------------------------- Cash withdraw --------------------------------|\n\n");
    int money;
    printf("What's the name of the account holder? ");
    gets(name_client);

    for(int i=0;i<person;i++){//Search for a person based on their name
        if(strcmp(data[i].name,name_client)==0){
            printf("\nAttention: It's only possible to withdraw the amount in banknotes.");
            printf("\n\nHow much do you want to withdraw? ");
            scanf("%d",&money);// Take the amount to withdraw
            int withdrawal=money;
            getchar();
            if(data[i].balance<money || money<0)  {//Check if the action was valid
                printf("\nOperation performed without success...\n\n");
                Sleep(2000);
                if(data[i].balance<money) {
                        printf("\n\nInsufficient balance\n\n");
                        printf("Press any key to continue...");
                        getche();
                        return 0;
                }
                else {
                    printf("\n\nInvalid cash withdrwal\n\n");
                    printf("Press any key to continue...");
                    getche();
                    return 0;
                }
            }
                // Counts how many notes of each type will be delivered
                int hundred=0,fifty=0,twenty=0,ten=0,five=0,two=0;

                if(withdrawal%10==3 || withdrawal%10==1) withdrawal--;//if the amount ends with 3 or 1

                    for(int i=0; withdrawal>0;i++){
                        if(withdrawal>=100){
                            hundred++;
                            withdrawal-=100;
                        }
                        else if(withdrawal>=50) {
                            fifty++;
                            withdrawal-=50;
                        }else if(withdrawal>=20) {
                            twenty++;
                            withdrawal-=20;
                        }else if(withdrawal>=10) {
                            ten++;
                            withdrawal-=10;
                       } else if(withdrawal>=5) {
                            five++;
                            withdrawal-=5;
                        }else if(withdrawal>=2){
                            two++;
                            withdrawal-=2;
                        }
                    }

                    /*/If the amount ends with 3 or 1,
                    it informs you that it will not be possible to print
                    everything and suggests a new withdrawal,
                    substituting 1 unit to deliver everything in ballots
                    */
                    if(money%10==3 || money%10==1){
                            printf("Sorry... It was not possible to withdraw the full value\n Do you accept receiving R$ %d(yes or no)?",money-1);
                            do{
                                gets(really);
                            }while(strcmp(really,"yes")!=0 && strcmp(really,"no")!=0);

                            if(strcmp(really,"no")==0){
                                printf("\n\nOperation canceled successfully!!!\n\n");
                                printf("Press any key to continue...");
                                getche();
                                return 0;
                            }else{
                                    int money_2=money-1;
                                    data[i].balance=data[i].balance-money_2;//debits the new amount from the account
                                    printf("\nWithdraw made successfully!!!\n\n");
                                    printf("\nYou will receive: \n\n");

                                        //Print how many notes of each type will be delivered
                                        if(hundred==1){ printf("%d note of R$ 100.00\n",hundred);}
                                        else if(hundred!=0) printf("%d notes of R$ 100.00\n",hundred);
                                        if(fifty==1) printf("%d note of R$ 50.00\n",fifty);
                                        else if(fifty!=0) printf("%d notes of R$ 50.00\n",fifty);
                                        if(twenty==1) printf("%d note of R$ 20.00\n",twenty);
                                        else if(twenty!=0) printf("%d notes of R$ 20.00\n",twenty);
                                        if(ten==1) printf("%d note of R$ 10.00\n",ten);
                                        else if(ten!=0) printf("%d notes of R$ 10.00\n",ten);
                                        if(five==1) printf("%d note of R$ 5.00\n",five);
                                        else if(five!=0) printf("%d notes of R$ 5.00\n",five);
                                        if(two==1) printf("%d note of R$ 2.00\n",two);
                                        else if(two!=0) printf("%d notes of R$ 2.00\n",two);


                                    printf("\nYour currently balance is R$ %.2f\n\n",data[i].balance);
                                    printf("Press any key to continue...");
                                    getche();

                                    return 1;
                            }
                    }else{

                                    //Debit the original value if it doesn't end with 3 or 1
                                    data[i].balance=data[i].balance-money;
                                    printf("\nWithdraw made successfully!!!\n\n");
                                    printf("\nYou will receive: \n\n");

                                        //Print how many notes of each type will be delivered
                                        if(hundred==1){ printf("%d note of R$ 100.00\n",hundred);}
                                        else if(hundred!=0) printf("%d notes of R$ 100.00\n",hundred);
                                        if(fifty==1) printf("%d note of R$ 50.00\n",fifty);
                                        else if(fifty!=0) printf("%d notes of R$ 50.00\n",fifty);
                                        if(twenty==1) printf("%d note of R$ 20.00\n",twenty);
                                        else if(twenty!=0) printf("%d notes of R$ 20.00\n",twenty);
                                        if(ten==1) printf("%d note of R$ 10.00\n",ten);
                                        else if(ten!=0) printf("%d notes of R$ 10.00\n",ten);
                                        if(five==1) printf("%d note of R$ 5.00\n",five);
                                        else if(five!=0) printf("%d notes of R$ 5.00\n",five);
                                        if(two==1) printf("%d note of R$ 2.00\n",two);
                                        else if(two!=0) printf("%d notes of R$ 2.00\n",two);


                                    printf("\nYour currently balance is R$ %.2f\n\n",data[i].balance);
                                    printf("Press any key to continue...");
                                    getche();

                                    return 1;
                    }

        }
    }
    //Cancel the action
    printf("\n\nOperation performed without success... \n\n");
    Sleep(2000);
    printf("You don't have an account yet\n\n");
    printf("Press any key to continue...");
    getche();
    return 0;



}

int deposit(client *data,int person){
    /*
    Receives the customer's name and searches the database for its existence;
    if the person exists make the deposit if not inform and cancel the action
    */


    char costumer[M];
    system("cls");
    printf("|-------------------------------- Deposit --------------------------------|\n\n");

    printf("What's the name of the account holder? ");
    gets(costumer);

    float balance;

    for(int i=0;i<person;i++){//Search for a person based on their name
        if(strcmp(data[i].name,costumer)==0){//Find a person

            printf("\n\nHow much do you want to deposit? ");
            scanf("%f",&balance);
            getchar();
            if(balance<0)  {//Check if the action was valid
                printf("\nOperation performed without success...\n\n");
                Sleep(2000);

                    printf("\n\nInvalid deposit\n\n");
                    printf("Press any key to continue...");
                    getche();
                    return 0;

            }
            data[i].balance+=balance;//Deposit in the "data base"

            printf("\nDeposit made successfully!!!\n\n");
            printf("Press any key to continue...");
            getche();
            return 1;

        }
    }
    //Cancel the action
    printf("\n\nOperation performed without success... \n\n");
    Sleep(2000);
    printf("You don't have an account yet\n\n");
    printf("Press any key to continue...");
    getche();
    return 0;

}
int check_balance(client *data,int person){
    /*
    Receives the customer's name and searches the database for its existence;
    If the person exists, check their balance
    */

    char costumer[M];
    system("cls");
    printf("|-------------------------------- Check Balance --------------------------------|\n\n");

    printf("What's the name of the account holder? ");
    gets(costumer);

    for(int i=0;i<person;i++){
        if(strcmp(data[i].name,costumer)==0){//Search for a person based on their name
            printf("\nOperation successfully completed!!!\n\n");
            Sleep(2000);
            printf("This is your balance: R$ %.2f \n\n",data[i].balance);//shows the balance
            printf("Press any key to continue...");
            getche();
            return 1;

        }
    }
    //Cancel the action
    printf("\n\nOperation performed without success... \n\n");
    Sleep(2000);
    printf("You don't have an account yet\n\n");
    printf("Press any key to continue...");
    getche();
    return 0;



}
int delete_client(client *data,int *person,int *e){

    /*
    Receives the customer's name and searches the database for its existence;
    If it exists, ask yourself if you really want to do it; if so, do it; if not, cancel it;
    if it doesn't exist, cancel the action
    */
    char costumer[M],really[4];
    system("cls");
    printf("|-------------------------------- Account Deletion --------------------------------|\n\n");

        do{
            printf("Are you sure about this(yes or no)? ");//ask yourself if you're sure
            gets(really);
        }while(strcmp(really,"yes")!=0 && strcmp(really,"no")!=0);

        if(strcmp(really,"no")==0){    //Cancel the action
            printf("\n\nExcellent, we will do best to improve our service!!! ");
            printf("\n\nPress any key to continue...");
            getche();
            return 0;
        }else {

            printf("\n\nWhat's the name of the account holder? ");
            gets(costumer);

            for(int i=0;i<*person;i++){
                if(strcmp(data[i].name,costumer)==0){//Search for a person based on their name
                    for(int j=i;j<*person-1;j++){

                /*overwrites the next person on top of the deleted one
                and rewrites the entire customer list without the deleted one*/

                       data[j]=data[j+1];
                    }
                    printf("\nOperation successfully completed\n");
                    Sleep(2000);
                    printf("\nPlease, consider creating an account with us again...\n\n");
                    (*person)--;
                    (*e)--;
                    printf("Press any key to continue...");
                    getche();
                    return 1;

                }
            }
                //Cancel the action
            printf("\n\nOperation performed without success... \n\n");
            Sleep(2000);
            printf("You don't have an account yet\n\n");
            printf("Press any key to continue...");
            getche();
            return 0;

}

}


// ------------------------------------------ MAIN ------------------------------------------ //

int main()
{
SetConsoleTitle("Banking System");

    client *data;
    int person=0;
    int menu_num,i=-1;

    data=(client*)malloc(1*sizeof(client)); //Create in memory for each the first person


    while(1){
    do{//Menu for actions
        system ("cls");
        printf("|-------------------------- Welcome to the our Banking System--------------------------|\n\n");
        printf("1. Create an account\n");
        printf("2. Withdraw\n");
        printf("3. Deposit\n");
        printf("4. Check Balance\n");
        printf("5. Delete account\n");
        printf("6. Exit\n\n");
        printf(" Choose what you will do: ");
        scanf("%d",&menu_num);
        getchar();
    }while(menu_num!=1 && menu_num!=2 && menu_num!=3 && menu_num!=4 && menu_num!=5 && menu_num!=6 && menu_num!=72127);

    if(menu_num==72127){//Code for adm to check costumers records
        for(int c=0;c<person;c++){
            printf("| Client: %s  | Balance: %.2f |\n",data[c].name,data[c].balance);
        }
        if(person==0) printf("We are currently without costumers...\n");
        getche();
    }

    if(menu_num==1){
        i++;//Go through my "data" vector
        person++;//Count how many person will register
        data=(client*)realloc(data,person*sizeof(client)); //Create in memory for each new person
        if(data==NULL){//Verific the Memory Allocation Failure
            i--;
            person--;
            printf("Operation performed without successfully...\n");
            printf("Sorry... We need to restart the system...");
            exit(EXIT_FAILURE);
        }
        register_client(data[i].name,&data[i].balance);//Register the costumer in the system

    }else if(menu_num==2){
        withdraw(data,person);//Perceive the withdraw

    }else if(menu_num==3){
        deposit(data,person);//Perceive the deposit

    }else if(menu_num==4){
        check_balance(data,person);//Check the user's balance

    }else if(menu_num==5){
        delete_client(data,&person,&i);//Remove costumer account

    }else if(menu_num==6){//Close the program
        printf("\nThank you, please continue using our banking system!\n\n");
        Sleep(3000);

        free(data);//Clear memory
        return 0;
    }
    }

}
