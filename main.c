// From Listing 9.2 Displaying the Addresses of Successive Array Elements; p.196
// Note: when I run this with Netbeans/Mingw/Msys on Windows PC, the address
//      output displays in Hex. Output in the book is NOT hex. Not sure why.
//      I also added to this example so that I initialized the arrays and then
//      demonstrated how to print out their actual CONTENTS/VALUE FOR EACH ELEMENT

// ***** WRITING OUTPUT TO A FILE NOW TOO IN ADDITION TO STDOUT
#include <stdio.h>
#include <stdlib.h>

void clear_kb(void);

//declare a counter and 3 arrays
int ctr;
short array_s[10] = {1,2,3,4,5,6,7,8,9,10};
float array_f[10] = {1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5,10.5};
double array_d[10] = {1.55,2.55,3.55,4.55,5.55,6.55,7.55,8.55,9.55,10.55};
//added a pointer to make more of an example pointer vs value
short int *ptr1_s;
float *ptr2_f;

char filename[20];

int main(void)
{

    //FILE * pFile;
    //pFile = fopen ("myfile.txt","w");
    //if (pFile!=NULL)
    //{
    //  fputs ("fopen example",pFile);
    //  fclose (pFile);
    //}
    //
    FILE *fp;
    // It put the text file in documents/netbeans/cppapplication_2_kam
    // I have no idea why it put it there.  Note: this set of commands
    // overwrites whatever is in the file each time - see fopen() for more info

    fp = fopen ("kamfile1.txt","w");
    if (fp!=NULL)
    {
      fputs ("fopen OK",fp);
      //fclose (fp);
    }
    else
    {
        fprintf(stderr, "Error opening file %s.",fp);
        exit(1);
    }
    // from book on page 425 if you want to try to prompt user for a filename
    // I couldn't get this to work so I hardcoded a filename above. Compiler
    // also didn't like gets() - I had to use fgets() instead

    //clear_kb();

    //puts("Enter a name for the file:");
    //puts("**************************");
    //fgets(filename,sizeof(filename),stdin);
    //
    //if((fp = fopen(filename, "w")) == NULL)
    //{
    //    fprintf(stderr, "Error opening file %s.",filename);
    //    exit(1);
    //}
    //fflush stdin;
    //

    //assign ptr1_s the address of the 5th element in array_s
    ptr1_s = &array_s[5];
    ptr2_f = &array_f[5];

    // print the table heading
    //prints to stdout
    printf("\nTable of ADDRESSES FOR EACH ARRAY\n\n");
    printf("\t\t Short\t\t\t Float\t\t\tDouble");
    printf("\n===================================");
    printf("=====================================\n");
    //prints to file
    fprintf(fp,"\nTable of ADDRESSES FOR EACH ARRAY\n\n");
    fprintf(fp,"\t\t Short\t\t\t Float\t\t\tDouble");
    fprintf(fp,"\n===================================");
    fprintf(fp,"=====================================\n");
    //print the ADDRESS of each array element
    for(ctr=0; ctr<10; ctr++)
    {
        //prints to stdout
        printf("\nElement %d:\t%p\t\t%p\t\t%p",ctr,
                &array_s[ctr],&array_f[ctr],&array_d[ctr]);
        //prints to file
        fprintf(fp,"\nElement %d:\t%p\t\t%p\t\t%p",ctr,
                &array_s[ctr],&array_f[ctr],&array_d[ctr]);
    }
    //prints to stdout
    printf("\n===================================");
      printf("=====================================\n\n");

    //prints to file
    fprintf(fp,"\n===================================");
      fprintf(fp,"=====================================\n\n");

    //print out the actual VALUES for each array
    //prints to stdout
    printf("\n\nTable of the CONTENTS/VALUE FOR EACH ARRAY ELEMENT\n\n");
    printf("\t\t Short\t\t\t Float\t\t\tDouble");
    printf("\n===================================");
    printf("=====================================\n");
    //prints to file
    fprintf(fp,"\n\nTable of the CONTENTS/VALUE FOR EACH ARRAY ELEMENT\n\n");
    fprintf(fp,"\t\t Short\t\t\t Float\t\t\tDouble");
    fprintf(fp,"\n===================================");
    fprintf(fp,"=====================================\n");

    //print the CONTENTS/VALUE of each array element
    for(ctr=0; ctr<10; ctr++)
    {
        //prints to stdout
        printf("\nElement %d:\t  %d\t\t\t%f\t\t%f",ctr,
                array_s[ctr],array_f[ctr],array_d[ctr]);
        //prints to file
        fprintf(fp,"\nElement %d:\t  %d\t\t\t%f\t\t%f",ctr,
                array_s[ctr],array_f[ctr],array_d[ctr]);
    }
    //prints to stdout
    printf("\n===================================");
      printf("=====================================\n\n\n\n");
    //prints to file
      fprintf(fp,"\n===================================");
      fprintf(fp,"=====================================\n\n\n\n");

    // Extra bit of fun to show address vs contents/value

    // prints to stdout
    printf("\n\t**********************************************************************");
    printf("\n\t*****                     MORE EXAMPLES                            ***");
    printf("\n\t*****                                                              ***");
    printf("\n\t*****         Prints out the address AND the contents              ***");
    printf("\n\t*****               of array_s[5], array_f[5]                      ***");
    printf("\n\t**********************************************************************");
    printf("\n\nThe address of array_s[5] is: %p",ptr1_s);
    printf("\nThe contents/value of array_s[5] is: %d\n",*ptr1_s);
    printf("\n\nPrints out the address and the contents");
    printf("of array_f[5]:\n");
    printf("\nThe address of array_f[5] is: %p",ptr2_f);
    printf("\nThe contents/value of array_f[5] is: %f\n",*ptr2_f);

    //prints to file
    fprintf(fp,"\n\t**********************************************************************");
    fprintf(fp,"\n\t*****                     MORE EXAMPLES                            ***");
    fprintf(fp,"\n\t*****                                                              ***");
    fprintf(fp,"\n\t*****         Prints out the address AND the contents              ***");
    fprintf(fp,"\n\t*****               of array_s[5], array_f[5]                      ***");
    fprintf(fp,"\n\t**********************************************************************");
    fprintf(fp,"\n\nThe address of array_s[5] is: %p",ptr1_s);
    fprintf(fp,"\nThe contents/value of array_s[5] is: %d\n",*ptr1_s);
    fprintf(fp,"\n\nPrints out the address and the contents");
    fprintf(fp,"of array_f[5]:\n");
    fprintf(fp,"\nThe address of array_f[5] is: %p",ptr2_f);
    fprintf(fp,"\nThe contents/value of array_f[5] is: %f\n",*ptr2_f);

    //prints to stdout
    printf("\n\t**********************************************************************");
    printf("\n\t*****                  EVEN MORE EXAMPLES                          ***");
    printf("\n\t*****                                                              ***");
    printf("\n\t*****     After changing the pointer to point to 7th element       ***");
    printf("\n\t*****             -- array_s[7], array_f[7]                        ***");
    printf("\n\t**********************************************************************");
    //set pointer to address of array[7]
    ptr1_s = &array_s[7];
    ptr2_f = &array_f[7];
    printf("\n\nPrints out the address and the contents");
    printf(" of array_s[7]:\n");
    printf("\nThe address of array_s[7] is: %p",ptr1_s);
    printf("\nThe contents/value of array_s[7] is: %d\n\n",*ptr1_s);
    printf("\nPrints out the address and the contents");
    printf("of array_f[7]:\n");
    printf("\nThe address of array_f[7] is: %p",ptr2_f);
    printf("\nThe contents/value of array_f[7] is: %f\n",*ptr2_f);

    //prints to file
    fprintf(fp,"\n\t**********************************************************************");
    fprintf(fp,"\n\t*****                  EVEN MORE EXAMPLES                          ***");
    fprintf(fp,"\n\t*****                                                              ***");
    fprintf(fp,"\n\t*****     After changing the pointer to point to 7th element       ***");
    fprintf(fp,"\n\t*****             -- array_s[7], array_f[7]                        ***");
    fprintf(fp,"\n\t**********************************************************************");
    fprintf(fp,"\n\nPrints out the address and the contents");
    fprintf(fp," of array_s[7]:\n");
    fprintf(fp,"\nThe address of array_s[7] is: %p",ptr1_s);
    fprintf(fp,"\nThe contents/value of array_s[7] is: %d\n\n",*ptr1_s);
    fprintf(fp,"\nPrints out the address and the contents");
    fprintf(fp,"of array_f[7]:\n");
    fprintf(fp,"\nThe address of array_f[7] is: %p",ptr2_f);
    fprintf(fp,"\nThe contents/value of array_f[7] is: %f\n",*ptr2_f);

    //more examples showing incrementing/decrementing pointers
    //
    //prints to stdout
    printf("\n\t**********************************************************************");
    printf("\n\t*****      DIFFERENT EXAMPLES SHOWING POINT ARITHMATIC             ***");
    printf("\n\t*****      after increment/decrementing pointer addresses          ***");
    printf("\n\t*****      Pointers pointed to element[7] previously....           ***");
    printf("\n\t***** Now we will increment by +2 to basically point to element[9] ***");
    printf("\n\t**********************************************************************");
    //...what pointer was previously set to
    //ptr1_s = &array_s[7];
    //ptr2_f = &array_f[7];

    //increments the pointer addresses by 2 to go from pointing to element [7] previously
    // to now pointing to element [9]
    ptr1_s += 2;  //since this pointer is a short integer, it's 2 bytes each element
                  //  ...therefore pointer address here is increasing by 2x2 or 4 bytes
    ptr2_f += 2;  //since this pointer is for a float, it's 4 bytes each element
                  //  ...therefore pointer address here is increasing by 4x2 or 8 bytes

    printf("\n\nPrints out the address and the contents");
    printf(" of array_s[9]:\n");
    printf("\nThe address of array_s[9] is: %p",ptr1_s);
    printf("\nThe contents/value of array_s[9] is: %d\n\n",*ptr1_s);
    printf("\n\nPrints out the address and the contents");
    printf("of array_f[9]:\n");
    printf("\nThe address of array_f[9] is: %p",ptr2_f);
    printf("\nThe contents/value of array_f[9] is: %f\n",*ptr2_f);

    //prints to file
    fprintf(fp,"\n\t**********************************************************************");
    fprintf(fp,"\n\t*****      DIFFERENT EXAMPLES SHOWING POINT ARITHMATIC             ***");
    fprintf(fp,"\n\t*****      after increment/decrementing pointer addresses          ***");
    fprintf(fp,"\n\t*****      Pointers pointed to element[7] previously....           ***");
    fprintf(fp,"\n\t***** Now we will increment by +2 to basically point to element[9] ***");
    fprintf(fp,"\n\t**********************************************************************");
    fprintf(fp,"\n\nPrints out the address and the contents");
    fprintf(fp," of array_s[9]:\n");
    fprintf(fp,"\nThe address of array_s[9] is: %p",ptr1_s);
    fprintf(fp,"\nThe contents/value of array_s[9] is: %d\n\n",*ptr1_s);
    fprintf(fp,"\n\nPrints out the address and the contents");
    fprintf(fp,"of array_f[9]:\n");
    fprintf(fp,"\nThe address of array_f[9] is: %p",ptr2_f);
    fprintf(fp,"\nThe contents/value of array_f[9] is: %f\n",*ptr2_f);

    //****************************************************************************
    //now subtraction to point to element[1]
    //****************************************************************************
    //prints to stdout
    printf("\n");
    printf("\n\t**********************************************************************");
    printf("\n\t*****      DIFFERENT EXAMPLES SHOWING POINT ARITHMATIC             ***");
    printf("\n\t*****      after increment/decrementing pointer addresses          ***");
    printf("\n\t*****      Pointers pointed to element[9] previously....           ***");
    printf("\n\t***** Now we will decrement by -8 to basically point to element[1] ***");
    printf("\n\t**********************************************************************");

    //decrements the pointer addresses by 8 to go from pointing to element [9] previously
    // to now pointing to element [1]
    ptr1_s -= 8;  //since this pointer is a short integer, it's 2 bytes each element
                  //  ...therefore pointer address here is decreasing by 2x8 or 16 bytes
    ptr2_f -= 8;  //since this pointer is for a float, it's 4 bytes each element
                  //  ...therefore pointer address here is decreasing by 4x8 or 32 bytes

    printf("\n\nPrints out the address and the contents");
    printf(" of array_s[1]:\n");
    printf("\nThe address of array_s[1] is: %p",ptr1_s);
    printf("\nThe contents/value of array_s[1] is: %d\n\n",*ptr1_s);
    printf("\nPrints out the address and the contents");
    printf("of array_f[1]:\n");
    printf("\nThe address of array_f[1] is: %p",ptr2_f);
    printf("\nThe contents/value of array_f[1] is: %f\n\n\n\n",*ptr2_f);

    //prints to file
    fprintf(fp,"\n");
    fprintf(fp,"\n\t**********************************************************************");
    fprintf(fp,"\n\t*****      DIFFERENT EXAMPLES SHOWING POINT ARITHMATIC             ***");
    fprintf(fp,"\n\t*****      after increment/decrementing pointer addresses          ***");
    fprintf(fp,"\n\t*****      Pointers pointed to element[9] previously....           ***");
    fprintf(fp,"\n\t***** Now we will decrement by -8 to basically point to element[1] ***");
    fprintf(fp,"\n\t**********************************************************************");
    fprintf(fp,"\n\nPrints out the address and the contents");
    fprintf(fp," of array_s[1]:\n");
    fprintf(fp,"\nThe address of array_s[1] is: %p",ptr1_s);
    fprintf(fp,"\nThe contents/value of array_s[1] is: %d\n\n",*ptr1_s);
    fprintf(fp,"\nPrints out the address and the contents");
    fprintf(fp,"of array_f[1]:\n");
    fprintf(fp,"\nThe address of array_f[1] is: %p",ptr2_f);
    fprintf(fp,"\nThe contents/value of array_f[1] is: %f\n\n\n\n",*ptr2_f);

    fclose(fp);
    printf("\n");

    return 0;
}
//void clear_kb(void)
//{
//    // clears stdin of any waiting characters
//    char junk[80];
//    fgets(junk, sizeof(junk),stdin);
//}
//

