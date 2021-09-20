// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ¸¨Öú°æ±¾£º0.3.0.1 (2020/05/22 13:45)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "ObjectLogicManager.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"    
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/ArtificialIntellegenceInterface.h" 

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, ObjectLogicManager)

namespace FrameworkToolset
{
	template
	class Framework::ObjectLogicManager<Framework::ObjectLogicInterface,Framework::ArtificialIntellegenceInterface>;
}
