 
#include <stdio.h>  

#include <conio.h>  
 
#include <stdlib.h>  

#include <string.h>  
  
  
  
struct library  
{  
    
    char book_name[100];  
   
    char author_name[100];  
     
    float date_of_issue;  
};  
  
 
int main()  
{  
    
    struct library lib[100];  
    char book_name[100];  
    int i, j, count;  
    i = 0;  
    j = 0;  
    count = 0;  
  
  
 
  
    while(j!=6)  
    {  
        printf(" \n\n1. Add Book details\n ");  
        printf(" 2. Display the list of books and its details\n ");  
        printf(" 3. Display the total no. of books in the library\n ");  
        printf(" 4. Exit\n\n");  
        printf(" Enter the number: ");  
        scanf(" %d", &j);  
  
  
      
  
        switch(j)  
        {  
           
            case 1:  
                printf(" \nYou can add the details of the book ");  
                printf(" \nEnter the book name: ");  
                scanf(" %s", lib[i].book_name);  
                printf(" \nEnter the author name: ");  
                scanf(" %s", lib[i].author_name);  
                printf(" \nEnter the date of issue: ");  
                scanf(" %f", &lib[i].date_of_issue);  
                 
                count = count + 1;  
                i = i + 1;  
                break;  
  
            case 2:  
                
                if (count==0)  
                {  
                    printf(" \nThere are no books stored!!\n\n ");  
                }  
                else  
                {  
                    
                    printf(" \nYou can view the list of books ");  
                    printf(" \nThe list of books are: ");  
                    for(i=0; i < count; i++)  
                    
                    {  
                        printf(" \nThe name of the book is: %s ", lib[i].book_name);  
                        printf(" \nThe name of the author is: %s ", lib[i].author_name);  
                        printf(" \nThe date of issue is: %.2f ", lib[i].date_of_issue);  
                        ;  
                    }  
                }  
                break;  
  
            case 3:  
                
                printf(" \nTotal number of books issues are: %d\n\n ", count);  
                break;  
              
            case 4:  
                
                exit(0);  
                  
            default:  
                
                printf(" \nInvalid number entered\n\n ");  
        }  
  
    }  
  
} 

