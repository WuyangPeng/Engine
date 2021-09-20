// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/05 18:07)

#ifndef BOOK_UML_TESTING_HELPER_H
#define BOOK_UML_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace BookUML
{
	class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		using ClassType = TestingHelper; 
		using ParentType = CMainFunctionTestingHelper;
		
	public:	
		TestingHelper(int argc, char** argv);

		CLASS_INVARIANT_FINAL_DECLARE;

	private: 
		void InitSuite(); 		

		void AddObjectOrientedModelingAndDesignWithUMLSuite();
		void AddApplyingUMLAndPatternsSuite();
		void AddTheUnifiedModelingLanguageUserGuideSuite();
		void AddUMLDistilledSuite();
		void AddSamsTeachYourselfUMLIn24HoursSuite();
		void AddTheUnifiedModelingLanguageReferenceManualSuite();
	};
}

#endif // BOOK_UML_TESTING_HELPER_H