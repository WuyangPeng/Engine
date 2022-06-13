///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/10 16:47)

#ifndef RESOURCE_MANAGER_TESTING_TESTING_HELPER_H
#define RESOURCE_MANAGER_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace ResourceManager
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