
#include <stdio.h>


struct CustomerAccount {
   int AccountNumber;
   char CustomerFullName[50];
   int Ballance;
};


static struct CustomerAccount sttcAccount[2];
struct CustomerAccount AddAccount(){
	
	struct CustomerAccount s1 = {1, "Yal��n UZUN", 100};
	struct CustomerAccount s2 = {2, "Ceyda �OBAN", 100};
	
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

struct CustomerAccount FindAccount(int id){
	int i;
	for( i=0;i<2;++i){
		if(sttcAccount[i].AccountNumber==id)
		{
			
			return sttcAccount[i];
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
	Set(Account.AccountNumber,Amount,"Deposit","Account");
	return Account.Ballance;
}

int Ask(){
	int process;
	printf("Bir i�lem se�iniz:\n");
	printf("1) Bakiye ��ren\n");
	printf("2) Para yat�r\n");
	printf("3) Ba�ka hesaba para transferi\n");
	scanf("%d", &process);
	return process;
}

int AnswerforSendMoney(){
	int sender,recipient,amount;
	printf("G�nderen Hesap:");
	scanf("%d", &sender);
	printf("\n");
	printf("Al�c� Hesap:");
	scanf("%d", &recipient);
	printf("\n");
	printf("Miktar:");
	scanf("%d", &amount);
	struct CustomerAccount senderAccount=FindAccount(sender);
	struct CustomerAccount recipientAccount=FindAccount(recipient);
	SendMoney(recipientAccount,senderAccount,amount);
	LookBalance(senderAccount);
	LookBalance(recipientAccount);
	
	return 0;
}

void Answer(int process){
				switch (process)
				{
    				case 1:
      				
      				break;

    				case 2:
     				
      				break;
    				
    				case 3:
     					AnswerforSendMoney();
      				break;
    
				}
}

void LookBalance(struct CustomerAccount Account){
	struct CustomerAccount fAccount=FindAccount(Account.AccountNumber);
	printf("%d %s %d",fAccount.AccountNumber,fAccount.CustomerFullName,fAccount.Ballance);
}

int main() {
  AddAccount();
  
  int answr=Ask();
  Answer(answr);
  return 0;
}
