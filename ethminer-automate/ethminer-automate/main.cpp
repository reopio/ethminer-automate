#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCKAPI_


#include <windows.h> 
#include <tchar.h>
#include <stdio.h> 
#include <strsafe.h>
#include <iostream>
#include <iomanip>
//#include <string>
#include <time.h>
//#include <signal.h>
#include <sstream>



#include "pipeex.h"
#include "ping.h"
#include "getip.h"
//#include "atlstr.h"

#define BUFSIZE 4096 

HANDLE g_hChildStd_IN_Rd = NULL;
HANDLE g_hChildStd_IN_Wr = NULL;
HANDLE g_hChildStd_OUT_Rd = NULL;
HANDLE g_hChildStd_OUT_Wr = NULL;

HANDLE g_hInputFile = NULL;

HANDLE phd;

unsigned icount = 0;
CHAR mh[8] = "Mh";
CHAR* pomh;
//DWORD ppid;


void CreateChildProcess(void);
void WriteToPipe(void);
unsigned ReadandProcessFromPipe(void);
void ErrorExit(PTSTR);
unsigned getmh(CHAR* bff, unsigned* hash);
unsigned x, y;
TCHAR cmd[256];


//CHAR chBuf[BUFSIZE];

//COMMTIMEOUTS timeouts = { 0, //interval timeout. 0 = not used
//                              0, // read multiplier
 //                             100, // read constant (milliseconds)
 //                             0, // Write multiplier
 //                             0  // Write Constant
//
//};

//SetCommTimeouts(defaultSTDIN, &timeouts);

//LPDWORD exitCode;

int main()
{
    std::stringstream ss;
    std::string combined;
    memset(cmd, sizeof(cmd), 0);
    char eaddr[64] = "0xCDDad13Dc047D4A261D2E0Af53F897BF3aA8836C", con = 'n', worker[32];


    //unsigned icount = 0;
    for (;;) {
        std::cout << "*****************************ETHMINER AUTOMATE******************************" << std::endl;
        std::cout << "||if you find this program useful, you can consider supporting me||" << std::endl;
        std::cout << "||my eth address 0xCDDad13Dc047D4A261D2E0Af53F897BF3aA8836C      ||" << std::endl;
        std::cout << "||my btc address bc1q2vp6ddu77qpapm4f9sek70cht7e34nz3dtaxlr      ||" << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "PLEASE INPUT YOUR ETH ADDRESS:(EXAMPLE:0xCDDad13Dc047D4A261D2E0Af53F897BF3aA8836C):" << std::endl;
        std::cin >> eaddr;
        std::cout << "confirm your address(y|n): " << eaddr << "?" << std::endl;
        std::cin >> con;
        if (con == 'y') {
            break;
        }

    }
    std::cout << std::endl;
    std::cout << "please enter your worker name:(anything you want, length<32)" << std::endl;
    std::cin >> worker;

    std::cout << std::endl;
    std::cout << "PLEASE ENTER THE HASHRATE RANGE: FROM X TO Y:" << std::endl;
    std::cout << "(the program will restart miner if your real hashrate is out of the range settled)" << std::endl;
    //std::cout << "||RESTARTCOUNTS:                                                      ||" << std::endl;
    std::cout << "X:                                                                 " << std::endl;
    //std::cout << "                                                                 " << std::endl;
    //std::cout << "||---------------------------------|----------------------------------||" << std::endl;
    //std::cout << "||                                 |                                  ||" << std::endl;
    //std::cout << "||MINING STSTUS:                                                      ||" << std::endl;
   // std::cout << "||                                 |                                  ||" << std::endl;
    //std::cout << "||                                 |                                  ||" << std::endl;
    //std::cout << "||---------------------------------|----------------------------------||" << std::endl;
    //std::cout << "************************************************************************" << std::endl;
    //std::cout << "\033[1A" << "\033[1A" << "\033[1A" << "\033[1A" << "\r";
    //Sleep(2000)
    std::cin >> x;
    std::cout << "Y:                                                                 " << std::endl;
    //std::cout << "                                                                 " << std::endl;
    //std::cout << "||                                 |                                  ||" << std::endl;
    std::cin >> y;
    system("cls");
    //std::cout << std::end


    //def net

    CPing p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
    char ip1[16], ip2[16], ip3[16], ip4[16], ip5[16],
        ip6[16], ip7[16], ip8[16], ip9[16], ip10[16],
        dname1[] = "eth.f2pool.com",
        dname2[] = "asia1.ethermine.org",
        dname3[] = "asia2.ethermine.org",
        dname4[] = "us1.ethermine.org",
        dname5[] = "us2.ethermine.org",
        dname6[] = "eu1.ethermine.org",
        dname7[] = "eth-asia.spiderpool.com",
        dname8[] = "eth-jp.pool.zhizhu.top",
        dname9[] = "eth-eu.pool.zhizhu.top",
        dname10[] = "eth-us.pool.zhizhu.top";
    PingReply r1, r2, r3, r4, r5, r6, r7, r8, r9, r10;
    unsigned sel = 0;


    getip(dname1, ip1);
    //std::cout << ip1 << std::endl;
    getip(dname2, ip2);
    getip(dname3, ip3);
    getip(dname4, ip4);
    getip(dname5, ip5);
    getip(dname6, ip6);
    getip(dname7, ip7);
    getip(dname8, ip8);
    getip(dname9, ip9);
    getip(dname10, ip10);


    for (;;) {
        system("cls");
        std::cout << "*****************************ETHMINER AUTOMATE******************************" << std::endl;
        std::cout << "||if you find this program useful, you can consider supporting me||" << std::endl;
        std::cout << "||my eth address 0xCDDad13Dc047D4A261D2E0Af53F897BF3aA8836C      ||" << std::endl;
        std::cout << "||my btc address bc1q2vp6ddu77qpapm4f9sek70cht7e34nz3dtaxlr      ||" << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "Please select your pool:(just enter the number)" << std::endl;// << std::endl;
        p1.Ping(ip1, &r1);
        std::cout << "[1]:  F2POOL(2% PPS+ fee)            PING: " << r1.m_dwRoundTripTime << "ms" << std::endl;
        p1.Ping(ip2, &r2);
        std::cout << "[2]:  ETHERMINE(ASIA1)(1% fee)       PING: " << r2.m_dwRoundTripTime << "ms" << std::endl;
        p1.Ping(ip3, &r3);
        std::cout << "[3]:  ETHERMINE(ASIA2)(1% fee)       PING: " << r3.m_dwRoundTripTime << "ms" << std::endl;
        p1.Ping(ip4, &r4);
        std::cout << "[4]:  ETHERMINE(US1)(1% fee)         PING: " << r4.m_dwRoundTripTime << "ms" << std::endl;
        p1.Ping(ip5, &r5);
        std::cout << "[5]:  ETHERMINE(US2)(1% fee)         PING: " << r5.m_dwRoundTripTime << "ms" << std::endl;
        p1.Ping(ip6, &r6);
        std::cout << "[6]:  ETHERMINE(EUROPE)(1% fee)      PING: " << r6.m_dwRoundTripTime << "ms" << std::endl;
        p1.Ping(ip7, &r7);
        std::cout << "[7]:  SPIDER(ASIA)(1% PPS+ fee)      PING: " << r7.m_dwRoundTripTime << "ms" << std::endl;
        p1.Ping(ip8, &r8);
        std::cout << "[8]:  SPIDER(JAPAN)(1% PPS+ fee)     PING: " << r8.m_dwRoundTripTime << "ms" << std::endl;
        p1.Ping(ip9, &r9);
        std::cout << "[9]:  SPIDER(EUROPE)(1% PPS+ fee)    PING: " << r9.m_dwRoundTripTime << "ms" << std::endl;
        p1.Ping(ip10, &r10);
        std::cout << "[10]: SPIDER(US)(1% PPS+ fee)        PING: " << r10.m_dwRoundTripTime << "ms" << std::endl;
        std::cout << "***********************************************************" << std::endl;
        std::cout << "enter 0 to refresh ping or enter number 1-10 to select pool:" << std::endl;
        std::cin >> sel;


        if (sel == 0) {
            /////////ethminer - P stratum1 + tcp://0xCDDad13Dc047D4A261D2E0Af53F897BF3aA8836C.gejifeng3@eth.f2pool.com:6688
            continue;
        }
        else {
            switch (sel) {

            case 1:
                ss << "ethminer -P stratum1+tcp://" << eaddr << "." << worker << "@" << dname1 << ":6688";
                combined = ss.str();
                for (unsigned j = 0; j < combined.length(); ++j) {
                    cmd[j] = combined[j];
                }
                break;
            case 2:
                ss << "ethminer -P stratum1+tcp://" << eaddr << "." << worker << "@" << dname2 << ":14444";
                combined = ss.str();
                for (unsigned j = 0; j < combined.length(); ++j) {
                    cmd[j] = combined[j];
                }
                break;
            case 3:
                ss << "ethminer -P stratum1+tcp://" << eaddr << "." << worker << "@" << dname3 << ":14444";
                combined = ss.str();
                for (unsigned j = 0; j < combined.length(); ++j) {
                    cmd[j] = combined[j];
                }
                break;
            case 4:
                ss << "ethminer -P stratum1+tcp://" << eaddr << "." << worker << "@" << dname4 << ":14444";
                combined = ss.str();
                for (unsigned j = 0; j < combined.length(); ++j) {
                    cmd[j] = combined[j];
                }
                break;
            case 5:
                ss << "ethminer -P stratum1+tcp://" << eaddr << "." << worker << "@" << dname5 << ":14444";
                combined = ss.str();
                for (unsigned j = 0; j < combined.length(); ++j) {
                    cmd[j] = combined[j];
                }
                break;
            case 6:
                ss << "ethminer -P stratum1+tcp://" << eaddr << "." << worker << "@" << dname6 << ":14444";
                combined = ss.str();
                for (unsigned j = 0; j < combined.length(); ++j) {
                    cmd[j] = combined[j];
                }
                break;
            case 7:
                ss << "ethminer -P stratum1+tcp://" << eaddr << "." << worker << "@" << dname7 << ":3867";
                combined = ss.str();
                for (unsigned j = 0; j < combined.length(); ++j) {
                    cmd[j] = combined[j];
                }
                break;
            case 8:
                ss << "ethminer -P stratum1+tcp://" << eaddr << "." << worker << "@" << dname8 << ":3867";
                combined = ss.str();
                for (unsigned j = 0; j < combined.length(); ++j) {
                    cmd[j] = combined[j];
                }
                break;
            case 9:
                ss << "ethminer -P stratum1+tcp://" << eaddr << "." << worker << "@" << dname9 << ":3867";
                combined = ss.str();
                for (unsigned j = 0; j < combined.length(); ++j) {
                    cmd[j] = combined[j];
                }
                break;
            case 10:
                ss << "ethminer -P stratum1+tcp://" << eaddr << "." << worker << "@" << dname10 << ":3867";
                combined = ss.str();
                for (unsigned j = 0; j < combined.length(); ++j) {
                    cmd[j] = combined[j];
                }
                break;


            default:
                std::cout << "error" << std::endl;
                exit(-9);
                break;
            }
            break;

        }


    }
    //std::wcout << cmd << std::endl;
    //system("pause");
    //turn off quick edit mode

    auto hStdin = ::GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    ::GetConsoleMode(hStdin, &mode);
    mode &= ~ENABLE_QUICK_EDIT_MODE;
    ::SetConsoleMode(hStdin, mode);


    SECURITY_ATTRIBUTES saAttr;


    // printf("\n->Start of parent execution.\n");

     // Set the bInheritHandle flag so pipe handles are inherited. 

    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;

    // Create a pipe for the child process's STDOUT. 


    // Create the child process. 

    for (;;) {
        system("cls");
        std::cout << "*********************************ETHMINER AUTOMATE**********************************" << std::endl;
        std::cout << "||if you find this program useful, you can consider supporting me||" << std::endl;
        std::cout << "||my eth address 0xCDDad13Dc047D4A261D2E0Af53F897BF3aA8836C      ||" << std::endl;
        std::cout << "||my btc address bc1q2vp6ddu77qpapm4f9sek70cht7e34nz3dtaxlr      ||" << std::endl;
        std::cout << "||--------------------------------------------------------------------------------||" << std::endl;
        std::cout << "||                                                                                ||" << std::endl;
        std::cout << "||RESTART COUNTS: " << std::setfill('0') << std::setw(7) << icount << "                                                         || " << std::endl;
        std::cout << "||                                                                                ||" << std::endl;
        //std::cout << "||                                                                                ||" << std::endl;
        std::cout << "||--------------------------------------------------------------------------------||" << std::endl;
        std::cout << "||                                                                                ||" << std::endl;
        std::cout << "||MINING STSTUS:                                                                  ||" << std::endl;
        std::cout << "||                                                                                ||" << std::endl;
        if (!icount) {
            std::cout << "||STARTING...(will take about 1 min)" << "\r";
        }
        //Sleep(2000);
        //std::cout << TerminateProcess(piProcInfo.hProcess, 0) << std::endl;
        if (!MyCreatePipeEx(&g_hChildStd_OUT_Rd, &g_hChildStd_OUT_Wr, &saAttr, 0, FILE_FLAG_OVERLAPPED, 0, 0)) {
            std::cout << std::endl << "pipe creation failed!" << std::endl;
            exit(-1);
        }
        //exit(-1);

    // Ensure the read handle to the pipe for STDOUT is not inherited.

        if (!SetHandleInformation(g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0)) {
            std::cout << std::endl << "handle info failed!" << std::endl;
            exit(-2);
        }
        //exit(-2);

    // Create a pipe for the child process's STDIN. 

    //if (!CreatePipe(&g_hChildStd_IN_Rd, &g_hChildStd_IN_Wr, &saAttr, 0))
       // exit(-3);

    // Ensure the write handle to the pipe for STDIN is not inherited. 

    //if (!SetHandleInformation(g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0))
    //    exit(-4);
    //SetCommTimeouts(g_hChildStd_OUT_Rd, &timeouts);
        CreateChildProcess();
        g_hInputFile = CreateFile(
            L"33",
            GENERIC_READ,
            0,
            NULL,
            OPEN_ALWAYS,
            FILE_ATTRIBUTE_READONLY,
            NULL);

        if (g_hInputFile == INVALID_HANDLE_VALUE) {
            std::cout << std::endl << "file ceation failed!" << std::endl;
            exit(-7);
        }
        //exit(-7);
    //std::cout << GetLastError();
    //exit(-7);

// Write to the pipe that is the standard input for a child process. 
// Data is written to the pipe's buffers, so it is not necessary to wait
// until the child process is running before writing data.

//WriteToPipe();
//printf("\n->Contents of %S written to child STDIN pipe.\n", L"3.txt");

// Read from pipe that is the standard output for child process. 

    //("\n->Contents of child process STDOUT:\n\n");
    //std::cout << "\033[1A" << "\033[1A" << "\033[1A" << "\033[1A" << "\r";
        ReadandProcessFromPipe();

        //printf("\n->End of parent execution.\n");
    }


    // Get a handle to an input file for the parent. 
    // This example assumes a plain text file and uses string output to verify data flow. 

    //if (argc == 1)
    //    exit(-5);
    //CreateFile(
    //    L"33",
    //    GENERIC_READ | GENERIC_WRITE,
     //   0,
    //    NULL,
     //   CREATE_ALWAYS,
     //   FILE_ATTRIBUTE_READONLY,
     //   NULL);



    // The remaining open handles are cleaned up when this process terminates. 
    // To avoid resource leaks in a larger application, close handles explicitly. 

    return 0;
}

void CreateChildProcess()
// Create a child process that uses the previously created pipes for STDIN and STDOUT.
{
    //TCHAR szCmdline[] = TEXT("ethminer -P stratum1+tcp://0xCDDad13Dc047D4A261D2E0Af53F897BF3aA8836C.gejifeng3@eth.f2pool.com:6688");
    PROCESS_INFORMATION piProcInfo;
    STARTUPINFO siStartInfo;
    BOOL bSuccess = FALSE;

    // Set up members of the PROCESS_INFORMATION structure. 

    ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));

    // Set up members of the STARTUPINFO structure. 
    // This structure specifies the STDIN and STDOUT handles for redirection.

    ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
    siStartInfo.cb = sizeof(STARTUPINFO);
    siStartInfo.hStdError = g_hChildStd_OUT_Wr;
    siStartInfo.hStdOutput = g_hChildStd_OUT_Wr;
    siStartInfo.hStdInput = g_hChildStd_IN_Rd;
    siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

    // Create the child process. 


    //SECURITY_ATTRIBUTES saAttr2;


    // printf("\n->Start of parent execution.\n");

     // Set the bInheritHandle flag so pipe handles are inherited. 

    //saAttr2.nLength = sizeof(SECURITY_ATTRIBUTES);
    //saAttr2.bInheritHandle = TRUE;
    //saAttr2.lpSecurityDescriptor = PROCESS_QUERY_INFORMATION;

    bSuccess = CreateProcess(NULL,
        cmd,     // command line 
        NULL,          // process security attributes 
        NULL,          // primary thread security attributes 
        TRUE,          // handles are inherited 
        0,             // creation flags 
        NULL,          // use parent's environment 
        NULL,          // use parent's current directory 
        &siStartInfo,  // STARTUPINFO pointer 
        &piProcInfo);  // receives PROCESS_INFORMATION 
    phd = piProcInfo.hProcess;
    //ppid = piProcInfo.dwProcessId;
     // If an error occurs, exit the application. 
    if (!bSuccess) {
        std::cout << "\n" << "error: no ethminer found. please check your file and file name." << std::endl;
        exit(-6);
    }
    //exit(-6);
    else
    {
        // Close handles to the child process and its primary thread.
        // Some applications might keep these handles to monitor the status
        // of the child process, for example. 


        CloseHandle(piProcInfo.hThread);

        // Close handles to the stdin and stdout pipes no longer needed by the child process.
        // If they are not explicitly closed, there is no way to recognize that the child process has ended.

        CloseHandle(g_hChildStd_OUT_Wr);
        CloseHandle(g_hChildStd_IN_Rd);
    }
}

void WriteToPipe(void)

// Read from a file and write its contents to the pipe for the child's STDIN.
// Stop when there is no more data. 
{
    DWORD dwRead, dwWritten;
    CHAR chBuf[BUFSIZE];
    BOOL bSuccess = FALSE;

    for (;;)
    {
        bSuccess = ReadFile(g_hInputFile, chBuf, BUFSIZE, &dwRead, NULL);
        if (!bSuccess || dwRead == 0) break;

        bSuccess = WriteFile(g_hChildStd_IN_Wr, chBuf, dwRead, &dwWritten, NULL);
        if (!bSuccess) break;
    }

    // Close the pipe handle so the child process stops reading. 

    if (!CloseHandle(g_hChildStd_IN_Wr))
        exit(-8);
}

unsigned ReadandProcessFromPipe()

// Read output from the child process's pipe for STDOUT
// and write to the parent process's pipe for STDOUT. 
// Stop when there is no more data. 
{
    DWORD dwRead;// , dwWritten;
    unsigned hash = 0;
    unsigned* hashrate = &hash;
    CHAR chBuf[BUFSIZE];
    BOOL bSuccess = FALSE;
    HANDLE hParentStdOut = GetStdHandle(STD_OUTPUT_HANDLE);// , phd2 = OpenProcess(PROCESS_QUERY_INFORMATION, TRUE, ppid);
    time_t clockstart = time(NULL), clockend = time(NULL), cs1 = time(NULL), ce2 = time(NULL);
    OVERLAPPED ovpp;
    memset(&ovpp, 0, sizeof(ovpp));
    //std::cout << 222222222222 << std::endl;
    for (;;)
    {
        //time(&clockstart);
        //std::cout << "***************************" << std::endl;

        //::cout << 111111 << std::endl;
        //std::cout << GetExitCodeProcess(phd2, exitCode);
        //std::cout << GetLastError() << std::endl;
        //while (GetExitCodeProcess(phd2, exitCode))
            //&& *exitCode == STILL_ACTIVE)
        //{
        //    std::cout << 111111 << std::endl;
        //std::cout << 222222222222 << std::endl;
        //SetCommTimeouts(phd2, &timeouts);
        bSuccess = ReadFile(g_hChildStd_OUT_Rd, chBuf, BUFSIZE, &dwRead, &ovpp);
        //Sleep(9000);
        if (!bSuccess) {

            if (GetLastError() == ERROR_IO_PENDING) {

                if (WaitForSingleObject(g_hChildStd_OUT_Rd, 45000) == WAIT_TIMEOUT) {
                    TerminateProcess(phd, 0);
                    CloseHandle(phd);
                    CloseHandle(g_hChildStd_OUT_Rd);
                    CloseHandle(g_hChildStd_IN_Wr);
                    CloseHandle(g_hInputFile);
                    std::cout << "||RESTARTING..." << "\r";
                    Sleep(8000);
                    system("cls");
                    //Sleep(1000);
                    ++icount;
                    return 1;
                    //break;
                }

            }
        }

        // {
         //  std::cout << 222222222 << std::endl;
         //       TerminateProcess(phd, 0);
         //              CloseHandle(phd);
        //               CloseHandle(g_hChildStd_OUT_Rd);
        //               CloseHandle(g_hChildStd_IN_Wr);
        //               CloseHandle(g_hInputFile);
        //               std::cout << "||RESTARTING..." << "\r";
        //               Sleep(1000);
        //               system("cls");
        //               ++icount;
        //               return 1;
        //    }
            //ReadFile(g_hChildStd_OUT_Rd, chBuf, BUFSIZE, &dwRead, 0);
       //     std::cout << 22222222 << std::endl;
      //      if (dwRead == 0) {
        //        
                //insert code to handle timeout here

            //WriteFile(writingEnd, chBuf, 1, &dwWritten, 0);





        //bSuccess = ReadFile(g_hChildStd_OUT_Rd, chBuf, BUFSIZE, &dwRead, NULL);
        //std::cout << 11111111111111111 << std::endl;
        //if (!bSuccess || dwRead == 0) break;
        // 
        // 
        // 
        //std::cout << 1 << std::endl;
        //bSuccess = WriteFile(hParentStdOut, chBuf,
        //    dwRead, &dwWritten, NULL);
        //if (!bSuccess) break;
        //std::cout << 2 << std::endl;
        //std::cout << std::endl << "---------------" << std::endl;
        //std::cout << chBuf << std::endl;// << "***************************" << std::endl << std::endl << std::endl;
        //Sleep(1000);
        switch (getmh(chBuf, hashrate)) {
        case 1://break;
            //chBuf

            std::cout << "\r";
            std::cout << "||" << chBuf;
            //hashrate = 100 * (*(chBuf - 7) - 48) + 10 * (*(chBuf - 6) - 48) + (*(chBuf - 5) - 48);
            //std::cout << "\n\n\n" << std::dec << *hashrate;
            if (*hashrate > x && *hashrate < y) {
                time(&cs1);
                std::cout << "\r                                                                                                       \r";
                std::cout << "||" << chBuf << "\r";
            }
            else {
                time(&ce2);
                std::cout << "           OUT OF RANGE" << "\r";
            }
            time(&clockstart); break;
            //Sleep(1000); break;
         //Sleep(1000);
            /*std::cout << "\r";
            std::cout << "||            ";
            std::cout << *(pomh - 8)
                << *(pomh - 7)
                << *(pomh - 6)
                << *(pomh - 5)
                << *(pomh - 4)
                << *(pomh - 3)
                << *(pomh - 2)
                << *(pomh - 1)
                << *pomh;
            std::cout << "            |              " << std::setw(6) << icount << "              ||"; break;*/
            /*case 2:
                std::cout << "\r";
                std::cout << "||            ";
                std::cout << " "
                    << *(pomh - 7)
                    << *(pomh - 6)
                    << *(pomh - 5)
                    << *(pomh - 4)
                    << *(pomh - 3)
                    << *(pomh - 2)
                    << *(pomh - 1)
                    << *pomh;
                std::cout << "            |              " << std::setw(6) << icount << "              ||"; break;
                */
        default:
            //std::cout << "000000000000000000000000000000000000000000000";
            time(&clockend); break;

        }
        //if (!getmh(chBuf)) {
        //    time(&clockend);
        //}
        //else {
        if (ce2 - cs1 > 70) {
            // std::cout << "sdfnvhklehfkhewkofwkolfh" << std::endl;
            TerminateProcess(phd, 0);
            CloseHandle(phd);
            CloseHandle(g_hChildStd_OUT_Rd);
            CloseHandle(g_hChildStd_IN_Wr);
            CloseHandle(g_hInputFile);
            std::cout << "||RESTARTING..." << "\r";
            Sleep(8000);
            system("cls");
            ++icount;
            //std::cout << "\r";
            //std::cout << "||   dfvgbdfvbdfsvbdsvfd        ";
            //std::cout << " RESTARTING";

            //std::cout << "            |              " << std::setw(6) << ++icount << "              ||"; break;
            //++icount;

            //std::cout << ppid << std::endl;
            //std::cout << GetLastError() << std::endl;
            return 1;
        }

        //}

        //{
        //    std::cout << "            |              " << std::setw(6) << icount << "              ||";
        //}
        //else {
        //    std::cout << "            |              " << std::setw(6) << icount << "              ||";
        //}

        //memset(chBuf, '\0', sizeof(chBuf));

        //time(&clockend);
        if (clockend - clockstart > 90) {
            //std::cout << "000000000000000000000000000000000000000000000";
            //CloseHandle(piProcInfo.hProcess);
            //CloseHandle(piProcInfo.hThread);
            //std::cout << TerminateProcess(phd, 0) << std::endl;
            //HANDLE phd = OpenProcess(PROCESS_TERMINATE, FALSE, ppid);
            TerminateProcess(phd, 0);
            CloseHandle(phd);
            CloseHandle(g_hChildStd_OUT_Rd);
            CloseHandle(g_hChildStd_IN_Wr);
            CloseHandle(g_hInputFile);
            std::cout << "||RESTARTING..." << "\r";
            Sleep(8000);
            system("cls");
            ++icount;
            //std::cout << "\r";
            //std::cout << "||   dfvgbdfvbdfsvbdsvfd        ";
            //std::cout << " RESTARTING";

            //std::cout << "            |              " << std::setw(6) << ++icount << "              ||"; break;
            //++icount;

            //std::cout << ppid << std::endl;
            //std::cout << GetLastError() << std::endl;
            return 1;
        }
    }

    return 0;
}

unsigned getmh(CHAR* bff, unsigned* hash) {

    pomh = strstr(bff, mh);
    if (pomh) {
        *(pomh + 2) = '\0';
        //system("cls");
        //std::cout << "\n\n\n" <<*(pomh - 7);
        //Sleep(2000);
        if (*(pomh - 7) == ' ') {
            *hash = 10 * (*(pomh - 6) - 48) + (*(pomh - 5) - 48);
        }
        else {
            *hash = 100 * (*(pomh - 7) - 48) + 10 * (*(pomh - 6) - 48) + (*(pomh - 5) - 48);
        }

        return 1;
    }
    else {
        //std::cout << "error";
        return 2;
    }



}
/**void ErrorExit(PTSTR lpszFunction)

// Format a readable error message, display a message box,
// and exit from the application.
{
    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError();

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0, NULL);

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
        (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
    StringCchPrintf((LPTSTR)lpDisplayBuf,
        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s failed with error %d: %s"),
        lpszFunction, dw, lpMsgBuf);
    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
    ExitProcess(1);
}*/