// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.2 (2019/09/29 09:51)

#ifndef BOOK_SOFTWARE_ENGINEERING_TESTING_HELPER_H
#define BOOK_SOFTWARE_ENGINEERING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace BookSoftwareEngineering
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites(); 	

		void AddCatastropheDisentanglementGettingSoftwareProjectsBackOnTrackSuite();

		void AddFuzzingBruteForceVulnerabilityDiscoverySuite();

		void AddCodeOptimizationEffectiveMemoryUsageSuite();

		void AddContinuousIntegrationImprovingSoftwareQualityAndReducingRiskSuite();

		void AddBeautifulArchitectureSuite();

		void AddApplyingDomainDrivenDesignAndPatternsSuite();

		void AddAntiPatternsRefactoringSoftwareArchitecturesAndProjectsInCrisisSuite();

		void AddWritingEffectiveUseCasesSuite();

		void AddSoftwareEngineeringSuite();

		void AddSoftwareEngineeringSeventhEditionSuite(Suite& softwareEngineeringSuite);

		void AddSoftwareEngineeringEighthEditionSuite(Suite& softwareEngineeringSuite);

		void AddAnalysisPatternsReusableObjectModelsSuite();
	
	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // BOOK_SOFTWARE_ENGINEERING_TESTING_HELPER_H