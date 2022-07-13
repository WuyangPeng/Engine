///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/04 19:27)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "LinuxFrameBuild.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/LinuxFrame/LinuxFrameBuildDetail.h"
#include "Framework/LinuxFrame/LinuxProcess.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, LinuxFrameBuild)

namespace FrameworkToolset
{
    template class Framework::LinuxFrameBuild<Framework::LinuxProcessInterface>;
}
