#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
int globel = 1;
float calculator(char[]);
void displayAllOperator()
{
    char oprator[20];
    int value;
    printf("\n\n\n\n");
    printf("\tNOT FOLLOW DMAS RULL  EXIT 0  AND PRESS 1 CHECK HISTORY \n\n");
    printf("\t**************************************************************************************\n");
    printf("\t*                                                                                    *\n");
    printf("\t*    sin(s)      cos(c)        tan(t)        sec(a)       cosec(b)       cot(d)      *\n");
    printf("\t*                                                                                    *\n");
    printf("\t*                                                                                    *\n");
    printf("\t*                                                                                    *\n");
    printf("\t*    sinh(f)      cosh(g)      tanh(h)       sech(i)      cosec(j)       coth(x)     *\n");
    printf("\t*                                                                                    *\n");
    printf("\t*                                                                                    *\n");
    printf("\t*                                                                                    *\n");
    printf("\t*    phi(z)        e^x         x^2(p)        x^3(o)        log(l)        ln(n)       *\n");
    printf("\t*                                                                                    *\n");
    printf("\t*                                                                                    *\n");
    printf("\t*                                                                                    *\n");
    printf("\t*  +            -              x               /             ^                       *\n");
    printf("\t*                                                                                    *\n");
    printf("\t*                                                                                    *\n");
    printf("\t**************************************************************************************\n");
    printf("\n\t----> ");
}
float calculator(char value[])
{
    FILE *fileCalculator = fopen("text.txt", "w");
    fprintf(fileCalculator, "%s", value);
    fclose(fileCalculator);
    fileCalculator = fopen("text.txt", "r");
    int char_skip = 1, int_skip = 1;
    char operat;
    float dail_value, result;
    char ch[2];
    int g = 0;
    globel = 0;

    while (!feof(fileCalculator))
    {
        if (char_skip == 0)
        {
            fscanf(fileCalculator, "%c", &operat);
        } // if char_skip ==0 then first not input operator//
        if (int_skip == 1)
        {
            fscanf(fileCalculator, "%f", &result);
            int_skip = 67;
        } // first time input intiger then block this if statment

        if (char_skip == 1)
        {
            fscanf(fileCalculator, "%c", &operat);
            char_skip = 0;
        } // run this block on sexond irration //
        if (int_skip == 67)
        {
            fscanf(fileCalculator, "%f", &dail_value);
        } // this block run till loop  not terminated //
        //*****************************************************************************************************//

        if (operat == '+')
        {
            result += dail_value;
        }
        if (operat == '-')
        {
            result -= dail_value;
        }
        if (operat == '/')
        {
            result /= dail_value;
        }
        if (operat == '*')
        {
            result *= dail_value;
        }
        if (operat == 'c')
        {
            result = cos(dail_value);
        }
        if (operat == 's')
        {
            result = sin(dail_value);
        }
        if (operat == 't')
        {
            result = tan(dail_value);
        }
        if (operat == 'd')
        {
            result = cos(dail_value) / sin(dail_value);
        }
        if (operat == 'e')
        {
            result = exp(dail_value);
        }
        if (operat == '^')
        {
            result = pow(result, dail_value);
        }

        if (operat == 'f')
        {
            result = sinh(dail_value);
        }

        if (operat == 'g')
        {
            result = cosh(dail_value);
        }
        if (operat == 'h')
        {
            result = tanh(dail_value);
        }

        if (operat == 'x')
        {
            result = cosh(dail_value) / sinh(dail_value);
        }
        if (operat == 'l')
        {
            result = log10(dail_value);
        }
        if (operat == 'n')
        {
            if (value)
                result = log(dail_value);
        }
        if (operat == 'p')
        {

            result = dail_value * dail_value;
        }
        if (operat == 'o')
        {

            result = dail_value * dail_value * dail_value;
        }
    }
    fclose(fileCalculator);
    fileCalculator = fopen("histry.txt", "a");
    fprintf(fileCalculator, "\n%f", result);
    fclose(fileCalculator);

    return result;
}
void history()
{
    int i = 0;
    char result[40];
    system("cls");
    FILE *fileCalculator = fopen("histry.txt", "r");
    printf("\n\n\t\t******\n");
    printf("\t\tHISTORY\n");
    printf("\t\t*******\n\n\n\n");
    while (!feof(fileCalculator))
    {
        if (globel != 1)
        {
            i++;
            fscanf(fileCalculator, "%s", &result);
            printf("\n\t %i   =   %s ", i, result);
        }
        else
        {
            break;
        }
    }
    printf("\n\n\tPRESS ANY KEY FOR BACK ");
    getch();
    system("cls");
    fclose(fileCalculator);
}
int main()
{
    float ans;
    char dail[60];
    while (true)
    {
        displayAllOperator();
        scanf("%s", dail);
        if (dail[0] == '0' && dail[1] == '\0')
        {
            FILE *fileCalculator = fopen("histry.txt", "w");
            fprintf(fileCalculator,"");
            fclose(fileCalculator);
            break;
        }
        else if (dail[0] == '1' && dail[1] == '\0')
        {
            history();
        }
        else
        {

            ans = calculator(dail);
            printf("\n\t%f", ans);
            getch();
            system("cls");
        }
    }
    return 0;
}