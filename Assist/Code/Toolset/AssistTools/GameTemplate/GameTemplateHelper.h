// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/11 1:13)

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
        GameTemplateHelper(int argc, char* argv[], const String& consoleTitle,
                           const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        int DoRun() override;
    };
}

#endif  // GAME_TEMPLATE_GAME_TEMPLATE_HELPER_H