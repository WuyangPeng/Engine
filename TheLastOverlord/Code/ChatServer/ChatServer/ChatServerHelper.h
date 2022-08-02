///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/27 21:36)

#ifndef CHAT_SERVER_CHAT_SERVER_HELPER_H
#define CHAT_SERVER_CHAT_SERVER_HELPER_H

#include "ChatServerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace ChatServer
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, ChatServerMessageWindowProcessHandle>;

    class ChatServerHelper : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = ChatServerHelper;
        using ParentType = WindowMainFunctionHelperBase;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        ChatServerHelper(WindowsHInstance instance, char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // CHAT_SERVER_CHAT_SERVER_HELPER_H
