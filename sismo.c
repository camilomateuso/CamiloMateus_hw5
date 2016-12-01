#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float likelihood(float *tiempo);
int main(void){

  time_t t;
  int L =200000;
  float velocidad = 5.0;
  float *like;
  like = malloc (sizeof(float) * 200000);
  float *posicionX;
  posicionX = malloc (sizeof(float) * 200000);
  float *posicionY;
  posicionY = malloc (sizeof(float) * 200000);
 
  float posicion0X[6]= {3,4,5,3,4,5};
  
  float posicion0Y[6]={15,15,15,16,16,16};
  float *tiempos;
  tiempos = malloc (sizeof(float) * 6);
  float *tiemposrand;
  tiemposrand = malloc (sizeof(float) * 6);
  float xrand=0;
  float yrand=0;
  int i =1;
  int k=0;
  float lhood = 0;
  float lhoodrand = 0;
  float ratio = 0;
  int j =0;
  
  
  	srand((unsigned) time(&t));

	posicionX[0] = rand()%20;
	posicionY[0] = rand()%20;
	while(k<6){
     	tiemposrand[k] = sqrt( pow(posicion0X[k]-posicionX[0],2) + pow(posicion0Y[k]-posicionY[0],2))/velocidad; 
	k = k+1;
 	}
	
	while(i<L){
    
     xrand = posicionX[i-1] + (rand()%100)/40.0 - (rand()%100)/40.0 ;
     yrand = posicionY[i-1] + (rand()%100)/40.0 - (rand()%100)/40.0 ;
     k = 0 ;
     while(k<6){
     tiemposrand[k] = sqrt( pow(posicion0X[k]-xrand,2) + pow(posicion0Y[k]-yrand,2))/velocidad ;
	k = k+1 ;
     }
     while(k<6){
     tiempos[k] = sqrt( pow(posicion0X[k]-posicionX[i-1],2) + pow(posicion0Y[k]-posicionY[i-1],2))/velocidad ;
	k = k+1 ;
     }
     lhood = likelihood(tiempos) ;
     lhoodrand = likelihood(tiemposrand) ;

     ratio = lhoodrand/lhood ;
     if(ratio>= 1.0){
	posicionX[i] = xrand ;
	posicionY[i] = yrand ;
	like[i] = lhoodrand ;
	}
     else{

	if(rand()%1<=ratio){
	posicionX[i] = xrand ;
	posicionY[i] = yrand ;
	like[i] = lhoodrand ;
	}
	else{
	posicionX[i] = posicionX[i-1] ;
	posicionY[i] = posicionY[i-1] ;
	like[i] = lhood ;
	}
     
   
     }
 i = i+1;
	}
	for(i=0;i<L;i++){
     

        
        printf("%f %f\n",posicionX[i],posicionY[i]);
         }
         
} 

float likelihood(float *tiempo){

 
  float tiempos0[6]={3.12,2.98,2.84,3.26,3.12,2.98};
  float suma = 0;
  int j=0;
  while(j<6){
	suma += pow(tiempo[j]-tiempos0[j],2);
	j+=1;
  }
  float chisq = (1.0/2.0)*suma;
  return exp(-chisq);
}
 


 
     




