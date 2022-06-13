///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 17:52)

#ifndef MATHEMATICS_ALGEBRA_SUITE_ALGEBRA_AGGREGATE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_ALGEBRA_AGGREGATE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class AlgebraAggregateTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AlgebraAggregateTesting);

    private:
        void MainTest();
        void HomogeneousPointTest() noexcept;
        void Vector2Test() noexcept;
        void Vector3Test() noexcept;
        void Vector4Test() noexcept;
        void AVectorTest() noexcept;
        void APointTest() noexcept;
        void VariableLengthVectorTest() noexcept;
        void PlaneTest() noexcept;
        void PolynomialTest() noexcept;
        void Matrix2Test() noexcept;
        void Matrix3Test() noexcept;
        void Matrix4Test() noexcept;
        void MatrixTest() noexcept;
        void VariableMatrixTest() noexcept;
        void BandedMatrixTest() noexcept;
        void BandedMatrixSolveTest() noexcept;
        void QuaternionTest() noexcept;
        void AQuaternionTest() noexcept;
        void Float1Test() noexcept;
        void Float2Test() noexcept;
        void Float3Test() noexcept;
        void Float4Test() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_QUATERN_SWING_TWIST_TESTING_H