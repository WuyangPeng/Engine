// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ¸¨Öú°æ±¾£º0.3.0.1 (2020/05/22 13:45)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "MacintoshMainFunctionHelper.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Framework/MacintoshFrame/MacintoshProcessDetail.h"
#include "Framework/MacintoshFrame/MacintoshFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/MacintoshMainFunctionHelperDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, MacintoshMainFunctionHelper)

namespace FrameworkToolset
{
	template
	class Framework::MacintoshMainFunctionHelper<Framework::MacintoshFrameBuild, Framework::MacintoshProcessInterface>;
}


