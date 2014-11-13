/*
Authors:Brett Koenig
Date: 2/4/13
This is a short program which takes in an input line by line and determines Owner cost, Customer Cost, and profit for the owner
*/
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
//prototypes for our functions
void printout(FILE *outfp, char *suppTypeCheck[15],float  ownCostCheck,float custCostCheck,float profCheck);
int equalitycheck(char *suppTypeCheck[15], char *suppType[15]);

int main() { 
  //create file pointers and file IO error handling
  FILE *fpin, *outfp;
  fpin = fopen("lab2p1in","r"); // read mode  
  if( fpin == NULL ) 
    { 
      perror("Error while opening the input file.\n"); 
      exit(EXIT_FAILURE); 
    }
  outfp = fopen("lab2p1out", "w");
  if(outfp == NULL)
    {
      fprintf(stderr, "Can't open output file the output file!");
      exit(EXIT_FAILURE);
    }
  //declare all needed variables
  char *supplyType[100], productName[100], *supplyTypeCheck[100];
  float wholesalePrice, retailPrice, ownerCost, customerCost, profit, ownerCostCheck, customerCostCheck, profitCheck;
  int quantityWholesale, retailQuantity, truth, truthTwo;
  //scan in first line of input
  fscanf(fpin,"%s %s %f %d %f %d",supplyType,productName,&wholesalePrice,&quantityWholesale,&retailPrice,&retailQuantity);
  //run while loop while not at end of input
  while (!feof(fpin)) 
    {
      //set variables based upon input
      *supplyTypeCheck = *supplyType;
      ownerCost = wholesalePrice*(float)quantityWholesale;
      customerCost = retailPrice*(float)retailQuantity;
      profit = customerCost- ownerCost;
      ownerCostCheck = ownerCost;
      customerCostCheck = customerCost;
      profitCheck = profit;
      //scan in the next line
      fscanf(fpin,"%s %s %f %d %f %d",supplyType,productName,&wholesalePrice,&quantityWholesale,&retailPrice,&retailQuantity);
      //checks to see if supply types of lines is the same
      truth = equalitycheck(supplyTypeCheck, supplyType);
      //runs while supply types of lines is the same and not at end
      while((!feof(fpin))&&(truth))
  {
    ownerCost = wholesalePrice*(float)quantityWholesale;
    customerCost = retailPrice*(float)retailQuantity;
    profit=customerCost-ownerCost;
    //checks if supply types are equal
    truthTwo = equalitycheck(supplyTypeCheck, supplyType);
    //continues to add to existing variables if supply types are equal
    if(truthTwo)
      {
        ownerCostCheck = ownerCost + ownerCostCheck;
        customerCostCheck = customerCost + customerCostCheck;
        profitCheck=profit+profitCheck;
      }
    //prints out all information for previous supply type and sets variables equal to new supply type info
    else
      {
        printout(outfp, supplyTypeCheck, ownerCostCheck, customerCostCheck, profitCheck);
        *supplyTypeCheck = *supplyType;
        ownerCostCheck=ownerCost;
        customerCostCheck=customerCost;
        profitCheck=profit;
      }
    //scans in next line
    fscanf(fpin,"%s %s %f %d %f %d",supplyType,productName,&wholesalePrice,&quantityWholesale,&retailPrice,&retailQuantity);
  }
      //print out last info if needed
      printout(outfp, supplyTypeCheck, ownerCostCheck, customerCostCheck, profitCheck);
    }
  //close all files
  fclose(fpin);
  fclose(outfp); 
  return 0; 
} 
//function takes in supply types of two lines as pointers and checks for equality, returns a 1 if equal, else returns 0
int equalitycheck(char *suppTypeCheck[100], char *suppType[100])
{
  if(*suppTypeCheck == *suppType)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}
//function prints out to a file  needed information after taking in appropriate variables
void printout(FILE *outfp, char *suppTypeCheck[100],float  ownCostCheck,float custCostCheck,float profCheck)
{
  fprintf(outfp, "Type: %s \n", suppTypeCheck);
  fprintf(outfp, "Owner Cost: $%.02f\n", ownCostCheck);
  fprintf(outfp, "Customer Cost: $%.02f\n", custCostCheck);
  fprintf(outfp, "Profit: $%.02f\n", profCheck);
  fprintf(outfp, "\n");
}
