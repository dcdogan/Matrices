//
//  MatrixOperations.h
//  Matrices
//
//  Created by DoganCan on 11/1/12.
//  Copyright (c) 2012 Dogan Can Dogan. All rights reserved.
//

#include "MatriceProgram.h"
#ifndef Matrices_MatrixOperations_h
#define Matrices_MatrixOperations_h

// Matrice operations functions


int determinantFunction(Matrice &squareMatrice);


void matrixMultiplication(Matrice &firstMatrice, Matrice &secondMatrice ){
    
    // hold sum for adding multiolication results
    
    int matriceSum ;
    
    if(firstMatrice.columnSize != secondMatrice.rowSize)
        cout<<"These matrices are not suitable for multiplication, please choose another operation!"<<endl;
    else{
        
        for( int i=0; i < firstMatrice.rowSize ;  i++){
            for (int j=0; j < secondMatrice.columnSize; j++){
                matriceSum = 0;
                for( int k = 0, l = 0; k < firstMatrice.columnSize, l < secondMatrice.rowSize ; k++, l++ ){
                    matriceSum += firstMatrice.elements[i][k].value * secondMatrice.elements[l][j].value ;
            }
                cout << matriceSum;
                cout<<" ";
    }
            cout<<endl;
        
    }
        
    }
}



void transpozeOperation(Matrice &firstMatrice, Matrice &secondMatrice ){
    
    //create a for loop for printing result on the screen
    
    cout<<"Transpoze of first matrice:"<<endl;
    
    for( int i = 0; i < firstMatrice.columnSize ; i++){
        for(int j = 0; j < firstMatrice.rowSize ; j++)
            cout<< firstMatrice.elements[j][i].value <<" ";
        cout<<endl;
    }
    
    cout<<endl;
    
    cout<<"Transpoze of second matrice"<<endl;
    for( int i = 0; i < secondMatrice.columnSize ; i++){
        for(int j = 0; j < secondMatrice.rowSize ; j++)
            cout<< secondMatrice.elements[j][i].value <<" ";
        cout<<endl;
    }

}



void checkIfSymmetric(Matrice &firstMatrice, Matrice &secondMatrice ){
    
    // create a for loop for symmetry check 
    
    bool symmetric = true ;
    
    if(firstMatrice.rowSize != firstMatrice.columnSize)
        cout<<"First Matrice is not symmetric because row and column sizes are different.";
    else{
        if(firstMatrice.rowSize >= 3){
            for(int i=0,j=0; i < firstMatrice.rowSize-2, j < firstMatrice.columnSize-2 ; i++,j++)
                if(firstMatrice.elements[i+2][j].value != firstMatrice.elements[i][j+2].value)
                    symmetric = false;

        for(int i=0,j=0; i < firstMatrice.rowSize-1, j < firstMatrice.columnSize-1 ; i++,j++)
            if(firstMatrice.elements[i+1][j].value != firstMatrice.elements[i][j+1].value)
                symmetric = false ;
        
        if(symmetric == false)
            cout<<"First Matrice is not symmetric because elements are not symmetric."<<endl;
            
        }
        
    }
    
    cout<<endl;
    
    if(secondMatrice.rowSize != secondMatrice.columnSize)
        cout<<"Second Matrice is not symmetric because row and column sizes are different.";
    else{
        if(secondMatrice.rowSize >= 3){
            for(int i=0,j=0; i < secondMatrice.rowSize-2, j < secondMatrice.columnSize-2 ; i++,j++)
                if(secondMatrice.elements[i+2][j].value != secondMatrice.elements[i][j+2].value)
                    symmetric = false;
            
            for(int i=0,j=0; i < secondMatrice.rowSize-1, j < secondMatrice.columnSize-1 ; i++,j++)
                if(secondMatrice.elements[i+1][j].value != secondMatrice.elements[i][j+1].value)
                    symmetric = false ;
            
            if(symmetric == false)
                cout<<"Second Matrice is not symmetric because elements are not symmetric."<<endl;
            
        }
    }

    cout<<endl;
    
}


void checkIfZeroMatrix(Matrice &firstMatrice, Matrice &secondMatrice ){
    
    // if it is not for loop break loops and print onn the screen
    
    bool zero = true ;
    
    for(int i = 0, j = 0 ; i < firstMatrice.rowSize, j < firstMatrice.columnSize ; i++, j++){
        for (int k = i, l = j  ; k < firstMatrice.columnSize, l < firstMatrice.rowSize ; k++, l++ ){
            if( firstMatrice.elements[i][k].value != 0 || firstMatrice.elements[j][l].value != 0 )
                zero = false;
            if(zero==false)
                break;
        }
        if(zero==false)
            break;
    }
    if(zero == true)
        cout<<"First matrix is a zero matrice"<<endl;
    else
        cout<<"First matrix is not a zero matrice"<<endl;
    
    cout<<endl;
    

    for(int i = 0, j = 0 ; i < secondMatrice.rowSize, j < secondMatrice.columnSize ; i++, j++){
        for (int k = i, l = j  ; k < secondMatrice.columnSize, l < secondMatrice.rowSize ; k++, l++ ){
            if( secondMatrice.elements[i][k].value != 0 || secondMatrice.elements[j][l].value != 0 )
                zero = false;
            if(zero==false)
                break;
        }
        if(zero==false)
            break;
    }
    if(zero == true)
        cout<<"Second matrix is a zero matrice"<<endl;
    else
        cout<<"Second matrix is not a zero matrice"<<endl;
    
    cout<<endl;


}





void determinantOperation(Matrice &firstMatrice, Matrice &secondMatrice ){
    
    
    // check if suitable for determinant
    
    if(firstMatrice.rowSize != firstMatrice.columnSize || firstMatrice.rowSize == 1 || firstMatrice.rowSize > 3)
        cout<<"This is not a square matrice please choose a square matrice for this operation"<<endl;
    else
        cout<<"Determinant of first matrix is: "<<determinantFunction(firstMatrice)<<endl;
    
    if(secondMatrice.rowSize != secondMatrice.columnSize || secondMatrice.rowSize == 1 || firstMatrice.rowSize > 3)
        cout<<"This is not a square matrice please choose a square matrice for this operation"<<endl;
    else
        cout<<"Determinant of second matrix is: "<<determinantFunction(secondMatrice)<<endl;

    
    
}



int determinantFunction(Matrice &squareMatrice){
    
    // calculate the result
    
    int result = 0 ;
    
    if ( squareMatrice.rowSize == 2)
        result = squareMatrice.elements[0][0].value * squareMatrice.elements[1][1].value - squareMatrice.elements[1][0].value*squareMatrice.elements[0][1].value ;
    else{
        
        result = squareMatrice.elements[0][0].value * (squareMatrice.elements[1][1].value*squareMatrice.elements[2][2].value-squareMatrice.elements[2][1].value*squareMatrice.elements[1][2].value) - squareMatrice.elements[0][1].value * (squareMatrice.elements[1][0].value*squareMatrice.elements[2][2].value-squareMatrice.elements[1][2].value*squareMatrice.elements[2][0].value) + squareMatrice.elements[0][2].value * (squareMatrice.elements[1][0].value*squareMatrice.elements[2][1].value-squareMatrice.elements[2][0].value*squareMatrice.elements[1][1].value) ;
    
    }
    return result;
    
}





#endif
