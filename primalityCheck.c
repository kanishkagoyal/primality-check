#include<stdio.h>
#include<time.h>
#include "typedef.c"
void mersennes_prime(num a);
void brutforce(num a);
void fermats(int a);
	int  main(){
		num a;
		int x;
		clock_t t;
		double time_taken;
		printf("This program checks whether a number is prime or not.\n");
		a = "1243476375365388876654434243544655876878978687676565344232121213445465768979878756534232121433567576678";
		printf("The number is %s\n",a);
		x = strlen(a);
		printf("The number is of %d digits\n",x);
		t = clock();
		mersennes_prime(a);
		t = clock() - t; 
	    time_taken = ((double)t)/CLOCKS_PER_SEC;
		printf("it took %f seconds to execute \n", time_taken);
		//brutforce(a);
		return 0;
}
	void mersennes_prime(num a){
			num k,dividend,series,multiply_series,subtract_series,remainders;
			int power,flag,x,p,i;
			 flag =0;
			 power = 0;
			 p=1;
			 x = strlen(a);
			dividend = add(a,"1");	
			while(flag==0){
				k = dividestrings(dividend,"2");
				strcpy(dividend,k);
				free(k);
				power = power+1;
				if(valuecompare(dividend,"1")== 0 ){
					flag =1;
				}
			}
			 free(dividend);
			 series = (char *)malloc((5*x)*sizeof(char));
			 series[0] = '4' ;
			 series[1]='\0';
			 while(valuecompare(a,series) == 1){
			   multiply_series = multiplystrings(series,series);
			   subtract_series = subtract(multiply_series,"2");
			   series[0]='\0';
			   strcpy(series,subtract_series);
			   free(multiply_series);
			   free(subtract_series);
			   p++;
			 }  
			    for(i=p;i<power-1;i++){
				remainders = modulus(series,a);
				series[0]='\0';
				strcpy(series,remainders);
				multiply_series = multiplystrings(series,series);
				subtract_series = subtract(multiply_series,"2");
				series[0]='\0';
				strcpy(series,subtract_series);
				free(multiply_series);
				free(subtract_series); 
				free(remainders);
				}	
				remainders = modulus(series,a);
				if(atoi(remainders)== 0){
					printf("It is a prime number.\n");
				}
				else{
					printf("It is not a prime number.\n");
				}
				free(remainders);
				free(series);	 
	}
	
	// fermat's test
	void fermats(int a){
		    unsigned long long int i,j,k,multiplication,subtract;
			    k=0;
			    for(j=1;j<a;j++){
			    multiplication = 1;
			    for(i=1;i<=a;i++){
					multiplication = multiplication*j;
				}
                subtract = multiplication-j;
                if(subtract%a!=0){
					k=1;
					printf("Not a prime number\n");
					break;
				}					
	       } 
		     if(k==0){
				 printf("It is a prime number\n");
			 }
	          
	}
	
	
	void brutforce(num a){
		    num increment,i,remainder;
			int x,z;
			z=0;
			x = strlen(a);
			i = (char *)malloc((x+1)*sizeof(char));
			i[0] = '2';
			i[1] = '\0';
			while(valuecompare(a,i)==1){
			 remainder = modulus(a,i);
             if(atoi(remainder)== 0){
					printf("It is not a prime number.\n");
					free(remainder);
					z++;
					break;
				}
			free(remainder);
		    increment = add(i,"1");
			strcpy(i,increment);
			free(increment);
	}    
         if(z==0){
			 printf("its a prime number\n");
		 } 	
        free(i);		 
	}
		