// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/09 19:22)

#ifndef ANIMATION_TESTING_TESTING_HELPER_H
#define ANIMATION_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace CoreTools
{
    class Suite;
}

namespace Animation
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
        void AddConsoleGraphSuite();
        void AddElfAnimationSuite();
        void AddTextureAnimationSuite();
        void AddRigidBodyHierarchyAnimationSuite();
        void AddSkeletonAnimationSuite();
        void AddPerVertexAnimationSuite();
        void AddMorphTargetAnimationSuite();
        void AddGradientAnimationSuite();
        void AddAnimationManagerSuite();
    };
}

#endif  // ANIMATION_TESTING_TESTING_HELPER_H