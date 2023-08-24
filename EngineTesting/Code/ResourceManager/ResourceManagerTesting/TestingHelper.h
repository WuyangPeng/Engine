///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/02 14:37)

#ifndef RESOURCE_MANAGER_TESTING_TESTING_HELPER_H
#define RESOURCE_MANAGER_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace ResourceManager
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

        void AddHelperSuite();
        void AddThreeDimensionalModelSuite();
        void AddTextureSuite();
        void AddMaterialSuite();
        void AddFontSuite();
        void AddSkeletonSuite();
        void AddCollisionSuite();
        void AddPhysicalParametersSuite();
        void AddGameWorldMapSuite();
        void AddMiscellaneousSuite();
    };
}

#endif  // RESOURCE_MANAGER_TESTING_TESTING_HELPER_H