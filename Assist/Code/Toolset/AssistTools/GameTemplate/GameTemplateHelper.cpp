///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 16:03)

#include "GameTemplate.h"
#include "GameTemplateHelper.h"
#include "GenerateEngine.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

#include <iostream>

GameTemplate::GameTemplateHelper::GameTemplateHelper(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ argc, argv, consoleTitle, environmentDirectory }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameTemplate, GameTemplateHelper)

int GameTemplate::GameTemplateHelper::DoRun()
{
    GenerateEngine generateEngine{ "Configuration/StringReplacing.json", "Configuration/GameParameter.json" };

    return 0;
}
