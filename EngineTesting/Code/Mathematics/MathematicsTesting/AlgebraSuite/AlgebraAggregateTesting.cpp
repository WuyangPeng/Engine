///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 11:15)

#include "AlgebraAggregateTesting.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Mathematics/Algebra/PolynomialDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"

#include <random>

Mathematics::AlgebraAggregateTesting::AlgebraAggregateTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, AlgebraAggregateTesting)

void Mathematics::AlgebraAggregateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::AlgebraAggregateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HomogeneousPointTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Vector2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Vector3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Vector4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AVectorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(APointTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VariableLengthVectorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PlaneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PolynomialTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Matrix2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Matrix3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Matrix4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(MatrixTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VariableMatrixTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BandedMatrixTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BandedMatrixSolveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(QuaternionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AQuaternionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Float1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Float2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Float3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Float4Test);
}

void Mathematics::AlgebraAggregateTesting::HomogeneousPointTest() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::Vector2Test() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::Vector3Test() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::Vector4Test() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::AVectorTest() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::APointTest() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::VariableLengthVectorTest() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::PlaneTest() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::PolynomialTest() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::Matrix2Test() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::Matrix3Test() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::Matrix4Test() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::MatrixTest() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::VariableMatrixTest() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::BandedMatrixTest() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::BandedMatrixSolveTest() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::QuaternionTest() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::AQuaternionTest() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::Float1Test() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::Float2Test() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::Float3Test() noexcept
{
}

void Mathematics::AlgebraAggregateTesting::Float4Test() noexcept
{
}