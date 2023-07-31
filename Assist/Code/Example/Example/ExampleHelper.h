///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:44)

#ifndef EXAMPLE_EXAMPLE_HELPER_H
#define EXAMPLE_EXAMPLE_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace Example
{
    using WindowMainFunctionHelper = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, Framework::WindowProcessInterface>;

    class ExampleHelper final : public WindowMainFunctionHelper
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