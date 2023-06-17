///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:25)

#ifndef FRAMEWORK_APPLICATION_SUITE_OBJECT_MOTION_TESTING_H
#define FRAMEWORK_APPLICATION_SUITE_OBJECT_MOTION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Framework
{
    class ObjectMotionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ObjectMotionTesting;
        using ParentType = UnitTest;
        using Matrixf = Mathematics::MatrixF;
        using AVectorf = Mathematics::AVectorF;

    public:
        explicit ObjectMotionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void NoParentMoveObjectTest() noexcept;
        void ParentMoveObjectTest() noexcept;
        void TrackBallDownTest() noexcept;
        void NoParentRotateTrackBallTest() noexcept;
        void ParentRotateTrackBallTest() noexcept;

        void AssertRotate(const Matrixf& lhs, const Matrixf& rhs);

        NODISCARD AVectorf GetSphereVector(float x, float y) const noexcept(gAssert < 3 || gMathematicsAssert < 3);
    };
}

#endif  // FRAMEWORK_APPLICATION_SUITE_OBJECT_MOTION_TESTING_H
