#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void sendTemperature(int value) {
    char command[200];

    sprintf(command,
        "curl.exe -X POST http://127.0.0.1:5000/temperature "
        "-H \"Content-Type: application/json\" "
        "-d \"{\\\"temp\\\": %d}\"",
        value);

    system(command);
}

int main() {
    srand(time(NULL));

     int temp = 20;

    while (1) {
        temp = temp + (rand() % 5 - 2);

        printf("Sending temperature: %d\n", temp);

        sendTemperature(temp);

        
#ifdef _WIN32
        Sleep(5000);
#else
        sleep(5);
#endif
    }

    return 0;
}