///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 16:51)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "ConsoleMainFunctionHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/ConsoleFrame/ConsoleFrameBuildDetail.h"
#include "Framework/ConsoleFrame/ConsoleProcessDetail.h"
#include "Framework/MainFunctionHelper/ConsoleMainFunctionHelperDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, ConsoleMainFunctionHelper)

namespace FrameworkToolset
{
    template class Framework::ConsoleMainFunctionHelper<Framework::ConsoleFrameBuild, Framework::ConsoleProcessInterface>;
}
