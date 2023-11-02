#include<stdio.h>
#include<ctype.h>
void FIRST(char[],char);
void addToResultSet(char[],char);
int numOfProductions;
char ProductionSet[10][10];
int main()
{
	int i;
	char choice;
	char c;
	char result[20];
	printf("How many number of Productions ? : ");
	scanf("%d",&numOfProductions);
	for(i=0;i<numOfProductions;i++)
	{
		printf("Enter productions Number %d : ",i+1);
		scanf("%s",ProductionSet[i]);
	}
	do
	{
		printf("\n Find the FIRST of : ");
		scanf(" %c%c",&c);
		FIRST(result,c);
		printf("\n FIRST( %c )= { ",c);
		for(i=0;result[i]!='\0';i++)
		printf(" %c ",result[i]);
		printf(" } \n");
		printf("Press y to continue : ");
		scanf("%c",&choice);
	}
	while(choice=='y'||choice=='Y');
}
void FIRST(char*Result,char c)
{
	int i,j,k;
	char subResult[20];
	int foundEpsilon;
	subResult[0]='\0';
	Result[0]='\0';
	if(!(isupper(c)))
	{
		addToResultSet(Result,c);
		return;
	}
	for(i=0;i<numOfProductions;i++)
	{
		if(ProductionSet[i][0]==c)
		{
			if (ProductionSet[i][2]=='$')
			addToResultSet(Result,'$');
			else
			{
				j=2;
				while(ProductionSet[i][j]!='\0')
				{
					foundEpsilon=0;
					FIRST(subResult,ProductionSet[i][j]);
					for(k=0;subResult[k!='\0'];k++)
					addToResultSet(Result,subResult[k]);
					for(k=0;subResult[k!='\0'];k++)
					if(subResult[k]=='$')
					{
						foundEpsilon=1;
						break;
					}
					if(!foundEpsilon)
					break;
					j++;
				}
			}
		}
	}
	return;
}
void addToResultSet(char Result[],char val)
{
	int k;
	for(k=0;Result[k]!='\0';k++)
	if(Result[k]==val)
	return;
	Result[k]=val;
	Result[k+1]='\0';
}