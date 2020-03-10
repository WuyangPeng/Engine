// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:25)

#include "Rendering/RenderingExport.h"

#include "OpenGLRenderTarget.h"
#include "OpenGLTexture2D.h"
#include "OpenGLMapping.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::OpenGLRenderTarget
    ::OpenGLRenderTarget (Renderer* renderer,const RenderTarget* renderTarget)
	: ParentType{}, m_OpenGLRenderTargetData{ renderer, renderTarget }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLRenderTarget
    ::~OpenGLRenderTarget ()
{
    RENDERING_SELF_CLASS_IS_VALID_9;     
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLRenderTarget)

void Rendering::OpenGLRenderTarget
    ::Enable (Renderer* renderer)
{
    RENDERING_CLASS_IS_VALID_9; 

    return m_OpenGLRenderTargetData.Enable(renderer); 
}

void Rendering::OpenGLRenderTarget
    ::Disable (Renderer* renderer)
{
    RENDERING_CLASS_IS_VALID_9;  

    return m_OpenGLRenderTargetData.Disable(renderer);  
}

Rendering::ConstTexture2DSmartPointer Rendering::OpenGLRenderTarget
    ::ReadColor(int index,Renderer* renderer)
{
    RENDERING_CLASS_IS_VALID_9;  

    return m_OpenGLRenderTargetData.ReadColor(index,renderer);    
}

