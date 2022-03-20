 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
void student_login();
void management_login();
void write_student();
void display_all();
void display_specific(num);
void modify_student();
void delete_student();

   struct student
     {
         int rollno;
         char name[50];
        int pps_marks,chem_marks,math_marks,eng_marks;
        float per;
       char grade;
        int std;
     }st;

 FILE *fptr;

int main() 
{ 
  
       int i;
         do
            {
                 printf("Select any one of the option\n");
                 printf("1.Management login\n");
                 printf("2.Student login\n");
                 printf("3.Exit\n");
                 printf("Enter your choice\n");
                 scanf("%d",&i); 
	        switch(i)
                          {
    	                      case 1:
    		                  printf("1.Management login\n");
    	                             management_login();
    		                 break;
    	                    case 2:
    		                printf("2.Student login\n");
    		                student_login();
    		                break;
                               case 3:
                                       printf("Exit\n");
                                      exit(0);
                                      break;
                              default:
    		              printf("Please enter correct choice\n");
                       }
           }
 	 while(i!=3);
	return 0;
}
 void management_login()
     {
 	char str1[20],str2[20];
 	int i,j,num,count=0;
            puts("Enter the username\n");
           scanf("%s",str1);
           puts("Enter password\n");
           scanf("%s",str2);
           for(i=0;i<10;i++)
               {
                    if(str1[i]==str2[i])
                    count++;
                }
        if(count==10)
            {
 	         printf("Login Successful\n");
 	         printf("Now you can proceed with the further operations");
    	
	 }
        else 
	      printf("Please, check your login credentials");
         do
	{  
		    printf("Select any one option\n");
		    printf("1.To enter student marks\n");
		    printf("2.Display the marks of all the students\n");
		    printf("3.Display the marks of only a specific student\n");
		    printf("4.Modifty the marks which are already existing\n");
		    printf("5.Delete the marks of a particular student\n");
		    printf("6.Exit\n");
	                printf("Select your choice\n");
        	                scanf("%d",&j);
			switch(j)
			   {
			         case 1:
			                  write_student();
                                                       break;
                                            case 2: 
	                                         display_all();
	                                         break;
                                            case 3:  
			            {
                                                      int num;
                                                      printf("\n\n\tPlease enter the roll number of the student/n ");
                                                       scanf("%d",&num);
                                                     display_specific(num);
                                                }
                                                      break;
                                              case 4: 
	                                        modify_student();
	                                        break;
                                        case 5: 
			            delete_student();
			             break;
                                        case 6:
			             exit(0);
	 		             break;
                                      default:
		    	            printf("Please select a valid choice/n");
		        }
	      }
	            while (j!=6);
        }
  void write_student()
      {
            fptr=fopen("text.txt","ab");
            printf("\nPlease enter the  details of student \n");
           printf("\nEnter the roll number of student ");
          scanf("%d",&st.rollno);
          fflush(stdin);
          printf("\n\nEnter the Name of student ");
         gets(st.name);
         printf("\nEnter the marks in pps out of 100 : ");
         scanf("%d",&st.pps_marks);
         printf("\nEnter the marks in chemistry out of 100 : ");
         scanf("%d",&st.chem_marks);
         printf("\nEnter the marks in maths out of 100 : ");
         scanf("%d",&st.math_marks);
        printf("\nEnter the marks in english out of 100 : ");
        scanf("%d",&st.eng_marks);
        st.per=(st.pps_marks+st.chem_marks+st.math_marks+st.eng_marks)/4.0;
           if(st.per>=60)
                    st.grade='A';
          else if(st.per>=50 &&st.per<60)
                  st.grade='B';
          else if(st.per>=33 &&st.per<50)
                 st.grade='C';
          else
                st.grade='F';
                fwrite(&st,sizeof(st),1,fptr);
                 fclose(fptr);
                 printf("\nStudent record has been created ");
                getch();
       }
void display_all()
{
    printf("\n\n\n\t\t RECORDS !!!\n\n");
    fptr=fopen("text.txt","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
        {
             printf("\nRoll Number of Student : %d",st.rollno);
             printf("\nName of student : %s",st.name);
             printf("\nMarks in PPS : %d",st.pps_marks);
             printf("\nMarks in Chemistry : %d",st.chem_marks);
             printf("\nMarks in Maths : %d",st.math_marks);
            printf("\nMarks in English : %d",st.eng_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
           printf("\nGrade of student is : %c",st.grade);
          printf("\n\n====================================\n");
           getch();
        }
          fclose(fptr);
         getch();
   }
void display_specific(int n)
{
    int flag=0;
    fptr=fopen("text.txt","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
     if(st.rollno==n)
        {
            printf("\nRoll number of student : %d",st.rollno);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in PPS : %d",st.pps_marks);
            printf("\nMarks in Chemistry : %d",st.chem_marks);
            printf("\nMarks in Maths : %d",st.math_marks);
            printf("\nMarks in English : %d",st.eng_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nGrade of student is : %c",st.grade);
            flag=1;
      }
  }
    fclose(fptr);
    if(flag==0)
        printf("\n\nRecord does not exist");
    getch();
}
  void modify_student()
{
    int no,found=0;
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease enter the roll number of the student");
    scanf("%d",&no);
    fptr=fopen("text.txt","rb+");
    while((fread(&st,sizeof(st),1,fptr))>0 && found==0)
      {
    if(st.rollno==no)
           {
            printf("\nRoll number of student : %d",st.rollno);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in PPS : %d",st.pps_marks);
            printf("\nMarks in Chemistry : %d",st.chem_marks);
            printf("\nMarks in Maths : %d",st.math_marks);
            printf("\nMarks in English : %d",st.eng_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nGrade of student is : %c",st.grade);
            printf("\nPlease enter the details of the student \n");
            printf("\nEnter the roll number of  the student ");
            scanf("%d",&st.rollno);
            fflush(stdin);
            printf("\n\nEnter the name of student ");
            gets(st.name);
            printf("\nEnter the marks in PPS out of 100 : ");
            scanf("%d",&st.pps_marks);
            printf("\nEnter the marks in chemistry out of 100 : ");
            scanf("%d",&st.chem_marks);
            printf("\nEnter the marks in maths out of 100 : ");
            scanf("%d",&st.math_marks);
            printf("\nEnter the marks in english out of 100 : ");
            scanf("%d",&st.eng_marks);
            st.per=(st.pps_marks+st.chem_marks+st.math_marks+st.eng_marks)/(4.0);
              if(st.per>=60)
                       st.grade='A';
              else if(st.per>=50 && st.per<60)
                       st.grade='B';
              else if(st.per>=33 && st.per<50)
                      st.grade='C';
              else
                     st.grade='F';
            fseek(fptr,-(long)sizeof(st),1);
            fwrite(&st,sizeof(st),1,fptr);
            printf("\n\n\t Record Updated");
            found=1;
                }
         }
        fclose(fptr);
        if(found==0)
        printf("\n\n Record Unavailablle ");
         getch();
    }
void delete_student()
 {
    int no;
    FILE *fptr2;
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease enter the roll number of student you wish to delete");
    scanf("%d",&no);
    fptr=fopen("text.txt","r”);
    fptr2=fopen("Temp.txt","wb");
    rewind(fptr);
    while((fread(&st,sizeof(st),1,fptr))>0)
      {
             if(st.rollno!=no)
               {
                   fwrite(&st,sizeof(st),1,fptr2);
               }
       }
          fclose(fptr2);
         fclose(fptr);
         remove("text.txt");
        rename("Temp.txt","text.tx");
        printf("\n\n\tRecord Deleted ..");
             getch();
            }
void student_login()
{
	char str1[20],str2[20];
 	int i,j,num,count=0,a;
            puts("Enter the username\n");
            scanf("%s",str1);
            puts("Enter password\n");
            scanf("%s",str2);
                for(i=0;i<10;i++)
                 {
                      if(str1[i]==str2[i])
                      count++;
                   }
               if(count==10)
                 {
 	         printf("Login Successful\n");
 	         printf("Now you can proceed with the further operations");
    	
	      }
	  else 
	         printf("Please, check your login credentials");
	         printf("Enter 1 to display your result");
	         scanf("%d",&a);
	if(a==1)
	    {
                       int num;
	           printf("\n\n\tPlease enter your roll number/n ");
                      scanf("%d",&num);
                     display_specific(num);
	    }
	  
          else
	   printf("Please enter a valid number");
}

