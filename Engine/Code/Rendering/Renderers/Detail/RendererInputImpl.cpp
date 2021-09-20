// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:03)

#include "Rendering/RenderingExport.h"

#include "RendererInputImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "../RendererFactory.h"

Rendering::RendererInputImpl
	::RendererInputImpl() noexcept
{	
   RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::RendererInputImpl
	:: ~RendererInputImpl()
{	
   RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,RendererInputImpl)

Rendering::RendererInputImpl::RendererInputPtr Rendering::RendererInputImpl::Create(RendererTypes type)
{
    return RendererFactory::CreateInput(type);
}

