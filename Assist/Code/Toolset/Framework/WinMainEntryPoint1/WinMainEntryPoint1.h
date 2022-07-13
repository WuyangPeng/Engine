///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 11:19)

#ifndef WIN_MAIN_ENTRY_POINT1_H
#define WIN_MAIN_ENTRY_POINT1_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace Framework
{
    using BaseType = WindowMainFunctionHelper<WindowsAPIFrameBuild, WindowProcessInterface>;

    class WinMainEntryPoint1 final : public BaseType
    {
    public:
        using ClassType = WinMainEntryPoint1;
        using ParentType = BaseType;

    public:
        WinMainEntryPoint1(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD static std::shared_ptr<WinMainEntryPoint1> Create(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);
    };
}

#endif  // WIN_MAIN_ENTRY_POINT1_H
