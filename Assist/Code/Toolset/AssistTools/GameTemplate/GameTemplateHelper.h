///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 16:04)

#ifndef GAME_TEMPLATE_GAME_TEMPLATE_HELPER_H
#define GAME_TEMPLATE_GAME_TEMPLATE_HELPER_H

#include "Framework/MainFunctionHelper/ConsoleMainFunctionHelper.h"

namespace GameTemplate
{
    class GameTemplateHelper : public Framework::ConsoleMainFunctionHelperBase
    {
    public:
        using ClassType = GameTemplateHelper;
        using ParentType = ConsoleMainFunctionHelperBase;
        using String = System::String;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        GameTemplateHelper(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int DoRun() override;
    };
}

#endif  // GAME_TEMPLATE_GAME_TEMPLATE_HELPER_H