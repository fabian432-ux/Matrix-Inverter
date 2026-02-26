#include <stdio.h>
#include <math.h>
//We add the vector on the specific i line so that we get 0 on the respective column
void Adunare(int col, float VectorTest[100], float MatriceInitiala[100][100], int k)
{
    for(int j=1;j<=col;j++)
    {
        MatriceInitiala[k][j]= MatriceInitiala[k][j] + VectorTest[j];
    }
}
//We multiply the vector with the 1st value that is not equal to 0 in the next lines
void InmultireVector(int col, float VectorTest[100], float MatriceInitiala[100][100], int i, int k)
{
    for(int j=1;j<=col;j++)
    {
        VectorTest[j]= VectorTest[j] * MatriceInitiala[k][i];
    }
}
//We copy the a vector into a vectortest
void Copiere(int col,float a[100],float VectorTest[100])
{
    for(int i=1;i<=col;i++)
    {
        VectorTest[i]=a[i];
    }
}
//We modify the rows of the matrix to get the I matrix on the left side
void ScadereLinii(int col, float MatriceInitiala[100][100], float a[100], int i, int n)
{
        for(int k=i+1;k<=n;k++)
        {
            float VectorTest[200];
            Copiere(col,a,VectorTest);
            InmultireVector(col, VectorTest, MatriceInitiala, i, k);
            Adunare(col, VectorTest, MatriceInitiala, k);

        }
}
//We modify the rows of the matrix to get the I matrix on the left side
void ScadereLiniiReverse(int col, float MatriceInitiala[100][100], float a[100], int i, int n)
{
    for(int k=i-1;k>-1;k--)
    {
        float VectorTest[200];
        Copiere(col, a, VectorTest);
        InmultireVector(col, VectorTest, MatriceInitiala, i, k);
        Adunare(col, VectorTest, MatriceInitiala, k);
    }
}
//We introduce into a vector the values of the lane we just devided but with the - sign
void VectorNou(int col, float MatriceInitiala[100][100], float a[100], int i)
{
    for(int j=1;j<=col;j++)
    {
        if(MatriceInitiala[i][j] == 0)
            a[j]=MatriceInitiala[i][j];
        else
            a[j]=-MatriceInitiala[i][j];
    }
}
//We devide the column i to the [i][i] element because after the calculations ont the positions unter the i line we will have 0
void Impartire(int col, float MatriceInitiala[100][100], int i)
{
    float t=MatriceInitiala[i][i];
    for(int j=i;j<=col;j++)
    {
        MatriceInitiala[i][j]= MatriceInitiala[i][j] / t;
    }
}
//The linie value will get the value of the line that has o on the principal diagonal
int ElementNul(int n, float MatriceInitiala[100][100])
{
    for(int i=1;i<=n;i++)
    {
        if(MatriceInitiala[i][i] == 0)
            return i;
    }
}
//We search the first line that has the element from the same column equal to 0
int PrimulDupaZero(int n, float MatriceInitiala[100][100], int linie)
{
    for(int i=1;i<=n;i++)
        if(MatriceInitiala[i][linie] != 0)
            return i;
}
//We swap the two lines with one another
void Schimbare(int col, float MatriceInitiala[100][100], int linie, int PrimaLinie)
{
    int aux;
    for(int i=1;i<=col;i++)
    {
        aux=MatriceInitiala[linie][i];
        MatriceInitiala[linie][i]=MatriceInitiala[PrimaLinie][i];
        MatriceInitiala[PrimaLinie][i]=aux;
    }
}
//We verify if on the principal diagonal we find emements equal to 0
int checkifok(int n, float MatriceInitiala[100][100]){
    for(int i=1;i<=n;i++)
    {
        if(MatriceInitiala[i][i] == 0)
            return 0;

    }
    return 1;
}
//We create a vector of a specific line from the matrix
void CreareVectorLinii(int n, float MatriceInitiala[100][100], float b[100], int i)
{
    for(int j=1;j<=n;j++)
    {
        b[j]=MatriceInitiala[i][j];
    }
}
//We compare the line with the next lines from the matrix
int ComparareLinii(int n, float MatriceInitiala[100][100], float b[100], int i)
{
    for(int j=i+1;j<=n;j++)
    {
        int VariabileEgale=0;
        for(int k=1;k<=n;k++)
        {
            if(b[k] == MatriceInitiala[j][k])
                VariabileEgale=VariabileEgale+1;
        }
        if(VariabileEgale==n)
            return 0;
    }
    return 1;
}
//We compare the column with the next columns from the matrix
int ComparareColoane(int n, float MatriceInitiala[100][100], float b[100], int i)
{
    for(int j=i+1;j<=n;j++)
    {
        int VariabileEgale=0;
        for(int k=1;k<=n;k++)
        {
            if(b[k] == MatriceInitiala[k][j])
                VariabileEgale=VariabileEgale+1;
        }
        if(VariabileEgale==n)
            return 0;
    }
    return 1;
}
//We create a vector of a specific column from the matrix
void CreareVectorColoane(int n, float MatriceInitiala[100][100], float b[100], int i)
{
    for(int j=1;j<=n;j++)
    {
        b[j]=MatriceInitiala[j][i];
    }
}
//We verify if the matrix has two equal rows
int CheckForSameLines(int n, float MatriceInitiala[100][100])
{
    for(int i=1;i<=n;i++)
    {
        float b[100];
        CreareVectorLinii(n, MatriceInitiala, b, i);
        if(ComparareLinii(n, MatriceInitiala, b, i) == 0)
        {
            printf("The matrix is not invertable");
            return 0;
        }

    }
    return 1;
}
//We verify if the matrix has two equal colums
int CheckForSameColums(int n,float MatriceInitiala[100][100])
{
    for(int i=1;i<=n;i++)
    {
        float b[100];
        CreareVectorColoane(n, MatriceInitiala, b, i);
        if(ComparareColoane(n, MatriceInitiala, b, i) == 0)
        {
            printf("The matrix is not invertable");
            return 0;
        }
    }
    return 1;
}
//We print the inverse of the matrix
void Afisare(int n,int col,float MatriceInitiala[100][100])
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=n+1;j<=col;j++)
            printf("%g ", MatriceInitiala[i][j]);
        printf("\n");
    }
}
//We verify if we have lines or columns with all the elements equal to 0
int CheckForZero(int n,float MatriceInitiala[100][100])
{
    int zero,zero1;
    for(int i=1;i<=n;i++)
    {
        zero=0;
        zero1=0;
        for(int j=1;j<=n;j++)
        {
            if(MatriceInitiala[i][j] == 0)
                zero=zero+1;
            if(MatriceInitiala[j][i] == 0)
                zero1=zero1+1;
        }
        if(zero==n || zero1 == n){
            printf("The matrix is not invertable");
            return 0;
        }
    }
    return 1;
}
//We add the I vector to the end of the n columns of the matrix
void Construire(int n,int col,float MatriceInitiala[100][100])
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=n+1;j<=col;j++)
            if(j-i==n)
                MatriceInitiala[i][j]=1;
            else
                MatriceInitiala[i][j]=0;
    }
}
//Scaning of the matrix
void Citire(int n,float MatriceInitiala[100][100])
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%f",&MatriceInitiala[i][j]);
}

int main()
{
    float MatriceInitiala[100][100],a[100],CopieMatriceInitiala[100][100];
    int n,i=1,col,m;
    scanf("%d",&n);
    scanf("%d",&m);
    if(m!=n)
    {
        printf("The matrix is not invertable because the number of rows and columns is not the same");
        return 0;
    }
    else {
        col = 2 * n;
        Citire(n, MatriceInitiala);
        Construire(n, col, MatriceInitiala);
        if (CheckForZero(n, MatriceInitiala) == 0)
            return 0;
        if (CheckForSameLines(n, MatriceInitiala) == 0)
            return 0;
        if (CheckForSameColums(n, MatriceInitiala) == 0)
            return 0;

        int isOK = checkifok(n, MatriceInitiala);
        while (isOK == 0) {
            int linie = ElementNul(n, MatriceInitiala);
            int PrimaLinie = PrimulDupaZero(n, MatriceInitiala, linie);
            Schimbare(col, MatriceInitiala, linie, PrimaLinie);
            //We verify if on the principal diagonal there is 0 on the new row
            isOK = checkifok(n, MatriceInitiala);
        }
        for (i = 1; i <= n; i++) {
            Impartire(col, MatriceInitiala, i);
            VectorNou(col, MatriceInitiala, a, i);
            ScadereLinii(col, MatriceInitiala, a, i, n);
        }
        for (i = n; i >= 1; i--) {
            //We must not divide the matrix anymore because the values on the principal diagonal are 1
            VectorNou(col, MatriceInitiala, a, i);
            ScadereLiniiReverse(col, MatriceInitiala, a, i, n);
        }
        for( i=1;i<=n;i++)
        {
            for(int j=1;j<=col;j++)
                if(isnan(MatriceInitiala[i][j])==1)
                {
                    printf("The matrix is not invertable");
                    return 0;
                }
        }
        Afisare(n, col, MatriceInitiala);
        return 0;
    }
}

