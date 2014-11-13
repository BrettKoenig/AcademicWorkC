/* Author: Brett Koenig
This program does essentially the same as entrepreneur.c, but uses linked lists as well */ 
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
//#include <alloc.h
//#include <conio.h> 

/* function prototypes */ 
struct node * initnode( char *, int, char *, float, int, float, int ); 
void printnode( struct node * ); 
void printlist( struct node *, char * ); 
void add( struct node * ); 
struct node * searchname( struct node *, char * ); 
struct node * searchproductnumber( struct node *, int);
float calctotal (struct node *);
float calcsupptype (struct node *, char *);
void listSupTypes( struct node * );
void deletenode( struct node * ); 
void insertnode( struct node * ); 
void deletelist( struct node * ); 

/* definition of a data node for holding student information */ 
struct node { 
  char suppType[20]; 
  int productNumber;
  char productDescription[100];
  float wholesale;
  int quantityWholesale;
  float retail;
  int quantityRetail; 
  struct node *next; 
}; 


/* head points to first node in list, end points to last node in list */ 
/* initialise both to NULL, meaning no nodes in list yet */ 
struct node *head = (struct node *) NULL; 
struct node *end = (struct node *) NULL; 


/* this initialises a node, allocates memory for the node, and returns */ 
/* a pointer to the new node. Must pass it the node details, name and id */ 
//float could need *
struct node * initnode( char *suppType, int productNumber, char *productDescription, float wholesale, int quantityWholesale, float retail, int quantityRetail ) 
{ 
  struct node *ptr; 
  ptr = (struct node *) calloc( 1, sizeof(struct node ) ); 
  if( ptr == NULL )               /* error allocating node? */ 
    return (struct node *) NULL;  /* then return NULL, else */ 
  else {                          /* allocated node successfully */ 
    strcpy( ptr->suppType, suppType );    /* fill in name details */ 
    ptr->productNumber = productNumber;
    strcpy( ptr->productDescription, productDescription);/* copy id details */
    ptr->wholesale = wholesale;
    ptr->quantityWholesale = quantityWholesale;
    ptr->retail = retail;
    ptr->quantityRetail = quantityRetail; 
    return ptr;                   /* return pointer to new node */ 
  } 
} 


/* this prints the details of a node, eg, the name and id */ 
/* must pass it the address of the node you want to print out */ 
void printnode( struct node *ptr ) 
{ 
  printf("Product Number ->%d\n", ptr->productNumber );
  printf("Product Description ->%s\n", ptr->productDescription);
} 


/* this prints all nodes from the current address passed to it. If you */ 
/* pass it 'head', then it prints out the entire list, by cycling through */ 
/* each node and calling 'printnode' to print each node found */ 
void printlist( struct node *ptr, char *suppType ) 
{ 
  while( ptr != NULL )  /* continue whilst there are nodes left */ 
    {
      if(strcmp(suppType, ptr->suppType ) == 0)
  { 
    printnode( ptr ); /* print out the current node */ 
  }
      ptr = ptr->next;  /* goto the next node in the list */ 
    } 
} 


/* this adds a node to the end of the list. You must allocate a node and */ 
/* then pass its address to this function */ 
void add( struct node *new )  
{ 
  if( head == NULL )    /* if there are no nodes in list, then */   
    head = new;         /* set head to this new node */ 
  if (end == NULL)
    end = new;
  end->next = new;      /* link in the new node to the end of the list */
  new->next = NULL;     /* set next field to signify the end of list */ 
  end = new;            /* adjust end to point to the last node */
} 


/* search the list for a name, and return a pointer to the found node */ 
/* accepts a name to search for, and a pointer from which to start. If */ 
/* you pass the pointer as 'head', it searches from the start of the list */ 
struct node * searchname( struct node *ptr, char *suppType ) 
{ 
  while( strcmp( suppType, ptr->suppType ) != 0 ) { /* whilst name not found */ 
    ptr = ptr->next;                        /* goto the next node */ 
    if( ptr == NULL )                       /* stop if we are at the */ 
      break;                                /* end of the list */ 
  } 
  return ptr;                               /* return a pointer to */ 
}                                           /* found node or NULL */ 

struct node * searchproductnumber( struct node *ptr, int productNumber ) 
{ 
  while(productNumber != ptr->productNumber) { /* whilst name not found */ 
    ptr = ptr->next;                        /* goto the next node */ 
    if( ptr == NULL )                       /* stop if we are at the */ 
      break;                                /* end of the list */ 
  } 
  return ptr;                               /* return a pointer to */ 
}   
float calctotal( struct node *ptr)
{
  float profit = 0;
  while( ptr != NULL )  /* continue whilst there are nodes left */ 
    { 
      profit = profit + ((ptr->retail*(float)ptr->quantityRetail)-(ptr->wholesale*(float)ptr->quantityWholesale)); /* print out the current node */ 
      ptr = ptr->next;  /* goto the next node in the list */ 
    }
  return profit;
}
float calcsupptype( struct node *ptr, char *suppType)
{
  float profit = 0;
  while( ptr != NULL )  /* continue whilst there are nodes left */ 
    {
      if (strcmp( suppType, ptr->suppType ) == 0)
  { 
    profit = profit + ((ptr->retail*(float)ptr->quantityRetail)-(ptr->wholesale*(float)ptr->quantityWholesale));
  } /* print out the current node */ 
      ptr = ptr->next;  /* goto the next node in the list */ 
    }
  return profit;
}
void listSupTypes( struct node *ptr )
{
  char *types[50];
  int i = 0;
  while( ptr != NULL)  //while not back at the head
    {
      int exists = 0, j = 0;
      types[i] = (char *)malloc(sizeof(ptr->suppType));
      strcpy(types[i], ptr->suppType);
      while( j < i )  //search types for any prior occurrence of supType
  {
    //don't print
    if( strcmp(types[i], types[j]) == 0 ){
      exists = 1;
    }
    j++;
  }
      if( !exists ){   //this is unique
  printf("%s \n", types[i]);
      }
      i++;
      ptr = ptr->next;   //go to next node
    }
}

                                        
/* deletes the specified node pointed to by 'ptr' from the list */ 
void deletenode( struct node *ptr ) 
{ 
  struct node *temp, *prev; 
  temp = ptr; /* node to be deleted */ 
  prev = head; /* start of the list, will cycle to node before temp */ 
  if( temp == prev ) { /* are we deleting first node */ 
    head = head->next; /* moves head to next node */ 
    if( end == temp ) /* is it end, only one node? */ 
      end = end->next; /* adjust end as well */ 
    free( temp ); /* free space occupied by node */ 
  } 
  else { /* if not the first node, then */ 
    while( prev->next != temp ) { /* move prev to the node before*/ 
      prev = prev->next; /* the one to be deleted */ 
    } 
    prev->next = temp->next; /* link previous node to next */ 
    if( end == temp ) /* if this was the end node, */ 
      end = prev; /* then reset the end pointer */ 
    free( temp ); /* free space occupied by node */ 
  } 
} 
/* inserts a new node, uses name field to align node as alphabetical list */ 
/* pass it the address of the new node to be inserted, with details all */ 
/* filled in */ 
void insertnode( struct node *new ) 
{ 
  struct node *temp, *prev; /* similar to deletenode */ 
  if( head == NULL ) { /* if an empty list, */ 
    head = new; /* set 'head' to it */ 
    end = new; 
    head->next = NULL; /* set end of list to NULL */ 
    return; /* and finish */ 
  } 
  temp = head; /* start at beginning of list */ 
  /* whilst currentname < newname to be inserted then */ 
  while( strcmp( temp->suppType, new->suppType) < 0 ) { 
    temp = temp->next; /* goto the next node in list */ 
    if( temp == NULL ) /* dont go past end of list */ 
      break; 
  } 
 
/* we are the point to insert, we need previous node before we insert */ 
/* first check to see if its inserting before the first node! */ 
  if( temp == head ) { 
    new->next = head; /* link next field to original list */ 
    head = new; /* head adjusted to new node */ 
  } 
  else { /* okay, so its not the first node, a different approach */ 
    prev = head; /* start of the list, will cycle to node before temp */ 
    while( prev->next != temp ) { 
      prev = prev->next; 
    } 
    prev->next = new; /* insert node between prev and next */ 
    new->next = temp; 
    if( end == prev ) /* if the new node is inserted at the */ 
      end = new; /* end of the list the adjust 'end' */ 
  } 
} 
 
/* this deletes all nodes from the place specified by ptr */ 
/* if you pass it head, it will free up entire list */ 
void deletelist( struct node *ptr ) 
{ 
  struct node *temp; 
  if( head == NULL ) return; /* dont try to delete an empty list */ 
  if( ptr == head ) { /* if we are deleting the entire list */ 
    head = NULL; /* then reset head and end to signify empty */ 
    end = NULL; /* list */ 
  } 
  else { 
    temp = head; /* if its not the entire list, readjust end */ 
    while( temp->next != ptr ) /* locate previous node to ptr */ 
      temp = temp->next; 
    end = temp; /* set end to node before ptr */ 
  }  
  while( ptr != NULL ) { /* whilst there are still nodes to delete */ 
    temp = ptr->next; /* record address of next node */ 
    free( ptr ); /* free this node */ 
    ptr = temp; /* point to next node to be deleted */ 
  } 
} 
 
/* this is the main routine where all the glue logic fits */ 
main() 
{ 
  char suppType[100],productDescription[100]; 
  int productNumber, quantityWholesale, quantityRetail, ch = 1;
  float wholesale, retail; 
  struct node *ptr; 
  while( ch != 7 ) { 
    printf("\n");
    printf("1 add a product \n");
    //should be add a product number 
    printf("2 delete a product number \n"); 
    //should be delete a product number
    printf("3 list the products  for certain supplier type \n");
    //list all occurences of certain supply type 
    printf("4 list all unique supply types \n");
    //list all unique supply types
    printf("5 determine profit for a specific supply type \n"); 
    //determine profit for a specific supplier type
    printf("6 determine the total profit made by owner \n");
    printf("7 quit\n"); 
    scanf("%d", &ch ); 
    float profit = 0;
    struct node *temp;
    switch( ch ) 
      { 
      case 1: /* add a name to end of list */ 
  printf("Enter in supply type -- "); 
  scanf("%s", suppType ); 
  printf("Enter in product number -- "); 
  scanf("%d", &productNumber ); 
  printf("Enter in product Description -- "); 
  scanf("%s", productDescription ); 
  printf("Enter in wholesale price -- "); 
  scanf("%f", &wholesale  ); 
  printf("Enter in the quantity of wholesale items bought -- "); 
  scanf("%d", &quantityWholesale ); 
  printf("Enter in retail price -- "); 
  scanf("%f", &retail );
  printf("Enter in the quantity of retail items bought -- "); 
  scanf("%d", &quantityRetail );  
  ptr = initnode( suppType, productNumber, productDescription, wholesale, quantityWholesale, retail, quantityRetail ); 
  add( ptr ); 
  break; 
      case 2: /* delete a product number */
  if(head == NULL)
    {
      printf("There is nothing in the list, you must add something first. \n");
    }
  else{
    printf("Enter in a product number: "); 
    scanf("%d", &productNumber );
    ptr = searchproductnumber( head, productNumber ); 
    if( ptr ==NULL ) { 
      printf("product number %d not found\n", productNumber ); 
    } 
    else{
      while(searchproductnumber( head, productNumber )!= NULL)
        {
    deletenode( ptr );
    ptr = searchproductnumber( head, productNumber );
        }
    }
  }
  break; 
      case 3: /* list all products for specified supply type */
  if(head == NULL)
    {
      printf("There is nothing in the list, you must add something first. \n");
    }
  else{
    printf("Enter in supply type -- "); 
    scanf("%s", suppType );
    ptr = searchname( head, suppType); 
    if( ptr ==NULL ) { 
      printf("Supply Type %s not found\n", suppType ); 
    } 
    else 
      {
        printlist( head, suppType );
      }
  }
  break; 
      case 4: /* search and print unique supply types */
  listSupTypes( head );
  break; 
      case 5: /* profit for certain supply type*/
  printf("Enter in supply type -- "); 
  scanf("%s", suppType );
  ptr = searchname( head, suppType); 
  if( ptr ==NULL ) { 
    printf("Supply Type %s not found\n", suppType ); 
  } 
  else 
    {
      profit = calcsupptype( ptr, suppType );
      printf("The total profit made by the owner is: $%.02f \n", profit);
      break;
    }
  break; 
      case 6://calculate total profit
  profit = calctotal( head );
  printf("The total profit made by the owner is: $%.02f \n", profit);
  break;
      } //switch
  } //while
  deletelist( head ); 
}
