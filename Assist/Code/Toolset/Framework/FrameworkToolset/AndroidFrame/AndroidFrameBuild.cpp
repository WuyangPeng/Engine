// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ¸¨Öú°æ±¾£º0.3.0.1 (2020/05/22 13:47)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "AndroidFrameBuild.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/AndroidFrame/AndroidProcess.h"
#include "Framework/AndroidFrame/AndroidFrameBuildDetail.h" 

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, AndroidFrameBuild)

namespace FrameworkToolset
{
	template
	class Framework::AndroidFrameBuild<Framework::AndroidProcessInterface>;
}
