/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:10)

#ifndef CORSS_SERVER_CORSS_SERVER_HELPER_H
#define CORSS_SERVER_CORSS_SERVER_HELPER_H

#include "CorssServerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace CorssServer
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, CorssServerMessageWindowProcessHandle>;

    class CorssServerHelper final : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = CorssServerHelper;
        using ParentType = WindowMainFunctionHelperBase;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        CorssServerHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // CORSS_SERVER_CORSS_SERVER_HELPER_H
