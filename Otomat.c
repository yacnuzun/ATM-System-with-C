
#include <stdio.h>


struct CustomerAccount {
   int AccountNumber;
   char CustomerFullName[50];
   int Ballance;
};
static struct CustomerAccount sttcAccount[2];
struct CustomerAccount AddAccount(){
	
	struct CustomerAccount s1 = {1, "Yalçýn UZUN", 100};
	struct CustomerAccount s2 = {2, "Ceyda ÇOBAN", 100};
	
	sttcAccount[0]=s1;
	sttcAccount[1]=s2;
	return sttcAccount[2];
}



int SendMoney(struct CustomerAccount RecipientAccount,struct CustomerAccount SenderAccount,int Amount){
	SenderAccount.Ballance=SenderAccount.Ballance+Amount;
	RecipientAccount.Ballance=RecipientAccount.Ballance+Amount;
	return 0;
}

int Deposit(struct CustomerAccount Account,int Amount){
	Account.Ballance=Account.Ballance+Amount;
	return 0;
}

void LookBalance(struct CustomerAccount Account){
	
	printf("%d %s %d",Account.AccountNumber,Account.CustomerFullName,Account.Ballance);
}

int main() {
  // Create a structure variable and assign values to it
  AddAccount();
  
  LookBalance(sttcAccount[0]);
  printf("\n");
  printf("%s",sttcAccount[1].CustomerFullName);
  
  return 0;
}
