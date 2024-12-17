#include <stdio.h>
#include <stdlib.h>


void nhapmang(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}


void hienmang(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int tinhdodaimang(int n) {
    return n;
}


int tinhtong(int *arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i];
    }
    return tong;
}


int phantumax(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n = 0; 
    int luaChon;
    int *arr = NULL; 

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &n);

            
               
                if (arr == NULL) {
                    printf("Khong du bo nho!\n");
                    exit(1);
                }

                nhapmang(arr, n);
                break;
            case 2:
                if (n > 0) {
                    hienmang(arr, n);
                } else {
                    printf("Mang chua duoc nhap!\n");
                }
                break;
            case 3:
                printf("Do dai mang: %d\n", tinhdodaimang(n));
                break;
            case 4:
                if (n > 0) {
                    printf("Tong cac phan tu trong mang: %d\n", tinhtong(arr, n));
                } else {
                    printf("Mang chua duoc nhap!\n");
                }
                break;
            case 5:
                if (n > 0) {
                    printf("Phan tu lon nhat: %d\n", phantumax(arr, n));
                } else {
                    printf("Mang chua duoc nhap!\n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    } while (luaChon != 6);

    
    if (arr != NULL) {
        free(arr);
    }

    return 0;
}

					 	
