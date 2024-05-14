#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include<pthread.h>
#include<math.h>

float x , y , dis = 0.0;
int c = 0 , s = 0;

void *floatRandom(void *n){
   int limit = (int *) (n);
   float randomNum1 , randomNum2;
   
      srand((unsigned int)time(NULL));
       
      for(int i=1;i<=limit;i++)
      {
         x = (((float)rand())/RAND_MAX) * 2 - 1;
       
         y = (((float)rand())/RAND_MAX) * 2 - 1;
         
         //calculateDistance(x,y);
         
         dis =  sqrt((x*x) + (y*y));
         
         if(dis >= 1.0)
         {
           s++ ;
         }
         else
         {
           c++;
         }
         
         printf("%f %f %f\n",x,y,dis);
         
      }
       
     
}

int main(int argc, char *argv[])
{
  // floatRandom();
   
   pthread_t tid[10];
   pthread_attr_t attr1;
   
   float limit = 10;
   
   
   //pthread_attr_init(&attr);
   
   for(int i=0;i<10;i++)
   {
   }
   
   pthread_create(&tid1,NULL,floatRandom,(void*) &limit);
   
   pthread_join(tid1,NULL);
   
   
   printf("%d %d %f",s,c,4*((float)c/(float)(c+s)));


}