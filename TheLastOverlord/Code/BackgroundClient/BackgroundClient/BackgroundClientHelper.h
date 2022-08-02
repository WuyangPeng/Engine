///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/22 23:13)

#ifndef BACKGROUND_CLIENT_BACKGROUND_CLIENT_HELPER_H
#define BACKGROUND_CLIENT_BACKGROUND_CLIENT_HELPER_H

#include "BackgroundClientMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace BackgroundClient
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, BackgroundClientMessageWindowProcessHandle>;

    class BackgroundClientHelper : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = BackgroundClientHelper;
        using ParentType = WindowMainFunctionHelperBase;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        BackgroundClientHelper(WindowsHInstance instance, char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // BACKGROUND_CLIENT_BACKGROUND_CLIENT_HELPER_H
