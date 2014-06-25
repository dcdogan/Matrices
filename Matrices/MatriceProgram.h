//
//  Header.h
//  Matrices
//
//  Created by DoganCan on 10/22/12.
//  Copyright (c) 2012 Dogan Can Dogan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#ifndef Matrices_Header_h
#define Matrices_Header_h

using namespace std ;


struct MatriceElements{
    
    int value ;
    
    MatriceElements* right ;
    MatriceElements* down ;
    
} ;


struct Matrice {
    
    int rowSize;
    int columnSize ;
    
    MatriceElements** elements ;
    
    void allocateMemoryForMatriceElements() ;
    
    void getRandomValuesForMatriceElements() ;
    
    void bindMatriceElements() ;
    
    void printMatrice() ;
    
    void readLinesFromFile() ;
    
};


void Matrice::allocateMemoryForMatriceElements(){
    
    elements = new MatriceElements *[rowSize];
    
    for( int i = 0; i < rowSize ; i++)
        
        elements[i] = new MatriceElements [columnSize] ;

}

void Matrice::getRandomValuesForMatriceElements(){
    
    for( int i = 0; i < rowSize ; i++)
        for(int j = 0; j < columnSize ; j++)
            elements[i][j].value = rand()%10 ;
            
}

void Matrice::bindMatriceElements(){
    
    // bind right pointers through row size  ---->
    //                                       ---->
    //                                       ---->

    for( int i = 0; i < rowSize ; i++)
        for(int j = 0; j < columnSize ; j++){
            elements[i][j].right = &elements[i][j+1];
            if (j == columnSize-1)              // if it comes to rightmost element connect right pointer to leftmost pointer
                elements[i][j].right = &elements[i][0];

        }
   
    // bind down pointers through column size |||
    //                                        |||
    //                                        VVV
    for( int i = 0; i < columnSize ; i++)
        for(int j = 0; j < rowSize ; j++){
            elements[j][i].down = &elements[j+1][i];
            if (j == rowSize-1)                  // if it comes to bottom element connect down pointer to first element
                elements[j][i].down = &elements[0][i];
        }

    
    // You can delete the comments and compile if you want to see linked values
    /*
   
    for( int i = 0; i < rowSize ; i++){
        cout<<"\n" ;
        for(int j = 0; j < columnSize ; j++)
            cout<<elements[i][j].right->value <<" " ;
        
    }

*/

}
    

void Matrice::printMatrice(){
    
    for( int i = 0; i < rowSize ; i++){
        cout<<"\n" ;
        for(int j = 0; j < columnSize ; j++)
            cout<<elements[i][j].value<<" " ;

    }
    cout<<endl<<endl;
}
    
    

// File Part


void Matrice::readLinesFromFile(){
    
    // read matrix file from the directory
    
    // you should change directory before compiling !!!
    
    //get the size with firstLine
    //and parse otherlines for assigning matrice elements
    string firstLine;
    string otherLines;
    ifstream myFile ("/Users/DoganCan/Documents/Developer/Matrices/Matrices/matrix.txt");
    
    
    if (myFile.is_open())
    {
        getline (myFile,firstLine);
        
        rowSize = firstLine[0]-'0';
        columnSize = firstLine[2]-'0';
        
        allocateMemoryForMatriceElements();
        
        for( int i = 0; i < rowSize ; i++){
            getline (myFile,otherLines);
            for(int j = 0, k = 0;  j < (2*columnSize-1), k < columnSize ; j=j+2, k++)
                elements[i][k].value = otherLines[j] - '0' ;
        }
        myFile.close();

    }
    
    else cout << "Unable to open file";
     
    
    
}



#endif
