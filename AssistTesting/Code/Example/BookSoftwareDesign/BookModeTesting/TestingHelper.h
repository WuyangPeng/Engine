// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.0.3.0 (2020/03/24 21:37)

#ifndef BOOK_MODE_TESTING_HELPER_H
#define BOOK_MODE_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace BookMode
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper);

	private:
		virtual int DoRun() override;

		void AddSuites();

		void AddDesignPatternsExplainedSuite();

		void AddDesignPatternsElementsOfReusableObjectOrientedSoftwareSuite();

		void AddPatternLanguagesOfProgramDesignSuite();

		void AddPatternLanguagesOfProgramDesign1Suite(Suite& patternLanguagesOfProgramDesignSuite);

		void AddPatternLanguagesOfProgramDesign2Suite(Suite& patternLanguagesOfProgramDesignSuite);

		void AddPatternLanguagesOfProgramDesign3Suite(Suite& patternLanguagesOfProgramDesignSuite);

		void AddPatternLanguagesOfProgramDesign4Suite(Suite& patternLanguagesOfProgramDesignSuite);

		void AddPatternLanguagesOfProgramDesign5Suite(Suite& patternLanguagesOfProgramDesignSuite);

		void AddPatternHatchingDesignPatternsAppliedSuite();

		void AddPatternOrientedSoftwareArfhitectureSuite();

		void AddPatternOrientedSoftwareArfhitectureASystemOfPatternsSuite(Suite& patternOrientedSoftwareArfhitectureSuite);

		void AddPatternOrientedSoftwareArfhitecturePatternsForConcurrentAndNetworkedObjectsSuite(Suite& patternOrientedSoftwareArfhitectureSuite);

		void AddPatternOrientedSoftwareArfhitecturePatternsForResourceManagermentSuite(Suite& patternOrientedSoftwareArfhitectureSuite);

		void AddPatternOrientedSoftwareArfhitectureAPatternLanguageForDistributedComputingSuite(Suite& patternOrientedSoftwareArfhitectureSuite);

		void AddPatternOrientedSoftwareArfhitectureOnPatternsAndPatternLanguagesSuite(Suite& patternOrientedSoftwareArfhitectureSuite);

		void AddPatternsOfEnterpriseApplicationArchitectureSuite();

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // BOOK_MODE_TESTING_HELPER_H