// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ¸¨Öú°æ±¾£º0.3.0.1 (2020/05/22 13:44)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "CameraControllerMiddleLayer.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"    
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "Framework/MiddleLayer/CameraControllerMiddleLayerDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, CameraControllerMiddleLayer)

namespace FrameworkToolset
{
	template
	class Framework::CameraControllerMiddleLayer<Framework::WindowApplicationTrait>;
}
