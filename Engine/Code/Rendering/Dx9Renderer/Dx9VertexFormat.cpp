// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:44)

#include "Rendering/RenderingExport.h" 

#include "Dx9VertexFormat.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Contract/Noexcept.h"

Rendering::Dx9VertexFormat::Dx9VertexFormat([[maybe_unused]] Renderer* renderer, [[maybe_unused]] const VertexFormat* vertexFormat) noexcept
    : ParentType{}
{    
 

	RENDERING_SELF_CLASS_IS_VALID_1;
}
 
 

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::Dx9VertexFormat
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::Dx9VertexFormat::Enable([[maybe_unused]] Renderer* renderer)
{		
	RENDERING_CLASS_IS_VALID_1;
    CoreTools::DisableNoexcept();
 
}

void Rendering::Dx9VertexFormat::Disable([[maybe_unused]] Renderer* renderer)
{
	RENDERING_CLASS_IS_VALID_1;
    CoreTools::DisableNoexcept();
	 	
}
