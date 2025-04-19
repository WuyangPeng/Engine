///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:26)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "MacintoshFrameBuild.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MacintoshFrame/MacintoshFrameBuildDetail.h"
#include "Framework/MacintoshFrame/MacintoshProcess.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, MacintoshFrameBuild)

namespace Framework
{
    template class Framework::MacintoshFrameBuild<Framework::MacintoshProcessInterface>;
}
