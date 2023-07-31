///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:53)

#ifndef WIN_MAIN_ENTRY_POINT2_H
#define WIN_MAIN_ENTRY_POINT2_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace Framework
{
    using BaseType = WindowMainFunctionHelper<WindowsAPIFrameBuild, WindowProcessInterface>;

    class WinMainEntryPoint2 final : public BaseType
    {
    public:
        using ClassType = WinMainEntryPoint2;
        using ParentType = BaseType;

    public:
        WinMainEntryPoint2(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // WIN_MAIN_ENTRY_POINT2_H
