// Code obtained from Wisconsin Benchmark paper

#include <stdio.h>
#include <stdlib.h>

long prime, generator;
char result[7];

// generates a value between 1 and limit
long myRand(long seed, long limit)
{
   do {
      seed = (generator * seed) % prime;
   } while (seed > limit);
   return seed;
}

char *convert(unique)
int unique;
{ 
   char tmp[7];
   int i,j, rem, cnt;
   for ( i=0 ; i<7 ; i++) 
      result[i]='A';
   i = 6;
   while ( (unique > 0) )
   { 
      rem = unique % 26;
      tmp[i] = 'A' + rem;
      unique = unique / 26;
      i--;
   }
   for (i = i + 1; i <= 6; i++)
   {
      result[i] = tmp[i];
   }

   return (&result[0]);
}

void generate_relation(int tupCount)
{
   FILE *f = fopen("out.txt", "w");
   int i, unique1, unique2, two, four, ten, twenty, onePercent, tenPercent, twentyPercent, 
   fiftyPercent, unique3, evenOnePercent, oddOnePercent;
   char *stringu1, *stringu2, *string4;
   long myRand(), seed;
   seed = generator;

   for(int i = 0; i < tupCount; i++) {
      seed = myRand(seed, (long)tupCount);
      unique1 = (int)seed - 1;
      unique2 = i;
      // all the other values generated here
      two = unique1 % 2;
      four = unique1 % 4;
      ten = unique1 % 10;
      twenty = unique1 % 20;
      onePercent = unique1 % 100;
      tenPercent = unique1 % 10;
      twentyPercent = unique1 % 5;
      fiftyPercent = unique1 % 2;
      unique3 = unique1;
      evenOnePercent = (onePercent * 2);
      oddOnePercent = (onePercent * 2) + 1;
      stringu1 = convert(unique1);
      stringu2 = convert(unique2);
      // generate string4
      if((i % 4) == 0) string4 = "AAAAAAA";
      else if((i % 4) == 1) string4 = "HHHHHHH";
      else if((i % 4) == 2) string4 = "OOOOOOO";
      else string4 = "VVVVVVV";

      fprintf(f, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%s,%s,%s\n", unique1, unique2, 
      two, four, ten, twenty, onePercent, tenPercent, twentyPercent, fiftyPercent, unique3, 
      evenOnePercent, oddOnePercent, stringu1, stringu2, string4);
   }
}

int main(int argc, char *argv[])
{
   int tupCount;             // number of tuples in result relation
   tupCount = atoi(argv[1]); // get the desired table size
   if(tupCount <= 1000)           { generator = 279; prime = 1009; }
   else if(tupCount <= 10000)     { generator = 2969; prime = 10007; }
   else if(tupCount <= 100000)    { generator = 21395; prime = 100003; }
   else if(tupCount <= 1000000)   { generator = 2107; prime = 10000; }
   else if(tupCount <= 10000000)  { generator = 211; prime = 10000; }
   else if(tupCount <= 100000000) { generator = 21; prime = 10000; }
   else { printf("too many rows requested.\n"); return 1; }

   generate_relation(tupCount);
}
