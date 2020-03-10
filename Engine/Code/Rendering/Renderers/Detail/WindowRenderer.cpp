// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:12)

#include "Rendering/RenderingExport.h"

#include "WindowRenderer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "../RendererBasis.h"

Rendering:: WindowRenderer
	:: WindowRenderer(const RendererBasis& basis)
    :ParentType(basis)
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, WindowRenderer)

Rendering::RendererTypes Rendering::WindowRenderer
	::GetRendererType() const
{
	return RendererTypes::Window;
}

