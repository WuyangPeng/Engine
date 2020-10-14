// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:41)

#include "Rendering/RenderingExport.h" 
#include "Dx9PixelShader.h"
#include "CoreTools/Contract/Noexcept.h"
using namespace Rendering;


Dx9PixelShader::Dx9PixelShader(Renderer* renderer,const PixelShader* pshader)
{
    CoreTools::DisableNoexcept();
	renderer; pshader;
/*    IDirect3DDevice9* device = renderer->mData->mDevice;

    // Compile the shader to assembly code.
    const char* programText =
        pshader->GetProgram(PixelShader::GetProfile())->c_str();
    int programLength = (int)strlen(programText);
    LPD3DXBUFFER compiledShader = 0;
    LPD3DXBUFFER errors = 0;
    HRESULT hr = D3DXAssembleShader(programText, programLength, 0, 0, 0,
        &compiledShader, &errors);
#ifdef _DEBUG
    if (errors)
    {
        DWORD size = errors->GetBufferSize();
        WM5_UNUSED(size);
        char* data = (char*)errors->GetBufferPointer();
        WM5_UNUSED(data);
        RENDERING_ASSERTION_0(false, "Failed to assemble pixel shader.\n");
    }
#endif
    WM5_UNUSED(hr);
    RENDERING_ASSERTION_0(hr == D3D_OK && compiledShader,
        "Failed to assemble pixel shader: %s\n", DXGetErrorString(hr));

    // Create the pixel shader.
    hr = device->CreatePixelShader( 
        (DWORD*)(compiledShader->GetBufferPointer()), &mShader);
    RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to create pixel shader\n");

    // Release buffers, if necessary.
    if (compiledShader)
    {
        compiledShader->Release();
    }
    if (errors)
    {
        errors->Release();
    }*/
}

Dx9PixelShader::~Dx9PixelShader()
{
    mShader->Release();
}

void Dx9PixelShader::Enable(Renderer* renderer, const PixelShader* pshader,const ShaderParameters* parameters)
{
	renderer; pshader; parameters;
    /*IDirect3DDevice9* device = renderer->mData->mDevice;

    // Enable the buffer by setting the state.
    HRESULT hr = device->SetPixelShader(mShader);
    RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to enable pixel shader: %s\n",
        DXGetErrorString(hr));

    // Set the shader constants.
    int profile = PixelShader::GetProfile();
    const int numConstants = pshader->GetNumConstants();
    int i;
    for (i = 0; i < numConstants; ++i)
    {
        hr = device->SetPixelShaderConstantF(
            pshader->GetBaseRegister(profile, i),
            parameters->GetConstant(i)->GetData(),
            pshader->GetNumRegistersUsed(i));
        RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set shader constant: %s\n",
            DXGetErrorString(hr));
    }

    SetSamplerState(renderer, pshader, profile, parameters,
        renderer->mData->mMaxPShaderImages, 0,
        renderer->mData->mCurrentPSState);*/
		
		CoreTools::DisableNoexcept();
}

void Dx9PixelShader::Disable(Renderer* renderer, const PixelShader* pshader,const ShaderParameters* parameters)
{
	renderer; pshader; parameters;
	
	CoreTools::DisableNoexcept();
   /* IDirect3DDevice9* device = renderer->mData->mDevice;
    HRESULT hr;
    WM5_UNUSED(hr);

#ifdef WM5_PDR_DEBUG
    // Verify that the active shader is the one making the disable request.
    IDirect3DPixelShader9* activePShader = 0;
    hr = device->GetPixelShader(&activePShader);
    RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to get pixel shader: %s\n",
        DXGetErrorString(hr));
    RENDERING_ASSERTION_0(activePShader == mShader, "Mismatched pixel shaders\n");
    activePShader->Release();
#endif

    int profile = PixelShader::GetProfile();
    DisableTextures(renderer, pshader, profile, parameters,
        renderer->mData->mMaxPShaderImages, 0);

    // Disable the shader by clearing the state.
    hr = device->SetPixelShader(0);
    RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set pixel shader: %s\n",
        DXGetErrorString(hr));*/
}

