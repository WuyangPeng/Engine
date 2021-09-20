// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:32)

#include "Rendering/RenderingExport.h"

#include "OpenGLVertexBuffer.h"
#include "OpenGLMapping.h"

#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Renderers/BufferLockManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
Rendering::OpenGLVertexBuffer ::OpenGLVertexBuffer([[maybe_unused]] Renderer* renderer, const VertexBuffer* vertexBuffer)
    : ParentType{}, m_Buffer{ 0 }
{
    Init(vertexBuffer);
    
 
    
	RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::OpenGLVertexBuffer
    ::Init(const VertexBuffer* vertexBuffer)
{
  //  m_Buffer = System::GLBufferData(vertexBuffer->GetNumBytes(),g_OpenGLBufferUsage[System::EnumCastUnderlying(vertexBuffer->GetUsage())]);

	BufferLockManager<ClassType> manager(*this);
	void* data = manager.Lock(BufferLocking::WriteOnly);

	memcpy(data, vertexBuffer->GetReadOnlyData(), vertexBuffer->GetNumBytes());   
}

Rendering::OpenGLVertexBuffer
    ::~OpenGLVertexBuffer ()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
    
   // m_Buffer = System::GLDeleteBuffers(m_Buffer);
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

void Rendering::OpenGLVertexBuffer ::Enable([[maybe_unused]] Renderer* renderer, [[maybe_unused]] unsigned int vertexSize, [[maybe_unused]] unsigned int streamIndex, [[maybe_unused]] unsigned int offset) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
   // System::GLBindBuffer(m_Buffer);
    
 
}

void Rendering::OpenGLVertexBuffer ::Disable([[maybe_unused]] Renderer* renderer, [[maybe_unused]] unsigned int streamIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
   // System::GLBindBuffer(0);
    
 
}

void* Rendering::OpenGLVertexBuffer
    ::Lock (BufferLocking mode) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    mode;
 //   GLvoid* videoMemory = System::GetGLMapBuffer(m_Buffer,g_OpenGLBufferLocking[System::EnumCastUnderlying(mode)]);

  //  return videoMemory;

    return nullptr;
}

void Rendering::OpenGLVertexBuffer
    ::Unlock () noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
//	System::SetGLUnmapBuffer(m_Buffer);
}

#include STSTEM_WARNING_POP