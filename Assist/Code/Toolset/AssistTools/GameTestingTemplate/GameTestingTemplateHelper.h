///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:27)

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