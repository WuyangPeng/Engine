///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 11:10)

#ifndef MATHEMATICS_ALGEBRA_SUITE_ALGEBRA_AGGREGATE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_ALGEBRA_AGGREGATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class AlgebraAggregateTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = AlgebraAggregateTesting;
        using ParentType = UnitTest;

    public:
        explicit AlgebraAggregateTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

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