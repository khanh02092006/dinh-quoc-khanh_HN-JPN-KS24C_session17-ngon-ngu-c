#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Hàm nh?p chu?i
void nhapchuoi(char *str) {
    printf("Nhap chuoi: ");
    getchar(); 
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; 
}


void daonguocchuoi(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}


int demtu(char *str) {
    int count = 0;
    char *tachkytu = strtok(str, " "); 
    while (tachkytu != NULL) {
        count++;
        tachkytu = strtok(NULL, " "); 
    }
    return count;
}


void chuhoa(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char chuoi[100]; 
    char *str = (char *)malloc(100 * sizeof(char)); 
    char *newstr = (char *)malloc(100 * sizeof(char)); 
    int lua_chon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1:
                nhapchuoi(chuoi);
                printf("Chuoi vua nhap: %s\n", chuoi);
                break;

            case 2:
                daonguocchuoi(chuoi);
                printf("Chuoi dao nguoc: %s\n", chuoi);
                break;

            case 3: {
                char tam[100];
                strcpy(tam, chuoi); 
                int so_tu = demtu(tam);
                printf("So luong tu trong chuoi: %d\n", so_tu);
                break;
            }

            case 4:
                printf("Nhap chuoi khac: ");
                nhapchuoi(newstr);
                if (strcmp(chuoi, newstr) == 0) {
                    printf("Hai chuoi giong nhau.\n");
                } else {
                    printf("Hai chuoi khac nhau.\n");
                }
                break;

            case 5:
                chuhoa(chuoi);
                printf("Chuoi sau khi in hoa: %s\n", chuoi);
                break;

            case 6:
                printf("Nhap chuoi khac: ");
                nhapchuoi(newstr);
                strcat(chuoi, newstr); 
                printf("Chuoi sau khi noi: %s\n", chuoi);
                break;

            case 7:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }
    } while (lua_chon != 7);

  
    free(str);
    free(newstr);

    return 0;
}

