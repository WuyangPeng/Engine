///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 16:30)

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
