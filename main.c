
/**********************************************/
/*   C graduation project                     */
/*   Made by : ziyad khaled mohammed khafag   */
/*   Description: Bank System                 */
/*   Organization: IMT                        */
/*                                            */ 
/*   notes :                                  */
/*   admin ID =2003 ,admin password =2003     */  
/**********************************************/

#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include <math.h>
#include <stdbool.h>


node head;

void new_account (void)
{
	account new_acc;
	fflush(stdin);
	printf("please enter your full name : ");
    scanf("%[^\n]s",&new_acc.FullName);
	fflush(stdin);
	printf("please enter your address : ");
	gets (new_acc.Address);
	fflush(stdin);
	printf("please enter your age : ");
	scanf("%lu",&new_acc.Age);
	printf("please enter your National ID : ");
	scanf("%llu",&new_acc.NationalID);
    while (new_acc.NationalID >=99999999999999 || new_acc.NationalID <=10000000000000)
    {
        printf("Please enter your National ID contains 14 digit: ");
        scanf("%lld", &new_acc.NationalID);
    }
	if(new_acc.Age<21)
	{
		printf("please enter your guardian national ID : ");
		scanf("%llu",&new_acc.GuardianID);
    while (new_acc.GuardianID >=99999999999999 || new_acc.GuardianID <=10000000000000)
    {
        printf("Please enter your National ID contains 14 digit : ");
        scanf("%lld", &new_acc.GuardianID);
	}
	}
	else
	{
		new_acc.GuardianID=0;
	}
	printf("please enter your balance : ");
	scanf("%lf",&new_acc.Balance);
	new_acc.BankAccountID = 1000000000 + (rand()%9999999999);
	new_acc.Password = rand();
	new_acc.Status = active ;
	printf("---------------------------------- \n");
	printf("account created successfully \n");
	printf("your account ID : %llu  \n",new_acc.BankAccountID);
	printf ("your password : %u \n",new_acc.Password);
	new_user(new_acc);
    printf("---------------------------------- \n");	
}
/*----------------------------------------------------------------------*/
void make_transtion(u64 ID)
{
	node *client= GetUser(ID);
	u64 accountID;
	printf("Enter Client Bank Account ID to transfer money to: ");
    scanf("%lld", &accountID);
	node *User = GetUser(accountID);
	if (User)
	{
        printf("your Balance: %lf \n", client->value.Balance);
        printf("User Balance: %lf \n", User->value.Balance);

        f64 money;
        printf("Please enter the amount of money you want to transfer : ");
        scanf("%lf", &money);
        fflush(stdin);
        if (client->value.Balance >= money)
        {
			if ( client->value.Status == active && User->value.Status == active )
			{
            User->value.Balance += money;
            client->value.Balance -= money;
		printf("------------------------------------------------------------ \n");
		printf("transtion successed\n");
        printf("your Balance: %lf \n", client->value.Balance);
        printf("User Balance: %lf \n", User->value.Balance);
		printf("------------------------------------------------------------ \n");
            }
			else
			{   printf("------------------------------------------------------------ \n");
		        printf("transtion failed \n");
				printf("please make sure both accounts are active \n");
				printf("------------------------------------------------------------ \n");
			}
		}
        else
        {
			printf("------------------------------------------------------------ \n");
		    printf("transtion failed \n");
            printf("The amount you enter exceeds your balance\n");
			printf("------------------------------------------------------------ \n");
        }
        
	}	
}
/*----------------------------------------------------------------------*/
void change_status(u64 ID)
{
	node *client= GetUser(ID);
    u32 x;
    switch(client->value.Status)
	{
		case active :
		printf("Current Account Status is : Active \n");
		break ;
		case restricted :
		printf("Current Account Status is : Active \n");
		break ;
		case closed :
		printf("Current Account Status is : closed \n");
		break ;	
		
		
	};
    printf("Choose Status \n");
    printf("1: Set Account to Active \n");
    printf("2: Set Account to Restricted \n");
    printf("3: Set Account to Closed \n");
    printf("Your Choice : ");
    scanf("%u",&x);
    fflush(stdin);
	switch(x)
	{
    case 1:
       client->value.Status = active;
        break;
    case 2:
        client->value.Status = restricted;
        break;
    case 3:
        client->value.Status = closed;
        break;
    default:
        printf("Invalid Choice\n");
        break;
    }
    printf("------------------------------------\n");
	printf("Status changed successfully \n"); 
	 switch(client->value.Status)
	{
		case active :
		printf("Current Account Status is : Active \n");
		break ;
		case restricted :
		printf("Current Account Status is : Active \n");
		break ;
		case closed :
		printf("Current Account Status is : closed \n");
		break ;	
		
		
	};
	printf("------------------------------------\n");
}
   
    
/*----------------------------------------------------------------------*/
void get_cash(u64 ID)
{
	node *client= GetUser(ID);
	f64 money;
	printf("your current balance is : %lf \n",client->value.Balance);
	printf("please enter the amount you want to take : ");
	scanf ("%lf",&money);
	if (money<=client->value.Balance)
	{
		printf("------------------------------------\n");
		printf("successed\n");
		client->value.Balance -= money;
	}
	else
	{
		printf("the amount you enter is higher than your balance \n");
	}
	 printf("your current balance is : %.2lf \n",client->value.Balance);
	 printf("------------------------------------\n");
}
/*----------------------------------------------------------------------*/
void deposite (u64 ID)
{
	node *client= GetUser(ID);
	f64 money;
	printf("your current balance is : %lf \n",client->value.Balance);
	printf("please enter the amount you want to add : ");
	scanf ("%lf",&money);
	printf("------------------------------------\n");
	printf("successed\n");
	client->value.Balance += money;
	printf("your current balance is : %.2lf \n",client->value.Balance);
	printf("------------------------------------\n");
}
/*----------------------------------------------------------------------*/
void change_password(u64 ID)
{
	node *client= GetUser(ID);
	u32 old_password,new_password,check;
	printf("please enter your old password : ");
	scanf("%u",&old_password);
	if(client->value.Password == old_password)
	{
		printf("please enter your new password : ");
		scanf("%u",&new_password);
		printf("please enter confirm your  password : ");
		scanf("%u",&check);
		if (check==new_password)
		{
		client->value.Password = new_password;
		printf("------------------------------------\n");
		printf("password changed \n");
		printf("------------------------------------\n");
        }
    }
	else
	{
		printf("wrong password \n");
	}
}
/*----------------------------------------------------------------------*/
void open_account(void)
{
	u32 op;
	u64 account_id;
	printf("please enter your bank ID : ");
	scanf("%llu",&account_id);
	if(SearchUser(account_id))
	{
		printf("1: Make Transaction\n");
        printf("2: Change Account Status\n");
        printf("3: Get Cash\n");
        printf("4: Deposit in Account\n");
        printf("5: Return to main Menu\n");
		printf("------------------------ \n");
        printf("Your Choice: ");
        scanf("%d", &op);
		 fflush(stdin);
        switch (op)
        {
        case 1:
            make_transtion(account_id);
            break;
        case 2:
            change_status(account_id);
            break;
        case 3:
            get_cash(account_id);
            break;
        case 4:
            deposite(account_id);
            break;
        case 5:
            return;
            break;
        default:
            printf("invalid Choice\n");
            break;
        }
    }
    else
    {
        printf("Invalid Bank Account ID\n");
        return;
    }
	}
/*----------------------------------------------------------------------*/
void adimn_window (void)
{
	u32 x;
	u32 exit=0;
	while(exit==0)
	{
		printf("1- Create New Account    2- Open Exiting Account \n");
		printf("3- Exit System \n");
		scanf("%u",&x);
		switch (x)
		{
			case 1:
			new_account();
			break;
			case 2:
			open_account();
			break;
			case 3:
			exit =1;
			printf("------------------------------------ \n");
			break;
			default:
			printf("invalid choise \n");
		}
	}
	return ;
}
/*----------------------------------------------------------------------*/
void user_window(u64 accoutid)
{   
	u32 x;
	u32 exit=0;
	while(exit==0)
	{
	    printf("\n1: Make Transaction\n");
        printf("2: Change Account Password\n");
        printf("3: Get Cash\n");
        printf("4: Deposit in Account\n");
        printf("5: Return to main Menu\n");
        printf("Your Choice: ");
		scanf("%u",&x);
		switch (x)
		{
		case 1:
			make_transtion(accoutid);
			break;
		case 2:
			change_password(accoutid);
			break;
		case 3:
            get_cash(accoutid);
            break;
        case 4:
            deposite(accoutid);
            break;
        case 5:
            exit = 1;
			printf("------------------------------------\n");
            return;
        default:
            printf("Invalid Choice\n");
            break;
		}
	}
	return ;
}
/*----------------------------------------------------------------------*/
void start (void)
{
	u32 input;
    u32 ID, Password, UserPassword;
    u64 UserID;
    u32 Exit = 0;
    while (Exit == 0)
    {
        printf("1: Admin\n");
        printf("2: User\n");
        printf("3: Exit System \n");
        printf("Your Choice: ");
        scanf("%d", &input);
        fflush(stdin);
        switch (input)
        {
        case 1:
            printf("Enter Admin ID: ");
            scanf("%d", &ID);
            printf("Enter Admin Password: ");
            scanf("%d", &Password);
            if (ID == 2003 && Password == 2003)
            {
                adimn_window();
            }
            else
            {
                printf("Invalid ID or Password\n");
                start();
            }
            break;
        case 2:
            printf("Enter User Bank Account ID: ");
            scanf("%lld", &UserID);
            printf("Enter your Password: ");
             scanf("%d", &UserPassword);
            node *User = GetUser(UserID);
            if (User != NULL && User->value.Password == UserPassword)
            {
                user_window(UserID);
            }
            else
            {
                printf("Invalid ID or Password\n");
                start();
            }
            break;
        case 3:
	     	printf("------------------------------------\n");
            printf("Thank You ^_^ \n");
			printf("------------------------------------\n");
            Exit = 1;
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
	
}
/*----------------------------------------------------------------------------------------------*/
void main(void)
{
    start();
    return;
}