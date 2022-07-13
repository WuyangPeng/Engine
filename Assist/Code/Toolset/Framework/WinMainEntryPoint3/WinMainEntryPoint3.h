///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 11:28)

#ifndef WIN_MAIN_ENTRY_POINT3_H
#define WIN_MAIN_ENTRY_POINT3_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace Framework
{
    using BaseType = WindowMainFunctionHelper<WindowsAPIFrameBuild, WindowProcessInterface>;

    class WinMainEntryPoint3 final : public BaseType
    {
    public:
        using ClassType = WinMainEntryPoint3;
        using ParentType = BaseType;

    public:
        WinMainEntryPoint3(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD static std::shared_ptr<WinMainEntryPoint3> Create(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);
    };
}

#endif  // WIN_MAIN_ENTRY_POINT3_H
