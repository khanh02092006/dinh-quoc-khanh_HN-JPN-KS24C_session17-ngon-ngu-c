#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void nhapchuoi(char *str){
	printf(" nhap chuoi ");
	fgets(str,100,stdin);
	str[strcspn(str,"\n")]=0;
	}
int inchuoi(char *str){
    printf("chuoi:%s\n",str);
	}
int demchucai(char *str){
    int dem=0;
    while(*str){
    	if(isalpha(*str)){
    		dem++;
    	}
    		*str++;
   	}	
    return dem;
}
int demchuso(char *str){
	int dem=0;
    while(*str){
	if(isdigit(*str)){
		dem++;
		}
		*str++;
	}
	return dem;
}
int demkytudacbiet(char *str){
	int tongkytu=strlen(str);

   return tongkytu-demchucai(str)-demchuso(str);
 }
int main(){
    char chuoi[100];
	int lua_chon;
	do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi\n");
        printf("4. Dem so luong chu so trong chuoi\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &lua_chon);
    switch(lua_chon){\
	    case 1:
	   	nhapchuoi(chuoi);
	   	break;
		case 2:
		inchuoi(chuoi);
		break;
		case 3:
		printf("so luong chu cai%d\n",demchucai(chuoi));
		break;
		case 4:
		printf("so luong chu so%d\n",demchuso(chuoi));
		case 5:
		printf("so luong ki tu dac biet %d\n",demkytudacbiet(chuoi));
		break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    } while (lua_chon != 6);

    return 0;
}   	
		
		
			
			
	

