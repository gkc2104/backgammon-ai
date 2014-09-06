#include<stdio.h>
#include<string.h>

typedef struct node
{
	int board[25];
	int pb;
	int nb;
	int m1[2];
	int m2[2];
	int moves;
} node;
int i_board[25];
int r1;
int r2;
int ipb;
int inb;

node s[30];
int cnt;

void getStates();
void printStates();

int main()
{
	int i;
	char aba[1000];
	for(i=1;i<=24;i++)
	{
		scanf("%d",&i_board[i]);
	}
	scanf("%s",aba);
	scanf("%d %d",&r1,&r2);
	int sum=0;
	for(i=0;i<strlen(aba);i++)
	{
		if(aba[i]=='a')
			ipb++;
		else if(aba[i]=='b')
			inb++;
	}
	for(i=1;i<=18;i++)
	{
		if(i_board[i] <= 0)
			sum++;
	}
	int bear_flag=0;
	if(sum == 18 && ipb == 0)
		bear_flag=1;
	if(bear_flag==0)
	{
		getStates();
		printStates();
		int max=utility(0);
		int maxi=0;
		for(i=1;i<cnt;i++)
		{
			if(utility(i)>max)
			{
				max=utility(i);
				maxi=i;
			}
		}
		if(s[maxi].m1[0]==0 && s[maxi].m1[1]==0)
		{
			printf("pass\n");
			return 0;
		}
		else
		{
			if(s[maxi].m1[0]==0)
				printf("Z ");
			else
				printf("%d ",s[maxi].m1[0]);
			if(s[maxi].m1[1]==0)
				printf("Z\n");
			else
				printf("%d\n",s[maxi].m1[1]);
		}
		if(s[maxi].m2[0]==0 && s[maxi].m2[1]==0)
		{
			printf("pass\n");
			return 0;
		}
		else
		{
			if(s[maxi].m2[0]==0)
				printf("Z ");
			else
				printf("%d ",s[maxi].m2[0]);
			if(s[maxi].m2[1]==0)
				printf("Z\n");
			else
				printf("%d\n",s[maxi].m2[1]);
		}

		return 0;
	}
	else
	{
		int t1,t2,kamal=0;
		if(r1 <= r2)
		{
			t1 = r1;
			t2 = r2;
		}
		else
		{
			t1 = r2;
			t2 = r1;
		}
		if(i_board[25-t1] > 0)
		{
			i_board[25-t1]--;
			printf("%d %d\n",25-t1,0);
		}
		else
		{
			for(i=24-t1;i>=19;i--)
			{
				if(i_board[i] > 0)
				{
					i_board[i]--;
					i_board[i+t1]++;
					printf("%d %d\n",i,i+t1);
					break;
				}
			}

		}
		kamal=0;
		if(i_board[25-t2] > 0)
		{
			i_board[25 - t2]--;
			printf("%d %d\n",25-t2,0);
		}
		else
		{
			for(i=24-t2;i>=19;i--)
			{
				if(i_board[i] > 0)
				{
					i_board[i]--;
					i_board[i+t2]++;
					kamal = 1;
					printf("%d %d\n",i,i+t2);
					break;
				}
			}
			if(kamal == 0)
			{
				printf("pass\n");
			}
		}
	}
}

void getStates()
{
	int i;
	if(ipb>=2)
	{
		if(i_board[r1]>=0 && i_board[r2]>=0)
		{
			s[cnt].pb=ipb-2;
			s[cnt].nb=inb;
			for(i=1;i<=24;i++)
				s[cnt].board[i]=i_board[i];
			s[cnt].board[r1]++;
			s[cnt].moves=2;
			s[cnt].m1[0]=0;
			s[cnt].m1[1]=r1;
			s[cnt].m1[0]=0;
			s[cnt].m1[1]=r2;
			s[cnt++].board[r2]++;
		}
		else if(i_board[r1]>=0)
		{
			s[cnt].pb=ipb-1;
			s[cnt].nb=inb;
			for(i=1;i<=24;i++)
				s[cnt].board[i]=i_board[i];
			s[cnt].moves=1;
			s[cnt].m1[0]=0;
			s[cnt].m1[1]=r1;
			s[cnt].m1[0]=0;
			s[cnt].m1[1]=0;
			s[cnt++].board[r1]++;
		}
		else if(i_board[r2]>=0)
		{
			s[cnt].pb=ipb-1;
			s[cnt].nb=inb;
			for(i=1;i<=24;i++)
				s[cnt].board[i]=i_board[i];
			s[cnt].moves=1;
			s[cnt].m1[0]=0;
			s[cnt].m1[1]=r2;
			s[cnt].m1[0]=0;
			s[cnt].m1[1]=0;
			s[cnt].board[r2]++;
		}
		else if(i_board[r1+r2]>=0)
		{
			s[cnt].pb=ipb-1;
			s[cnt].nb=inb;
			for(i=1;i<=24;i++)
				s[cnt].board[i]=i_board[i];
			s[cnt].moves=1;
			s[cnt].m1[0]=0;
			s[cnt].m1[1]=r1+r2;
			s[cnt].m1[0]=0;
			s[cnt].m1[1]=0;
			s[cnt].board[r1+r2]++;
		}
		if(i_board[r1]==-1 && i_board[r2]==-1)
		{
			s[cnt].pb=ipb-2;
			s[cnt].nb=inb+2;
			for(i=1;i<=24;i++)
				s[cnt].board[i]=i_board[i];
			s[cnt].moves=1;
			s[cnt].m1[0]=0;
			s[cnt].m1[1]=r1;
			s[cnt].m1[0]=0;
			s[cnt].m1[1]=r2;
			s[cnt].board[r1]=1;
			s[cnt++].board[r2]=1;
		}
		else if(i_board[r1]==-1)
		{
			s[cnt].pb=ipb-1;
			s[cnt].nb=inb+1;
			for(i=1;i<=24;i++)
				s[cnt].board[i]=i_board[i];
			s[cnt].moves=1;
			s[cnt].m1[0]=0;
			s[cnt].m1[1]=r1;
			s[cnt].m2[0]=0;
			s[cnt].m2[1]=0;
			s[cnt++].board[r1]=1;
		}
		else if(i_board[r2]==-1)
		{
			s[cnt].pb=ipb-1;
			s[cnt].nb=inb+1;
			for(i=1;i<=24;i++)
				s[cnt].board[i]=i_board[i];
			s[cnt].moves=1;
			s[cnt].m1[0]=0;
			s[cnt].m1[1]=r2;
			s[cnt].m2[0]=0;
			s[cnt].m2[1]=0;
			s[cnt++].board[r2]=1;
		}
		else
			return;
	}
	else if(ipb==1)
	{
		if(i_board[r1]>=-1 && i_board[r2]>=-1)
		{
			int check=0;
			node dummy;
			dummy.pb=ipb-1;
			dummy.nb=inb;
			int j;
			for(j=1;j<=24;j++)
				dummy.board[j]=i_board[j];
			dummy.moves=1;
			dummy.m1[0]=0;
			dummy.m1[1]=r1;
			dummy.m2[0]=0;
			dummy.m2[1]=0;
			if(i_board[r1]==-1)
			{
				dummy.nb++;
				dummy.board[r1]=1;
			}
			for(j=1;j<=24;j++)
			{
				check=1;

				if(dummy.board[j+r2]>=-1)
				{
					s[cnt].pb=dummy.pb;
					s[cnt].nb=dummy.nb;
					int k;
					for(k=1;k<=24;k++)
						s[cnt].board[k]=dummy.board[k];
					s[cnt].board[j+r2]++;
					s[cnt].board[j]--;
					s[cnt].moves=1;
					s[cnt].m1[0]=0;
					s[cnt].m1[1]=r1;
					s[cnt].m2[0]=j;
					s[cnt].m1[0]=j+r2;
					check=1;
					if(dummy.board[j+r2]==-1)
					{
						s[cnt].nb++;
						s[cnt].board[j+r2]=1;
					}
					cnt++;
				}
			}
			if(check==0)
			{
				s[cnt].pb=ipb-1;
				s[cnt].nb=inb;
				for(j=1;j<=24;j++)
					s[cnt].board[j]=i_board[j];
				s[cnt].board[r1]++;
				s[cnt].moves=1;
				s[cnt].m1[0]=0;
				s[cnt].m1[0]=r1;
				s[cnt].m1[0]=0;
				s[cnt].m1[0]=0;
				if(i_board[i+r1]==-1)
				{
					s[cnt].nb++;
					s[cnt].board[r1]=1;
				}
				cnt++;
			}
			dummy.pb=ipb-1;
			dummy.nb=inb;
			for(j=1;j<=24;j++)
				dummy.board[j]=i_board[j];
			dummy.moves=1;
			dummy.m1[0]=0;
			dummy.m1[1]=r2;
			dummy.m2[0]=0;
			dummy.m2[1]=0;
			if(i_board[r2]==-1)
			{
				dummy.nb++;
				dummy.board[r2]=1;
			}
			for(j=1;j<=24;j++)
			{
				check=1;

				if(dummy.board[j+r1]>=-1)
				{
					s[cnt].pb=dummy.pb;
					s[cnt].nb=dummy.nb;
					int k;
					for(k=1;k<=24;k++)
						s[cnt].board[k]=dummy.board[k];
					s[cnt].board[j+r1]++;
					s[cnt].board[j]--;
					s[cnt].moves=1;
					s[cnt].m1[0]=0;
					s[cnt].m1[1]=r2;
					s[cnt].m2[0]=j;
					s[cnt].m1[0]=j+r1;
					check=1;
					if(dummy.board[j+r1]==-1)
					{
						s[cnt].nb++;
						s[cnt].board[j+r1]=1;
					}
					cnt++;
				}
			}
			if(check==0)
			{
				s[cnt].pb=ipb-1;
				s[cnt].nb=inb;
				for(j=1;j<=24;j++)
					s[cnt].board[j]=i_board[j];
				s[cnt].board[r2]++;
				s[cnt].moves=1;
				s[cnt].m1[0]=0;
				s[cnt].m1[0]=r2;
				s[cnt].m1[0]=0;
				s[cnt].m1[0]=0;
				if(i_board[i+r2]==-1)
				{
					s[cnt].nb++;
					s[cnt].board[r2]=1;
				}
				cnt++;
			}
		}
		else if(i_board[r1]>=-1 || i_board[r2]>=-1);
		{
			if(i_board[r1]>=-1)
			{
				s[cnt].pb=ipb-1;
				s[cnt].nb=inb;
				int j;
				for(j=1;j<=24;j++)
					s[cnt].board[j]=i_board[j];
				s[cnt].moves=1;
				s[cnt].m1[0]=0;
				s[cnt].m1[1]=r1;
				s[cnt].m2[0]=0;
				s[cnt].m2[1]=0;
				if(i_board[r1]==-1)
				{
					s[cnt].nb++;
					s[cnt].board[r1]=1;
				}
				cnt++;
			}
			else if(i_board[r2]>=-1)
			{
				s[cnt].pb=ipb-1;
				s[cnt].nb=inb;
				int j;
				for(j=1;j<=24;j++)
					s[cnt].board[j]=i_board[j];
				s[cnt].moves=1;
				s[cnt].m1[0]=0;
				s[cnt].m1[1]=r2;
				s[cnt].m2[0]=0;
				s[cnt].m2[1]=0;
				if(i_board[r1]==-1)
				{
					s[cnt].nb++;
					s[cnt].board[r2]=1;
				}
				cnt++;
			}
		}
	}
	else
	{
		for(i=1;i<=24;i++)
		{
			if(i_board[i]<=0)
				continue;
			if(i+r1>24 || i+r2>24)
				continue;
			if(i_board[i+r1]>=-1 )
			{
				int j;
				int check=0;
				node dummy;
				dummy.pb=ipb;
				dummy.nb=inb;
				for(j=1;j<=24;j++)
					dummy.board[j]=i_board[j];
				dummy.board[i]--;
				dummy.board[i+r1]++;
				dummy.moves=1;
				dummy.m1[0]=i;
				dummy.m1[1]=i+r1;
				dummy.m2[0]=0;
				dummy.m2[1]=0;
				if(i_board[i+r1]==-1)
				{
					dummy.nb++;
					dummy.board[i+r1]=1;
				}
				for(j=i;j<=24;j++)
				{
					if(dummy.board[j]<=0)
						continue;
					check=1;
					if(j+r2>24)
						continue;
					if(dummy.board[j+r2]>=-1)
					{
						s[cnt].pb=dummy.pb;
						s[cnt].nb=dummy.nb;
						int k;
						for(k=1;k<=24;k++)
							s[cnt].board[k]=dummy.board[k];
						s[cnt].board[j]--;
						s[cnt].board[j+r2]++;
						s[cnt].moves=2;
						s[cnt].m1[0]=i;
						s[cnt].m1[1]=i+r1;
						s[cnt].m2[0]=j;
						s[cnt].m2[1]=j+r2;
						check=1;
						if(dummy.board[j+r2]==-1)
						{
							s[cnt].nb++;
							s[cnt].board[j+r2]=1;
						}
						cnt++;
					}
				}
				if(check==0)
				{
					s[cnt].pb=ipb;
					s[cnt].nb=inb;
					for(j=1;j<=24;j++)
						s[cnt].board[j]=i_board[j];
					s[cnt].board[i]--;
					s[cnt].board[i+r1]++;
					s[cnt].moves=1;
					s[cnt].m1[0]=i;
					s[cnt].m1[1]=i+r1;
					s[cnt].m2[0]=0;
					s[cnt].m2[1]=0;
					if(i_board[i+r1]==-1)
					{
						s[cnt].nb++;
						s[cnt].board[i+r1]=1;
					}
					cnt++;
				}
			}
			if(i_board[i+r2]>=-1)
			{
				int j;
				int check=0;
				node dummy;
				dummy.pb=ipb;
				dummy.nb=inb;
				for(j=1;j<=24;j++)
					dummy.board[j]=i_board[j];
				dummy.board[i+r2]++;
				dummy.board[i]--;
				dummy.moves=1;
				dummy.m1[0]=i;
				dummy.m1[1]=i+r2;
				dummy.m2[0]=0;
				dummy.m2[1]=0;
				if(i_board[i+r2]==-1)
				{
					dummy.nb++;
					dummy.board[i+r2]=1;
				}
				for(j=i;j<=24;j++)
				{
					if(dummy.board[j]<=0)
						continue;
					if(j+r1>24)
						continue;
					if(i_board[j+r1]>=-1)
					{
						s[cnt].pb=dummy.pb;
						s[cnt].nb=dummy.nb;
						int k;
						for(k=1;k<=24;k++)
							s[cnt].board[k]=dummy.board[k];
						s[cnt].board[j+r1]++;
						s[cnt].board[j]--;
						s[cnt].moves=2;
						s[cnt].m1[0]=i;
						s[cnt].m1[1]=i+r2;
						s[cnt].m2[0]=j;
						s[cnt].m2[1]=j+r1;
						check=1;
						if(dummy.board[j+r2]==-1)
						{
							s[cnt].nb++;
							s[cnt].board[j+r1]=1;
						}
						cnt++;
					}
				}
				if(check==0)
				{
					s[cnt].pb=ipb;
					s[cnt].nb=inb;
					for(j=1;j<=24;j++)
						s[cnt].board[j]=i_board[j];
					s[cnt].board[i+r2]++;
					s[cnt].board[i]--;
					s[cnt].moves=1;
					s[cnt].m1[0]=i;
					s[cnt].m1[1]=i+r2;
					s[cnt].m2[0]=0;
					s[cnt].m2[1]=0;
					if(i_board[j+r2]==-1)
					{
						s[cnt].nb++;
						s[cnt].board[i+r2]=1;
					}
					cnt++;
				}
			}
			if(i+r1+r2>24)
				continue;
			if(i_board[i+r1+r2]>=-1)
			{
				s[cnt].pb=ipb;
				s[cnt].nb=inb;
				int j;
				for(j=1;j<=24;j++)
					s[cnt].board[j]=i_board[j];
				s[cnt].board[i+r1+r2]++;
				s[cnt].board[i]--;
				s[cnt].moves=2;
				s[cnt].m1[0]=i;
				s[cnt].m1[1]=i+r2;
				s[cnt].m2[0]=i+r2;
				s[cnt].m2[1]=i+r1+r2;
				if(i_board[i+r1+r2]==-1)
				{
					s[cnt].nb++;
					s[cnt].board[i+r1+r2]=1;
				}
				cnt++;
				s[cnt].pb=ipb;
				s[cnt].nb=inb;
				for(j=1;j<=24;j++)
					s[cnt].board[j]=i_board[j];
				s[cnt].board[i+r1+r2]++;
				s[cnt].board[i]--;
				s[cnt].moves=2;
				s[cnt].m1[0]=i;
				s[cnt].m1[1]=i+r1;
				s[cnt].m2[0]=i+r1;
				s[cnt].m2[1]=i+r1+r2;
				if(i_board[i+r1+r2]==-1)
				{
					s[cnt].nb++;
					s[cnt].board[i+r1+r2]=1;
				}
				cnt++;
			}
			else
			{
				return;
			}
		}
	}
}
int utility(int in)
{
	int nkills=s[in].nb-inb;
	int i;
	int sing=0;
	int ising=0;
	int utility=0;
	int anc;
	int ud=0;int ld=0;
	int iud=0;int ild=0;
	for(i=1;i<=24;i++)
	{
		if(s[in].board[i]==1)
			sing++;
		else if(i_board[i]==1)
			ising++;
	}
	for(i=1;i<=6;i++)
	{
		if(s[in].board[i]>=2)
			anc++;
	}
	for(i=1;i<=12;i++)
	{
		if(s[in].board[i]>=2)
			ld++;
		if(i_board[i]>=2)
			ild++;
	}
	for(i=13;i<=24;i++)
	{
		if(s[in].board[i]>=2)
			ud++;
		if(i_board[i]>=2)
			iud++;
	}
	utility+=(ud-iud)*1;
	utility+=nkills*5;
	utility+=anc*3;
	utility-=(sing-ising)*2;
	return utility;
}
void printStates()
{
	int i;
	int move=0;
	for(i=0;i<cnt;i++)
	{
		if(s[i].moves>move)
			move=s[i].moves;
	}
	for(i=0;i<cnt;i++)
	{
		if(s[i].moves<move)
			continue;
		int j;
	}
	return;
}
