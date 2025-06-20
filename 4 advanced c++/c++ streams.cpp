// C++ streams are the foundation of input and output (I/O) operations in the language. 
// They are a part of the iostream library and are implemented using classes and objects.

// Data flows into a program from an input stream and out of a program to an output stream.



// | Stream | Direction | Description                    |
// | ------ | --------- | ------------------------------ |
// | `cin`  | Input     | Standard input (keyboard)      |
// | `cout` | Output    | Standard output (console)      |
// | `cerr` | Output    | Standard error (unbuffered)    |
// | `clog` | Output    | Standard log/errors (buffered) |

// CERR GIVES IMEDIATE OUTPUT 
// CLOG OUTPUT MAY DELAY


//These are instances of C++ stream classes like istream and ostream.


        //         ios_base
        //            |
        //          ios
        //         /    \
        //   istream   ostream
        //         \     /
        //        iostream


// ios_base: Base class, contains formatting flags, state info, etc.

// ios: Adds error checking, tie to stream buffers

// istream / ostream: Input / Output streams

// iostream: Both input and output (e.g., cin, cout)



// #include<fstream>

// ifstream fin;   // input file stream
// ofstream fout;  // output file stream
// fstream  file;   // input + output


// These classes inherit from istream, ostream, or both.




// ofstream fout("data.txt");
// fout << "Writing to file";
// fout.close();

// ifstream fin("data.txt");
// string line;
// getline(fin, line);
// cout << line;
// fin.close();






// int x;
// cin>>x   ;   here input="ABC" we added 

// here cin.fail() become true 
// stream enter fail state 
// need to use .clear() or .ignore() to reset 



// cout buffer cerr not 
// use flush or endl to flush buffer manually 

// endl vs flush  
// endl flush + new line 
// flush just flush 


// tie()

// Used to tie two streams together. For example:
// cin.tie(&cout); // flushes cout before every cin
// This ensures prompt is visible before waiting for input.



// fstream f("data.txt", ios::in | ios::out | ios::app);


// | Flag          | Meaning           |
// | ------------- | ----------------- |
// | `ios::in`     | Read mode         |
// | `ios::out`    | Write mode        |
// | `ios::app`    | Append            |
// | `ios::trunc`  | Truncate existing |
// | `ios::binary` | Binary mode       |
