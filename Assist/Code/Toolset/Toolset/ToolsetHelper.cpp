///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 17:46)

#include "Toolset.h"
#include "ToolsetHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

Toolset::ToolsetHelper::ToolsetHelper(WindowsHInstance instance,
                                      const char* cmdLine,
                                      const WindowApplicationInformation& information,
                                      const EnvironmentDirectory& environmentDirectory)
    : ParentType{ instance, cmdLine, information, environmentDirectory }
{
    SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Toolset, ToolsetHelper)
