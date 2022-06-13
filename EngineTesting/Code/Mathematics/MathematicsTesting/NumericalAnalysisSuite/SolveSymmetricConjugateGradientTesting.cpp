///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/03 16:25)

#include "SolveSymmetricConjugateGradientTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, SolveSymmetricConjugateGradientTesting)

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
