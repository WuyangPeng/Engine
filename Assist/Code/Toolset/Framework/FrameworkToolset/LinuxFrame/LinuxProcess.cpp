// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ¸¨Öú°æ±¾£º0.3.0.1 (2020/05/22 13:46)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "LinuxProcess.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/LinuxFrame/LinuxProcessDetail.h"
#include "Framework/LinuxFrame/LinuxCallBackInterface.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, LinuxProcess)

namespace FrameworkToolset
{
	template
	class Framework::LinuxProcess<Framework::LinuxCallBackInterface>;
}
