
#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_NONSTDC_NO_DEPRECATE 1

#define ESC 27

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

// #include <stdlib.h>
// dont need ctype

#define STUDY 29 // 29 min
#define mdata0 "--text ~study for 29:00~"
#define REST 5 // 5 min
#define mdata1 "--text ~rest for 5:00~"

char* doublequote(char* x, char *y)
{
    int leng = strlen(x);
    for (int i = 0; i < leng; i++)
    {
        char cIn = x[i];
        if (cIn == '~')
        {
            cIn = '"';
        }
        y[i] = cIn; 
        
    }
    return 0;
}

DWORD WINAPI *ThreadFunc( int lmfao)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    //lmfao = "-h";//"https://www.youtube.com/watch?v=xgNeFTCzpgo";
    const char *mode[2];
    mode[0] = mdata0;
    mode[1] = mdata1;
    //--image ~if_terminal_298878.png~
    char kick[200] = "w.exe --appname ~pomodoro~ --aumi ~robot5.ca~ --expirems 10000 --attribute ~_~ ";

    strncat(kick, mode[lmfao], strlen(mode[lmfao]));
    char rewram[strlen(kick)];

    doublequote(kick, rewram);
    printf("%iLOADING%s\n", strlen(kick), rewram);
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    // if( argc != 2 )
    // {
    //     printf("Usage: %s [cmdline]\n", argv[0]);
    //     return;
    // }

    // Start the child process. 
    if( !CreateProcess( NULL,   // No module name (use command line)
        rewram,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi )           // Pointer to PROCESS_INFORMATION structure
    ) 
    {
        system("w.exe --appname asdasd");
        printf( "CreateProcess failed (%d).\n", GetLastError() );
        return;
    }

    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}

int main(void)
{
    int core = 1;
    int mode = 0;
    int min = STUDY;
    int sec = 0;

    const char * action[2];
    action[0] = "study!";
    action[1] = "take a rest";
    while (core == 1)
    {
        printf("%s %i:%i\n",action[mode] , min, sec);
        Sleep(1003);
        sec = sec - 1;
        if (sec <= 0)
        {
            sec = 60;
            min = min - 1;
            if (min <= 0)
            {
                printf("got a break!");
                if (mode == 1)
                {
                    mode = 0;
                    min = STUDY;
                } else {
                    mode = 1;
                    min = REST;
                }
                HANDLE thread = CreateThread(NULL, 0, ThreadFunc, mode, 0, NULL);
                
            }
        }
    }

    return 0;
}
