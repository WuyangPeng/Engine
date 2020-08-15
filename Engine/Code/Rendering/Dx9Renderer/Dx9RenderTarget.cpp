// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:42)

#include "Rendering/RenderingExport.h"

#include "Dx9RenderTarget.h" 
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/ClassInvariant/Noexcept.h"

Rendering::Dx9RenderTarget
	::Dx9RenderTarget (Renderer* renderer,const RenderTarget* renderTarget) 
	:ParentType{}
{
	SYSTEM_UNUSED_ARG(renderTarget);
	SYSTEM_UNUSED_ARG(renderer);
CoreTools::DoNothing();
	RENDERING_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_STUB_DEFINE(Rendering, Dx9RenderTarget)

void Rendering::Dx9RenderTarget
	::Enable (Renderer* renderer)
{
	RENDERING_CLASS_IS_VALID_9; 

	SYSTEM_UNUSED_ARG(renderer);

	CoreTools::DoNothing();
}

void Rendering::Dx9RenderTarget
	::Disable (Renderer* renderer)
{
	RENDERING_CLASS_IS_VALID_9;  

	 SYSTEM_UNUSED_ARG(renderer);

	 CoreTools::DoNothing();
}

Rendering::ConstTexture2DSmartPointer Rendering::Dx9RenderTarget
	::ReadColor(int index,Renderer* renderer)
{
	RENDERING_CLASS_IS_VALID_9;  

	SYSTEM_UNUSED_ARG(index);
	SYSTEM_UNUSED_ARG(renderer);

	CoreTools::DoNothing();

	return ConstTexture2DSmartPointer();
}

