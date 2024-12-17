#include <stdio.h>
#include <stdlib.h>


int kiemtra_nt(int n) {
    if (n <= 1) {
        return 0;
    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

void so_chan(int *arr, int size) {
    printf("Cac phan tu la so chan: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}


void so_nguyento(int *arr, int size) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < size; i++) {
        if (kiemtra_nt(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}


void daonguoc_mang(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    printf("M?ng sau khi d?o ngu?c: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void sap_xep_mang(int *arr, int size, int tang) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((tang && arr[j] > arr[j + 1]) || (!tang && arr[j] < arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int tim_kiem(int *arr, int size, int phantu_tim) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == phantu_tim) {
            return i; 
        }
    }
    return -1; 
}

int main() {    
    int *arr = NULL;
    int size = 0;
    int lua_chon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1: {
               
                printf("Nhap so phan tu: ");
                scanf("%d", &size);

                arr = (int*) malloc(size * sizeof(int));
                if (arr == NULL) {
                    printf("Khong du bo nho!\n");
                    return 1;
                }

                printf("Nhap cac phan tu: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                break;
            }

            case 2: {
                
                so_chan(arr, size);
                break;
            }

            case 3: {
               
                so_nguyento(arr, size);
                break;
            }

            case 4: {
                
                daonguoc_mang(arr, size);
                break;
            }

            case 5: {
               
                int lua_chon_sort;
                printf("1. Sap xep tang dan\n");
                printf("2. Sap xep giam dan\n");
                printf("Lua chon: ");
                scanf("%d", &lua_chon_sort);

                if (lua_chon_sort == 1) {
                    sap_xep_mang(arr, size, 1); 
                } else if (lua_chon_sort == 2) {
                    sap_xep_mang(arr, size, 0); 
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                break;
            }

            case 6: {
                
                int phantu_tim;
                printf("Nhap vao phan tu can tim: ");
                scanf("%d", &phantu_tim);

                int index = tim_kiem(arr, size, phantu_tim);
                if (index != -1) {
                    printf("Phan tu %d duoc tim thay tai chi so %d.\n", phantu_tim, index);
                } else {
                    printf("Phan tu %d khong ton tai trong mang.\n", phantu_tim);
                }
                break;
            }

            case 7: {
               
                printf("Thoat chuong trinh.\n");
                free(arr); 
                break;
            }

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }

    } while (lua_chon != 7);

    return 0;
}
		
