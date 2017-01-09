This is code is for illustration of interprocess communication between C++ and Java.
To run create a new poject in eclipse and add runnable.jave and sk_thread,java 
After this run Client.cpp in folder contaning text.txt file


Two matrix are passses from Client(C++) to Server(Java) using thread.
Client generate multiple request using P_Thread and Server is also multi threaded so it can handle multiple thread at same time.

After reciving request a Sever thread multiply a row of first matrix with whole second matrix and returns result back to Client.