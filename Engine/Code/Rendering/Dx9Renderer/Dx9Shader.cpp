// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:42)

#include "Rendering/RenderingExport.h" 

#include "Dx9Shader.h"
#include "Dx9Mapping.h"
#include "Dx9RendererData.h"
#include "CoreTools/Contract/Noexcept.h"

using namespace Rendering;


Dx9Shader::Dx9Shader() noexcept
{
}

 

void Dx9Shader::SetSamplerState(Renderer* renderer, const ShaderBase* shader,int profile, const ShaderParameters* parameters, int maxSamplers,DWORD base, Dx9RendererData::SamplerState* currentSS)
{
    CoreTools::DisableNoexcept();
	renderer; shader; profile; parameters; maxSamplers; base; currentSS;
   /* IDirect3DDevice9* device = renderer->mData->mDevice;
    HRESULT hr;

    int numSamplers = shader->GetNumSamplers();
    if (numSamplers > maxSamplers)
    {
        numSamplers = maxSamplers;
    }

    for (int i = 0; i < numSamplers; ++i)
    {
        ShaderBase::SamplerType type = shader->GetSamplerType(i);
        DWORD textureUnit = (DWORD)shader->GetTextureUnit(profile, i);
        DWORD unit = textureUnit + base;
        const Texture* texture = parameters->GetTexture(i);
        RendererData::SamplerState& current = currentSS[textureUnit];

        switch (type)
        {
        case ShaderBase::ST_1D:
        {
            renderer->Enable((const Texture1D*)texture, unit);

            DWORD wrap0 = gDX9WrapMode[shader->GetCoordinate(i, 0)];
            if (wrap0 != current.mWrap[0])
            {
                current.mWrap[0] = wrap0;
                hr = device->SetSamplerState(unit, D3DSAMP_ADDRESSU,
                    wrap0);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set wrap0: %s\n",
                    DXGetErrorString(hr));
            }

            DWORD wrap1 = wrap0;
            if (wrap1 != current.mWrap[1])
            {
                current.mWrap[1] = wrap1;
                hr = device->SetSamplerState(unit, D3DSAMP_ADDRESSV,
                    wrap1);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set wrap1: %s\n",
                    DXGetErrorString(hr));
            }
            break;
        }
        case ShaderFlags::SamplerType::Sampler2D:
        {
            renderer->Enable((const Texture2D*)texture, unit);

            DWORD wrap0 = gDX9WrapMode[shader->GetCoordinate(i, 0)];
            if (wrap0 != current.mWrap[0])
            {
                current.mWrap[0] = wrap0;
                hr = device->SetSamplerState(unit, D3DSAMP_ADDRESSU,
                    wrap0);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set wrap0: %s\n",
                    DXGetErrorString(hr));
            }

            DWORD wrap1 = gDX9WrapMode[shader->GetCoordinate(i, 1)];
            if (wrap1 != current.mWrap[1])
            {
                current.mWrap[1] = wrap1;
                hr = device->SetSamplerState(unit, D3DSAMP_ADDRESSV,
                    wrap1);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set wrap1: %s\n",
                    DXGetErrorString(hr));
            }
            break;
        }
        case ShaderBase::ST_3D:
        {
            renderer->Enable((const Texture3D*)texture, unit);

            DWORD wrap0 = gDX9WrapMode[shader->GetCoordinate(i, 0)];
            if (wrap0 != current.mWrap[0])
            {
                current.mWrap[0] = wrap0;
                hr = device->SetSamplerState(unit, D3DSAMP_ADDRESSU,
                    wrap0);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set wrap0: %s\n",
                    DXGetErrorString(hr));
            }

            DWORD wrap1 = gDX9WrapMode[shader->GetCoordinate(i, 1)];
            if (wrap1 != current.mWrap[1])
            {
                current.mWrap[1] = wrap1;
                hr = device->SetSamplerState(unit, D3DSAMP_ADDRESSV,
                    wrap1);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set wrap1: %s\n",
                    DXGetErrorString(hr));
            }

            DWORD wrap2 = gDX9WrapMode[shader->GetCoordinate(i, 2)];
            if (wrap2 != current.mWrap[2])
            {
                current.mWrap[2] = wrap2;
                hr = device->SetSamplerState(unit, D3DSAMP_ADDRESSW,
                    wrap2);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set wrap2: %s\n",
                    DXGetErrorString(hr));
            }
            break;
        }
        case ShaderBase::ST_CUBE:
        {
            renderer->Enable((const TextureCube*)texture, unit);

            DWORD wrap0 = gDX9WrapMode[shader->GetCoordinate(i, 0)];
            if (wrap0 != current.mWrap[0])
            {
                current.mWrap[0] = wrap0;
                hr = device->SetSamplerState(unit, D3DSAMP_ADDRESSU,
                    wrap0);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set wrap0: %s\n",
                    DXGetErrorString(hr));
            }

            DWORD wrap1 = gDX9WrapMode[shader->GetCoordinate(i, 1)];
            if (wrap1 != current.mWrap[1])
            {
                current.mWrap[1] = wrap1;
                hr = device->SetSamplerState(unit, D3DSAMP_ADDRESSV,
                    wrap1);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set wrap1: %s\n",
                    DXGetErrorString(hr));
            }
            break;
        }
        default:
            RENDERING_ASSERTION_0(false, "Invalid sampler type\n");
            break;
        }

        // Set the anisotropic filtering value.
        const float maxAnisotropy = (float)ShaderBase::MAX_ANISOTROPY;
        float anisotropy = shader->GetAnisotropy(i);
        if (anisotropy < 1.0f || anisotropy > maxAnisotropy)
        {
            anisotropy = 1.0f;
        }
        if (anisotropy != current.mAnisotropy)
        {
            current.mAnisotropy = anisotropy;
            hr = device->SetSamplerState(unit, D3DSAMP_MAXANISOTROPY,
                (DWORD)anisotropy);
            RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set anisotropy: %s\n",
                DXGetErrorString(hr));
        }

        // Set the LOD bias.
        float lodBias = shader->GetLodBias(i);
        if (lodBias != current.mLodBias)
        {
            current.mLodBias = lodBias;
            hr = device->SetSamplerState(unit,
                D3DSAMP_MIPMAPLODBIAS, *(DWORD*)&lodBias);
            RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set LOD bias: %s\n",
                DXGetErrorString(hr));
        }

        // Set the magfilter mode.
        ShaderBase::SamplerFilter filter = shader->GetFilter(i);
        if (filter == ShaderBase::SF_NEAREST)
        {
            if (D3DTEXF_POINT != current.mMagFilter)
            {
                current.mMagFilter = D3DTEXF_POINT;
                hr = device->SetSamplerState(unit,
                    D3DSAMP_MAGFILTER, D3DTEXF_POINT);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set magfilter: %s\n",
                    DXGetErrorString(hr));
            }
        }
        else
        {
            if (D3DTEXF_LINEAR != current.mMagFilter)
            {
                current.mMagFilter = D3DTEXF_LINEAR;
                hr = device->SetSamplerState(unit,
                    D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set magfilter: %s\n",
                    DXGetErrorString(hr));
            }
        }

        // Set the mipmap mode.
        if (1.0f < anisotropy && anisotropy <= maxAnisotropy)
        {
            if (D3DTEXF_ANISOTROPIC != current.mMinFilter)
            {
                current.mMinFilter = D3DTEXF_ANISOTROPIC;
                hr = device->SetSamplerState(unit, D3DSAMP_MINFILTER,
                    D3DTEXF_ANISOTROPIC);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set minfilter: %s\n",
                    DXGetErrorString(hr));
            }

            DWORD mipFilter = gDX9MipFilter[filter];
            if (mipFilter != current.mMipFilter)
            {
                current.mMipFilter = mipFilter;
                hr = device->SetSamplerState(unit, D3DSAMP_MIPFILTER,
                    mipFilter);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set mipfilter: %s\n",
                    DXGetErrorString(hr));
            }
        }
        else
        {
            DWORD minFilter = gDX9MinFilter[filter];
            if (minFilter != current.mMinFilter)
            {
                current.mMinFilter = minFilter;
                hr = device->SetSamplerState(unit, D3DSAMP_MINFILTER,
                    minFilter);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set minfilter: %s\n",
                    DXGetErrorString(hr));
            }

            DWORD mipFilter = gDX9MipFilter[filter];
            if (mipFilter != current.mMipFilter)
            {
                current.mMipFilter = mipFilter;
                hr = device->SetSamplerState(unit, D3DSAMP_MIPFILTER,
                    mipFilter);
                RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set mipfilter: %s\n",
                    DXGetErrorString(hr));
            }
        }

        // Set the border color (for clamp to border).
        Float4 color = shader->GetBorderColor(i);
        D3DCOLOR borderColor = D3DCOLOR_COLORVALUE(color[0], color[1],
            color[2], color[3]);
        if (borderColor != current.mBorderColor)
        {
            current.mBorderColor = borderColor;
            hr = device->SetSamplerState(unit, D3DSAMP_BORDERCOLOR,
                borderColor);
            RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to set border color: %s\n",
                DXGetErrorString(hr));
        }
    }*/
}

void Dx9Shader::DisableTextures(Renderer* renderer, const ShaderBase* shader,int profile, const ShaderParameters* parameters, int maxSamplers,DWORD base)
{
    CoreTools::DisableNoexcept();
	renderer; shader; profile; parameters; maxSamplers; base;
	/*
    int numSamplers = shader->GetNumSamplers();
    if (numSamplers > maxSamplers)
    {
        numSamplers = maxSamplers;
    }

    for (int i = 0; i < numSamplers; ++i)
    {
        ShaderBase::SamplerType type = shader->GetSamplerType(i);
        int unit = shader->GetTextureUnit(profile, i) + base;
        const Texture* texture = parameters->GetTexture(i);

        switch (type)
        {
        case ShaderBase::ST_1D:
        {
            renderer->Disable((const Texture1D*)texture, unit);
            break;
        }
        case ShaderFlags::SamplerType::Sampler2D:
        {
            renderer->Disable((const Texture2D*)texture, unit);
            break;
        }
        case ShaderBase::ST_CUBE:
        {
            renderer->Disable((const TextureCube*)texture, unit);
            break;
        }
        case ShaderBase::ST_3D:
        {
            renderer->Disable((const Texture3D*)texture, unit);
            break;
        }
        default:
            RENDERING_ASSERTION_0(false, "Invalid sampler type\n");
            break;
        }
    }*/
}

