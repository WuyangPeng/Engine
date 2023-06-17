///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:08)

#include "SolveSymmetricConjugateGradientTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixDetail.h"

#include <random>

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
