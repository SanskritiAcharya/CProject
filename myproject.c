#include <stdio.h> 
#include <string.h> 
#include <math.h> 

double BodmasCalculation(); 
double TrigoCalculation();  
void MatrixAddcalculation();
void MatrixMultiplyCalculation();
void BinarytoDecimal();
void DecimaltoBinary();
void LinearEquation();

void saveintofile_cal(char *op, double result);
void saveintofile_matrix(char *op, double result[2][2]);
void saveintofile_conversion(char *op, int result);
void saveintofile_equation(char *op, double x, double y);

double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double division(double num1, double num2);
double power(double base, double exp);
int factorial(int n);
double squareroot(double n);
double logarithm(double n);
double sinvalue(double n);
double cosvalue(double n);
double tanvalue(double n);
double secvalue(double n);
double cosecvalue(double n);
double cotvalue(double n);

int main(){
    int choice;
    while(1){
        printf("1 for Bodmas calculation\n");
        printf("2 for Trigonometric calculation\n");
        printf("3 for matrix addition\n");
        printf("4 for matrix multiplication\n");
        printf("5 for binary to decimal conversion\n");
        printf("6 for decimal to binary conversion\n");
        printf("7 for solving linear equation\n");
        printf("8 to exit the program\n");
        printf("Enter your choice: ");
        if(scanf("%d", &choice)!=1){
            printf("INVALD. Please enter one of the integers\n");
            while(getchar()!='\n');// the input buffer clears all the extra characters until new line is introduced
            continue;
        }
        switch(choice){
            case 1:
            BodmasCalculation();
            break;
            case 2:
            TrigoCalculation();
            break;
            case 3:
            MatrixAddcalculation();
            break;
            case 4:
            MatrixMultiplyCalculation();
            break;
            case 5:
            BinarytoDecimal();
            break;
            case 6:
            DecimaltoBinary();
            break;
            case 7:
            LinearEquation();
            break;
            case 8:
            printf("Thankyou for trying my program. Byebyeee\n");
            return 0;//terminate the program if user inputs 'exit'
            default:
            printf("Enter your choices only between 1-8\n");
        }
    }
    return 0;
}

double BodmasCalculation(){
    char op[100];
    double num1,num2, result;
    while(1){
    printf("Enter the type of operation(+,-,*,/,^,factorial,squareroot,log) OR enter 'exit' for other calculation:");
    scanf("%s", op);
    if(strcmp(op,"exit")==0){
        return 0;
    }
    if((strcmp(op,"+")==0)||(strcmp(op,"-")==0)||(strcmp(op,"*")==0)||(strcmp(op,"/")==0)||(strcmp(op,"^")==0)){
        printf("Enter the first number:");
        scanf("%lf",&num1);
        printf("Enter the second number:");
        scanf("%lf",&num2);
        if(strcmp(op,"+")==0){
            result= add(num1,num2);
        }else if(strcmp(op,"-")==0){
            result= subtract(num1,num2);
        }else if(strcmp(op,"*")==0){
            result= multiply(num1,num2);
        }else if(strcmp(op,"/")==0){
            result= division(num1,num2);
        }else if(strcmp(op,"^")==0){
            result= power(num1,num2);
        }
        printf("The output from %lf %s %lf = %lf\n",num1,op,num2,result);
        saveintofile_cal(op,result);
    }
    else if((strcmp(op,"factorial")==0)||(strcmp(op,"squareroot")==0)||(strcmp(op,"log")==0)){
        printf("Enter any number:");
        scanf("%lf", &num1);
        if(strcmp(op,"factorial")==0){
            result= factorial((int)num1);
        }else if(strcmp(op,"squareroot")==0){
            result= squareroot(num1);
        }else if(strcmp(op,"log")==0){
            result= logarithm(num1);
        }
        printf("The output of %s of %lf = %lf\n",op,num1,result);
        saveintofile_cal(op,result);
    }
    else{
        printf("Invalid operator. Try again\n");
    }
}
}

double TrigoCalculation(){
    char op[100];
    double num, result;
    while(1){
        printf("Enter the type of operation(sin,cos,tan,cosec,sec,cot) OR 'exit' for other calculation:");
        scanf("%s",op);
        if(strcmp(op,"exit")==0){
            return 0;
        }
        if((strcmp(op,"sin")==0)|| (strcmp(op,"cos")==0)||(strcmp(op,"tan")==0)||(strcmp(op,"cosec")==0)||(strcmp(op,"cot")==0)||(strcmp(op,"sec")==0)){
            printf("Enter the angle:");
            scanf("%lf",&num);
            if(strcmp(op,"sin")==0){
                result= sinvalue(num);
            }else if(strcmp(op,"cos")==0){
                result= cosvalue(num);
            }else if(strcmp(op,"tan")==0){
                result= tanvalue(num);
            }else if(strcmp(op,"cosec")==0){
                result= cosecvalue(num);
            }else if(strcmp(op,"sec")==0){
                result= secvalue(num);
            }else if(strcmp(op,"cot")==0){
                result= cotvalue(num);
            }
            printf("%s %lf = %lf\n",op,num,result);
            saveintofile_cal(op,result);
        }
        else{
            printf("Invalid operator. Try again\n");
        }
    }
}

void MatrixAddcalculation(){
    int row, col;
    double A[2][2], B[2][2], result[2][2];
    printf("Enter the elements in first matrix:\n");
    for(row=0; row<2; row++){
        for(col=0; col<2; col++){
            printf("Enter the element at position %d,%d:",row+1,col+1);
            scanf("%lf", &A[row][col]);
        }
    }
    printf("Enter the elments in second matrix:\n");
    for(row=0; row<2; row++){
        for(col=0; col<2; col++){
            printf("Enter the element at position %d,%d:", row+1, col+1);
            scanf("%lf", &B[row][col]);
        }
    }
    for(row=0; row<2; row++){
        for(col=0; col<2; col++){
            result[row][col]=A[row][col]+B[row][col];
        }
    }
    printf("The output after addition is:\n");
    for(row=0; row<2; row++){
        for(col=0; col<2; col++){
            printf("%lf ", result[row][col]);
        }
        printf("\n");
    }
    saveintofile_matrix("Matrix addition",result);
}
void MatrixMultiplyCalculation(){
    int row, col;
    double A[2][2], B[2][2], result[2][2], sum;
    printf("Enter the elements in first matrix:\n");
    for(row=0; row<2; row++){
        for(col=0; col<2; col++){
            printf("Enter the element at position %d,%d:",row+1,col+1);
            scanf("%lf", &A[row][col]);
        }
    }
    printf("Enter the elments in second matrix:\n");
    for(row=0; row<2; row++){
        for(col=0; col<2; col++){
            printf("Enter the element at position %d,%d:", row+1, col+1);
            scanf("%lf", &B[row][col]);
        }
    }
    for(row=0; row<2; row++){
        for(col=0; col<2; col++){
            sum=0;
            for(int i=0; i<2; i++){
                sum+=A[row][i]*B[i][col];
            }
            result[row][col]=sum;
        }
    }
    printf("The output after multiplication is:\n");
    for(row=0; row<2; row++){
        for(col=0; col<2; col++){
            printf("%lf ", result[row][col]);
        }
        printf("\n");
    }
    saveintofile_matrix("Matrix multiplication", result);
}

void BinarytoDecimal(){
    long long binarynum;
    int decimalnum=0, base=1, remainder;
    printf("Enter any binary number:");
    scanf("%lld", &binarynum);
    while(binarynum!=0){
        remainder=binarynum%10;
        decimalnum+= (remainder*base);
        binarynum=binarynum/10;
        base=base*2;
    }
    printf("Output in decimal=%d\n",decimalnum);
    saveintofile_conversion("Binary to decimal conversion", decimalnum);
}

void DecimaltoBinary(){
    long long binarynum=0, base=1;
    int decimalnum;
    printf("Enter any decimal number:");
    scanf("%d", &decimalnum);
    while(decimalnum!=0){
        binarynum+= (decimalnum%2)*base;
        decimalnum=decimalnum/2;
        base=base*10;
    }
    printf("Output in binary=%lld\n", binarynum);
    saveintofile_conversion("Decimal to binary conversion", binarynum);
}

void LinearEquation(){
    double a1,b1,c1,a2,b2,c2;
    printf("Enter the coefficients for first equation(a1x+b1y=c1):\n");
    printf("Enter a1:");
    scanf("%lf", &a1);
    printf("Enter b1:");
    scanf("%lf", &a2);
    printf("Enter c1:");
    scanf("%lf",&c1);
    printf("Enter the coefficients for second equation(a2x+b2y=c2):\n");
    printf("Enter a2:");
    scanf("%lf", &a2);
    printf("Enter b2:");
    scanf("%lf", &b2);
    printf("Enter c2:");
    scanf("%lf", &c2);
    double determinant= a1*b2-a2*b1;
    if(determinant==0){
        printf("No unique solution");
    }else{
        double x= (c1*b2-c2*b1)/determinant;
        double y= (a1*c2-a2*c1)/determinant;
        printf("The solution for the equation is:\n");
        printf("x = %lf\n",x);
        printf("y = %lf\n",y);
        saveintofile_equation("Linear equation solution",x,y);
    }
}

double add(double num1, double num2){
    return (num1+num2);
}
double subtract(double num1, double num2){
    return (num1-num2);
}
double multiply(double num1, double num2){
    return (num1*num2);
}
double division(double num1, double num2){
    if(num2!=0){
        return (num1/num2);
    }else{
        printf("undefined");
        return 0;
    }
}
double power(double base, double exp){
    return pow(base,exp);
}
int factorial(int n){
    //by recursion
    if(n==1){// base condition
        return 1;
    }
    int fact=factorial(n-1)*n;
    return fact;
}
double squareroot(double n){
    return sqrt(n);
}
double logarithm(double n){
    return log10(n);
}
double sinvalue(double n){
    return sin(n);
}
double cosvalue(double n){
    return cos(n);
}
double tanvalue(double n){
    return tan(n);
}
double secvalue(double n){
    double coskovalue=cos(n);
    if(coskovalue!=0){
        return (1/coskovalue);
    }else{
        printf("undefined");
        return 0;
    }
}
double cosecvalue(double n){
    double sinkovalue=sin(n);
    if(sinkovalue!=0){
        return (1/sinkovalue);
    }else{
        printf("undefined");
        return 0;
    }
}
double cotvalue(double n){
    double tankovalue=tan(n);
    if(tankovalue!=0){
        return (1/tankovalue);
    }else{
        printf("undefined");
        return 0;
    }
}

void saveintofile_cal(char *op, double result){
    FILE *fptr=fopen("hamrocalculations.txt","a");
    if(fptr==NULL){
        printf("File doesnt exist");
        return;
    }else{
        fprintf(fptr,"%s = %lf\n",op,result);
    }
    fclose(fptr);
}
void saveintofile_matrix(char *op, double result[2][2]){
    FILE *fptr=fopen("hamrocalculations.txt","a");
    if(fptr==NULL){
        printf("File doesnt exist\n");
        return;
    }else{
        fprintf(fptr,"%s=\n",op);
        for(int row=0; row<2; row++){
            for(int col=0; col<2; col++){
                fprintf(fptr,"%lf ",result[row][col]);
            }
            fprintf(fptr, "\n");
        }
    }
    fclose(fptr);
}
void saveintofile_conversion(char *op, int result){
    FILE *fptr=fopen("hamrocalculations.txt","a");
    if(fptr==NULL){
        printf("File doesnt exist");
        return;
    }else{
        fprintf(fptr, "%s = %d\n",op,result);
    }
    fclose(fptr);
}
void saveintofile_equation(char *op, double x, double y){
    FILE *fptr=fopen("hamrocalculations.txt","a");
    if(fptr==NULL){
        printf("File doesnt exist");
        return;
    }else{
        fprintf(fptr,"%s=\n",op);
        fprintf(fptr,"x = %lf\n",x);
        fprintf(fptr,"y = %lf\n",y);
    }
    fclose(fptr);