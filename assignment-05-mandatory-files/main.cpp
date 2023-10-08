#include <iostream>
#include <fstream>          // for file I/O
#include <cassert>          // for assertion checking
// Check if Git Push works

using namespace std;

enum Action {Encrypt, Decrypt} ;

int seed = 0 ;

void initialise_pseudo_random (int r)
{
//  pre-condition:
    assert (r > 0 && r <= 65536) ;
/*  post-condition:
    seed has value r.
*/
    seed = r ;
}

int next_pseudo_random_number ()
{
//  pre-condition:
    assert (seed > 0 && seed <= 65536) ;
/*  post-condition:
    result value > 0 and result value <= 65536 and result value != seed at entry of function
*/
    const int SEED75 = seed * 75 ;
    int next = (SEED75 & 65535) - (SEED75 >> 16) ;
    if (next < 0)
        next += 65537 ;
    seed = next ;
    return next ;
}

char rotate_char (char a, int r, Action action)
{
//  Pre-condition:
    assert(true);
/*  Post-condition: 
    only if a >= 32, a will be transformed in encryption or decryption, and the result car will be within the range [32,127)
*/  
    if (action == 0)
    {
        if (a >= 32)
        a = (a - 32 + (r % (128 - 32)) + (128 - 32)) % 96 + 32; // encryption
    }
    else
    {
        if (a >= 32)
        a = (a - 32 - (r % (128 - 32)) + (128 - 32)) % 96 + 32; // decryption
    }
    return a;
}

bool open_input_and_output_file (ifstream& infile, ofstream& outfile)
{
//  Pre-condition:
    assert(!infile.is_open() && !outfile.is_open());
/*  Post-condition: 
    When both input and output files have been opened successfully, the result value is true, otherwise it is false
*/ 

    string inputFileName, outputFileName;

    cout << "Enter file name for input (No layout symbols): ";
    cin >> inputFileName;
    cout << "Enter file name for output (No layout symbols): ";
    cin >> outputFileName;

    while (inputFileName == outputFileName) // If input and output file names are identical, user need to type again
    {
        cerr << "Error: Input and output file names are identical. Please type again." << endl;
        cout << "Enter file name for input (No layout symbols): ";
        cin >> inputFileName;
        cout << "Enter file name for output (No layout symbols): ";
        cin >> outputFileName;
    }

    infile.open(inputFileName);
    if (infile.fail())
        cerr << "Error: Input file "<< inputFileName << " could not be opened." << endl;
    else
        cout << "Input file "<< inputFileName << " has been opened successfully." << endl;

    outfile.open(outputFileName);
    if (outfile.fail())
        cerr << "Error: Output file "<< outputFileName << " could not be opened." << endl;
    else
        cout << "Output file "<< outputFileName << " has been opened successfully. " << endl;    
    
    if (infile.is_open() && outfile.is_open())
        {
        cout << "Both input and output files have been opened successfully." << endl;
        return true;
        } 
    else
        return false;

}

Action get_user_action ()
{// Pre-condition:
    assert ( true ) ;
/*  Post-condition:
    result is the Action that the user has indicated that the program should encrypt / decrypt
*/
    cout << "Do you want to encrypt the file? (y/n): " ;
    string answer ;
    cin  >> answer ;
    if (answer == "y")
        return Encrypt;
    else
        return Decrypt;
}

int initial_encryption_value ()
{// Pre-conditie:
    assert (true) ;
/*  Post-condition:
    result is a value between 0 and 65355 (both inclusive)
*/
    int initial_value = -1 ;
    while (initial_value < 0 || initial_value > 65535)
    {
        cout << "Please enter the initial coding value (greater or equal to 0 and less than 65536)" << endl ;
        cin  >> initial_value ;
    }
    return initial_value ;
}

void use_OTP (ifstream& infile, ofstream& outfile, Action action, int initial_value)
{
//  Pre-condition:
    assert (infile.is_open() && outfile.is_open());
/*  Post-condition:
    
*/
    initialise_pseudo_random (initial_value);

    char c;
    infile.get (c);
    while (!infile.fail ())
    {
        rotate_char (c, seed, action);
        outfile.put (c);
        infile.get (c);
        next_pseudo_random_number ();
    }
}

#ifndef TESTING
int main ()
{
    const Action ACTION = get_user_action();
    ifstream input_file;
    ofstream output_file;
    if (!open_input_and_output_file (input_file,output_file))
    {
        cout << "Program aborted." << endl;
        return -1;
    }
    const int INITIAL_VALUE = initial_encryption_value ();
    use_OTP (input_file,output_file,ACTION,INITIAL_VALUE);
    input_file.clear ();
    output_file.clear ();
    input_file.close ();
    output_file.close ();

    if (!input_file || !output_file)
    {
        cout << "Not all files were closed successfully. The output might be incorrect." << endl;
        return -1;
    }
    return 0;
}
#endif
