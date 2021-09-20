// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ¸¨Öú°æ±¾£º0.3.0.1 (2020/05/22 13:47)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "ConsoleProcess.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/ConsoleFrame/ConsoleProcessDetail.h"
#include "Framework/ConsoleFrame/ConsoleCallBackInterface.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, ConsoleProcess)

namespace FrameworkToolset
{
	template
	class Framework::ConsoleProcess<Framework::ConsoleCallBackInterface>;
}
