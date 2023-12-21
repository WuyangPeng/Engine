/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#ifndef MESSAGE_CLIENT_MESSAGE_CLIENT_HELPER_H
#define MESSAGE_CLIENT_MESSAGE_CLIENT_HELPER_H

#include "MessageClientMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace MessageClient
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, MessageClientMessageWindowProcessHandle>;

    class MessageClientHelper final : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = MessageClientHelper;
        using ParentType = WindowMainFunctionHelperBase;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        MessageClientHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // MESSAGE_CLIENT_MESSAGE_CLIENT_HELPER_H
