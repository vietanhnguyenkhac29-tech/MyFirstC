#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- KHAI BÁO HÀM (Prototypes) ---
void clearInputBuffer();
int performLogin();
void runCalculator();
void runCurrencyConverter();
void runProfileManager();

int main() {
    int choice;
    int loggedIn = 0;

    // 1. YÊU CẦU ĐĂNG NHẬP TRƯỚC KHI VÀO HỆ THỐNG
    if (performLogin()) {
        loggedIn = 1;
    } else {
        printf("\n>> Qua so lan thu. Chuong trinh ket thuc.\n");
        return 1;
    }

    // 2. MENU CHÍNH (Vòng lặp)
    while (loggedIn) {
        printf("\n========================================\n");
        printf("       HE THONG QUAN LY TONG HOP        \n");
        printf("========================================\n");
        printf("1. May tinh bo tui (Calculator)\n");
        printf("2. Doi tien te (Currency Converter)\n");
        printf("3. Ho so ca nhan (Profile Manager)\n");
        printf("4. Thoat (Exit)\n");
        printf("========================================\n");
        printf("Chon chuc nang (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            // Xử lý nếu người dùng nhập chữ thay vì số
            clearInputBuffer();
            choice = 0; 
        }

        switch (choice) {
            case 1:
                runCalculator();
                break;
            case 2:
                runCurrencyConverter();
                break;
            case 3:
                runProfileManager();
                break;
            case 4:
                printf("\nCam on ban da su dung he thong. Tam biet!\n");
                return 0;
            default:
                printf("\n>> Lua chon khong hop le! Vui long chon lai.\n");
        }
    }

    return 0;
}

// --- CÁC HÀM HỖ TRỢ ---

// Hàm xóa bộ nhớ đệm để tránh lỗi trôi lệnh khi nhập chuỗi sau số
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Hàm đăng nhập (Dựa trên profile.c cũ)
int performLogin() {
    char username[50];
    char password[50];
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;

    printf("\n--- HE THONG DANG NHAP ---\n");
    
    while (attempts < MAX_ATTEMPTS) {
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);

        if (strcmp(username, "vanakao") == 0 && strcmp(password, "9987") == 0) {
            printf(">> Dang nhap thanh cong!\n");
            return 1; // Success
        } else {
            attempts++;
            printf(">> Sai thong tin! Con %d lan thu.\n\n", MAX_ATTEMPTS - attempts);
        }
    }
    return 0; // Failed
}

// Chức năng 1: Máy tính (Dựa trên calculator.c)
void runCalculator() {
    int choice;
    float num1, num2, result;

    printf("\n=== Calculator Program ===\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("Choose an operation (1-4): ");
    scanf("%d", &choice);

    printf("Enter number 1: ");
    scanf("%f", &num1);
    printf("Enter number 2: ");
    scanf("%f", &num2);

    switch(choice) {
        case 1:
            result = num1 + num2;
            printf(">> Result: %.2f\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf(">> Result: %.2f\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf(">> Result: %.2f\n", result);
            break;
        case 4:
            if(num2 != 0) {
                result = num1 / num2;
                printf(">> Result: %.2f\n", result);
            } else {
                printf(">> Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf(">> Invalid calculation option!\n");
    }
}

// Chức năng 2: Đổi tiền (Dựa trên currency.c)
void runCurrencyConverter() {
    float amount, converted_amount;
    int choice;
    
    // Tỉ giá
    float usd_rate = 25450.0;
    float eur_rate = 28000.0;
    float jpy_rate = 210.0;
    float gbp_rate = 33000.0;
    float aud_rate = 19000.0;
    float cad_rate = 23000.0;

    printf("\n=== Currency Conversion Program ===\n");
    printf("1. VND to USD\n");
    printf("2. VND to EUR\n");
    printf("3. VND to JPY\n");
    printf("4. VND to GBP\n");
    printf("5. VND to AUD\n");
    printf("6. VND to CAD\n");
    printf("Choose a conversion option (1-6): ");
    scanf("%d", &choice);

    printf("Enter the amount (VND) you want to exchange: ");
    scanf("%f", &amount);

    switch (choice) {
        case 1:
            converted_amount = amount / usd_rate;
            printf(">> Converted Amount: %.2f USD\n", converted_amount);
            break;
        case 2:
            converted_amount = amount / eur_rate;
            printf(">> Converted Amount: %.2f EUR\n", converted_amount);
            break;
        case 3:
            converted_amount = amount / jpy_rate;
            printf(">> Converted Amount: %.2f JPY\n", converted_amount);
            break;
        case 4:
            converted_amount = amount / gbp_rate;
            printf(">> Converted Amount: %.2f GBP\n", converted_amount);
            break;
        case 5:
            converted_amount = amount / aud_rate;
            printf(">> Converted Amount: %.2f AUD\n", converted_amount);
            break;
        case 6:
            converted_amount = amount / cad_rate;
            printf(">> Converted Amount: %.2f CAD\n", converted_amount);
            break;
        default:
            printf(">> Option not valid!\n");
    }
}

// Chức năng 3: Hồ sơ (Dựa trên phần Input của profile.c)
void runProfileManager() {
    char name[50];
    int age;
    int years;
    char bank[50];
    int money;
    char address[100]; // Tăng kích thước
    char marital_status[50];
    char gender[50];

    printf("\n--- Nhap Thong Tin Ho So ---\n");
    
    // Xử lý buffer trước khi nhập chuỗi
    clearInputBuffer();
    
    printf("Enter your name: ");
    // Sử dụng %[^\n]s để nhận cả dấu cách (ví dụ: Nguyen Van A)
    scanf("%[^\n]s", name);
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    printf("Enter your years (experience?): ");
    scanf("%d", &years);
    
    clearInputBuffer(); // Xóa buffer sau khi nhập số để nhập chuỗi tiếp theo
    printf("Enter your address: ");
    scanf("%[^\n]s", address);
    
    clearInputBuffer();
    printf("Enter your bank name: ");
    scanf("%[^\n]s", bank);
    
    printf("Enter your money: ");
    scanf("%d", &money);
    
    clearInputBuffer();
    printf("Enter your marital status: ");
    scanf("%[^\n]s", marital_status);
    
    clearInputBuffer();
    printf("Enter your gender: ");
    scanf("%[^\n]s", gender);

    // Result Display
    printf("\n----------------------------\n");
    printf("       YOUR PROFILE         \n");
    printf("----------------------------\n");
    printf("Name:           %s\n", name);
    printf("Age:            %d\n", age);
    printf("Address:        %s\n", address);
    printf("Bank:           %s\n", bank);
    printf("Years:          %d\n", years);
    printf("Money:          %d\n", money);
    printf("Marital status: %s\n", marital_status);
    printf("Gender:         %s\n", gender);
    printf("----------------------------\n");
    printf("Congratulations on your success!\n");

    return 0;
}