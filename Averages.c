#include  <stdio.h> 
/*Authors: Brett Koenig */
/*This program computes the average of one line of integers entered by user*/
main( )
{
  char  character;
  int final_num = 0;
  int total = 0;
  float average = 0;
  int count_nums = 0;
  /* Prompt the user for the integer values of which they want to compute the average. */
  printf("Enter a string of integers between 0 and 100, each integer separated by a single space. Press <Return> at end:\n");
  do
    {
      /*this gets characters from the input while they are not a new line character*/
      character = getchar();
      int count = 0;
      while(character!=' '&&character !='\n')
  {
   /*Convers input character to integer*/
   int c = character - 48;
   /*This if else structure is to handle the case of making a number that is more than one digit, for example 10, 15, 100*/
   if(count==0)
     {
       final_num = c;
       count++;
       /*count_nums keeps track of the number of values input by the user*/
       count_nums++;
     }
   /*final_num keeps track of the current number*/
   else
     {
       final_num = final_num*10;
       final_num+= c;
     }
   character = getchar();
  }
      total = total + final_num;
      final_num = 0;
    }
  while(character != '\n');
  //Computes the average
  average = (float)total/(float)count_nums;
  //Displays the average
  printf("The average of the numbers you input is: %.02f\n", average);
}
