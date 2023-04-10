///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.5 (2023/04/03 09:40)

#ifndef DATABASE_GENERATE_SERVER_DATABASE_GENERATE_SERVER_HELPER_H
#define DATABASE_GENERATE_SERVER_DATABASE_GENERATE_SERVER_HELPER_H

#include "DatabaseGenerateServerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace DatabaseGenerateServer
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, DatabaseGenerateServerMessageWindowProcessHandle>;

    class DatabaseGenerateServerHelper final : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = DatabaseGenerateServerHelper;
        using ParentType = WindowMainFunctionHelperBase;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        DatabaseGenerateServerHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // DATABASE_GENERATE_SERVER_DATABASE_GENERATE_SERVER_HELPER_H
