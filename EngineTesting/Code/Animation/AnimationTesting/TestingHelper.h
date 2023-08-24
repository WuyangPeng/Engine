///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/01 20:04)

#ifndef ANIMATION_TESTING_TESTING_HELPER_H
#define ANIMATION_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace Animation
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
        void AddSpriteAnimationSuite();
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