// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.1 (2020/01/11 1:13)

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
    GenerateEngine generateEngine("Configuration/StringReplacing.json", "Configuration/GameParameter.json");

    return 0;
}
