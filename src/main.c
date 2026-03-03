#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

struct Person {
    char surname[MAX_LEN];
    char name[MAX_LEN];
    char patronymic[MAX_LEN];
    int index;
    char country[MAX_LEN];
    char region[MAX_LEN];
    char district[MAX_LEN];
    char city[MAX_LEN];
    char street[MAX_LEN];
    int house;
    int apartment;
    char phone[MAX_LEN];
};

int main() {
    FILE *input = fopen("input.txt", "r");
    if (!input) {
        printf("Error to open input.txt\n");
        return 1;
    }
    
    FILE *output = fopen("output.txt", "w");
    if (!output) {
        printf("Error to open output.txt\n");
        fclose(input);
        return 1;
    }
    
    char line[1024];
    struct Person p;
    int found_count = 0;
    
    while (fgets(line, sizeof(line), input)) {
        line[strcspn(line, "\n")] = 0;
        if (strlen(line) == 0) continue;
        
        
        int parsed = sscanf(line, "%s %s %s %d %s %s %s %s %s %d %d %s",
               p.surname, p.name, p.patronymic, &p.index,
               p.country, p.region, p.district, p.city,
               p.street, &p.house, &p.apartment, p.phone);
        
        if (parsed == 12 && strncmp(p.phone, "621", 3) == 0) {
            found_count++;
            
            fprintf(output, "Запись #%d:\n", found_count);
            fprintf(output, "  ФИО: %s %s %s\n", p.surname, p.name, p.patronymic);
            fprintf(output, "  Индекс: %d\n", p.index);
            fprintf(output, "  Страна: %s\n", p.country);
            fprintf(output, "  Область: %s\n", p.region);
            fprintf(output, "  Район: %s\n", p.district);
            fprintf(output, "  Город: %s\n", p.city);
            fprintf(output, "  Улица: %s\n", p.street);
            fprintf(output, "  Дом: %d\n", p.house);
            fprintf(output, "  Квартира: %d\n", p.apartment);
            fprintf(output, "  Телефон: %s\n", p.phone);
            fprintf(output, "\n");
        }
    }
    
    if (found_count == 0) {
        fprintf(output, "Владельцы с номерами 621 не найдены.\n");
    } else {
        fprintf(output, "Всего найдено: %d записей\n", found_count);
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}
