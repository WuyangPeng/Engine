///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/20 16:20)

#ifndef PHYSICS_TESTING_TESTING_HELPER_H
#define PHYSICS_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace Physics
{
    class TestingHelper : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddMacroSuite();
        void AddCollisionDetectionSuite();
        void AddFluidSuite();
        void AddIntersectionSuite();
        void AddLCPSolverSuite();
        void AddParticleSystemSuite();
        void AddRigidBodySuite();
        void AddMiscellaneousSuite();
    };
}

#endif  // PHYSICS_TESTING_TESTING_HELPER_H