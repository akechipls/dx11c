#include <stdio.h>
#include <windows.h>
#include <d3d11.h>
#include "directx.h"

void logError(const char* functionName) {
    printf("error occured at %s, last error code: %lu\n", functionName, GetLastError());
}
    
HWND CreateWindowInstance(HINSTANCE hInstance, int nShowCmd) {

    // Create the window
    HWND hwnd = CreateWindowExA(0, "Button", "sample window", 
                               WS_BORDER, CW_USEDEFAULT, CW_USEDEFAULT,
                               CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL,
                               hInstance, NULL);

    if (hwnd == NULL) {
        logError(__func__);
        return NULL;  // Return NULL if window creation fails
    }

    ShowWindow(hwnd, nShowCmd);  // Show the window
    UpdateWindow(hwnd);          // Update the window

    return hwnd;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    HWND hwnd = CreateWindowInstance(hInstance, nShowCmd);
    DXObjects init = dx11init();
    cleanup(init);
    return 0;
}