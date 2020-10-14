// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:42)

#include "Rendering/RenderingExport.h"

#include "Dx9RenderTarget.h" 

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 

#include "CoreTools/Contract/Noexcept.h"

Rendering::Dx9RenderTarget ::Dx9RenderTarget([[maybe_unused]] Renderer* renderer, [[maybe_unused]] const RenderTarget* renderTarget)
    : ParentType{}
{
 
CoreTools::DisableNoexcept();
	RENDERING_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_STUB_DEFINE(Rendering, Dx9RenderTarget)

void Rendering::Dx9RenderTarget ::Enable([[maybe_unused]] Renderer* renderer)
{
	RENDERING_CLASS_IS_VALID_9; 

 

	CoreTools::DisableNoexcept();
}

void Rendering::Dx9RenderTarget ::Disable([[maybe_unused]] Renderer* renderer)
{
	RENDERING_CLASS_IS_VALID_9;  

	  

	 CoreTools::DisableNoexcept();
}

Rendering::ConstTexture2DSharedPtr Rendering::Dx9RenderTarget ::ReadColor([[maybe_unused]] int index, [[maybe_unused]] Renderer* renderer)
{
	RENDERING_CLASS_IS_VALID_9;  

 
	CoreTools::DisableNoexcept();

	return ConstTexture2DSharedPtr();
}

