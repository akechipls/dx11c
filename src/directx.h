#ifndef DIRECTX_INIT
#define DIRECTX_INIT

#include <d3d11.h>

typedef struct DXObjects {
    ID3D11Device *device;
    ID3D11DeviceContext *context;
    IDXGISwapChain *swapChain;
} DXObjects;

DXObjects dx11init(void);
void cleanup(DXObjects dxObjects);

#endif