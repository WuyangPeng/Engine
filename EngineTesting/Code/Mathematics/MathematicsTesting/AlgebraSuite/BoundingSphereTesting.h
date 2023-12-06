/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/06 09:31)

#ifndef MATHEMATICS_ALGEBRA_SUITE_BOUNDING_SPHERE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_BOUNDING_SPHERE_TESTING_H

#include "Detail/TransformTool.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Algebra/BoundingSphere.h"

namespace Mathematics
{
    class BoundingSphereTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = BoundingSphereTesting;
        using ParentType = UnitTest;

    public:
        explicit BoundingSphereTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();
        void DefaultTest();
        NODISCARD bool ModifyTest();
        NODISCARD bool InsideTest();
        NODISCARD bool NegativeSideTest();
        NODISCARD bool PositiveSideTest();
        NODISCARD bool GrowToContainTest();
        NODISCARD bool TransformByTest();
        NODISCARD bool ComputeFromAPointTest();
        NODISCARD bool ComputeFromVector3Test();
        NODISCARD bool ComputeFromDataTest();
        NODISCARD bool StreamTest();
        NODISCARD bool LineIntersectionTest();
        NODISCARD bool LineNonIntersectionTest();
        NODISCARD bool RayIntersectionTest();
        NODISCARD bool RayNonIntersectionTest();
        NODISCARD bool SegmentIntersectionTest();
        NODISCARD bool SegmentNonIntersectionTest();
        NODISCARD bool BoundingSphereStaticTest();
        NODISCARD bool BoundingSphereVelocityTest();

    private:
        using APointFApproximateFunction = bool (*)(const APointF& lhs, const APointF& rhs, float epsilon) noexcept;
        using BoundingSphereFApproximateFunction = bool (*)(const BoundingSphereF& lhs, const BoundingSphereF& rhs, float epsilon);

        using APointDApproximateFunction = bool (*)(const APointD& lhs, const APointD& rhs, double epsilon) noexcept;
        using BoundingSphereDApproximateFunction = bool (*)(const BoundingSphereD& lhs, const BoundingSphereD& rhs, double epsilon);

    private:
        TransformTool transformTool;

        APointFApproximateFunction aPointFApproximateFunction;
        BoundingSphereFApproximateFunction boundingSphereFApproximateFunction;

        APointDApproximateFunction aPointDApproximateFunction;
        BoundingSphereDApproximateFunction boundingSphereDApproximateFunction;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_BOUNDING_SPHERE_TESTING_H