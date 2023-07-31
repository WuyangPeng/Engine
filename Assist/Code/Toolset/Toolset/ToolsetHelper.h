///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:12)

#ifndef TOOLSET_TOOLSET_HELPER_H
#define TOOLSET_TOOLSET_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace Toolset
{
    using WindowMainFunctionHelper = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, Framework::WindowProcessInterface>;

    class ToolsetHelper final : public WindowMainFunctionHelper
    {
    public:
        using ClassType = ToolsetHelper;
        using ParentType = WindowMainFunctionHelper;
        ;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        ToolsetHelper(WindowsHInstance instance,
                      const char* cmdLine,
                      const WindowApplicationInformation& information,
                      const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // TOOLSET_TOOLSET_HELPER_H