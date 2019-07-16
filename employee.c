#include <stdio.h>
#include <string.h>

typedef struct {
	int staffID;
	char familyName[23];
	int age;
	int salary;
} Employee;


void add_employee(Employee person, int *id)
{
	char key[10];
	
	do{
		printf("追加する社員の名前を入力してください: ");
		scanf("%s", person.familyName);
		printf("年齢を入力してください: ");
		scanf("%d", &person.age);
		printf("年俸を入力してください: ");
		scanf("%d", &person.salary);
		person.staffID = *id;

		printf("以下の社員をデータベースに追加してよいですか？\n");
	
		printf("ID: %d\nName: %s\nAge: %d\nSalary: %d\n\n", *id, person.familyName, person.age, 						person.salary);
		do{
			printf("(Y/N/E)? ");
			scanf("%s", key);
			if(strcmp(key, "Y") == 0){
				printf("\n追加しました.\n\n");
				*id = *id + 1;
			}
		}while(strcmp(key, "Y") != 0 && strcmp(key, "E") != 0 && strcmp(key, "N") != 0);

		if(strcmp(key, "N") == 0){
			printf("社員の追加を終了します. \n");
		}
	}while(strcmp(key, "E") == 0);
}

void show_list(Employee people[], int id)
{
	//int i;
	if(id == 1){
		printf("登録社員はいません.\n");
	}else{
		printf("age is %d", people[0].age);
	}
}


int main(void)
{

	int menu, delete_id;
	int id = 1;
	Employee employees[100];

	do{
		
		printf("**** 社員データベース管理プログラム ****\n1: 社員追加\n2: 社員削除\n3: 昇給\n4: 社員検索（名前）\n5: 社員検索（年俸）\n6: 全社員の表示（名前順）\n7: 全社員の表示（年俸順）\n\n9: End\n\n");
		printf("Select a number ? ");
		scanf("%d", &menu);
		if(menu < 1 || menu == 8 || menu > 9){
			menu = 0;
			while(getchar() != '\n')
				;
		}

		switch(menu){
			case 1:
				printf("社員を追加します.\n\n");
				add_employee(employees[id], &id);
				break;
			case 2:
				if(id == 1){
					printf("社員は存在しません\n");
				}else{
					do{
						printf("社員を削除します.\n\n");
						printf("社員番号1〜%dを入力してください.\n Input: ", id - 1);
						scanf("%d", &delete_id);
					}while(id <= delete_id || delete_id < 1);
					
				}
				break;			
			case 6:	
				show_list(employees, id);
				break;
			case 9:
				break;
			default:
				printf("\n1~7までの数字、または9を入力してください\n");
		}
	} while(menu != 9);

	printf("終了します.\n");

	return 0;
}
