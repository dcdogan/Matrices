//
//  main.cpp
//  Matrices
//
//  Created by DoganCan on 10/22/12.
//  Copyright (c) 2012 Dogan Can Dogan. All rights reserved.
//

#include "MatriceProgram.h"


using namespace std ;



int main(int argc, const char * argv[])
{
    string line;
    ifstream myfile ("matrix.txt");
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            getline (myfile,line);
            cout << line << endl;
        }
        myfile.close();
    }
    
    else cout << "Unable to open file"; 

   /*
    // create a random matrice struct called RandomMatrice
    
    Matrice RandomMatrice ;
    
    // we should get the dimension from the user in this scheme: row x column
    // so I am creating a string with 3 bytes to get it
    
    char getMatriceSize[3] ;
    cout << "Please enter the dimensions of the matrice (e.g 2x3):" ;
    cin  >> getMatriceSize ;
    cout << "Here is a matrice with size of "<< getMatriceSize << "\n" ;
    //  we can add exception here in case of user enters invalid size
    
    // In order to get the size, I subtsracted ascii value '0' from the char value
    RandomMatrice.rowSize = getMatriceSize[0]-'0';
    //cout << "Row size "<< rowSize << "\n" ;
    
    // Same operation for column size of the matrice
    RandomMatrice.columnSize = getMatriceSize[2]-'0';
    //cout << "Column size "<< columnSize << "\n" ;
    
    // allocate memory for given dimension in random matrice
    RandomMatrice.allocateMemoryForMatriceElements() ;

    // get random values for the matrice
    RandomMatrice.getRandomValuesForMatriceElements() ;
    
    // print the matrice with new elements
    RandomMatrice.printMatrice() ;

    RandomMatrice.bindMatriceElements() ;
    
       
    
    // Menu
    
    
    bool menuChoice = true;            //  boolean value for menu choice (continue ? (Y or N))
    char operationChoice ;             // char value for menu operations 
    char askIfTheUserWantsToContinueOperations ;
    while (menuChoice){
    
        cout << "\t\t\tMatrice Operation Menu\n" ;
        cout << "Select one of the matrice operations: \n" ;
           
        cout<< "1. Multiply the matrices and print the result to the screen.(M)\n"<<
            "2. Find transpose of the matrices (both) and print them to the screen.(T)\n"<<
            "3. Check if the matrices are symmetric.(S)\n"<<
            "4. Check if the matrices are zero matrix or not and give messages to the user about the result.(C)\n"<<
            "5. Calculate the determinant of the matrices.(D)\n";
        
        cin>> operationChoice ;
        
        switch (operationChoice) {
            case 'M':
                //statements
                break;
            case 'T':
                //statements
                break;
            case 'S':
                //statements
                break;
            case 'C':
                //statements
                break;
            case 'D':
                //statements
                break;
            default:
                break;
        }
        
        cout<<"Would you like to continue ?(Y or N)\n";
        cin>>askIfTheUserWantsToContinueOperations ;
        
        if(askIfTheUserWantsToContinueOperations == 'Y')
            menuChoice = true ;
        else if(askIfTheUserWantsToContinueOperations == 'N')
            menuChoice = false ;
        else
            cout<< "Wrong Choice, but operation menu is not terminated by default.\n";
            
    }
    
    


    
    
    
    
    
    
    
    
    
    */
    
    
    
    
    
    return 0;
}

