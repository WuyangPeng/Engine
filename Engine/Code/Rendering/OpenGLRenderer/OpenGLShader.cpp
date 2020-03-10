// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:28)

#include "Rendering/RenderingExport.h"

#include "OpenGLShader.h"
#include "OpenGLMapping.h"

using namespace Rendering;


OpenGLShader::OpenGLShader()
{
}

OpenGLShader::~OpenGLShader()
{
}

void OpenGLShader::SetSamplerState(Renderer* renderer, const ShaderBase* shader,int profile, const ShaderParameters* parameters, int maxSamplers,RendererData::SamplerState* currentSS)
{
	renderer; profile; parameters; maxSamplers; currentSS;
    int numSamplers = shader->GetNumSamplers();
    if (numSamplers > maxSamplers)
    {
        numSamplers = maxSamplers;
    }
	/*
    for (int i = 0; i < numSamplers; ++i)
    {
        ShaderBase::SamplerType type = shader->GetSamplerType(i);
        GLenum target = gOGLTextureTarget[type];
        int textureUnit = shader->GetTextureUnit(profile, i);
        const Texture* texture = parameters->GetTexture(i);
        RendererData::SamplerState& current = currentSS[textureUnit];

        switch (type)
        {
        case ShaderBase::ST_1D:
        {
            renderer->Enable((const Texture1D*)texture, textureUnit);
            current.GetCurrent(target);

            GLint wrap0 = gOGLWrapMode[shader->GetCoordinate(i, 0)];
            if (wrap0 != current.mWrap[0])
            {
                current.mWrap[0] = wrap0;
                glTexParameteri(target, GL_TEXTURE_WRAP_S, wrap0);
            }
            break;
        }
        case ShaderFlags::SamplerType::Sampler2D:
        {
            renderer->Enable((const Texture2D*)texture, textureUnit);
            current.GetCurrent(target);

            GLint wrap0 = gOGLWrapMode[shader->GetCoordinate(i, 0)];
            if (wrap0 != current.mWrap[0])
            {
                current.mWrap[0] = wrap0;
                glTexParameteri(target, GL_TEXTURE_WRAP_S, wrap0);
            }

            GLint wrap1 = gOGLWrapMode[shader->GetCoordinate(i, 1)];
            if (wrap1 != current.mWrap[1])
            {
                current.mWrap[1] = wrap1;
                glTexParameteri(target, GL_TEXTURE_WRAP_T, wrap1);
            }
            break;
        }
        case ShaderBase::ST_3D:
        {
            renderer->Enable((const Texture3D*)texture, textureUnit);
            current.GetCurrent(target);

            GLint wrap0 = gOGLWrapMode[shader->GetCoordinate(i, 0)];
            if (wrap0 != current.mWrap[0])
            {
                current.mWrap[0] = wrap0;
                glTexParameteri(target, GL_TEXTURE_WRAP_S, wrap0);
            }

            GLint wrap1 = gOGLWrapMode[shader->GetCoordinate(i, 1)];
            if (wrap1 != current.mWrap[1])
            {
                current.mWrap[1] = wrap1;
                glTexParameteri(target, GL_TEXTURE_WRAP_T, wrap1);
            }

            GLint wrap2 = gOGLWrapMode[shader->GetCoordinate(i, 2)];
            if (wrap2 != current.mWrap[2])
            {
                current.mWrap[2] = wrap2;
                glTexParameteri(target, GL_TEXTURE_WRAP_R, wrap2);
            }
            break;
        }
        case ShaderBase::ST_CUBE:
        {
            renderer->Enable((const TextureCube*)texture, textureUnit);
            current.GetCurrent(target);

            GLint wrap0 = gOGLWrapMode[shader->GetCoordinate(i, 0)];
            if (wrap0 != current.mWrap[0])
            {
                current.mWrap[0] = wrap0;
                glTexParameteri(target, GL_TEXTURE_WRAP_S, wrap0);
            }

            GLint wrap1 = gOGLWrapMode[shader->GetCoordinate(i, 1)];
            if (wrap1 != current.mWrap[1])
            {
                current.mWrap[1] = wrap1;
                glTexParameteri(target, GL_TEXTURE_WRAP_T, wrap1);
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
            glTexParameterf(target, GL_TEXTURE_MAX_ANISOTROPY_EXT,
                anisotropy);
        }

        // Set the LOD bias.
        float lodBias = shader->GetLodBias(i);
        if (lodBias != current.mLodBias)
        {
            current.mLodBias = lodBias;
            glTexEnvf(GL_TEXTURE_FILTER_CONTROL, GL_TEXTURE_LOD_BIAS,
                lodBias);
        }

        // Set the magfilter mode.
        ShaderBase::SamplerFilter filter = shader->GetFilter(i);
        if (filter == ShaderBase::SF_NEAREST)
        {
            if (GL_NEAREST != current.mMagFilter)
            {
                current.mMagFilter = GL_NEAREST;
                glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            }
        }
        else
        {
            if (GL_LINEAR != current.mMagFilter)
            {
                current.mMagFilter = GL_LINEAR;
                glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            }
        }

        // Set the minfilter mode.
        GLint minFilter = gOGLMinFilter[filter];
        if (minFilter != current.mMinFilter)
        {
            current.mMinFilter = minFilter;
            glTexParameteri(target, GL_TEXTURE_MIN_FILTER, minFilter);
        }

        // Set the border color (for clamp to border).
        Float4 color = shader->GetBorderColor(i);
        if (color != current.mBorderColor)
        {
            current.mBorderColor = color;
            glTexParameterfv(target, GL_TEXTURE_BORDER_COLOR, &color[0]);
        }
    }
	*/
}

void OpenGLShader::DisableTextures(Renderer* renderer, const ShaderBase* shader,int profile, const ShaderParameters* parameters, int maxSamplers)
{
	renderer; profile; parameters;
    int numSamplers = shader->GetNumSamplers();
    if (numSamplers > maxSamplers)
    {
        numSamplers = maxSamplers;
    }

	/*
    for (int i = 0; i < numSamplers; ++i)
    {
        ShaderBase::SamplerType type = shader->GetSamplerType(i);
        int textureUnit = shader->GetTextureUnit(profile, i);
        const Texture* texture = parameters->GetTexture(i);

        switch (type)
        {
        case ShaderBase::ST_1D:
        {
            renderer->Disable((const Texture1D*)texture, textureUnit);
            break;
        }
        case ShaderFlags::SamplerType::Sampler2D:
        {
            renderer->Disable((const Texture2D*)texture, textureUnit);
            break;
        }
        case ShaderBase::ST_CUBE:
        {
            renderer->Disable((const TextureCube*)texture, textureUnit);
            break;
        }
        case ShaderBase::ST_3D:
        {
            renderer->Disable((const Texture3D*)texture, textureUnit);
            break;
        }
        default:
            RENDERING_ASSERTION_0(false, "Invalid sampler type\n");
            break;
        }
    }
	*/
}

