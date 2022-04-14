// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/02 13:08)

#ifndef RESOURCE_MANAGER_TESTING_TESTING_HELPER_H
#define RESOURCE_MANAGER_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace CoreTools
{
    class Suite;
}

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