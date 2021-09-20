// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.2 (2019/09/28 16:43)

#ifndef BOOK_GRAPHICS_TESTING_HELPER_H
#define BOOK_GRAPHICS_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace BookGraphics
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites(); 	

		void AddInteractiveComputerGraphicsSuite();

		void AddInteractiveComputerGraphicsFifthEditionSuite(Suite& interactiveComputerGraphicsSuite);

		void AddInteractiveComputerGraphicsSeventhEditionSuite(Suite& interactiveComputerGraphicsSuite);

		void Add3DGamesSuite();

		void Add3DGamesRealTimeRenderingAndSoftwareTechnologySuite(Suite& threeDGamesSuite);

		void Add3DGamesAnimationAndAdvancedRealTimeRenderingSuite(Suite& threeDGamesSuite);

		void Add3DComputerGraphicsSuite();

		void AddComputerGraphicsSuite();

		void AddComputerGraphicsPrinciplesAndPracticeSuite();

		void AddFundamentalsOfComputerGraphicsSuite();

		void AddMichaelAbrashsGraphicsProgrammingBlackBookSuite();

		void AddTheCgTutorialSuite(); 
	
	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // BOOK_GRAPHICS_TESTING_HELPER_H