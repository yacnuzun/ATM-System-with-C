
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
	SenderAccount.Ballance=SenderAccount.Ballance-Amount;
	RecipientAccount.Ballance=RecipientAccount.Ballance+Amount;
	Set(SenderAccount.AccountNumber,Amount,"SendMoney","SenderAccount");
	Set(RecipientAccount.AccountNumber,Amount,"SendMoney","RecipientAccount");
	return 0;
}

void AddSet(int id,int amount){
	int i;
	for( i=0;i<2;++i){
		if(sttcAccount[i].AccountNumber==id)
		{
			
			sttcAccount[i].Ballance=sttcAccount[i].Ballance+amount;
			break;
		}
	}
}

void GetSet(int id, int amount){
	int i;
	for( i=0;i<2;++i){
		if(sttcAccount[i].AccountNumber==id)
		{
			
			sttcAccount[i].Ballance=sttcAccount[i].Ballance-amount;
			break;
		}
	}
}

void Set(int id,int amount,char process[50],char AccountType[50]){
	if(process=="Deposit"){
		AddSet(id,amount);
	}
	else{
		if(AccountType=="RecipientAccount"){
			AddSet(id,amount);
		}
		else{
			GetSet(id,amount);
		}
	}
		
}

int Deposit(struct CustomerAccount Account,int Amount){
	Account.Ballance=Account.Ballance+Amount;
	return Account.Ballance;
}

void LookBalance(struct CustomerAccount Account){
	
	printf("%d %s %d",Account.AccountNumber,Account.CustomerFullName,Account.Ballance);
}

int main() {
  AddAccount();
  
  SendMoney(sttcAccount[0],sttcAccount[1],100);
  
  
  
  LookBalance(sttcAccount[0]);
  printf("\n");
  printf("%s",sttcAccount[1].CustomerFullName);
  
  return 0;
}
