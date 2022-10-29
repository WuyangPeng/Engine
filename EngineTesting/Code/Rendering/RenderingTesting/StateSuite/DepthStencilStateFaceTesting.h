///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/04 16:07)

#ifndef RENDERING_STATE_SUITE_DEPTH_STENCIL_STATE_FACE_TESTING_H
#define RENDERING_STATE_SUITE_DEPTH_STENCIL_STATE_FACE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Rendering/State/DepthStencilStateFace.h"
#include "Rendering/State/StateFwd.h"

namespace Rendering
{
    class DepthStencilStateFaceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DepthStencilStateFaceTesting;
        using ParentType = UnitTest;

    public:
        explicit DepthStencilStateFaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void ConstructorTest();
        void SetFailTest();
        void SetDepthFailTest();
        void SetPassTest();
        void SetComparisonTest();

        void DepthStencilStateFaceTest();

        void DepthStencilStateFaceValueTest();
        void DepthStencilStateFaceSaveTest();

        void GetStreamingSizeTest();

        void EqualTest();

    private:
        DepthStencilStateOperation fail;
        DepthStencilStateOperation depthFail;
        DepthStencilStateOperation pass;
        DepthStencilStateComparison comparison;
        DepthStencilStateFace depthStencilStateFace;
    };
}

#endif  // RENDERING_STATE_SUITE_DEPTH_STENCIL_STATE_FACE_TESTING_H