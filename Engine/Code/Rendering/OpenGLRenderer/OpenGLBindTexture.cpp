// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:22)

#include "Rendering/RenderingExport.h" 

#include "OpenGLBindTexture.h"
#include "OpenGLMapping.h"
#include "System/OpenGL/OpenGLAPI.h"

Rendering::UInt Rendering
    ::BindTexture (ShaderFlags::SamplerType target, UInt texture)
{
    Int current = 0;
	System::GetGlIntegerv(System::OpenGLQuery(g_OpenGLTextureTargetBinding[System::EnumCastUnderlying(target)]),&current);
	System::SetGlBindTexture(System::TextureTarget(g_OpenGLTextureTarget[System::EnumCastUnderlying(target)]),texture);

    return static_cast<UInt>(current);
}

Rendering::UInt Rendering
    ::GetBoundTexture (ShaderFlags::SamplerType target)
{
    Int current = 0;
	System::GetGlIntegerv(System::OpenGLQuery(g_OpenGLTextureTargetBinding[System::EnumCastUnderlying(target)]),&current);

    return static_cast<UInt>(current);
}

