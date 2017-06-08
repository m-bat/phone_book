#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 30
#define MAXNUMBER 15
#define MODENAME 7
#define ANSWERNAME 4

struct word{
	char name[MAXNAME];
	char number[MAXNUMBER];
	struct word *next;
	struct word *pre;
};

struct word head;

int  add_word(struct word book);
struct word * search_word(char *buf);
void list_printf(struct word *q);
void delete_word(struct word  *buf);


int main()
{
	
	struct word book;
	struct word *wtab;

	char str[MODENAME], answer[ANSWERNAME];
	int result, yes, no;

	head.next = head.pre = &head;

	printf("Please register name and phone number\n");
	
	while ((scanf("%s %s", book.name, book.number)) != EOF) {
		add_word(book);
	}

	printf("\n");

	printf("Please input mode. list or search or delete or exit? : ");

	rewind(stdin);
	
	while (scanf("%s", str) != EOF) {
		if ((result = strcmp("list", str)) == 0) {
			list_printf(&head);
		printf("Please input mode. list or search or delete or exit? : ");
		}
		
		else if ((result = strcmp("search",str)) == 0){
			printf("Please input search name : ");
			scanf("%s", book.name);
			wtab=search_word(book.name);
			if (wtab == NULL) {
				do{
					printf("Can't find name!\n");
					printf("Do you register this name? yes or no : ");
					scanf("%s", answer);
					yes = strcmp("yes", answer);
					no = strcmp("no", answer);
				}while (yes != 0 && no != 0);
				if (yes == 0){
					printf("Please input phone number: ");
					scanf("%s", book.number);
					add_word(book);
					printf("Please input mode. list or search or delete or exit? : ");
				}
				if(no == 0){
					printf("Please input mode. list or search oe  delete or exit? : ");
				}	
				
				
			}
			else{
				printf("%s %s\n", wtab->name, wtab->number);
				printf("Please input mode! list or search or delete or exit? : ");
				
			}
		}
		else if ((result = strcmp("delete", str)) == 0) {
			printf("Please input delete name : ");
			scanf("%s", book.name);
			wtab = search_word(book.name);
			
			if(wtab == NULL){
				printf("This name don't register!\n");
				printf("Please input mode. list or search oe  delete or exit? : ");
			
			}else{
				delete_word(wtab);
				printf("Success delete!\n");
				printf("Please input mode! list or search or delete or exit? : ");
			}
		}			
		else if ((result = strcmp("exit", str)) == 0) {
			printf("Program exit!\n");
			free(head.next);
			return 0;
		}
		else
		printf("No Mode! One more time :  ");
	}
	
	free(head.next);
	
	return 0;
	
}

int add_word(struct word book)
{

	struct word *p, *wtab, *n;
	int name_result;


	if ((p = (struct word *)malloc(sizeof(struct word))) == NULL) {
		fprintf(stderr, "Can't malloc Memory!\n");
		exit(1);
	}
	
	strcpy(p->name, book.name);
	strcpy(p->number, book.number);

	wtab=head.next;

	if (wtab != &head)
		name_result=strcmp(wtab->name, p->name);
	
	

	while (wtab != &head) {

		if (name_result == 0) {
			free(p);
			return -1;
		}
		
		else if (name_result < 0) {
			wtab = wtab -> next;
			name_result = strcmp(wtab -> name, p -> name);
		}
		else
			break;
	}

	n = wtab;
	p -> next = n;
	p -> pre = n -> pre;
	n -> pre -> next = p;
	n -> pre = p;
	
	return 0;
}


struct word * search_word(char *search_name)
{

	struct word *wtab;
	int result;

	for (wtab = head.next; wtab != &head; wtab = wtab -> next) {
		if((result = strcmp(search_name, wtab -> name)) == 0){
			return wtab;
		}
	}

	return NULL;
}

void list_printf(struct word *q)
{
	struct word *wtab;
	if(q->next == &head)
		printf("No register name and phone number!\n");
	
	else
		for(wtab = q->next; wtab != q; wtab = wtab -> next){
			printf("%s %s\n", wtab -> name, wtab -> number);
		}
	
}

void delete_word(struct word *delete_name)
{
	delete_name -> next -> pre = delete_name ->pre;
	delete_name -> pre -> next = delete_name -> next;
	delete_name -> next = delete_name -> pre = NULL;

	free(delete_name);
}





			
	   
  




	  
		
