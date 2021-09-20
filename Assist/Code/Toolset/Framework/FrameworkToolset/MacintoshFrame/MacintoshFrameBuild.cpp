// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.3.0.1 (2020/05/22 13:46)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "MacintoshFrameBuild.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/MacintoshFrame/MacintoshProcess.h"
#include "Framework/MacintoshFrame/MacintoshFrameBuildDetail.h" 

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, MacintoshFrameBuild)

namespace FrameworkToolset
{
	template
	class Framework::MacintoshFrameBuild<Framework::MacintoshProcessInterface>;
}
