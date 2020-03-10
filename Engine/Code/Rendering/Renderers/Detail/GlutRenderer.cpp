// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/26 17:26)

#include "Rendering/RenderingExport.h"

#include "GlutRenderer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering:: GlutRenderer
	:: GlutRenderer(const RendererBasis& basis)
    :ParentType(basis)
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GlutRenderer)

Rendering::RendererTypes Rendering::GlutRenderer
	::GetRendererType() const
{
	return RendererTypes::Glut;
}

