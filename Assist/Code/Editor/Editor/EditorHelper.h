///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/06 13:48)

#ifndef EDITOR_EDITOR_HELPER_H
#define EDITOR_EDITOR_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace Editor
{
    using WindowMainFunctionHelper = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, Framework::WindowProcessInterface>;

    class EditorHelper : public WindowMainFunctionHelper
    {
    public:
        using ClassType = EditorHelper;
        using ParentType = WindowMainFunctionHelper;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        EditorHelper(WindowsHInstance hInstance, char* cmdLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // EDITOR_EDITOR_HELPER_H