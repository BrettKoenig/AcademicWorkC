/*
Authors:Brett Koenig
Date: 2/4/13
This is a short program which takes in an input line by line and makes every alphabetical character capitalized and reverses all words using pointers
*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
void main () {
  //create all file pointers and other variables needed
  FILE *infp, *outfp;
  char* mode="r";
  char outfile[]="lab2p2out";

  char startchar, finishchar;

  char input[101], save_first_letter;
  char *start, *finish, *marker;
 
  /*first two if statements handle file I/O errors*/

  infp = fopen("lab2p2in", mode);
  if(infp == NULL)
    {
      fprintf(stderr, "can't open input file lab2p2in!\n");
      exit(EXIT_FAILURE);
    }
  outfp = fopen(outfile, "w");
  if(outfp == NULL)
    {
      fprintf(stderr, "Can't open output file %s!\n", outfile);
      exit(EXIT_FAILURE);
    }
  //Gets first line and puts it into input array
  fscanf(infp, "%s", input);
  /*continue to read while not at end of input file*/
    while(!feof(infp))
      {
  /*points both start and finish at the beginning index of input array*/
  start = (input);
  finish = (input);


  /*runs while input array is not at the end of line*/
  while((*finish)!='\0'&&(*finish)!='\n')
    {
      /*increments  start pointer until its an alphabetial character*/
      while(!isalpha(*start)&&(*start)!= '\n' && (*start)!= '_' && (*start)!= '\0')
        {
    start++;
        }
      /*sets finish pointer to same address as start*/
      finish =(start);
      /*increments finish pointer until its an underline or null character*/
      while(isalpha(*finish))
        {
    finish++;
        }
      /*if finish is at an underline, replace it with a space*/
      if((*finish)=='_')
        {
    *finish = ' ';
        }
      /*set marker pointer equal to finish so we know the farthest index we have reached in the array*/
      marker =(finish);
      /*decrement finish until it is at the end of the word that the start pointer is at the beginning of*/
      while(!isalpha(*finish))
        {
    finish--;
        }
      /*until finish and start pointer overlap, make all characters in the word upper case and swap them towards the middle*/
      while(finish >= start)
        {
    finishchar = toupper(*finish);
    startchar = toupper(*start);
    (*start) = finishchar;
    (*finish) = startchar;
    start++;
    finish--;
        }
      /*set start and finish to the farthest index reached in array*/
      start=(marker);
      finish=(marker);
    }
  /*print encoded line, and scan for new input*/
  fprintf(outfp, "Your encoded coded message is %s\n", input);
  fscanf(infp, "%s", input);
      }
    //close file I/O
    fclose(outfp);
    fclose(infp);
}