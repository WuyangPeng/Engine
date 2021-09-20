// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.3.0.1 (2020/05/22 13:47)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "ConsoleFrameBuild.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/ConsoleFrame/ConsoleProcess.h"
#include "Framework/ConsoleFrame/ConsoleFrameBuildDetail.h" 

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, ConsoleFrameBuild)

namespace FrameworkToolset
{
	template
	class Framework::ConsoleFrameBuild<Framework::ConsoleProcessInterface>;
}
