///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/11 15:42)

#ifndef EXAMPLE_EXAMPLE_HELPER_H
#define EXAMPLE_EXAMPLE_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace Example
{
    using WindowMainFunctionHelper = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, Framework::WindowProcessInterface>;
    class ExampleHelper : public WindowMainFunctionHelper
    {
    public:
        using ClassType = ExampleHelper;
        using ParentType = WindowMainFunctionHelper;
        ;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        ExampleHelper(WindowsHInstance instance, char* cmdLine, const WindowApplicationInformation& information, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // EXAMPLE_EXAMPLE_HELPER_H