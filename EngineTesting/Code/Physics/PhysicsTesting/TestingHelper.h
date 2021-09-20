// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 16:31)

#ifndef PHYSICS_TESTING_TESTING_HELPER_H
#define PHYSICS_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace Physics
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 
	
		virtual int DoRun() override;	
		
	private:
                void AddSuites();
		
		void AddMacroSuite();
		void AddCollisionDetectionSuite();
		void AddFluidSuite();
		void AddIntersectionSuite();
		void AddLCPSolverSuite();
		void AddParticleSystemSuite();
		void AddRigidBodySuite();
		void AddMiscellaneousSuite();

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // PHYSICS_TESTING_TESTING_HELPER_H