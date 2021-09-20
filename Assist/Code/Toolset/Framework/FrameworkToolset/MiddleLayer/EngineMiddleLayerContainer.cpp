// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ¸¨Öú°æ±¾£º0.3.0.1 (2020/05/22 13:45)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "EngineMiddleLayerContainer.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"    
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, EngineMiddleLayerContainer)

namespace FrameworkToolset
{
	template
	class Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait>;
}
