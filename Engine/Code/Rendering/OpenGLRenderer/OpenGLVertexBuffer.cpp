// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:32)

#include "Rendering/RenderingExport.h"

#include "OpenGLVertexBuffer.h"
#include "OpenGLMapping.h"
#include "System/Helper/UnusedMacro.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Renderers/BufferLockManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::OpenGLVertexBuffer
    ::OpenGLVertexBuffer (Renderer* renderer,const VertexBuffer* vertexBuffer)
	:ParentType{}, m_Buffer{ 0 }
{
    Init(vertexBuffer);
    
    SYSTEM_UNUSED_ARG(renderer);
    
	RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::OpenGLVertexBuffer
    ::Init(const VertexBuffer* vertexBuffer)
{
    m_Buffer = System::GlBufferData(vertexBuffer->GetNumBytes(),g_OpenGLBufferUsage[System::EnumCastUnderlying(vertexBuffer->GetUsage())]);

	BufferLockManager<ClassType> manager(*this);
	void* data = manager.Lock(BufferLocking::WriteOnly);

	memcpy(data, vertexBuffer->GetReadOnlyData(), vertexBuffer->GetNumBytes());   
}

Rendering::OpenGLVertexBuffer
    ::~OpenGLVertexBuffer ()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
    
    m_Buffer = System::GlDeleteBuffers(m_Buffer);
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::OpenGLVertexBuffer
    ::IsValid() const noexcept
{
	if(ParentType::IsValid() && 0 <= m_Buffer)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::OpenGLVertexBuffer
    ::Enable (Renderer* renderer, unsigned int vertexSize,unsigned int streamIndex, unsigned int offset)
{
    RENDERING_CLASS_IS_VALID_1;
    
    System::GlBindBuffer(m_Buffer);
    
    SYSTEM_UNUSED_ARG(renderer);
    SYSTEM_UNUSED_ARG(vertexSize);
    SYSTEM_UNUSED_ARG(streamIndex);
    SYSTEM_UNUSED_ARG(offset);
}

void Rendering::OpenGLVertexBuffer
    ::Disable (Renderer* renderer, unsigned int streamIndex)
{
    RENDERING_CLASS_IS_VALID_1;
    
    System::GlBindBuffer(0);
    
    SYSTEM_UNUSED_ARG(renderer);
    SYSTEM_UNUSED_ARG(streamIndex);
}

void* Rendering::OpenGLVertexBuffer
    ::Lock (BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;

    GLvoid* videoMemory = System::GetGlMapBuffer(m_Buffer,g_OpenGLBufferLocking[System::EnumCastUnderlying(mode)]);

    return videoMemory;
}

void Rendering::OpenGLVertexBuffer
    ::Unlock ()
{
    RENDERING_CLASS_IS_VALID_1;
    
	System::SetGlUnmapBuffer(m_Buffer);
}

