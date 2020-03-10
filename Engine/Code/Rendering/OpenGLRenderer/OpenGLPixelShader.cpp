// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:23)

#include "Rendering/RenderingExport.h"

#include "OpenGLPixelShader.h"
 
using namespace Rendering;


PdrPixelShader::PdrPixelShader (Renderer*, const PixelShader* pshader)
{
	pshader;
   /* const char* programText = pshader->GetProgram(PixelShader::GetProfile())->c_str();
    int programLength = (int)strlen(programText);

    glEnable(GL_FRAGMENT_PROGRAM_ARB);
    glGenProgramsARB(1, &mShader);
    glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, mShader);
    glProgramStringARB(GL_FRAGMENT_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB,programLength, programText);
    glDisable(GL_FRAGMENT_PROGRAM_ARB);*/
}

PdrPixelShader::~PdrPixelShader ()
{
    //glDeleteProgramsARB(1, &mShader);
}

void PdrPixelShader::Enable (Renderer* renderer, const PixelShader* pshader,const ShaderParameters* parameters)
{
	renderer; pshader; parameters;
	/*
    // Enable the buffer by setting the state.
    glEnable(GL_FRAGMENT_PROGRAM_ARB);
    glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, mShader);

    // Set the shader constants.
    int profile = PixelShader::GetProfile();
    const int numConstants = pshader->GetNumConstants();
    for (int i = 0; i < numConstants; ++i)
    {
        const int numRegisters = pshader->GetNumRegistersUsed(i);
        const float* data = parameters->GetConstant(i)->GetData();
        int baseRegister = pshader->GetBaseRegister(profile, i);
        for (int j = 0; j < numRegisters; ++j)
        {
            glProgramLocalParameter4fvARB(GL_FRAGMENT_PROGRAM_ARB,(GLuint)baseRegister, data);
            baseRegister++;
            data += 4;
        }
    }

    SetSamplerState(renderer, pshader, profile, parameters,renderer->mData->mMaxPShaderImages, renderer->mData->mCurrentSS);*/
}

void PdrPixelShader::Disable (Renderer* renderer, const PixelShader* pshader,
    const ShaderParameters* parameters)
{
	renderer; pshader; parameters;
   /* glDisable(GL_FRAGMENT_PROGRAM_ARB);
    int profile = PixelShader::GetProfile();
    DisableTextures(renderer, pshader, profile, parameters,renderer->mData->mMaxPShaderImages);*/
}

