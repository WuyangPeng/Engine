///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:35)

#include "GameTemplate.h"
#include "GameTemplateHelper.h"
#include "GenerateEngine.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

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
