#include <stdio.h>
#include <windows.h>
#include <d3d11.h>

typedef struct DXObjects {
    ID3D11Device *device;
    ID3D11DeviceContext *context;
    IDXGISwapChain *swapChain;
} DXObjects;

DXObjects dx11init(void);

DXObjects dx11init(void) {
    DXObjects dxObjects = {NULL, NULL, NULL};       

    D3D_FEATURE_LEVEL featureLevel;
    D3D_FEATURE_LEVEL featureLevels[] = {D3D_FEATURE_LEVEL_11_0};

    HRESULT hr = D3D11CreateDevice(
        NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0,
        featureLevels, 1, D3D11_SDK_VERSION,
        &dxObjects.device, &featureLevel, &dxObjects.context
    );

    if (FAILED(hr)) {
        MessageBox(NULL, "Failed to create DirectX 11 device", "Error", MB_OK);
        return dxObjects;
    };

    MessageBox(NULL, "DirectX 11 Initialized!", "Success", MB_OK);

    return dxObjects;
}

void cleanup(DXObjects dxObjects) {
    if (dxObjects.device) dxObjects.device->lpVtbl->Release(dxObjects.device);
    if (dxObjects.context) dxObjects.context->lpVtbl->Release(dxObjects.context);
    if (dxObjects.swapChain) dxObjects.swapChain->lpVtbl->Release(dxObjects.swapChain);

}

int main() {
    DXObjects init = dx11init();
    cleanup(init);
    return 0;
}