#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char *num;
num add(num a, num b);
num subtract(num a,num b);
num multiplynumber( num a, int b);
num multiplystrings(num a, num b);
int valuecompare(num a,num b);
int stringcompare(num a, num b);

    // code for addition of two strings
    num add(num a, num b){
		        num add_answer;
			    int i,y,differ_length,carry;
				carry = 0;
				differ_length= stringcompare(a,b);//call to stringcompare function to find difference between lengths
		if(differ_length!=0){           
				if(valuecompare(a,b) == 1){ // call to valuecompare fxn for comparing the value 
					y = strlen(a);
					add_answer = (char *)malloc((y+2)*sizeof(char));
					strcpy(add_answer,a);
					add_answer[y] = '\0'; // ending the string with null character
					for(i=strlen(b)-1;i>=0;i--){    // loop iteration according to the value of b
					add_answer[i+differ_length] = ((a[i+differ_length]-'0') + (b[i]-'0') +carry )%10 + '0';
                    carry = ((a[i+differ_length]-'0') + (b[i]-'0') + carry )/10;
				   }  
				   i = differ_length-1;
				   // if carry is not equal to zero
				if(carry!=0){
				    while(carry!=0 && i>=0){  // keep adding the carry till it becomes non zero
						add_answer[i]= ((a[i]-'0')+carry)%10 +'0';
						carry = ((a[i] - '0') + carry)/10;
						i--;
					} 
					// if carry is still non zero after iterating through complete string a
			   if(carry!=0){
				        add_answer[i+1]= ((a[i+1]-'0') +carry)%10 + '0';
					    for(i=y;i>0;i--){   // shift the string by one charcter to its right
						add_answer[i] = add_answer[i-1];
						} 
						// put the carry at 0th index
						add_answer[0] = '1';
						add_answer[y+1]= '\0';
				   }
				 } 
		    }				
				else{   // case when b>a
					y = strlen(b);
					add_answer = (char *)malloc((y+2)*sizeof(char));
					strcpy(add_answer,b);
					add_answer[y] = '\0';
					for(i=strlen(a)-1;i>=0;i--){
					add_answer[i+differ_length] = ((a[i]-'0') + (b[i+differ_length]-'0') +carry )%10 + '0';
                    carry = ((a[i]-'0') + (b[i+differ_length]-'0') + carry )/10;
				}
				   i = differ_length-1;
				    // if carry is not equal to zero
				   if(carry!=0){
				    while(carry!=0 && i>=0){   // keep adding the carry till it becomes non zero
						add_answer[i]= ((b[i]-'0')+carry)%10 +'0';
						carry = ((b[i] - '0') + carry)/10;
						i--;
					} 
					// if carry is still non zero after iterating through complete string b
			   if(carry!=0){
				        add_answer[i+1]= ((b[i+1]-'0') +carry)%10 + '0';
					    for(i=y;i>0;i--){      // shift the string by one charcter to its right
						add_answer[i] = add_answer[i-1];
						} 
						// put the carry at 0th index
						add_answer[0] = '1';
						add_answer[y+1]= '\0';
				   }
				 } 
				}
		}
            else{ // it is the case when strings are of equal length
				y = strlen(a);
				add_answer = (char *)malloc((y+2)*sizeof(char));
				for(i=y-1;i>=0;i--){
					add_answer[i] = ((a[i]-'0') + (b[i]-'0') +carry )%10 + '0';
                    carry = ((a[i]-'0') + (b[i]-'0') + carry )/10;
				}
				add_answer[y]= '\0'; // ending the string with null character
                 // if carry is non zero after iterating through complete string 				
	                if(carry!=0){
					for(i=y;i>0;i--){  //shift string by one character to its right
						add_answer[i] = add_answer[i-1];
						}
						// put the value of carry at 0th index
						add_answer[0] = carry + '0';
						add_answer[y+1]= '\0';
				   }
			}
				return add_answer;  // return the pointer add_answer
	}		
	
	
// subtraction of two strings
    num subtract(num a,num b){
			  int x,y,differ_length,i,j;
			  num sub_answer,second_number;
			        x = strlen(a);
			        y = strlen(b);
			        sub_answer =  (char *)malloc((x+1)*sizeof(char));
			        second_number =  (char *)malloc((x+1)*sizeof(char));
			        j = valuecompare(b,a); // compare the value of a and b
			        if(j == 1){ // case where b>1 
					 printf("enter the bigger number at first place\n");
					    free(sub_answer);
					    exit(EXIT_FAILURE);
					 }
					 if(j == 0){ // case where a and b are equal
						 sub_answer[0]= '0';
						 sub_answer[1]='\0';
						 return(sub_answer);
					 }
					 differ_length = stringcompare(a,b); // finding the difference between the lengths of strings
					 //making the 'b' length string equal to 'a' length by storing it in second_number
					 if(differ_length!=0){
						 for(i=0;i<differ_length;i++){
							 second_number[i]='0';
						 }
						 for(j=i;j<i+y;j++){  // copying value of b after the last 0 assigned in second_number
							 second_number[j] = b[j-i];
						 }
						 second_number[j] = '\0'; // ending string with null character
					 }
					 else{
						 strcpy(second_number,b); // directly copying b in second_number
					 }
					 strcpy(sub_answer,a); // copying string a in sub_answer
					 for(i=x-1;i>=0;i--){ // perform subtraction of corresponding digits
						 if( sub_answer[i]-'0' >= second_number[i]-'0' ){
							 sub_answer[i] = (sub_answer[i]-'0') - (second_number[i]-'0') + '0';
						 }
						 else{
							 sub_answer[i] = ((sub_answer[i]-'0')+10) - (second_number[i]-'0') + '0' ;
							 sub_answer[i-1] = (sub_answer[i-1]-'0')-1 + '0';
							 }
						 }
					// deleting the extra zero's from the left
				      i=0;
					 while(sub_answer[i]== '0'){
							i++;
					 }
					 // shifting the string at the 0th index after deleting the zeros
					 for(j=i;j<=x;j++){
						 sub_answer[j-i]=sub_answer[j];
					 }
					 free(second_number);
                return(sub_answer); // return the answer of subtraction as char pointer
		}	
   
	// Multiplying a string with a number
		num multiplynumber( num a, int b){
			   int i,x,carry=0;
			   num multi_num_ans;
			   x = strlen(a);
			   if(b==0){ // if the 2nd number is zero
				   multi_num_ans = (char *)malloc(2*sizeof(char));
				   multi_num_ans[0] = '0';
				   multi_num_ans[1] = '\0';
				   return multi_num_ans;
			   }
			   // if number is non zero 
			   multi_num_ans =(char *)malloc((x+2)*sizeof(char));
			   for(i=x-1;i>=0;i--){  // multiply string individually character by character
					   multi_num_ans[i]= ((a[i]-'0')*b + carry)%10 + '0';
					   carry = ((a[i]-'0')*b + carry)/10;
				   }
				   multi_num_ans[x]= '\0'; // Put null character at the end
				   // if carry is not equal to zero
				   if(carry!=0){
				       for(i=x;i>0;i--){  //shift the string by 1 character to it's right
						multi_num_ans[i] = multi_num_ans[i-1];
						}
						// put the value of carry at the 0th index
						multi_num_ans[0] = carry + '0';
						multi_num_ans[x+1]= '\0';
				   }
			    return multi_num_ans;
			   }	
			   
		// multiply two strings
		   num multiplystrings(num a, num b){
					int i,j,x,y;
					num ptr,mul_answer,multiplication,addition;
					x = strlen(b); 
					y = strlen(a);
					  mul_answer = (char *)malloc((y+x+1)*sizeof(char));
					  mul_answer[0] = '0'; // initially assigning value 0 to the answer
					  mul_answer[1] = '\0'; 
					  for(i=x-1;i>=0;i--){ // perform multiplication according to the string b
					  ptr = multiplynumber(a,b[i]- '0'); // call to multiplication fxn for multiplying by individual characters
					  multiplication = (char *)malloc((y+x+1)*sizeof(char));
					  strcpy(multiplication,ptr);
					  free(ptr); // freed the memory allocated by multiplynumber function 
					  y = strlen(multiplication);
					 for(j=0;j<x-i-1;j++){   // assign zeros at the last of the number accordingly
					    multiplication[y] = '0'; 
						y++;
					 }	
					 multiplication[y]= '\0';					 
                     addition = add(mul_answer,multiplication); // call to addition fxn
					 free(multiplication); // freed multiplication for assigning next value
                     strcpy(mul_answer,addition);
                     free(addition);  // freed the memory allocated by addition fxn					
			   }  
				return(mul_answer);
		   }
	// string compare
		int stringcompare (num a, num b){
			    int differ_length;
				int x,y;
				x= strlen(a);
				y=strlen(b);
               	if(x>y){
					differ_length = x-y;
				}
                else{
					differ_length = y-x;
				}	
            return 	differ_length;			
		}
		
//  compares the value between two strings 
    int valuecompare(num a,num b){
		 int x,y,i;
		 x= strlen(a);
		 y= strlen(b);
		 if(x>y)
			 return 1;
		 else if(x<y)
			 return -1;
		 else {
			 for(i=0;i<x;i++){
				 if(a[i]>b[i]){
					return 1;	
                    break;				
				}
				else if(a[i]<b[i]){
					return -1;
					break;
				}	
		 }
	}
	return 0;
}
		