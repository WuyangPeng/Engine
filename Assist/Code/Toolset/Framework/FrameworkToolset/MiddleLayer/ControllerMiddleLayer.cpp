// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ¸¨Öú°æ±¾£º0.3.0.1 (2020/05/22 13:44)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "ControllerMiddleLayer.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"    
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/MiddleLayer/ControllerMiddleLayerDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, ControllerMiddleLayer)

namespace FrameworkToolset
{
	template
	class Framework::ControllerMiddleLayer<Framework::WindowApplicationTrait>;
}
