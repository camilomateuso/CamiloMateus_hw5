#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float likelihood(float *tiempo);
int main(void){

  time_t t;
  int L =200000;
  float *like;
  like = malloc (sizeof(float) * 200000) ;
  float *logM;
  logM = malloc (sizeof(float) * 200000);
  float *n;
  n = malloc (sizeof(float) * 200000);
  float G=6.67*pow(10,-11);
  float radios[8] ={0.337,0.7218,1.001,1.37,5.07,9.387,20.06,30.02};
  
  float *logvelocidad;
  logvelocidad = malloc (sizeof(float) * 8);
  float *logvelocidadrand;
  logvelocidadrand = malloc (sizeof(float) * 8);
  float logMrand =0;
  float nrand = 0;
  int k=0;
  int j=0;
  
  
  int i =1;
  
  	srand((unsigned) time(&t));

	logM[0] = rand()%20;
	n[0] = rand()%20;
	
	
  while(i<L){
    
     logMrand = logM[i-1] + (rand()%100)/10.0 - (rand()%100)/10.0; 
     nrand = n[i-1] + (rand()%100)/10.0 - (rand()%100)/10.0;
     k = 0;
     while(k<8){
     logvelocidadrand[k] = (log(G)+logMrand -nrand*log(radios[k]));
	k = k+1;
 	}
     while(k<8){
     logvelocidad[k] = (log(G)+logM[i-1] -n[i-1]*log(radios[k]));
	k = k+1;
 	}
     float lhood = likelihood(logvelocidad);
     float lhoodrand = likelihood(logvelocidadrand);

     float ratio = lhoodrand/lhood;
     if(ratio>= 1.0){
	logM[i] = logMrand;
	n[i] = nrand;
	like[i] = lhoodrand;
	}
     else{

	if(rand()%1<=ratio){
	logM[i] = logMrand;
	n[i] = nrand;
	like[i] = lhoodrand;
	}
	else{
	logM[i] = logM[i-1];
	n[i] = n[i-1];
	like[i] = lhood;
	}
    } 
    i = i+1;
}
for(i=0;i<L;i++){
      

        
        printf("%f %f\n",logM[i],n[i]);
         }
         
  }
  
  
float likelihood(float *logvelocidad){
  
  float logvelocidades0[8]={16.287,9.128,7.31,4.5392,1.954,2.059,1.359,0.965};
  int j =0;
  float suma = 0;
  while(j<8){
	suma += pow(logvelocidades0[j]-logvelocidad[j],2);
	j=j+1;
  }
  float chisq = (1.0/2.0)*suma;
  return exp(-chisq);
}
 

