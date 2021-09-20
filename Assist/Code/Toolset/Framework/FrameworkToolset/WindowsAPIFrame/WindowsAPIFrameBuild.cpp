// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ¸¨Öú°æ±¾£º0.3.0.1 (2020/05/22 11:53)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "WindowsAPIFrameBuild.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"   
#include "Framework/WindowProcess/WindowProcessHandleDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, WindowsAPIFrameBuild)

namespace FrameworkToolset
{
	template
	class Framework::WindowsAPIFrameBuild<Framework::WindowProcessInterface>;
}
