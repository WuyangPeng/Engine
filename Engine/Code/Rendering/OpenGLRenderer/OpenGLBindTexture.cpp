// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:22)

#include "Rendering/RenderingExport.h" 

#include "OpenGLBindTexture.h"
#include "OpenGLMapping.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26472)
Rendering::UInt Rendering
    ::BindTexture (ShaderFlags::SamplerType target, UInt texture) noexcept
{
    Int current = 0;
	System::GetGlIntegerv(System::OpenGLQuery(g_OpenGLTextureTargetBinding[System::EnumCastUnderlying(target)]),&current);
	System::SetGlBindTexture(System::TextureTarget(g_OpenGLTextureTarget[System::EnumCastUnderlying(target)]),texture);

    return static_cast<UInt>(current);
}

Rendering::UInt Rendering
    ::GetBoundTexture (ShaderFlags::SamplerType target) noexcept
{
    Int current = 0;
	System::GetGlIntegerv(System::OpenGLQuery(g_OpenGLTextureTargetBinding[System::EnumCastUnderlying(target)]),&current);

    return static_cast<UInt>(current);
}

#include STSTEM_WARNING_POP