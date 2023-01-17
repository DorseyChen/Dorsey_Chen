#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;

struct book
{
	int catalog;
	char title[20];
	char author[20];
	int price;
	int issue;
};

void addinfo(book content[],int n)
{
	int c,i,num;
	cout<<"Please enter a catalog to choose a book."<<endl;
	cin>>num;
	for(i=0;i<n;i++)
		if(content[i].catalog==num)
			break;
	do{
		cout<<"Please choose a number for the next operation. "<<endl;
		cout<<"(1)Edit the catalog"<<endl;
		cout<<"(2)Edit the title"<<endl;
		cout<<"(3)Edit the author"<<endl;
		cout<<"(4)Edit the price"<<endl;
		cout<<"(5)Change issuance"<<endl;
		cout<<"(6)Leave"<<endl;
		cin>>c;
		switch(c)
		{
			case 1:
				cin>>num;
				for(i=0;i<n;i++)
					if(content[i].catalog==num)
					{
						cout<<"Conflicting catalog number!"<<endl;
						break;
					}
					else if(i==n-1)
						content[i].catalog==num;
				break;
			case 2:
				cin>>content[i].title;
				break;
			case 3:
				cin>>content[i].author;
				break;
			case 4:
				cin>>content[i].price;
				break;
			case 5:
				content[i].issue=-content[i].issue;
				break;
		}
	}while(c!=6);
}

void display(book content[],int n)
{
	int i,num;
        cout<<"Please enter a catalog to choose a book."<<endl;
        cin>>num;
        for(i=0;i<n;i++)
                if(content[i].catalog==num)
                        break;	
	cout<<"The infomation of the book: "<<endl<<endl;
	cout<<"The catalog number: "<<content[i].catalog<<endl;
	cout<<"The title: "<<content[i].title<<endl;
	cout<<"The author: "<<content[i].author<<endl;
	cout<<"The price: "<<content[i].price<<endl;
	if(content[i].issue>-1)
		cout<<"not ";
	cout<<"issued"<<endl;
}

void listauthor(book content[],int n)
{
	int i;
	char name[20];
	cout<<"Please enter an author: ";
	cin>>name;
	cout<<"The following books are writen by the author:"<<endl;
	for(i=0;i<n;i++)
		if(!strcmp(content[i].author,name))
			cout<<content[i].title<<endl;
}

void listtitle(book content[],int n)
{
	int i,num;
	cout<<"Please enter a catalog number to choose a book."<<endl;
	cin>>num;
	for(i=0;i<n;i++)
		if(content[i].catalog==num)
			cout<<content[i].title<<endl;
}

void listcount(book content[],int n)
{
	int i,num=0;
	cout<<"The count of books in the library: "<<endl;
	for(i=0;i<n;i++)
		if(content[i].issue>0)
			num++;
	cout<<num<<endl;
}

void listcata(book content[],int n)
{
	int i,j;
	book tmp;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(content[i].catalog>content[j].catalog)
			{
				tmp=content[i];
				content[i]=content[j];
				content[j]=tmp;
			}
	cout<<"Catalog number: "<<"Title:     "<<"Author:  "<<"Price: "<<"Issued:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<std::left<<setw(16)<<content[i].catalog;
		cout<<std::left<<setw(11)<<content[i].title;
		cout<<std::left<<setw(10)<<content[i].author;
		cout<<std::left<<setw(7)<<content[i].price;
		if(content[i].issue>0)
			cout<<std::left<<"Not";
		else
			cout<<std::left<<"Yes";
		cout<<endl;
	}
}

int main()
{
	int n,c;
	cout<<"Please enter the number of books."<<endl;
	cin>>n;
	book content[n];
	for(int i=0;i<n;i++)
	{
		content[i].issue=1;
		content[i].catalog=i+1;
	}
	do{
		cout<<"Please choose a option."<<endl;
		cout<<"(1)Add book information"<<endl;
		cout<<"(2)Display book information"<<endl;
		cout<<"(3)List all books of given author"<<endl;
		cout<<"(4)List the title of a specified book"<<endl;
		cout<<"(5)List the count of books in the library"<<endl;
		cout<<"(6)List the books in the order of catalog number"<<endl;
		cout<<"(7)Exit"<<endl;
		cin>>c;
		
		switch(c)
		{
			case 1:
				addinfo(content,n);
				break;
			case 2:
				display(content,n);
				break;
			case 3:
				listauthor(content,n);
				break;
			case 4:
				listtitle(content,n);
				break;
			case 5:
				listcount(content,n);
				break;
			case 6:
				listcata(content,n);
				break;
			case 7:
				break;
		}
	}while(c!=7);
	return 0;
}
