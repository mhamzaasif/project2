#include<iostream>
#include<fstream>
#include<cmath>
#include<stdlib.h>
using namespace std;
void solidwords(char []);
void read(char [], char []);
void changecase(char []);
void makesets(char [],char [],int, int &);
void convert_to_cipher(int [],int,int, int &);
void compare(int [],int,int,int);
void arraysort(int []);
void readfile(int [],int [],int [],int [],int[],int[],int &,int &,int &);
int main()
{
	char sentence[500]={'\0'};
	char ch_set[6]={'\0'};
	int count=365,count1=365,count2=365;
	int random[10]={0};
	char fullname[10]={'\0'};
	char name[6]={'t','e','x','t','\0','\0'};
	char ext[5]={'.','t','x','t','\0'};
	for(int i=0;i<3;i++)
	{
		int k=0;
		for(int j=0;name[j]!='\0';j++,k++)
		{
			fullname[k]=name[j];
		}
		fullname[k]=static_cast<char>(i+49);
		k++;
		for(int j=0;ext[j]!='\0';j++,k++)
		{
			fullname[k]=ext[j];
		}
		read(sentence,fullname);
		changecase(sentence);
		solidwords(sentence);
		if(i==0)
		{
			
			makesets(sentence,ch_set,i,count);
		}
		else if(i==1)
		{
			makesets(sentence,ch_set,i,count1);
		}
		else
		{
			makesets(sentence,ch_set,i,count2);
		}
		
	}
	compare(random,count,count1,count2);
	return 0;
}
void read(char sentence[], char fullname[]){
	ifstream inFile;
	inFile.open(fullname,ios::in);
	inFile.getline(sentence,499);
	inFile.close();
}
void changecase(char sentence[]){
	for(int i=0;sentence[i]!='\0';i++)
	{
		if(sentence[i]>='A' && sentence[i]<='Z')
		{
			sentence[i]+=32;
		}
	}
}
void solidwords(char sentence[]){
	for(int i=0;sentence[i]!='\0';i++)
	{
		if(!(sentence[i]>='a' && sentence[i]<='z'))
		{
			for(int j=i;sentence[j]!='\0';j++)
			{
				sentence[j]=sentence[j+1];
			}
			i--;
		}
		
	}
}
void makesets(char sentence[],char ch_set[], int i, int &counter){
	int cipher=0;
	int cipher_sum[1000]={0};
	int cipher_index=0;
	for(int i1=0;sentence[i1+4]!='\0';i1++)
	{
		for(int j=0;j<5;j++)
		{
			ch_set[j]=sentence[i1+j];
		}
		for(int i1=0;i1<5;i1++)
		{
			cipher+=ch_set[i1]-96;
		}
		cipher_sum[cipher_index]=cipher;
		cipher_index++;
		cipher=0;
	}
	convert_to_cipher(cipher_sum,cipher_index,i,counter);
}
void convert_to_cipher(int cipher_sum[],int cipher_index,int i, int &counter){
	char fullname[12]={'\0'};
	char name[7]={'c','i','p','h','e','r','\0'};
	char ext[5]={'.','t','x','t','\0'};
	int k=0;
	for(int j=0;name[j]!='\0';j++,k++)
	{
		fullname[k]=name[j];
	}
	fullname[k]=static_cast<char>(i+49);
	k++;
	for(int j=0;ext[j]!='\0';j++,k++)
	{
		fullname[k]=ext[j];
	}
	fullname[k]='\0';
	ofstream outFile;
	outFile.open(fullname,ios::out);
	for(int i=0;i<cipher_index-4;i++)
	{
			outFile<<cipher_sum[i]<<" "<<cipher_sum[i+1];
			outFile<<endl;
			outFile<<cipher_sum[i+2]<<" "<<cipher_sum[i+3];
			outFile<<endl;
	}
	outFile.close();
}
void compare(int random[],int count,int count1,int count2){
	float check1=0,check2=0,check3=0;
	int random1[10]={0};
	int random2[10]={0};
	int diff[10]={0};
	int diff1[10]={0};
	int diff2[10]={0};
	int counter=0,counter1=0,counter2=0;
	count-=4;
	count1-=4;
	count2-=4;
	for(int i=0;i<10;i++)
	{
		random[i]=rand()%count+1;
	}
	for(int i=0;i<10;i++)
	{
		random1[i]=rand()%count1+1;
	}
	for(int i=0;i<10;i++)
	{
		random2[i]=rand()%count2+1;
	}
	arraysort(random);
	arraysort(random1);
	arraysort(random2);
	readfile(random,random1,random2,diff,diff1,diff2,counter,counter1,counter2);
	check1=float(counter/10.0)*100;
	check2=float(counter1/10.0)*100;
	check3=float(counter2/10.0)*100;
	if(check1>=60)
	{
		cout<<"File 1 and file 2 have "<<check1<<" % similarity"<<endl;
	}
	else
	{
		cout<<"File 1 and File 2 are not same "<<endl;
	}
	if(check2>=60)
	{
		cout<<"File 1 and file 3 have "<<check2<<" % similarity"<<endl;
	}
	else
	{
		cout<<"File 1 and File 3 are not same "<<endl;
	}
	if(check3>=60)
	{
		cout<<"File 3 and file 2 have "<<check3<<" % similarity"<<endl;
	}
	else
	{
		cout<<"File 3 and File 2 are not same "<<endl;
	}
}
void arraysort(int random[]){
	int min=0;
	int loc=0;
	int temp=0;
	bool flag=0;
	for(int i=0;i<10;i++)
	{
		min=random[i];
		for(int j=i;j<10;j++)
		{
			if(random[j]<min)
			{
				flag=1;
				min=random[j];
				loc=j;
			}
		}
		if(flag==1)
		{
			temp=random[i];
			random[i]=random[loc];
			random[loc]=temp;
			flag=0;
		}
		if(random[i-1]==random[i])
		{
			random[i]+=3;
		}
		flag=0;
	}
}
void readfile(int random[],int random1[],int random2[],int diff[],int diff1[],int diff2[],int &counter,int &counter1,int &counter2){
	int mat1[2][2]={0},mat2[2][2]={0},mat3[2][2]={0},r_count=0,arr_counter=0;
	ifstream inFile;
	inFile.open("cipher1.txt",ios::in);
	ifstream inFile1;
	inFile1.open("cipher2.txt",ios::in);
	ifstream inFile2;
	inFile2.open("cipher3.txt",ios::in);
	int count=0;
	int sum1=0,sum2=0,sum3=0;
	int i=0;
	int j=0;
	int k=0;
	for(;arr_counter<10;)
	{
		for(;i!=random1[arr_counter];i++)
		{
			inFile>>sum1>>sum2;
		}

		for(int l=0;l<2;l++)
		{
			for(int m=0;m<2;m++)
			{
				inFile>>mat1[l][m];
			}
			i++;
		}



		for(;j!=random2[arr_counter];j++)
		{
			inFile1>>sum1>>sum2;
		}


		for(int l=0;l<2;l++)
		{
			for(int m=0;m<2;m++)
			{
				inFile1>>mat2[l][m];
			}
			j++;
		}


		for(;k!=random2[arr_counter];k++)
		{
			inFile2>>sum1>>sum2;
		}


		for(int l=0;l<2;l++)
		{
			for(int m=0;m<2;m++)
			{
				inFile1>>mat3[l][m];
			}
			k++;
		}


		sum1=0;sum2=0;sum3=0;
		for(int l=0;l<2;l++)
		{
			for(int m=0;m<2;m++)
			{
				sum1+=abs(mat1[l][m]-mat2[l][m]);
				sum2+=abs(mat1[l][m]-mat3[l][m]);
				sum3+=abs(mat2[l][m]-mat3[l][m]);
				
			}
		}
		diff[arr_counter]=sum1;
		if(sum1<60)
		{
			counter++;
		}
		diff1[arr_counter]=sum2;
		if(sum2<60)
		{
			counter1++;
		}
		diff2[arr_counter]=sum3;
		if(sum3<60)
		{
			counter2++;
		}
		arr_counter++;
	}	
}

