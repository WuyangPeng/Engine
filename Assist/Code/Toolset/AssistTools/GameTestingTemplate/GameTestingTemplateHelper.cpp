///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 10:35)

#include "GameTestingTemplate.h"
#include "GameTestingTemplateHelper.h"
#include "GenerateEngine.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

GameTestingTemplate::GameTestingTemplateHelper::GameTestingTemplateHelper(int argc, char** argv, const System::String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ argc, argv, consoleTitle, environmentDirectory }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameTestingTemplate, GameTestingTemplateHelper)

int GameTestingTemplate::GameTestingTemplateHelper::DoRun()
{
    GenerateEngine generateEngine("Configuration/TestingStringReplacing.json", "Configuration/GameTestingParameter.json");

    return 0;
}
