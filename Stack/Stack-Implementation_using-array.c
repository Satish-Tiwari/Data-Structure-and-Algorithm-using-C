#include<stdio.h>
#include<conio.h>
#define MAX 100
int Stack[MAX];
int Top=-1;
void PUSH(void);
void POP(void);
void PEEP(void);
void DISPLAY(void);
int main()
{
    int opt;
    printf("\t Implementation of Stack using Array.");
    while(1)
    {
        printf("\n 1. Push Operation");
        printf("\n 2. Pop Operation");
        printf("\n 3. Peep Operation.");
        printf("\n 4. Display Operation");
        printf("\n 5. Exit from the Program");
        printf("\n\t Enter Option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: PUSH();
                    break;
            case 2: POP();
                    break;
            case 3: PEEP();
                    break;
            case 4: DISPLAY();
                    break;
            case 5: exit(0);
            default: exit(0);                                
        }
    }
    return 0;
}
/*Stack Push Operation*/
void PUSH(void)
{
    if(Top==MAX-1)
    {
        printf("\n\t Overflow\n");
    }
    else
    {
    Top+=1;
    printf("\n Enter the Element that you want to Push into the Stack: ");
    scanf("%d",&Stack[Top]);
    } 
}
/*Stack Pop Operation*/
void POP(void)
{
   int value;
   if(Top==-1)
   {
       printf("\n\t Underflow\n");
   }
   else
   {
       value=Stack[Top];
       Top-=1;
       printf("\nThe value deleted (Poped) from the Stack: %d\n",value);
   }
}
/*Stack Peep Operation*/
void PEEP(void)
{
  int Top_element;
  if(Top==-1)
  {
      printf("\n\t Underflow\n");
  }
  else
  {
      Top_element=Stack[Top];
      printf("\nThe Top most element: %d\n",Top_element);
  }
}
/*Stack Display Operation*/
void DISPLAY(void)
{
   int counter=Top;
   if(Top==-1)
   {
      printf("\n\t Underflow\n");
   }
   else
   {
       printf("\nThe elements stored in the Stack:");
       while(counter>=0)
       {
           printf(" %d ",Stack[counter]);
           counter--;
       }
       printf("\n");
   }
}