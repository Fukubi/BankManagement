#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    int id;
    char name[20];
    char birth[15];
    char cpf[17];
    char address[40];
    char phoneNumber[40];
    int accountNumber;
    double balance;
    char accountType[30];
};

void menu(void);
void new_acc(void);
void edit(void);
int generate_id(void);
void transac(void);
void see(void);
void erase(void);
void viewList(void);

int main(void) {
    menu();

    return 0;
}

void menu(void) {
    system("cls");
    printf("\n");
    printf("\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
    printf("\n");
    printf("\n");

    //WELCOME PRINT

    printf("\t\t\t\t");
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }

    printf(" WELCOME TO THE MAIN MENU ", 178, 178, 178, 178, 178, 178, 178);
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }printf("\n");

    //END OF WELCOME PRINT

    printf("\n");
    printf("\t\t\t1.Create new account\n");
    printf("\t\t\t2.Update information of existing account\n");
    printf("\t\t\t3.For transactions\n");
    printf("\t\t\t4.Check the details of existing account\n");
    printf("\t\t\t5.Removing existing account\n");
    printf("\t\t\t6.View customer's list\n");
    printf("\t\t\t7.Exit\n");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    int choice;

    printf("\t\t\t Enter your choice: ");
    scanf("%i", &choice);

    switch(choice){
    case 1:
        new_acc();
        break;
    case 2:
        edit();
        break;
    case 3:
        transac();
        break;
    case 4:
        see();
        break;
    case 5:
        erase();
        break;
    case 6:
        viewList();
        break;
    case 7:
        return;
        break;
    default:
        menu();
        break;
    }
}

int generate_id(void) {
    FILE *fp;
    fp = fopen("test.txt", "r");
    char line[500];

    int lineNumber = 1;
    int idNumber = 0;

    while(fgets(line, sizeof(line), fp)) {
        if(lineNumber == 10) {
            idNumber++;
            lineNumber = 1;
        }
        lineNumber++;
    }

    return idNumber;
}

void new_acc(void) {
    system("cls");
    printf("\n");
    printf("\t\t\t\tCUSTOMER ACCOUNT BANKING SYSTEM MANAGEMENT\n");
    printf("\n");
    printf("\n");

    //WELCOME PRINT

    printf("\t\t\t\t");
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }

    printf(" ADD NEW ACCOUNT ", 178, 178, 178, 178, 178, 178, 178);
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }printf("\n");

    //END OF WELCOME PRINT

    printf("\n");
    printf("\n");

    struct account newAccount;
    printf("\t\t\t Type the name of the account owner: ");
    scanf("%s", newAccount.name);

    printf("\t\t\t Type the birth date of the account owner: ");
    scanf("%s", newAccount.birth);

    printf("\t\t\t Type the CPF of the account owner: ");
    scanf("%s", newAccount.cpf);

    printf("\t\t\t Type the address of the account owner: ");
    scanf("%s", newAccount.address);

    printf("\t\t\t Type the phone number of the account owner: ");
    scanf("%s", newAccount.phoneNumber);

    int accountType;

    accountChoose:
    printf("\t\t\t Choose the account type: \n");
    printf("\t\t\t\t1.Saving\n");
    printf("\t\t\t\t2.Current\n");
    printf("\t\t\t\t3.Fixed for 1 year\n");
    printf("\t\t\t\t4.Fixed for 2 years\n");
    printf("\t\t\t\t5.Fixed for 3 years\n");
    printf("\n");
    printf("\t\t\tChoose one option: ");
    scanf("%i", &accountType);

    if (accountType == 1) {
        strcpy(newAccount.accountType, "Saving");
    } else if (accountType == 2) {
        strcpy(newAccount.accountType, "Current");
    } else if (accountType == 3) {
        strcpy(newAccount.accountType, "Fixed for 1 year");
    } else if (accountType == 4) {
        strcpy(newAccount.accountType, "Fixed for 2 years");
    } else if (accountType == 5) {
        strcpy(newAccount.accountType, "Fixed for 3 years");
    } else {
        printf("\n");
        goto accountChoose;
    }

    printf("\t\t\tType the initial balance of the account: ");
    scanf("%lf", &newAccount.balance);

    char balanceString[50];
    char accountNumberString[50];
    char idString[10000];

    newAccount.accountNumber = rand();

    snprintf(balanceString, 50, "%f", newAccount.balance);
    itoa(newAccount.accountNumber, accountNumberString, 10);

    newAccount.id = generate_id();
    itoa(newAccount.id, idString, 10);

    FILE *fp;
    fp = fopen("test.txt", "a");
    fputs(strcat(idString, "\n"), fp);
    fputs(strcat(newAccount.name, "\n"), fp);
    fputs(strcat(newAccount.birth, "\n"), fp);
    fputs(strcat(newAccount.cpf, "\n"), fp);
    fputs(strcat(newAccount.address, "\n"), fp);
    fputs(strcat(newAccount.phoneNumber, "\n"), fp);
    fputs(strcat(accountNumberString, "\n"), fp);
    fputs(strcat(balanceString, "\n"), fp);
    fputs(strcat(newAccount.accountType, "\n"), fp);
    fputs("----------------------------------------------------\n", fp);
    fclose(fp);

    menu();
}

void edit(void) {
    system("cls");

    printf("\n");
    printf("\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
    printf("\n");
    printf("\n");

    //WELCOME PRINT

    printf("\t\t\t\t");
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }

    printf(" EDIT A EXISTENT ACCOUNT ", 178, 178, 178, 178, 178, 178, 178);
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }printf("\n");

    //END OF WELCOME PRINT

    printf("\n");
    FILE *fpInitial;
    char buff[1000];

    int idAlt;
    printf("\t\t\t Type the id of the account to change: ");
    scanf("%i", &idAlt);
    printf("\t\t\t----------------------------------------------------\n");

    fpInitial = fopen("test.txt", "r");

    int lineNumber = 1;
    int alterar = 0;
    int imprimir = 0;

    while(fgets(buff, sizeof(buff), fpInitial)) {
        if (lineNumber == 1) {
            if (atoi(buff) == idAlt) {
                imprimir = 1;
            }
        }
        if (imprimir) {
            if (lineNumber == 2) {
                printf("\t\t\t\tName: %s", buff);
            } else if (lineNumber == 3) {
                printf("\t\t\t\tBirth Date: %s", buff);
            } else if (lineNumber == 4) {
                printf("\t\t\t\tCPF: %s", buff);
            } else if (lineNumber == 5) {
                printf("\t\t\t\tAddress: %s", buff);
            } else if (lineNumber == 6) {
                printf("\t\t\t\tPhone number: %s", buff);
            } else if (lineNumber == 7) {
                printf("\t\t\t\tAccount number: %s", buff);
            } else if (lineNumber == 8) {
                printf("\t\t\t\tBalance: %s", buff);
            } else if (lineNumber == 9) {
                printf("\t\t\t\tAccount type: %s", buff);
            }
            if (lineNumber == 10) {
                printf("\t\t\t%s", buff);
                imprimir = 0;
                lineNumber = 0;
            }
        }
        if (lineNumber == 10) {
            lineNumber = 0;
        }
        lineNumber++;
    }

    fclose(fpInitial);

    struct account accountUpdate;
    printf("\n");
    printf("\t\t\t Type the name of new account owner (_ for don't change): ");
    scanf("%s", accountUpdate.name);

    printf("\t\t\t Type the new birth date of the owner (_ for don't change): ");
    scanf("%s", accountUpdate.birth);

    printf("\t\t\t Type the new CPF number of the owner (_ for don't change): ");
    scanf("%s", accountUpdate.cpf);

    printf("\t\t\t Type the new address of the owner (_ for don't change): ");
    scanf("%s", accountUpdate.address);

    printf("\t\t\t Type the new phone number of the owner (_ for don't change): ");
    scanf("%s", accountUpdate.phoneNumber);

    printf("\t\t\t Type the new balance of the account (-1 for don't change): ");
    scanf("%lf", &accountUpdate.balance);

    int accountType;

    accountChooseEdit:
    printf("\t\t\t Choose the account type: \n");
    printf("\t\t\t\t1.Saving\n");
    printf("\t\t\t\t2.Current\n");
    printf("\t\t\t\t3.Fixed for 1 year\n");
    printf("\t\t\t\t4.Fixed for 2 years\n");
    printf("\t\t\t\t5.Fixed for 3 years\n");
    printf("\n");
    printf("\t\t\tChoose one option: ");
    scanf("%i", &accountType);

    if (accountType == 1) {
        strcpy(accountUpdate.accountType, "Saving");
    } else if (accountType == 2) {
        strcpy(accountUpdate.accountType, "Current");
    } else if (accountType == 3) {
        strcpy(accountUpdate.accountType, "Fixed for 1 year");
    } else if (accountType == 4) {
        strcpy(accountUpdate.accountType, "Fixed for 2 years");
    } else if (accountType == 5) {
        strcpy(accountUpdate.accountType, "Fixed for 3 years");
    } else {
        printf("\n");
        goto accountChooseEdit;
    }

    FILE *fp;
    FILE *tempFile;
    fp = fopen("test.txt", "r");
    tempFile = fopen("testTemp.txt", "w");

    while(fgets(buff, sizeof(buff), fp)) {
        if (lineNumber == 1) {
            if (atoi(buff) == idAlt) {
                alterar = 1;
            }
        }
        if (alterar) {
            if (lineNumber == 1) {
                fputs(buff, tempFile);
            }
            if (lineNumber == 2) {
                if (strcmp(accountUpdate.name, "_") != 0) {
                    fputs(strcat(accountUpdate.name, "\n"), tempFile);
                } else {
                    fputs(buff, tempFile);
                }
            }
            if (lineNumber == 3) {
                if(strcmp(accountUpdate.birth, "_") != 0) {
                    fputs(strcat(accountUpdate.birth, "\n"), tempFile);
                } else {
                    fputs(buff, tempFile);
                }
            }
            if (lineNumber == 4) {
                if(strcmp(accountUpdate.cpf, "_") != 0) {
                    fputs(strcat(accountUpdate.cpf, "\n"), tempFile);
                } else {
                    fputs(buff, tempFile);
                }
            }
            if (lineNumber == 5) {
                if(strcmp(accountUpdate.address, "_") != 0) {
                    fputs(strcat(accountUpdate.address, "\n"), tempFile);
                } else {
                    fputs(buff, tempFile);
                }
            }
            if (lineNumber == 6) {
                if(strcmp(accountUpdate.phoneNumber, "_") != 0) {
                    fputs(strcat(accountUpdate.phoneNumber, "\n"), tempFile);
                } else {
                    fputs(buff, tempFile);
                }
            }
            if (lineNumber == 7) {
                fputs(buff, tempFile);
            }
            if (lineNumber == 8) {
                if(atof(buff) == -1) {
                    char balance[50];
                    snprintf(balance, 50, "%f", accountUpdate.balance);
                    fputs(balance, tempFile);
                } else {
                    fputs(buff, tempFile);
                }
            }
            if (lineNumber == 9) {
                if (accountType == 1) {
                    fputs("Saving\n", tempFile);
                } else if (accountType == 2) {
                    fputs("Current\n", tempFile);
                } else if (accountType == 3) {
                    fputs("Fixed for 1 year\n", tempFile);
                } else if (accountType == 4) {
                    fputs("Fixed for 2 years\n", tempFile);
                } else if (accountType == 5) {
                    fputs("Fixed for 3 years\n", tempFile);
                } else {
                    fputs(buff, tempFile);
                }
            }
            if (lineNumber == 10) {
                fputs(buff, tempFile);
                alterar = 0;
            }
        } else {
            fputs(buff, tempFile);
        }
        if(lineNumber == 10) {
            lineNumber = 0;
        }
        lineNumber++;
    }

    fclose(fp);
    fclose(tempFile);

    FILE *file;
    FILE *tempFileIn;

    tempFileIn = fopen("testTemp.txt", "r");
    file = fopen("test.txt", "w");

    while(fgets(buff, sizeof(buff), tempFileIn)) {
        fputs(buff, file);
    }

    fclose(tempFileIn);
    fclose(file);

    remove("testTemp.txt");

    menu();
}

void transac(void) {
    //WELCOME PRINT
    system("cls");

    printf("\n");
    printf("\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
    printf("\n");
    printf("\n");

    printf("\t\t\t\t");
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }

    printf(" DO A TRANSACTION ", 178, 178, 178, 178, 178, 178, 178);
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }printf("\n");

    //END OF WELCOME PRINT
    int senderAccountFound = 0;
    struct account senderAccount;

    printf("\n");
    printf("\t\t\tEnter your account id: ");
    scanf("%i", &senderAccount.id);

    FILE *fileSearchSend;
    fileSearchSend = fopen("test.txt", "r");

    char line[100];
    int lineNumber = 1;

    while(fgets(line, 100, fileSearchSend)) {
        if (lineNumber == 1) {
            if (atoi(line) == senderAccount.id) {
                senderAccountFound = 1;
            }
        }
        if (senderAccountFound) {
            if (lineNumber == 2) {
                strcpy(senderAccount.name, line);
            }
            if (lineNumber == 3) {
                strcpy(senderAccount.birth, line);
            }
            if (lineNumber == 4) {
                strcpy(senderAccount.cpf, line);
            }
            if (lineNumber == 5) {
                strcpy(senderAccount.address, line);
            }
            if (lineNumber == 6) {
                strcpy(senderAccount.phoneNumber, line);
            }
            if (lineNumber == 7) {
                senderAccount.accountNumber = atoi(line);
            }
            if (lineNumber == 8) {
                senderAccount.balance = atof(line);
            }
            if (lineNumber == 9) {
                strcpy(senderAccount.accountType, line);
            }
        }
        if (lineNumber == 10) {
            senderAccountFound = 0;
            lineNumber = 0;
        }
        lineNumber++;
    }

    fclose(fileSearchSend);

    printf("\n");
    printf("\t\t\tName: %s", senderAccount.name);
    printf("\t\t\tBirth Date: %s", senderAccount.birth);
    printf("\t\t\tCPF: %s", senderAccount.cpf);
    printf("\t\t\tAddress: %s", senderAccount.address);
    printf("\t\t\tPhone number: %s", senderAccount.phoneNumber);
    printf("\t\t\tAccount number: %i\n", senderAccount.accountNumber);
    printf("\t\t\tBalance: R$%.2f\n", senderAccount.balance);
    printf("\t\t\tAccount type: %s\n", senderAccount.accountType);

    struct account receiverAccount;

    printf("\t\t\tEnter the id of the receiver account: ");
    scanf("%i", &receiverAccount.id);

    FILE *fileSearchReceiver;
    fileSearchReceiver = fopen("test.txt", "r");
    int receiverAccountFound = 0;
    lineNumber = 1;

    while(fgets(line, 100, fileSearchReceiver)) {
        if (lineNumber == 1) {
            if (atoi(line) == receiverAccount.id) {
                receiverAccountFound = 1;
            }
        }
        if (receiverAccountFound) {
            if (lineNumber == 2) {
                strcpy(receiverAccount.name, line);
            }
            if (lineNumber == 3) {
                strcpy(receiverAccount.birth, line);
            }
            if (lineNumber == 4) {
                strcpy(receiverAccount.cpf, line);
            }
            if (lineNumber == 5) {
                strcpy(receiverAccount.address, line);
            }
            if (lineNumber == 6) {
                strcpy(receiverAccount.phoneNumber, line);
            }
            if (lineNumber == 7) {
                receiverAccount.accountNumber = atoi(line);
            }
            if (lineNumber == 8) {
                receiverAccount.balance = atof(line);
            }
            if (lineNumber == 9) {
                strcpy(receiverAccount.accountType, line);
            }
        }
        if (lineNumber == 10) {
            receiverAccountFound = 0;
            lineNumber = 0;
        }
        lineNumber++;
    }

    fclose(fileSearchReceiver);

    printf("\n");
    printf("\t\t\tName: %s", receiverAccount.name);
    printf("\t\t\tBirth Date: %s", receiverAccount.birth);
    printf("\t\t\tCPF: %s", receiverAccount.cpf);
    printf("\t\t\tAddress: %s", receiverAccount.address);
    printf("\t\t\tPhone number: %s", receiverAccount.phoneNumber);
    printf("\t\t\tAccount number: %i\n", receiverAccount.accountNumber);
    printf("\t\t\tBalance: R$%.2f\n", receiverAccount.balance);
    printf("\t\t\tAccount type: %s\n", receiverAccount.accountType);

    double transactionValue = 0;

    printf("\t\t\tType the value for transaction: ");
    scanf("%lf", &transactionValue);
    printf("\n");

    if (senderAccount.balance - transactionValue >= 0) {
        printf("\t\t\tExecuting transaction...");

        senderAccount.balance -= transactionValue;
        receiverAccount.balance += transactionValue;
        int senderTransaction = 0;
        int receiverTransaction = 0;
        lineNumber = 1;

        FILE *fileWriteTemp;
        FILE *tempFileWrite;

        fileWriteTemp = fopen("test.txt", "r");
        tempFileWrite = fopen("tempTest.txt", "w");

        while (fgets(line, sizeof(line), fileWriteTemp)) {
            if (lineNumber == 1) {
                if (atoi(line) == senderAccount.id) {
                    senderTransaction = 1;
                }
                if (atoi(line) == receiverAccount.id) {
                    receiverTransaction = 1;
                }
            }
            if (senderTransaction || receiverTransaction) {
                if (senderTransaction) {
                    if (lineNumber == 8) {
                        char balance[100];
                        snprintf(balance, 100, "%f", senderAccount.balance);
                        fputs(strcat(balance, "\n"), tempFileWrite);
                    } else {
                        fputs(line, tempFileWrite);
                    }
                }
                if (receiverTransaction) {
                    if (lineNumber == 8) {
                        char balance[100];
                        snprintf(balance, 100, "%f", receiverAccount.balance);
                        fputs(strcat(balance, "\n"), tempFileWrite);
                    } else {
                        fputs(line, tempFileWrite);
                    }
                }
            } else {
                fputs(line, tempFileWrite);
            }
            if (lineNumber == 10) {
                senderTransaction = 0;
                receiverTransaction = 0;
                lineNumber = 0;
            }
            lineNumber++;
        }
        fclose(fileWriteTemp);
        fclose(tempFileWrite);

        FILE *tempFileRead;
        FILE *fileWrite;

        tempFileRead = fopen("tempTest.txt", "r");
        fileWrite = fopen("test.txt", "w");

        while (fgets(line, sizeof(line), tempFileRead)) {
            fputs(line, fileWrite);
        }

        fclose(tempFileRead);
        fclose(fileWrite);

        remove("tempTest.txt");
    } else {
        printf("\t\t\tInsuficient balance\n");
    }
    menu();
}

void see(void) {
    system("cls");
    printf("\n");
    printf("\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
    printf("\n");
    printf("\n");

    //WELCOME PRINT

    printf("\t\t\t\t");
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }

    printf(" SEE ACCOUNT DETAILS ", 178, 178, 178, 178, 178, 178, 178);
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }printf("\n");

    //END OF WELCOME PRINT

    printf("\n");
    FILE *file;
    file = fopen("test.txt", "r");
    char line[100];

    int idSee;
    int lineNumber = 1;
    int imprimir = 0;

    printf("\t\t\tType the id of the account: ");
    scanf("%i", &idSee);
    printf("\n");

    while(fgets(line, sizeof(line), file)) {
        if (lineNumber == 1) {
            if (atoi(line) == idSee) {
                imprimir = 1;
            }
        }
        if (imprimir) {
            if (lineNumber == 2) {
                printf("\t\t\t\tName: %s", line);
            } else if (lineNumber == 3) {
                printf("\t\t\t\tBirth Date: %s", line);
            } else if (lineNumber == 4) {
                printf("\t\t\t\tCPF: %s", line);
            } else if (lineNumber == 5) {
                printf("\t\t\t\tAddress: %s", line);
            } else if (lineNumber == 6) {
                printf("\t\t\t\tPhone number: %s", line);
            } else if (lineNumber == 7) {
                printf("\t\t\t\tAccount number: %s", line);
            } else if (lineNumber == 8) {
                printf("\t\t\t\tBalance: %s", line);
            } else if (lineNumber == 9) {
                printf("\t\t\t\tAccount type: %s", line);
            }
            if (lineNumber == 10) {
                printf("\t\t\t%s", line);
                imprimir = 0;
                lineNumber = 0;
            }
        }
        if (lineNumber == 10) {
            lineNumber = 0;
        }
        lineNumber++;
    }
    menu();
}

void erase(void) {
    system("cls");
    printf("\n");
    printf("\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
    printf("\n");
    printf("\n");

    //WELCOME PRINT

    printf("\t\t\t\t");
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }

    printf(" ERASE ACCOUNT ", 178, 178, 178, 178, 178, 178, 178);
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }printf("\n");

    //END OF WELCOME PRINT

    printf("\n");

    int idErase;

    printf("\t\t\tType the id of the account to erase: ");
    scanf("%i", &idErase);
    printf("\n");

    FILE *file;
    FILE *tempFile;

    file = fopen("test.txt", "r");
    tempFile = fopen("tempTest.txt", "w");

    char line[100];
    int lineNumber = 1;
    int isErased = 0;

    while (fgets(line, sizeof(line), file)) {
        if (lineNumber == 1) {
            if (atoi(line) == idErase) {
                isErased = 1;
            }
        }
        if (isErased == 0) {
            fputs(line, tempFile);
        }
        if (lineNumber == 10) {
            isErased = 0;
            lineNumber = 0;
        }
        lineNumber++;
    }

    fclose(file);
    fclose(tempFile);

    FILE *tempFileIn;
    FILE *fileOut;

    tempFileIn = fopen("tempTest.txt", "r");
    fileOut = fopen("test.txt", "w");

    while (fgets(line, sizeof(line), tempFileIn)) {
        fputs(line, fileOut);
    }

    fclose(tempFileIn);
    fclose(fileOut);

    remove("tempTest.txt");

    menu();
}

void viewList(void) {
    system("cls");
    printf("\n");
    printf("\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
    printf("\n");
    printf("\n");

    //WELCOME PRINT

    printf("\t\t\t\t");
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }

    printf(" VIEW COSTUMER'S LIST ", 178, 178, 178, 178, 178, 178, 178);
    for(int i = 0; i < 7; i++) {
        printf("%c", 178);
    }printf("\n");

    //END OF WELCOME PRINT

    printf("\n");

    FILE *file;
    file = fopen("test.txt", "r");

    char line[100];

    while(fgets(line, sizeof(line), file)) {
        printf("\t\t\t%s", line);
    }

    fclose(file);
    system("pause");

    menu();
}
