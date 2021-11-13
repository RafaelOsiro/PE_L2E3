/*
UNIVERSIDADE CATÓLICA DE BRASÍLIA
CURSO: ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
DISCIPLINA: PROGRAMAÇÃO ESTRUTURADA
DOCENTE: JOYCE SIQUEIRA
DISCENTE: RAFAEL RIKI OGAWA OSIRO (UC21100716)

Exercício: 3. Faça um programa que solicite o primeiro e o último nome de 5 pessoas. Assim que a pessoa informar 
os dois nomes, apresente em tela o tamanho de cada um deles e se for possível concatene-os em uma única variável 
fazendo o uso da função de concatenação de strings.
*/

//!LIBRARIES _______________________________________________________________________________________________
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>
#include<ctype.h>

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________
void messageTitle();
void messageMenu();
void messageNameInput(int index, int option);
void messageConfirmExit();
void messageExit();
void messageName(char fullName[1000]);

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________
void errorMessageInput(int quantityOfError, int option);
void errorExit();

//! VALIDATION INPUT __________________________________________________________________________________________
bool validationString(char *string);

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________
int functionOptionInput();
void functionInputString(char firstName[][50], char lastName[][50]);
void functionConcatenateString(char firstName[][50], char lastName[][50], char *fullName);


int main()
{
    int option, quantityOfError = 0;
    char firstName[5][50], lastName[5][50], fullName[1000];
    bool validation = false, exitValidation = false;

    do
    {
        messageTitle();
        messageMenu();
        option = functionOptionInput();

        switch (option)
        {
        case 1:
            system("cls");
            quantityOfError = 0;
            
            functionInputString(firstName, lastName);
            functionConcatenateString(firstName, lastName, fullName);
            messageName(fullName);
            break;
        
        case 2:
            system("cls");
            quantityOfError = 0;
            
            do
            {
                messageConfirmExit();
                option = functionOptionInput();

                if (option == 1)
                {
                    exitValidation = true;
                    validation = true; 
                }
                else if(option == 2)
                {
                    exitValidation = true;
                    validation = false;
                }
                else
                {
                    exitValidation = false;
                    system("cls");
                    quantityOfError++;
                    errorMessageInput(quantityOfError, 1);

                    if (quantityOfError == 3)
                    {
                        errorExit();
                        exit(EXIT_FAILURE);
                    }    
                }

            } while (exitValidation == false);


            system("cls");
            quantityOfError = 0;
            
            break;

        default:
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError, 1);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
            break;
        }
    
    } while (validation == false);
    
    messageExit();
    exit(EXIT_SUCCESS);
}

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________

//  MESSAGE TITLE OF THE SYSTEM
void messageTitle()
{
    printf("SISTEMA PARA JUNTAR OS NOMES\n\n\n");
}

//  MESSAGE MENU
void messageMenu()
{
    printf("--------------------\n");
    printf("[1] ENTRADA DE NOMES\n");
    printf("[2] SAIR DO PROGRAMA\n");
    printf("--------------------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE ASK NAME INPUT
void messageNameInput(int index, int option)
{
    switch (option)
    {
    case 1:
        printf("DIGITE O NOME DA PESSOA %d: ", (index+1));
        break;
    
    case 2:
        printf("DIGITE O SOBRENOME DA PESSOA %d: ", (index+1));
        break;
    default:
        break;
    }
    
}

//  MESSAGE ASK CONFIRM EXIT OF THE SYSTEM
void messageConfirmExit()
{
    printf("DESEJA CONFIRMAR A SA\326DA DO SISTEMA?\n\n");
    printf("-------\n");
    printf("[1] SIM\n");
    printf("[2] N\307O\n");
    printf("-------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE TO EXIT SYSTEM
void messageExit()
{
    printf("O SISTEMA IR\265 FINALIZAR\n");
}

//  MESSAGE TO PRINT THE NAMES
void messageName(char fullName[1000])
{   
    printf("%s\n", fullName);
}

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________

//  ERROR MESSAGE INPUT
void errorMessageInput(int quantityOfError, int option)
{
    switch (option)
    {
    case 1:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UMA OP\200\307O V\265LIDA\n\n\n");
        break;
    
    case 2:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UM NOME V\265LIDO\n\n\n");
        break;

    default:
        break;
    }
}

//  ERROR EXIT SYSTEM
void errorExit()
{
    printf("QUANTIDADE DE ERROS ATINGIDO!\n");
    printf("O SISTEMA IR\265 FINALIZAR!\n\n\n");
}

//! VALIDATION INPUT __________________________________________________________________________________________

//  FUNCTION TO VALIDATE A STRING
bool validationString(char *string)
{
    int index = 0;

    if (strlen(string) == 1)
    {
        if (string[index] == "\n" || string[index] == " " || string[index] == "\0" || string[index] == "\r" || 
        string[index] == "\r\n" || !isalpha(string[index] || !isdigit(string[index])))
        {
            return false;
        }
    }
    else
    {
        while (index < strlen(string))
        {
            if (string[index] != "\n" && string[index] != " " && string[index] != "\0" && string[index] != "\r" && 
            string[index] != "\r\n" && !isspace(string[index]) && (isalpha(string[index]) || isdigit(string[index])))
            {
                return true;
            }
            index++;
        }

        return false;
    }

    return false;
}

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________

//  FUNCTION OPTION INPUT
int functionOptionInput()
{
    int number;

    fflush(stdin);
    scanf("%d", &number);

    return number;
}

//  FUNCTION INPUT STRING
void functionInputString(char firstName[][50], char lastName[][50])
{
    int size = (sizeof(firstName) + 1), quantityOfError = 0, count = 0;
    bool validation = false;

    for (int i = 0; i < size; i++)
    {
        messageTitle();
        while (validation == false)
        {
            messageNameInput(i, 1);
            fflush(stdin);
            fgets(firstName[i], sizeof(firstName[i]), stdin);
            validation = validationString(firstName[i]);

            if (strlen(firstName[i]) == 50-1)
            {
                char charactere;
                while ((charactere = getchar()) != '\n' && charactere != EOF);
            }

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 2);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        count = 0;
        validation = false;
        messageTitle();

        while (validation == false)
        {
            messageNameInput(i, 2);
            fflush(stdin);
            fgets(lastName[i], sizeof(lastName[i]), stdin);
            validation = validationString(lastName[i]);

            if (strlen(lastName[i]) == 50-1)
            {
                char charactere;
                while ((charactere = getchar()) != '\n' && charactere != EOF);
            }

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 2);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        count = 0;
        validation = false;
    }
}

//  FUNCTION TO CONCATENATE STRING
void functionConcatenateString(char firstName[][50], char lastName[][50], char *fullName)
{
    int size = (sizeof(firstName) + 1);

    for (int i = 0; i < size; i++)
    {
        strcat(fullName, firstName[i]);
        strcat(fullName, lastName[i]);
        if ((size - 1) != i)
        {
            strcat(fullName, ",");
            // strcat(fullName, " ");
        }
    }

    size = strlen(fullName);

    for (int i = 0; i < size; i++)
    {
        fullName[i] = fullName[i+1];
    }
    
    size = strlen(fullName);
    bool dot = false;

    for (int i = 0; i < size; i++)
    {
        if (fullName[i] == '\n')
        {
            if (dot && (size - 1) != i)
            {
                dot = false;
                fullName[i] = ',';
                fullName[i+1] = ' ';
            }
            else
            {
                dot = true;
                fullName[i] = ' ';
            }
        }
    }
}