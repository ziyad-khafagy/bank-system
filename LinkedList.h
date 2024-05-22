#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <stdbool.h>
#include "STD_TYPES.h"

enum Statu {active ,closed,restricted};
typedef struct 
{
    u8  FullName[80];
    u8  Address[80];
    u32 Age;
    u32 Password;
    u64 NationalID;
    u64 GuardianID;
    u64 BankAccountID;
    f64 Balance;
	enum Statu Status;
} account ;
typedef struct Node_type node;
struct Node_type
{
    account value;
    node *Next;
};

void new_user(account value);
bool SearchUser(u64 x);
node *GetUser(u64 y);


#endif