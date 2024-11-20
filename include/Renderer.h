#pragma once
#include <d3d12.h>
#include <wrl.h>
#include <DirectXMath.h>
#include <stdexcept>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <dxgi1_5.h>
#include <wrl.h>
#include <wrl/client.h>
#include <stdexcept>
#include <iostream>
#include <DirectXMath.h>
#include <d3dcompiler.h>

class Renderer {
public:
    void Initialize(HWND hwnd);
    void Render();

    // 使这些函数可以在外部调用
    void LoadShaders();
    void CreateDescriptorHeaps();
    void CreateRootSignature();
    void CreatePipelineState();
    void CreateVertexBuffer();
    void CreateCommandList();
    void ExecuteCommandList();
    void WaitForGpu();
    void CreateFence();

private:
    UINT m_width = 800;  // 窗口宽度
    UINT m_height = 600; // 窗口高度
    UINT m_swapChainBufferCount = 2; // 默认使用双缓冲

    void CreateDevice();
    void CreateCommandQueue();
    void CreateSwapChain(HWND hwnd);

    void ReleaseResources(); // Clean up resources when no longer needed

    HRESULT hr;

    Microsoft::WRL::ComPtr<ID3D12Device> m_device;
    Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_commandQueue;
    Microsoft::WRL::ComPtr<IDXGISwapChain4> m_swapChain;
    Microsoft::WRL::ComPtr<ID3D12PipelineState> m_pipelineState;
    Microsoft::WRL::ComPtr<ID3D12RootSignature> m_rootSignature;
    Microsoft::WRL::ComPtr<ID3D12Resource> m_vertexBuffer;
    Microsoft::WRL::ComPtr<ID3D12CommandAllocator> m_commandAllocator;
    Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> m_commandList;
    Microsoft::WRL::ComPtr<ID3DBlob> m_vertexShader;
    Microsoft::WRL::ComPtr<ID3DBlob> m_pixelShader;
    Microsoft::WRL::ComPtr<ID3D12Fence> m_fence;
    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_dsvHeap;
    uint64_t m_fenceValue = 1;

    static const UINT FRAME_COUNT = 2; // 假设交换链有两个后台缓冲区
    Microsoft::WRL::ComPtr<ID3D12Resource> m_renderTargets[FRAME_COUNT]; // 后台缓冲区数组
    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_rtvHeap; // RTV 堆
    UINT m_rtvDescriptorSize = 0; // RTV 描述符大小
};

