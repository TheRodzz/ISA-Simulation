#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
string MAR,IBR,mem[1000];
ll AC = 0, PC = 420,M[] = {0, 1, 4, 6, 5, 6, 3, 9, 4, 2, 10, 0},MBR;

// decoder 
void decoder(string inst)
{
    // right op code,left op code, right instruction and left instruction
    // 40 bit instruction is sliced and stored as required
    string opL, opR, iR, iL, rhs, lhs; 
    rhs = inst.substr(20, 40);
    lhs = inst.substr(0, 20);
    opL = lhs.substr(0, 8);
    iL = lhs.substr(8, 20);
    opR = rhs.substr(0, 8);
    iR = rhs.substr(8, 20);
    IBR=rhs;MAR=iL;

    // print statements have been commented out so that the 
    // LOAD M[X]
    if (opL == "00000001")
    
    {
        cout<<"PC: "<<PC<<endl;
        MAR = PC;
        AC = M[stoi(iL, 0, 2)];
        cout<<"AC: "<<AC<<endl;
        MBR = M[stoi(iL, 0, 2)];
        cout<<"MBR: "<<MBR<<endl;
    }

    // STOR M[X]
    else if (opL == "00100001")
    {
        cout<<"PC: "<<PC<<endl;
        M[stoi(iL, 0, 2)] = AC;
        cout<<"AC: "<<AC<<endl;
        MBR = M[stoi(iL, 0, 2)];
        cout<<"MBR: "<<MBR<<endl;
    }

    // ADD M[X]
    else if (opL == "00000101")
    {
        cout<<"PC: "<<PC<<endl;
        AC += M[stoi(iL, 0, 2)];
        cout<<"AC: "<<AC<<endl;
        MBR = M[stoi(iL, 0, 2)];
        cout<<"MBR: "<<MBR<<endl;
    }

    PC++;
    MAR=iR;
    if (opR == "00000001")
    {
        cout<<"PC: "<<PC<<endl;
        AC = M[stoi(iR, 0, 2)];
        cout<<"AC: "<<AC<<endl;
        MBR = M[stoi(iR, 0, 2)];
        cout<<"MBR: "<<MBR<<endl;
    }

    // STOR M[X]
    else if (opR == "00100001")
    {
        cout<<"PC: "<<PC<<endl;
        M[stoi(iR, 0, 2)] = AC;
        cout<<"AC: "<<AC<<endl;
        MBR = M[stoi(iR, 0, 2)];
        cout<<"MBR: "<<MBR<<endl;
    }

    // ADD M[X]
    else if (opR == "00000101")
    {
        cout<<"PC: "<<PC<<endl;
        AC += M[stoi(iR, 0, 2)];
        cout<<"AC: "<<AC<<endl;
        MBR = M[stoi(iR, 0, 2)];
        cout<<"MBR: "<<MBR<<endl;
    }

}

int main()
{
    // string h is initialised to a 40 bit 0 to check for halt
    string i, h = "";
    for (int j = 0; j < 40; j++)
        h += '0';

    // variable count is used to keep track of which memory location to write to next
    int count = 420;
    cout << "enter the 40 bit instructions\n";
    // the following loop takes 40 bit instructions and stores them in memory
    // memory is an array of strings (mem[1000])
    while (1)
    {
        cin >> i;
        mem[count++] = i;

        // checking if currently inputted instruction is halt 
        // if the instruction is halt, it is stored in the memory
        // and I stop taking instruction input, to move to decode cycle

        if (i == h)
            break;
        // HALT
        // count++;
    }
    // variable ctr keeps track of what instruction to execute next
    int ctr = 420, fib = 0;

    ll nfib;
    cout << "enter n" << endl;
    cin >> nfib;
    // nfib upto 92 works because 93rd fib number onwards exceed the size of long long int in c++
    // fib(93) > 2e19
    nfib -= 1;
    string t;
    while (1)
    {
        t = mem[ctr];
        // JUMP instruction
        // I have hardcoded the JUMP instruction
        // if the current instruction is JUMP, it is executed separately
        // else the instruction is sent to the decoder

        if (t == "0000000000000000000000001101000110100100")
        {
            ctr = 420;
            if (fib == nfib)
            {
                cout << "Fib(" << nfib + 1 << ") = " << M[0] << endl;
                break;
            }
            else
            {
                fib++;
                continue;
            }
        }
        else
        {
            decoder(t);
        }
        ctr++;
    }
    return 0;
}
  
/* input to print fib(n)
n is any integer in the range [1,92]
first 6 lines of input are the 40 bit instructions
next line contains n


for eg, to print fib(7), give the following input:
-------------start of input-------------
0000000100000000000000000101000000000001
0000000000000000000000100001000000000010
0000000100000000000100100001000000000000
0000000100000000001000100001000000000001
0000000000000000000000001101000110100100
0000000000000000000000000000000000000000
7 
--------------end of input--------------
*/
