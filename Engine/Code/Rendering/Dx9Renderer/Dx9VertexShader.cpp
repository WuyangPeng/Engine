// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:44)

#include "Rendering/RenderingExport.h" 
#include "Dx9VertexShader.h"
#include "CoreTools/ClassInvariant/Noexcept.h"

using namespace Rendering; 

Dx9VertexShader::Dx9VertexShader(Renderer* renderer,const VertexShader* vshader)
{
	renderer; vshader;
   /* IDirect3DDevice9* device = renderer->mData->mDevice;

    // Compile the shader to assembly code.
    const char* programText =
        vshader->GetProgram(VertexShader::GetProfile())->c_str();
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
        RENDERING_ASSERTION_0(false, "Failed to assemble vertex shader.\n");
    }
#endif
    WM5_UNUSED(hr);
    RENDERING_ASSERTION_0(hr == D3D_OK && compiledShader,
        "Failed to assemble vertex shader: %s\n", DXGetErrorString(hr));

    // Create the vertex shader.
    hr = device->CreateVertexShader(
        (DWORD*)(compiledShader->GetBufferPointer()), &mShader);
    RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to create vertex shader\n");

    // Release buffers, if necessary.
    if (compiledShader)
    {
        compiledShader->Release();
    }
    if (errors)
    {
        errors->Release();
    }*/
        CoreTools::DoNothing();
}

Dx9VertexShader::~Dx9VertexShader()
{
    mShader->Release();
}

void Dx9VertexShader::Enable(Renderer* renderer,const VertexShader* vshader, const ShaderParameters* parameters)
{
	renderer; vshader; parameters;
    /*IDirect3DDevice9* device = renderer->mData->mDevice;

    // Enable the buffer by setting the state.
    HRESULT hr = device->SetVertexShader(mShader);
    RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to enable vertex shader: %s\n",
        DXGetErrorString(hr));

    // Set the shader constants.
    int profile = VertexShader::GetProfile();
    const int numConstants = vshader->GetNumConstants();
    int i;
    for (i = 0; i < numConstants; ++i)
    {
        hr = device->SetVertexShaderConstantF(
            vshader->GetBaseRegister(profile, i),
            parameters->GetConstant(i)->GetData(),
            vshader->GetNumRegistersUsed(i));
        RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set shader constant: %s\n",
            DXGetErrorString(hr));
    }

    SetSamplerState(renderer, vshader, profile, parameters,
        renderer->mData->mMaxVShaderImages, D3DVERTEXTEXTURESAMPLER0,
        renderer->mData->mCurrentVSState);*/
        CoreTools::DoNothing();
}

void Dx9VertexShader::Disable(Renderer* renderer,const VertexShader* vshader, const ShaderParameters* parameters)
{
    CoreTools::DoNothing();
	renderer; vshader; parameters;
   /* IDirect3DDevice9* device = renderer->mData->mDevice;
    HRESULT hr;
    WM5_UNUSED(hr);

#ifdef WM5_PDR_DEBUG
    // Verify that the active shader is the one making the disable request.
    IDirect3DVertexShader9* activeVShader = 0;
    hr = device->GetVertexShader(&activeVShader);
    RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to get vertex shader: %s\n",
        DXGetErrorString(hr));
    RENDERING_ASSERTION_0(activeVShader == mShader, "Mismatched vertex shaders\n");
    activeVShader->Release();
#endif

    int profile = VertexShader::GetProfile();
    DisableTextures(renderer, vshader, profile, parameters,
        renderer->mData->mMaxVShaderImages, D3DVERTEXTEXTURESAMPLER0);

    // Disable the shader by clearing the state.
    hr = device->SetVertexShader(0);
    RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set vertex shader: %s\n",
        DXGetErrorString(hr));*/
}

