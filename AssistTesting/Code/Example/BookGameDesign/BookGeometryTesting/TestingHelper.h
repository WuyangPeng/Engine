// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/06 21:43)

#ifndef BOOK_GEOMETRY_TESTING_HELPER_H
#define BOOK_GEOMETRY_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace BookGeometry
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

		void Add3DMathPrimerForGraphicsAndGameDevelopmentSuite();
		void AddMathematicsFor3DGameProgrammingAndComputerGraphicsSuite();
		void AddGeometricToolsForComputerGraphicsSuite();
		void AddProceduralElementsForComputerGraphicsSuite();
	};
}

#endif // BOOK_GEOMETRY_TESTING_HELPER_H