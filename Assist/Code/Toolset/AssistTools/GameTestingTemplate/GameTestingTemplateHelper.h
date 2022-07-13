///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 16:16)

#ifndef GAME_TESTING_TEMPLATE_GAME_TESTING_TEMPLATE_HELPER_H
#define GAME_TESTING_TEMPLATE_GAME_TESTING_TEMPLATE_HELPER_H

#include "Framework/MainFunctionHelper/ConsoleMainFunctionHelper.h"

namespace GameTestingTemplate
{
    class GameTestingTemplateHelper : public Framework::ConsoleMainFunctionHelperBase
    {
    public:
        using ClassType = GameTestingTemplateHelper;
        using ParentType = ConsoleMainFunctionHelperBase;
        using String = System::String;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        GameTestingTemplateHelper(int argc, char** argv, const System::String& consoleTitle, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int DoRun() override;
    };
}

#endif  // GAME_TESTING_TEMPLATE_GAME_TESTING_TEMPLATE_HELPER_H