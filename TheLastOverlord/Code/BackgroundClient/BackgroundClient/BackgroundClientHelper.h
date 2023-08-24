/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��0.9.1.3 (2023/08/21 10:42)

#ifndef BACKGROUND_CLIENT_BACKGROUND_CLIENT_HELPER_H
#define BACKGROUND_CLIENT_BACKGROUND_CLIENT_HELPER_H

#include "BackgroundClientMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace BackgroundClient
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, BackgroundClientMessageWindowProcessHandle>;

    class BackgroundClientHelper final : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = BackgroundClientHelper;
        using ParentType = WindowMainFunctionHelperBase;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        BackgroundClientHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // BACKGROUND_CLIENT_BACKGROUND_CLIENT_HELPER_H
