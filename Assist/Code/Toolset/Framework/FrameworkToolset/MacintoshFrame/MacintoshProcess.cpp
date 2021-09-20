// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ¸¨Öú°æ±¾£º0.3.0.1 (2020/05/22 13:46)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "MacintoshProcess.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/MacintoshFrame/MacintoshProcessDetail.h"
#include "Framework/MacintoshFrame/MacintoshCallBackInterface.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, MacintoshProcess)

namespace FrameworkToolset
{
	template
	class Framework::MacintoshProcess<Framework::MacintoshCallBackInterface>;
}
