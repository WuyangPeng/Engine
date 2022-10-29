///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/02 22:07)

#ifndef RENDERING_STATE_SUITE_BLEND_STATE_TARGET_TESTING_H
#define RENDERING_STATE_SUITE_BLEND_STATE_TARGET_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Rendering/State/BlendStateTarget.h"
#include "Rendering/State/StateFwd.h"

namespace Rendering
{
    class BlendStateTargetTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = BlendStateTargetTesting;
        using ParentType = UnitTest;

    public:
        explicit BlendStateTargetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void ConstructorTest();
        void SetEnableTest();
        void SetSourceColorTest();
        void SetDestinationColorTest();
        void SetOperationColorTest();
        void SetSourceAlphaTest();
        void SetDestinationAlphaTest();
        void SetOperationAlphaTest();
        void SetMaskTest();

        void GetStreamingSizeTest();

        void BlendStateTargetTest();

        void BlendStateTargetValueTest();
        void BlendStateTargetSaveTest();

        void EqualTest();

    private:
        bool enable;
        BlendStateMode sourceColor;
        BlendStateMode destinationColor;
        BlendStateOperation operationColor;
        BlendStateMode sourceAlpha;
        BlendStateMode destinationAlpha;
        BlendStateOperation operationAlpha;
        BlendStateColorWrite mask;
        BlendStateTarget blendStateTarget;
    };
}

#endif  // RENDERING_STATE_SUITE_BLEND_STATE_TARGET_TESTING_H