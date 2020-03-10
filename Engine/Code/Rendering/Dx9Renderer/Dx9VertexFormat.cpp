// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:44)

#include "Rendering/RenderingExport.h" 

#include "Dx9VertexFormat.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::Dx9VertexFormat
    ::Dx9VertexFormat (Renderer* renderer, const VertexFormat* vertexFormat)    
	:ParentType{}
{    
	SYSTEM_UNUSED_ARG(vertexFormat);
    SYSTEM_UNUSED_ARG(renderer);

	RENDERING_SELF_CLASS_IS_VALID_1;
}
 
Rendering::Dx9VertexFormat
	::~Dx9VertexFormat ()
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

void Rendering::Dx9VertexFormat
	::Enable (Renderer* renderer)
{		
	RENDERING_CLASS_IS_VALID_1;
	
	SYSTEM_UNUSED_ARG(renderer);
}

void Rendering::Dx9VertexFormat
	::Disable (Renderer* renderer)
{
	RENDERING_CLASS_IS_VALID_1;
	 
	SYSTEM_UNUSED_ARG(renderer);	
}
