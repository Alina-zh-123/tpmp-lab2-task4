#include <stdio.h>
#include <string.h>

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
    
    while (fgets(line, sizeof(line), input)) {
        line[strcspn(line, "\n")] = 0;
        
        char *fio = strtok(line, " ");
        char *index_str = strtok(NULL, " ");
        char *country = strtok(NULL, " ");
        char *oblast = strtok(NULL, " ");
        char *raion = strtok(NULL, " ");
        char *city = strtok(NULL, " ");
        char *street = strtok(NULL, " ");
        char *house = strtok(NULL, " ");
        char *flat = strtok(NULL, " ");
        char *phone = strtok(NULL, " ");
        
        if (fio && index_str && phone && strncmp(phone, "621", 3) == 0) {
            fprintf(output, "ФИО: %s\n", fio);
            fprintf(output, "Индекс: %s\n", index_str);
            fprintf(output, "Страна: %s\n", country ? country : "не указано");
            fprintf(output, "Область: %s\n", oblast ? oblast : "не указано");
            fprintf(output, "Район: %s\n", raion ? raion : "не указано");
            fprintf(output, "Город: %s\n", city ? city : "не указано");
            fprintf(output, "Улица: %s\n", street ? street : "не указано");
            fprintf(output, "Дом: %s\n", house ? house : "не указано");
            fprintf(output, "Квартира: %s\n", flat ? flat : "не указано");
            fprintf(output, "Телефон: %s\n", phone);
        }
    }
    
    fclose(input);
    fclose(output);
    return 0;
}

