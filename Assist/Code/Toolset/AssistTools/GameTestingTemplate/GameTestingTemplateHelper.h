///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/18 14:06)

#ifndef GAME_TESTING_TEMPLATE_GAME_TESTING_TEMPLATE_HELPER_H
#define GAME_TESTING_TEMPLATE_GAME_TESTING_TEMPLATE_HELPER_H

#include "Framework/MainFunctionHelper/ConsoleMainFunctionHelper.h"

namespace GameTestingTemplate
{
    class GameTestingTemplateHelper final : public Framework::ConsoleMainFunctionHelperBase
    {
    public:
        using ClassType = GameTestingTemplateHelper;
        using ParentType = ConsoleMainFunctionHelperBase;

        using String = System::String;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        GameTestingTemplateHelper(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int DoRun() override;
    };
}

#endif  // GAME_TESTING_TEMPLATE_GAME_TESTING_TEMPLATE_HELPER_H