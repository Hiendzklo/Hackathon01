#include <stdio.h>

int main() {
    int arr[100], n, choice, position, newElem;
    while (1) {
        //MENU
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Tim gia tri nho nhat va lon nhat trong mang\n");
        printf("4. In ra tong cua tat ca cac phan tu\n");
        printf("5. Them mot phan tu vao cuoi mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Bubble Sort(giam dan)\n");
        printf("8. Linear Search\n");
        printf("9. In ra toan bo so nguyen to trong mang\n");
        printf("10. Selection Sort(tang dan)\n");
        printf("11. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
        	//1.Nhap so phan tu va gia tri cho mang
            case 1:
                printf("Nhap so phan tu mang: ");
                scanf("%d", &n);
                printf("Nhap gia tri cho mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            //2.In ra gia tri
            case 2: 
                printf("Gia tri cac phan tu trong mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            //3. Tim Min,Max
            case 3:
                {
                    int min = arr[0], max = arr[0];
                    for (int i = 1; i < n; i++) {
                        if (arr[i] < min) min = arr[i];
                        if (arr[i] > max) max = arr[i];
                    }
                    printf("Gia tri nho nhat trong mang: %d\n", min);
                    printf("Gia tri lon nhat trong mang: %d\n", max);
                }
                break;
            //4.Tinh Sum
            case 4:
                {
                    int sum = 0;
                    for (int i = 0; i < n; i++) {
                        sum += arr[i];
                    }
                    printf("Tong cac phan tu trong mang: %d\n", sum);
                }
                break;
            //5.Them 1 phan tu vao cuoi
            case 5:
                printf("Nhap phan tu muon them vao cuoi mang: ");
                scanf("%d", &newElem);
                arr[n] = newElem;
                n++;
                printf("Phan tu %d da duoc them vao cuoi mang.\n", newElem);
                break;
			//6.Xoa phan tu trong mang
            case 6:
                printf("Nhap vi tri phan tu muon xoa (0 <= vi tri < %d): ", n);
                scanf("%d", &position);
                if (position >= 0 && position < n) {
                    for (int i = position; i < n-1; i++) {
                        arr[i] = arr[i+1];
                    }
                    n--;
                    printf("Phan tu tai vi tri %d da duoc xoa.\n", position);
                } else {
                    printf("Vi tri khong hop le!\n");
                }
                break;
            //7.Su dung Bubble Sort de sap xep giam dan 
            case 7:
               // Bubble Sort 
                for (int i = 0; i < n-1; i++) {
                    for (int j = 0; j < n-i-1; j++) {
                        if (arr[j] < arr[j+1]) { 
                            int temp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = temp;
                        }
                    }
                }
                printf("Mang sau khi Bubble Sort (giam dan):\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            //8.Su dung Linear Search de tim kiem
            case 8:
                {
                    int searchElem, found = 0;
                    printf("Nhap phan tu muon tim: ");
                    scanf("%d", &searchElem);
                    for (int i = 0; i < n; i++) {
                        if (arr[i] == searchElem) {
                            printf("Phan tu %d duoc tim thay tai vi tri %d.\n", searchElem, i);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Phan tu %d khong ton tai trong mang.\n", searchElem);
                    }
                }
                break;
            //9.In ra cac so nguyen to
            case 9:
                printf("Cac so nguyen to trong mang:\n");
                int primeFound = 0;
                for (int i = 0; i < n; i++) {
                    int isPrime = 1;
                    if (arr[i] < 2) isPrime = 0;
                    for (int j = 2; j * j <= arr[i]; j++) {
                        if (arr[i] % j == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                    if (isPrime) {
                        printf("%d ", arr[i]);
                        primeFound = 1;
                    }
                }
                if (!primeFound) {
                    printf("Khong co so nguyen to nao trong mang.\n");
                }
                printf("\n");
                break;
            //10.Su dung Selection Sort de sap xep mang tang dan 
            case 10:
                // Selection Sort
                for (int i = 0; i < n-1; i++) {
                    int minIdx = i;
                    for (int j = i+1; j < n; j++) {
                        if (arr[j] < arr[minIdx]) {
                            minIdx = j;
                        }
                    }
                    int temp = arr[minIdx];
                    arr[minIdx] = arr[i];
                    arr[i] = temp;
                }
                printf("Mang sau khi Selection Sort:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            //11.Thoat 
            case 11:
                printf("Thoat chuong trinh!!!\n");
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }
    return 0;
}

