#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct contact                  
{
	char phoneno[20];
	char name[20];
};

int main()
{
int i;
       /*declaring all function which are used in this program*/
void addition();
void searching();
void deletion();
void editing();  
void contact_list();    
printf("*******************************************************************************************************************************************\n");
printf("THIS IS A PHONEBOOK APPLICATION WHERE YOU ADD ANY CONTACT,SEARCH AN EXISTING CONTACT,DELETE AN EXISTING CONTACT AND EDIT A EXISTING CONTACT\n");
printf("*******************************************************************************************************************************************\n");
do{
printf("\npress 0 for showing all contacts\n");
printf("press 1 for addition of any contact\n");
printf("press 2 for seaching a existing contact\n");
printf("press 3 to delete any contact\n");
printf("press 4 to edit any contact\n");
printf("press 5 to exit from phonebook application\n");
printf("Enter your choice : ");
scanf("%d",&i);
printf("\n");
          /*switch case for doing different type of work as given by user*/
switch(i)
  {
  	case 0:contact_list();
  	      break;
   case 1:addition();

         break;
   case 2:searching();
           break;
   case 3:deletion();
            break;
   case 4:editing();
            break;
    case 5:printf("you are exiting the phonebook application \n");
            break;
    default:printf("INVALID CHOICE\n");       
  }
}while(i!=5);
}

     /*this is a function for priting all contacts*/

void contact_list()
{
	FILE *fp;
	char c;
	fp=fopen("phonebook.txt","r");           //opening file for reading the data
	if(fp==NULL)
	{
		printf("No contacts\n");
		exit(0);
	}
	while((c = fgetc(fp)) != EOF)             //while loop for printing all data
	{
		printf("%c",c);
	}
	fclose(fp);
	
}
        /*this is function for addition of new contacts*/

void addition()
{
	struct contact a;
    FILE *fp;
    char *entry;
    fp = fopen("phonebook.txt","a");           //opening file for opening new data
	printf("Enter Name:");
	scanf("%s",a.name);
	printf("Enter phone no : ");
	scanf("%s",a.phoneno);
	entry = a.name;
	strcat(entry,",");
	strcat(entry,a.phoneno);          
	fputs(entry, fp);
	fprintf(fp,"\n");
	fclose(fp);
	printf("contact add successfully\n");
}
       /*this is function for seaching of exiting contact*/   

void searching()
{ 
	char c[100],x[20],d[100];
	char *p;
	int i=0;
	FILE *fp;
	fp = fopen("phonebook.txt","r");
	printf("Enter name or phoneno you want to search:");
	scanf("%s",x);
	                     /*while loop for checking given name or phoneno to my file*/
	while(fscanf(fp,"%s",c)==1)           
	{
       	strcpy(d,c);
		p=strtok(d,",");
		while(p!=NULL)                           
	    {    
			if(strcmp(p,x)==0)                            
			{
				i=5;                                     
				printf("Name and numbers are :%s\n",c);       //printing seached contact       

				break;
			}
		 	p=strtok(NULL,",");
	   }
    }
    if(i==5)
    {
    	printf("contact searched succesfully\n");
    }

    else
    {
    	printf("Invalid name or phoneno..please try again\n");    
    }

    fclose(fp);
} 
       /*this is function for deletion of any contact*/
void deletion()
{
	char c[100],x[20],q[100],d[100];
	char *p;
	int i=0;
	FILE *fp1,*fp2;
	fp1=fopen("phonebook.txt","r");             //opening old file for reading 
	fp2=fopen("phonebook_new.txt","w");          //opening new file for writing new data
	printf("Enter name or phoneno u want to delete: ");
	scanf("%s",x);
               /*while loop for checking given name or phoneno to my file*/	
	while(fscanf(fp1,"%s",c)==1)
	{
   strcpy(d,c);
	char *p=strtok(c,",");
		if(strcmp(p,x)==0)
		{  
           
            strcpy(q,d);
            break;
		}		
         p=strtok(NULL,",");
         if(strcmp(p,x)==0)
		{  
           
            strcpy(q,d);
            break;
		}		
		
	}
	fseek(fp1, 0, SEEK_SET);        //shifting file pointer to beginning using this function
         /*while loop for printing old file data to new file after deletion of new contact*/
	while(fscanf(fp1,"%s",c)==1)
	{
	    if(strcmp(q,c)!=0)
	    	{ 
	    		i=5;
	    		fprintf(fp2,"%s\n",c);
	    	}
	}
	if(i==5)
	{
		printf("contact delete successfully\n");

	}
	else
	{
		printf("Invlaid name or phoneno. which you want to delete\nplease give existing contact");
	
	}
	remove("phonebook.txt");                     //removing old file
	rename("phonebook_new.txt","phonebook.txt");            //renaming new file
	fclose(fp1);
	fclose(fp2);
}
         /*this is function of editing of new contacts*/
void editing()
{
	char c[100],x[20],d[100],q[100];
	int i=0;
	struct contact a;
	char *p,*new;
	FILE *fp1,*fp2;
	fp1=fopen("phonebook.txt","r");        //opening old file for reading
	fp2=fopen("phonebook_new.txt","w");         //opening new file for writning
	printf("Enter name or phone u want to Edit: ");
	scanf("%s",x);
	           /*while loop for checking given name or phoneno to my file*/
	while(fscanf(fp1,"%s",c)==1)

    {
		strcpy(d,c);
		p=strtok(c,",");
		if(strcmp(p,x)==0)
		{ 
			
            strcpy(q,d);
            break;
		}
		p=strtok(NULL,",");
		 if(strcmp(p,x)==0)
		{  
           
            strcpy(q,d);
            break;
		}		


	}
	fseek(fp1, 0, SEEK_SET);      //shifting file pointer to the beginning 
	             /*while loop for editing the contact*/    
    while(fscanf(fp1,"%s",c)==1)
    {
    	if(strcmp(q,c)!=0)
    	{
    		fprintf(fp2,"%s\n",c);
    	}
    	else
    	{
    		i=5;
    printf("Enter Name:");
	scanf("%s",a.name);
	printf("Enter phone no : ");                  //adding of edited contact
	scanf("%s",a.phoneno);
	new=a.name;
	strcat(new,",");
	strcat(new,a.phoneno);
	fputs(new,fp2);
    fprintf(fp2,"\n");

    	}
    }
     if(i==5)
    {
    	printf("contact edit succesfully\n");
    }

    else
    {
    	printf("Invalid name or phoneno. .please try againt\n");
     
    }
    remove("phonebook.txt");            //removng old file
	rename("phonebook_new.txt","phonebook.txt");        //renaming my new file
	fclose(fp1);
	fclose(fp2);

}
