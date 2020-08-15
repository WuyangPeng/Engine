// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:43)

#include "Rendering/RenderingExport.h"

#include "Dx9VertexBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/UnusedMacro.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Renderers/BufferLockManagerDetail.h"
#include "CoreTools/ClassInvariant/Noexcept.h"

Rendering::Dx9VertexBuffer
    ::Dx9VertexBuffer (Renderer* renderer,const VertexBuffer* vertexBuffer) noexcept
    :ParentType{}
{
    SYSTEM_UNUSED_ARG(renderer);
    SYSTEM_UNUSED_ARG(vertexBuffer);
    
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

 

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::Dx9VertexBuffer
    ::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::Dx9VertexBuffer
    ::Enable (Renderer* renderer, unsigned int vertexSize,unsigned int streamIndex, unsigned int offset)
{
    RENDERING_CLASS_IS_VALID_1;   
 
    CoreTools::DoNothing();
    SYSTEM_UNUSED_ARG(renderer);
    SYSTEM_UNUSED_ARG(vertexSize);
    SYSTEM_UNUSED_ARG(streamIndex);
    SYSTEM_UNUSED_ARG(offset);
}

void Rendering::Dx9VertexBuffer
    ::Disable (Renderer* renderer, unsigned int streamIndex)
{
    RENDERING_CLASS_IS_VALID_1; 
    CoreTools::DoNothing();
    SYSTEM_UNUSED_ARG(renderer);
    SYSTEM_UNUSED_ARG(streamIndex);
}

void* Rendering::Dx9VertexBuffer
    ::Lock (BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;
    CoreTools::DoNothing();
    SYSTEM_UNUSED_ARG(mode);

	return nullptr;
}

void Rendering::Dx9VertexBuffer
    ::Unlock ()
{
    RENDERING_CLASS_IS_VALID_1;
    CoreTools::DoNothing();
    
}

