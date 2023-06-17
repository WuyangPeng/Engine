///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:56)

#ifndef RENDERING_DATA_TYPES_SUITE_BOUND_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_BOUND_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class BoundTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BoundTesting;
        using ParentType = UnitTest;

    public:
        explicit BoundTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void BaseTest() noexcept;
        void GrowToContainTest() noexcept;
        void TransformByTest() noexcept;
        void ComputeFromDataTest() noexcept;
        void LineIntersectionTest() noexcept;
        void BoundIntersectionTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_DATA_TYPES_SUITE_BOUND_TESTING_H