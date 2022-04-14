// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:43)

#include "Rendering/RenderingExport.h"

#include "Dx9VertexBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Renderers/BufferLockManagerDetail.h"
#include "CoreTools/Contract/Noexcept.h"

Rendering::Dx9VertexBuffer::Dx9VertexBuffer([[maybe_unused]] Renderer* renderer, [[maybe_unused]] const VertexBuffer* vertexBuffer) noexcept
    : ParentType{}
{
 
    
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

void Rendering::Dx9VertexBuffer::Enable([[maybe_unused]] Renderer* renderer, [[maybe_unused]] unsigned int vertexSize, [[maybe_unused]] unsigned int streamIndex, [[maybe_unused]] unsigned int offset)
{
    RENDERING_CLASS_IS_VALID_1;   
 
    CoreTools::DisableNoexcept();
     
}

void Rendering::Dx9VertexBuffer::Disable([[maybe_unused]] Renderer* renderer, [[maybe_unused]] unsigned int streamIndex)
{
    RENDERING_CLASS_IS_VALID_1; 
    CoreTools::DisableNoexcept();
  
}

void* Rendering::Dx9VertexBuffer::Lock([[maybe_unused]] BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;
    CoreTools::DisableNoexcept();
 

	return nullptr;
}

void Rendering::Dx9VertexBuffer
::Unlock ()
{
    RENDERING_CLASS_IS_VALID_1;
    CoreTools::DisableNoexcept();
    
}

