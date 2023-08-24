/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��0.9.1.3 (2023/08/21 10:43)

#ifndef UPDATE_SERVER_UPDATE_SERVER_HELPER_H
#define UPDATE_SERVER_UPDATE_SERVER_HELPER_H

#include "UpdateServerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace UpdateServer
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, UpdateServerMessageWindowProcessHandle>;

    class UpdateServerHelper final : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = UpdateServerHelper;
        using ParentType = WindowMainFunctionHelperBase;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        UpdateServerHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // UPDATE_SERVER_UPDATE_SERVER_HELPER_H
