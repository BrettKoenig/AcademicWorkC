/*Author: Brett Koenig */
/*This program plays rock paper scissors between a user and the computer*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
  enum WEAPON {rock=1,paper=2, scis=3};
  int comp_choice, response=1;
  enum WEAPON user_choice;
  char character;
  do
    {
      /* initialize random seed: */
      srand ( time(NULL) );
      /* generate secret number: */
      comp_choice = rand() % 3 +1;
      printf("Please enter 'R' for rock, 'P' for paper, or 'S' for scissors, and then hit Enter:\n ");
      scanf(" %c", &character);
      /* Assign the value of the user's choice to the appropriate enum type. */
      if(character == 'R')
  {
   user_choice = rock;
  }
      else if(character == 'P')
  {
   user_choice = paper;
  }
      else if(character == 'P')
  {
   user_choice = scis;
  }
      else
  {
   printf("\nThat was not a valid choice.\n");
   goto stop;
  }
      /* Switch to check whether the user chose rock, paper, or scissors */
      switch(user_choice)
  {
   /* User chose rock */
  case 1:
   if(comp_choice == 1)
     {
       printf("\nIt is a tie!\n");
     }
   else if (comp_choice == 2)
     {
       printf("\nComputer Wins!\n");
     }
   else
     {
       printf("\nUser wins!\n");
     }
   break;
   /* User chose paper */
  case 2:
   if(comp_choice == 2)
     {
       printf("\nIt is a tie!\n");
     }
   else if (comp_choice == 3)
     {
       printf("\nComputer Wins!\n");
     }
   else
     {
       printf("\nUser wins!\n");
     }
   break;
   /* User chose scissors */
  case 3:
   if(comp_choice == 3)
     {
       printf("\nIt is a tie!\n");
     }
   else if (comp_choice == 1)
     {
       printf("\nComputer Wins!\n");
     }
   else
     {
       printf("\nUser wins!\n");
     }
   break;
  }
      /* Ask the user if they want to play again */
    stop:printf("\nDo you want to play again?(Enter a 1 for yes or any other digit for no (Don't enter a character!) and then hit enter)\n ");
      /* Read in the user's response */
      scanf("%d", &response);
    } 
  while(response == 1);
} 


