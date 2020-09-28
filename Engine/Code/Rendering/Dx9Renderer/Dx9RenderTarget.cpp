// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 11:42)

#include "Rendering/RenderingExport.h"

#include "Dx9RenderTarget.h" 

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/ClassInvariant/Noexcept.h"

Rendering::Dx9RenderTarget ::Dx9RenderTarget([[maybe_unused]] Renderer* renderer, [[maybe_unused]] const RenderTarget* renderTarget)
    : ParentType{}
{
 
CoreTools::DoNothing();
	RENDERING_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_STUB_DEFINE(Rendering, Dx9RenderTarget)

void Rendering::Dx9RenderTarget ::Enable([[maybe_unused]] Renderer* renderer)
{
	RENDERING_CLASS_IS_VALID_9; 

 

	CoreTools::DoNothing();
}

void Rendering::Dx9RenderTarget ::Disable([[maybe_unused]] Renderer* renderer)
{
	RENDERING_CLASS_IS_VALID_9;  

	  

	 CoreTools::DoNothing();
}

Rendering::ConstTexture2DSmartPointer Rendering::Dx9RenderTarget ::ReadColor([[maybe_unused]] int index, [[maybe_unused]] Renderer* renderer)
{
	RENDERING_CLASS_IS_VALID_9;  

 
	CoreTools::DoNothing();

	return ConstTexture2DSmartPointer();
}

