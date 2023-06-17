///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 16:51)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "MacintoshMainFunctionHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MacintoshFrame/MacintoshFrameBuildDetail.h"
#include "Framework/MacintoshFrame/MacintoshProcessDetail.h"
#include "Framework/MainFunctionHelper/MacintoshMainFunctionHelperDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, MacintoshMainFunctionHelper)

namespace FrameworkToolset
{
    template class Framework::MacintoshMainFunctionHelper<Framework::MacintoshFrameBuild, Framework::MacintoshProcessInterface>;
}
