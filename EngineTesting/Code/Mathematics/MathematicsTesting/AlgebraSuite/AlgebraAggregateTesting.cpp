///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 18:15)

#include "AlgebraAggregateTesting.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
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

using std::default_random_engine;
using std::make_shared;
using std::uniform_int;
using std::uniform_real;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, AlgebraAggregateTesting)

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