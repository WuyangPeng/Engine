///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:34)

#include "GameTestingTemplate.h"
#include "GameTestingTemplateHelper.h"
#include "GenerateEngine.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

GameTestingTemplate::GameTestingTemplateHelper::GameTestingTemplateHelper(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ argc, argv, consoleTitle, environmentDirectory }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameTestingTemplate, GameTestingTemplateHelper)

int GameTestingTemplate::GameTestingTemplateHelper::DoRun()
{
    GenerateEngine generateEngine{ "Configuration/GameTemplate.json" };

    return 0;
}