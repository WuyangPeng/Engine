// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/09/02 10:56)

#ifndef SOUND_EFFECT_TESTING_TESTING_HELPER_H
#define SOUND_EFFECT_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace SoundEffect
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 
	
		virtual int DoRun() override;			

	private:
                void AddSuites();	

		void AddMacroSuite();
		void AddConfigurationSuite();
		void AddInterfaceSuite();
		void AddCsynUtilSuite();
		void AddDirectSoundSuite();
		void AddOggSuite();
		void AddOpenALSuite();
		void AddVorbisSuite();
		void AddFreeAlutSuite();

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // SOUND_EFFECT_TESTING_TESTING_HELPER_H