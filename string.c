#include <stdio.h>
#include <stdlib.h>

typedef struct string {
    char val;
    struct string *next;
}String;

String* node(){
    String *string = (String*)malloc(sizeof(String));
    string->val = '\0';
    string->next = NULL;
    return string;
}

void print(String *string) {
    while (string != NULL) {
        printf("%c", string->val);
        string = string->next;
    }
}

void add(String *old_node, char a){
    String* new_node = node();
    new_node->val = a;
    while(old_node->next){
        old_node = old_node->next;
    }
    old_node->next = new_node;
}

String* copy(String* old_string){
    String* new_string = node();
    while (old_string){
        add(new_string, old_string->val);
        old_string = old_string->next;
    }
    return new_string;
}

String* concat(String* first_n, String* last_n, ...){
    String* string_cp1 = copy(first_n);
    String* string_cp2 = copy(last_n);
    String* concat = string_cp1;
    
    while(string_cp1->next){
        string_cp1 = string_cp1->next;
    }
    string_cp1->next = string_cp2;

    return concat;
}

void println(String *string) {
    print(string);
    printf("\n");
}

String* create_string(char* a){
    String *string = node();
    int i=0;
    while(a[i] != '\0'){
        add(string, a[i]);
        i++;
    }
    return string;
}

String* slice(String* string, int a, int b){
    String* new_string = node();
    for (int i = 0; i < a && string->next != NULL; i++){
        string = string->next;
    }
    
    for (int i = a; i < b && string->next != NULL; i++){
        add(new_string, string->val);
        string = string->next;
    }
    return new_string;
}



int main() {
    /* There are 4 main functions: add(), create_string(), concat(), slice() */
    
    //create an empty string
    String* string = node();
    //add single charaters at a time
    add(string, 'H');
    add(string, 'e');
    add(string, 'l');
    add(string, 'l');
    add(string, 'o');
    println(string);
    //actual string
    String* string1 = node();
    string1 = create_string(", World! :) ");
    println(string1);
    //concatinating both strings
    string1 = concat(string, string1);
    println(string1);
    //second string
    String* string2 = node();
    string2 = create_string("Nice to see you here.");
    println(string2);
    //concatinating two strings again
    String* string3 = node();
    string3 = concat(string1, string2);
    println(string3);
    //slicing
    String* string4 = node();
    string4 = slice(string3, 19, 21);
    println(string4);
    
    return 0;
}
