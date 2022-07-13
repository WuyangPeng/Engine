///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/04 19:01)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "WindowsAPIFrameBuild.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowProcess/WindowProcessHandleDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, WindowsAPIFrameBuild)

namespace FrameworkToolset
{
    template class Framework::WindowsAPIFrameBuild<Framework::WindowProcessInterface>;
}
