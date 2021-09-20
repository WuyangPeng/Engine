// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.0.0.1 (2019/09/28 20:48)

#ifndef BOOK_OPENGL_TESTING_HELPER_H
#define BOOK_OPENGL_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace BookOpenGL
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites(); 	

		void AddOpenGLSuperBibleSuite();

		void AddOpenGLSuperBibleFourthEditionSuite(Suite& openGLSuperBibleSuite);

		void AddOpenGLSuperBibleFifthEditionSuite(Suite& openGLSuperBibleSuite);

		void AddOpenGLShadingLanguageSuite();

		void AddOpenGLProgrammingGuideSuite();

		void AddOpenGLProgrammingGuideSeventhEditionSuite(Suite& openGLProgrammingGuideSuite);

		void AddOpenGLProgrammingGuideNinthEditionSuite(Suite& openGLProgrammingGuideSuite);

		void AddOpenGLES30ProgrammingGuideSuite();

		void AddOpenGLReferenceManualSuite();

		void AddComputerGraphicsWithOpenGLSuite();

		void AddComputerGraphicsUsingOpenGLSuite();
	
	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // BOOK_OPENGL_TESTING_HELPER_H