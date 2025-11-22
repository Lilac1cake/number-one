#include <iostream>
#include <cstdlib>
//пункт 1

void expandMatrix(int**& matrix, int& rows, int& cols, int A, int B, int C, int D) {

    int newRows = rows + A;   
    int newCols = cols + B;   

    matrix = (int**)realloc(matrix, newRows * sizeof(int*));
    for (int u=0;u<newRows;++u){
        matrix[u]=(int*)realloc(matrix[u],sizeof(int)*newCols);
    }

    for (int i = 0; i < newRows; ++i) {
        for (int j=0;j<newCols;++j){
            matrix[i][j]=i*C+j*D;
        }
    }
    matrix[newRows-1][newCols-1]=D;
    matrix[newRows-1][newCols-2]=C;
    matrix[newRows-2][newCols-1]=B;
    matrix[newRows-2][newCols-2]=A;
    rows=newRows;
    cols=newCols;
   
}

int* removeRowsWithZero(int** &matrix, int &rows, int cols) {
    // Находим индексы строк с нулями
    int* zeroRows = new int[rows];
    int zeroCount = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroRows[zeroCount++] = i;
                break;
            }
        }
    }
    
    if (zeroCount == 0) {
        delete[] zeroRows;
        return nullptr;
    }
    

    int** newMatrix = new int*[rows - zeroCount];
    int newIndex = 0;
    
    for (int i = 0; i < rows; i++) {
        bool keepRow = true;
        for (int j = 0; j < zeroCount; j++) {
            if (zeroRows[j] == i) {
                keepRow = false;
                break;
            }
        }
        
        if (keepRow) {
            newMatrix[newIndex] = matrix[i];
            newIndex++;
        } else {
            delete[] matrix[i];
        }
    }
    
    delete[] matrix;
    matrix = newMatrix;
    rows -= zeroCount;
    
    return zeroRows;
}

int main() {
    int A, B, C, D;

    std::cout << "Enter A and B: ";
    std::cin >> A >> B;
    while (A < 0 || B < 0) {
        std::cout << "A,B >= 0. Enter again: ";
        std::cin >> A >> B;
    }
    std::cout << "Enter C and D: ";
    std::cin >> C >> D;

    // исходная матрица 2*2 
    int rows = 2, cols = 2;

    int** matrix = (int**)malloc(rows*sizeof(int*));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int*)malloc(cols*sizeof(int));

    matrix[0][0] = A;  
    matrix[0][1] = B;
    matrix[1][0] = C;
    matrix[1][1] = D;

    std::cout << "\nInitial 2*2 matrix:\n";
    std::cout << matrix[0][0] << " " << matrix[0][1] << "\n";
    std::cout << matrix[1][0] << " " << matrix[1][1] << "\n\n";

    //расширяем матрицу 
    expandMatrix(matrix, rows, cols, A, B, C, D);

    std::cout << "Expanded matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }

    //удаляем строки с нулями
    int* removedRows = removeRowsWithZero(matrix, rows, cols);
    
    if (removedRows) {
        std::cout << "\nMatrix after removing rows with zero:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                std::cout << matrix[i][j] << " ";
            std::cout << "\n";
        }
        delete[] removedRows;
    } else {
        std::cout << "\nNo rows with zero found\n";
    }
    
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
//пункт 2
#include<iostream>
int main(){
    int a;
    int b;
    std::cout<<"Enter a,b: "<<std::endl;
    std::cin>>a>>b;
    std::cout<<"Current a and b: "<<a<<" "<<b<<std::endl;
    int* fst;
    int* scnd;
    fst = new int(a);
    scnd= new int(b);
    *fst*=2;
    std::cout<<"Current a and b: "<<*fst<<" "<<*scnd<<std::endl;
    int n=*fst;
    *fst=*scnd;
    *scnd=n;
    std::cout<<"Current a and b: "<<*fst<<" "<<*scnd<<std::endl;
    delete fst;
    delete scnd;
    return 0;
}