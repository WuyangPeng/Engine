// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:41)

#include "Rendering/RenderingExport.h" 

#include "Dx9IndexBuffer.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ClassInvariant/NoexceptDetail.h"
Rendering::Dx9IndexBuffer
	::Dx9IndexBuffer(Renderer* renderer, const IndexBuffer* indexBuffer) noexcept
	:ParentType{}
{
	SYSTEM_UNUSED_ARG(indexBuffer);
	SYSTEM_UNUSED_ARG(renderer);

	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::Dx9IndexBuffer
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::Dx9IndexBuffer
	::Enable(Renderer* renderer)
{
	RENDERING_CLASS_IS_VALID_1;

	SYSTEM_UNUSED_ARG(renderer);
	
	CoreTools::DoNothing();
}

void Rendering::Dx9IndexBuffer
	::Disable(Renderer* renderer)
{
	RENDERING_CLASS_IS_VALID_1;

	SYSTEM_UNUSED_ARG(renderer);
	
	CoreTools::DoNothing();
}

void* Rendering::Dx9IndexBuffer
	::Lock(BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

	SYSTEM_UNUSED_ARG(mode);
	
	CoreTools::DoNothing();

	return nullptr;
}

void Rendering::Dx9IndexBuffer
	::Unlock() 
{
	RENDERING_CLASS_IS_VALID_1;
	
	CoreTools::DoNothing();
}