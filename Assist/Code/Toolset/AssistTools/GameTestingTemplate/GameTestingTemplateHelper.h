// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/12 0:32)

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
		GameTestingTemplateHelper(int argc, char* argv[], const System::String& consoleTitle,
								  const EnvironmentDirectory& environmentDirectory);
		virtual ~GameTestingTemplateHelper();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		virtual int DoRun() override;
	};
}

#endif // GAME_TESTING_TEMPLATE_GAME_TESTING_TEMPLATE_HELPER_H