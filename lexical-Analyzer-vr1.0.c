 #include<stdio.h> 
 #include<ctype.h>
 #include<stdlib.h>
 #include<string.h>
 /*Creating states*/
 typedef enum{start,build_id,identifier,stop,build_num,number} states;
 /* Declaring Function Prototype*/
 states transition(states current_state,char transition_char);
 void main(){
	states current_state;
        char transition_char;
        current_state=start;
        printf("Enter the string \n");
        scanf("%c",&transition_char);
        do{
               if(current_state==identifier){
                  printf("-Identifier\n");
                  current_state=start;            
               }
               else if(current_state==number){
                    printf("-Number\n");
                    current_state=start;
               }
               scanf("%c",&transition_char);
               if(transition_char!=' ')
                 printf("%c",transition_char);
               current_state=transition(current_state,transition_char);
        }while(current_state != stop);
 }
 states transition(states current_state,char transition_char){
	   switch(current_state){
   case start: if(isdigit(transition_char))
                         return build_num;
                     else if(isalpha(transition_char))
                         return build_id;
                     else if(transition_char==' ')
                         return stop;
                     else
                         exit(0);
   case build_id: if(isdigit(transition_char))
                             return build_id;
                          else if(isalpha(transition_char))
                             return build_id;
                          else if(transition_char=='_')
                             return build_id;
                          else if(transition_char==' ')
                             return identifier;
                          else
                             exit(0);
   case identifier: return identifier;
   case build_num: if(isdigit(transition_char))
                                 return build_num;
                              else if(transition_char==' ')
                                return number;
                              else
                                exit(0);
   case number: return number;
   case stop: return stop;
 }
 }