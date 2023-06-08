///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/03 16:25)

#include "SolveSymmetricConjugateGradientTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

Mathematics::SolveSymmetricConjugateGradientTesting::SolveSymmetricConjugateGradientTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, SolveSymmetricConjugateGradientTesting)

void Mathematics::SolveSymmetricConjugateGradientTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::SolveSymmetricConjugateGradientTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VariableMatrixTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SparseMatrixTest);
}

void Mathematics::SolveSymmetricConjugateGradientTesting::VariableMatrixTest() noexcept
{
}

void Mathematics::SolveSymmetricConjugateGradientTesting::SparseMatrixTest() noexcept
{
}
