///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 16:15)

#include "GameTestingTemplate.h"
#include "GameTestingTemplateHelper.h"
#include "GenerateEngine.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

#include <iostream>

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
