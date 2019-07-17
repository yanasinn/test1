#include <stdio.h>
#include <string.h>

typedef struct {
    int staffID;
    char familyName[23];
    int age;
    int salary;
} Employee;


void add_employee(Employee  *person, int *id, int *number)
{
    char key[10];
    
    do{
        printf("追加する社員の名前を入力してください: ");
        scanf("%s", person->familyName);
        printf("年齢を入力してください: ");
        scanf("%d", &person->age);
        printf("年俸を入力してください: ");
        scanf("%d", &person->salary);
        person->staffID = *id;
        
        printf("以下の社員をデータベースに追加してよいですか？\n");
        
        printf("ID: %d\nName: %s\nAge: %d\nSalary: %d\n\n", *id, person->familyName, person->age, person->salary);
        do{
            printf("(Y/N/E)? ");
            scanf("%s", key);
            if(strcmp(key, "Y") == 0){
                printf("\n追加しました.\n\n");
                *id = *id + 1;
                *number = *number + 1;
            }
        }while(strcmp(key, "Y") != 0 && strcmp(key, "E") != 0 && strcmp(key, "N") != 0);
        
        if(strcmp(key, "N") == 0){
            printf("社員の追加を終了します. \n");
        }
    }while(strcmp(key, "E") == 0);
}

void show_list(Employee *people, int number)
{
    Employee *sorted_employees[100];
    Employee *tmp;
    int i,j;
    if(number == 0){
        printf("登録社員はいません.\n");
    }else{
        for(i = 0; i < number; i++){
            sorted_employees[i] = &people[i];
        }
        for(i = 0; i < number - 1; i++){
            for(j = i + 1; j < number; j++){
                if(strcmp(sorted_employees[i]->familyName, sorted_employees[j]->familyName)  > 0){
                    tmp = sorted_employees[i];
                    sorted_employees[i] = sorted_employees[j];
                    sorted_employees[j] = tmp;
                }
            }
        }
        for(i = 0; i < number; i++){
            printf("番号: %d \n名前: %s\n年齢: %d\n年俸: %d\n\n",
                   (*sorted_employees[i]).staffID, (*sorted_employees[i]).familyName,
                   (*sorted_employees[i]).age, (*sorted_employees[i]).salary);
        }
    }
}

void delete_employee(Employee *people, int *number)
{
    int delete_id, i, index = - 1;
    if(*number == 0){
        printf("登録社員はいません.\n");
    }else{
        for(;;){
            printf("社員を削除します.\n\n");
            printf("社員番号を入力してください.\n Input: ");
            scanf("%d", &delete_id);
            for (i = 0; i < *number ; i++){
                if((people+i)->staffID == delete_id){
                    index = i;
                }
            }
            if(index == -1){
                printf("存在しない社員です.\n");
                continue;
            }
            printf("番号: %d \n名前: %s\n年齢: %d\n年俸: %d\n\n上記の社員を削除しました.\n\n",
                   (people+index)->staffID, (people+index)->familyName,
                   (people+index)->age, (people+index)->salary);
            for(i = index; i < *number - 1; i++){
                *(people+i) = *(people+i+1);
            }
            *number = *number - 1;
            break;
        }
    }
}

void search_name(Employee *people, int *number)
{
    char name[255];
    int i, count = 0;
    printf("検索したい社員の名前を入力してください: ");
    scanf("%s", name);
    for(i = 0; i < *number; i++){
        if(strcmp(name, (people+i)->familyName) == 0){
            count += 1;
            printf("番号: %d \n名前: %s\n年齢: %d\n年俸: %d\n\n", (people+i)->staffID, (people+i)->familyName,
                   (people+i)->age, (people+i)->salary);
        }
    }
    if(count == 0){
        printf("入力された名前の社員は存在しませんでした.\n");
    }
}

void search_saraly(Employee *people, int *number)
{
    int saraly, i, count = 0;
    printf("検索したい社員の年俸を入力してください: ");
    scanf("%d", &saraly);
    for(i = 0; i < *number; i++){
        if(saraly == (people+i)->salary){
            count += 1;
            printf("番号: %d \n名前: %s\n年齢: %d\n年俸: %d\n\n", (people+i)->staffID, (people+i)->familyName,
                   (people+i)->age, (people+i)->salary);
        }
    }
    if(count == 0){
        printf("入力された年俸の社員は存在しませんでした.\n");
    }
}

void upgrade(Employee *people, int *number)
{
    int id, i, index = -1, up;
    printf("昇給する社員の番号(ID)を入力してください: ");
    scanf("%d", &id);
    for(i = 0; i < *number; i++){
        if((people+i)->staffID == id){
            index = i;
        }
    }
    if(index == -1){
        printf("入力された番号(ID)の社員は存在しませんでした.\n");
    }else{
        printf("社員の現在の詳細です.\n\n");
        printf("番号: %d \n名前: %s\n年齢: %d\n年俸: %d\n\n",
               (people+index)->staffID, (people+index)->familyName,
               (people+index)->age, (people+index)->salary);
        printf("昇給額を入力してください.");
        scanf("%d", &up);
        printf("昇給しました．昇給後の社員の詳細です.\n\n");
        (people+index)->salary += up;
        printf("番号: %d \n名前: %s\n年齢: %d\n年俸: %d\n\n",
               (people+index)->staffID, (people+index)->familyName,
               (people+index)->age, (people+index)->salary);
    }
}

void show_sorted_saraly(Employee *people, int number)
{
    Employee *sorted_employees[100];
    Employee *tmp;
    int i,j;
    if(number == 0){
        printf("登録社員はいません.\n");
        return;
    }
    for(i = 0; i < number; i++){
        sorted_employees[i] = &people[i];
    }
    for(i = 0; i < number - 1; i++){
        for(j = i + 1; j < number; j++){
            if((*sorted_employees[i]).salary > (*sorted_employees[j]).salary){
                tmp = sorted_employees[i];
                sorted_employees[i] = sorted_employees[j];
                sorted_employees[j] = tmp;
            }
        }
    }
    for(i = 0; i < number; i++){
        printf("番号: %d \n名前: %s\n年齢: %d\n年俸: %d\n\n",
               (*sorted_employees[i]).staffID, (*sorted_employees[i]).familyName,
               (*sorted_employees[i]).age, (*sorted_employees[i]).salary);
    }
    
}


int main(void)
{
    
    int menu;
    int id = 1, number = 0;
    Employee employees[100];
    employees[0].age = 1;
    employees[0].salary = 321;
    
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
                add_employee(&employees[number], &id, &number);
                break;
            case 2:
                delete_employee(employees, &number);
                break;
            case 3:
                upgrade(employees, &number);
                break;
            case 4:
                search_name(employees, &number);
                break;
            case 5:
                search_saraly(employees, &number);
                break;
            case 6:
                show_list(employees, number);
                break;
            case 7:
                show_sorted_saraly(employees, number);
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
