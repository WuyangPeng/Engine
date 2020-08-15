// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:23)

#include "Rendering/RenderingExport.h"

#include "OpenGLIndexBuffer.h"
#include "OpenGLMapping.h"
#include "System/Helper/UnusedMacro.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Renderers/BufferLockManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
Rendering::OpenGLIndexBuffer
    ::OpenGLIndexBuffer (Renderer* renderer,const IndexBuffer* indexBuffer)
	:ParentType{}, m_Buffer{ 0 }
{
    Init(indexBuffer);
    
    SYSTEM_UNUSED_ARG(renderer);
    
	RENDERING_SELF_CLASS_IS_VALID_1;
}

// private
void Rendering::OpenGLIndexBuffer
    ::Init(const IndexBuffer* indexBuffer)
{
    m_Buffer = System::GlElementBufferData(indexBuffer->GetNumBytes(),g_OpenGLBufferUsage[System::EnumCastUnderlying(indexBuffer->GetUsage())]);
    
	BufferLockManager<ClassType> manager{ *this };
	void* data = manager.Lock(BufferLocking::WriteOnly);

    memcpy(data, indexBuffer->GetReadOnlyData(), indexBuffer->GetNumBytes());   
}

Rendering::OpenGLIndexBuffer
    ::~OpenGLIndexBuffer ()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
    
    m_Buffer = System::GlDeleteElementBuffers(m_Buffer);
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::OpenGLIndexBuffer
    ::IsValid() const noexcept
{
	if(ParentType::IsValid() && 0 <= m_Buffer)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::OpenGLIndexBuffer
    ::Enable (Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
    System::GlBindElementBuffer(m_Buffer);
    
    SYSTEM_UNUSED_ARG(renderer);
}

void Rendering::OpenGLIndexBuffer
    ::Disable (Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
    System::GlBindElementBuffer(0);
    
    SYSTEM_UNUSED_ARG(renderer);
}

void* Rendering::OpenGLIndexBuffer
    ::Lock (BufferLocking mode) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
    auto videoMemory = System::GlMapElementBuffer(m_Buffer,g_OpenGLBufferLocking[System::EnumCastUnderlying(mode)]);
    
    return videoMemory;
}

void Rendering::OpenGLIndexBuffer
    ::Unlock () noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
    System::GlUnmapElementBuffer(m_Buffer);
}



#include STSTEM_WARNING_POP