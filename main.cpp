/*#include <iostream>
int sumDig(int n){
        int sum=0;
        while (n!=0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    
    }
int main(){
    int count=0;
    int x[5];
    x[0]=989;
    x[1]=999;
    x[2]=57;
    x[3]=88;
    x[4]=48;
    for(int i=0;i<5;++i){
        if(sumDig(x[i])>25){
            count++;
        }

    }
    if(count>=2){
        std::cout<<"There are >=2 numbers with sum of digits>25"<<std::endl;
        for(int i=0;i<4;++i){
        for(int j=i+1;j<5;++j){
            if(x[i]>x[j]){
                std::swap(x[i],x[j]);
            }
        }
    }
    for (int i=0;i<5;++i){
        std::cout<<x[i]<<std::endl;
    }

    }
    else{
        std::cout<<"series of numbers does not match the condition"<<std::endl;
    }

    
    return 0;
}
*/


#include <iostream>
int main(){
    const int length=4;//cтолбцы
    const int width=3;//строки
    int matrix[width][length]={
        {-1,5,8,-7},
        {4,-3,6,9},
        {6,-9,3,8}, 
    };
    //подсчет положительных в столбцах
    int positiveCount[length]={0};
    for(int j=0;j<length;++j){
        for(int i=0;i<width;++i){
            if (matrix[i][j]>0){
                positiveCount[j]++;
            }

        }
    
    }
    //проверка, что есть хотя бы одно положительное
    bool hasPositive=false;
    for(int j=0;j<length;++j){
        if(positiveCount[j]>0){
            hasPositive=true;
            break;
        }
    }
    //столбец с мин количеством положительных
    int minCol=0;
    if(hasPositive){
        for(int j=1;j<length;++j){
        if(positiveCount[j]<positiveCount[minCol]){
            minCol=j;
        
        }
        
    }
    for(int i=0;i<width;++i){
        matrix[i][minCol]=100;
    }

    }
    else{
        
        std::cout<<"no positive"<<std::endl;
    }
    
    
    std::cout<<"Result matrix: "<<std::endl;
    for (int i=0;i<width;++i){
        for(int j=0;j<length;++j){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}