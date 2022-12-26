/*
My training fun projects in CPP.
Password Validation.
Building a password evaluator to validate the input.
Visit for more fun projects: https://github.com/viperbytes
Made by Konstantinos "viperbytes" Papageorgiou.
*/

/*
The password is valid if it has at a minimum 2 numbers, 2 of the following special characters and a length of at least 7 characters.
The phases we have are "Very Strong","Strong","Medium","Weak".
-----------------------------------------------------------------------------------------------------------
[Level 1: "Very Strong"]
2 Numbers - 2 Special Characters ('!','@','#','$','%','&','*') - 2 Upper Letters - length >=  12 Characters 
-----------------------------------------------------------------------------------------------------------
[Level 2: "Strong"]
2 Numbers - 1 Special Characters ('!','@','#','$','%','&','*') - 1 Upper Letter -  length <=  7 Characters
-----------------------------------------------------------------------------------------------------------
[Level 3: "Medium"]
1 Number - 1 Upper Letter - length 7 Characters
-----------------------------------------------------------------------------------------------------------
[Level 4: "Weak"]
1 Number  - length 7 Characters
-----------------------------------------------------------------------------------------------------------
*/

// Declaring libraries and using namespace
#include <iostream>
#include <cstring>
using namespace std;

// Creating password_validation function
void password_validation(){
    string lock_key;                    // Password variable
    string pass_security;               // Level of security
    cout << "Enter your password: ";
    cin >> lock_key;
    cout << endl;

    
// My constant string array variables
    const string special_ch[7] = {"!","@","#","$","%","&","*"};
    const string numbers[10] = {"0","1","2","3","4","5","6","7","8","9"};
    const string ABC_HIGH[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    const string ABC_LOW[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

// My integers variables
    int spec_counter = 0;
    int num_counter = 0;
    int abc_high_counter = 0;
    int abc_low_counter = 0;

// My variables counting size
    int locksize = size(lock_key);
    int numsize = size(numbers);
    int special_chsize = size(special_ch);
    int abclowsize = size(ABC_LOW);
    int abchighsize = size(ABC_HIGH);


// My variables for detecting place of numbers and characters
    int char_passplace[locksize];
    int num_passplace[locksize];
    int ABC_HIGH_passplace[locksize];
    int ABC_LOW_passplace[locksize];

// My conversion string to char for making comparisons
    char char_array[locksize + 1];
    strcpy(char_array,lock_key.c_str());

// for loop - detecting characters from password through conditions
    for(int i=0; i<locksize;i++){
        
        string y = {char_array[i]};
        
        for(int k=0; k<special_chsize; k++){
        
        if (y == special_ch[k])
        {
            char_passplace[i+1] = i+1; 
            cout << "The character: [" << special_ch[k] << "]  found at place : [" << char_passplace[i+1] << "]" << endl;
            spec_counter = spec_counter + 1; // [SPECIAL CHARACTERS NUMBER]
        }
        }

        for (int z=0;z<numsize;z++){

            if (y == numbers[z])
            {
                num_passplace[i+1] = i+1;
                cout << "The character: [" << numbers[z] << "]  found at place : [" << num_passplace[i+1] << "]" << endl;
                num_counter = num_counter + 1; // [NUMBERS NUMBER]

            }
            
        }

                for (int r=0;r<abclowsize;r++){

            if (y == ABC_LOW[r])
            {
                ABC_LOW_passplace[i+1] = i+1;
                cout << "The character: [" << ABC_LOW[r] << "]  found at place : [" << ABC_LOW_passplace[i+1] << "]" << endl;
                abc_low_counter = abc_low_counter + 1; // [ABC LOWERCASE LETTERS NUMBER] 

            }
            
        }

                
                for (int n=0;n<abchighsize;n++){

            if (y == ABC_HIGH[n])
            {
                ABC_HIGH_passplace[i+1] = i+1;
                cout << "The character: [" << ABC_HIGH[n] << "]  found at place : [" << ABC_HIGH_passplace[i+1] << "]" << endl;
                abc_high_counter = abc_high_counter + 1; // [ABC UPPERCASE LETTERS NUMBER] 

            }
            
        }
    }

// Setting the security level to inform the user and label it.
if(locksize>=12 && spec_counter>=2 && num_counter>=2 && abc_high_counter>=2){

    pass_security = "Very Strong";

}

if(locksize>=7 && spec_counter>=1 && num_counter>=1 && abc_high_counter>=1){

    pass_security = "Strong";
    
}

if(locksize == 7 && num_counter>=1 && abc_high_counter>=1){

    pass_security = "Medium";
    
}

if(locksize == 7 && num_counter>=1){

    pass_security = "Weak";
    
}

//Output Display
cout << endl << "Password Information: " << endl << endl;
cout << "Uppercase Letters:  " << abc_high_counter << endl;    
cout << "Lowercase Letters:  " << abc_low_counter << endl;
cout << "Special Characters: " << spec_counter << endl;
cout << "Numbers:            " << num_counter << endl;
cout << endl;
cout << "Password Security:  " << pass_security << endl;

}

int main(){

cout << "---------------------------------------------------------------------------------------------------------"<< endl;
cout << "[Level 1: Very Strong]" << endl;
cout <<"2 Numbers - 2 Special Characters ('!','@','#','$','%','&','*') - 2 Upper Letters - length >=12 Characters"<< endl;
cout <<"---------------------------------------------------------------------------------------------------------"<< endl;
cout <<"[Level 2: Strong]"<< endl;
cout <<"2 Numbers - 1 Special Characters ('!','@','#','$','%','&','*') - 1 Upper Letter - length <=  7 Characters"<< endl;
cout <<"---------------------------------------------------------------------------------------------------------"<< endl;
cout <<"[Level 3: Medium]" << endl;
cout <<"1 Number - 1 Upper Letter - length 7 Characters"<<endl;
cout <<"---------------------------------------------------------------------------------------------------------" << endl;
cout <<"[Level 4: Weak]" << endl;
cout <<"1 Number  - length 7 Characters" << endl;
cout <<"---------------------------------------------------------------------------------------------------------" << endl;

password_validation();
cout << endl;

system("pause");
}

/*
Thank you for reading my code. Euxaristo polu gia ton xrono sou. Wish you happy programming.
*/