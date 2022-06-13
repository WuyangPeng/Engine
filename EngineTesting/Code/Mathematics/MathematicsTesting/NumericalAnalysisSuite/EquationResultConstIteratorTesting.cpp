///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/02 17:13)

#include "EquationResultConstIteratorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIteratorDetail.h"

#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, EquationResultConstIteratorTesting)

void Mathematics::EquationResultConstIteratorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DereferenceTest);
}

void Mathematics::EquationResultConstIteratorTesting::DereferenceTest()
{
    using IntVector = vector<size_t>;
    using IntVectorConstIter = IntVector::const_iterator;

    IntVector firstIntVector;

    for (size_t i = 0; i < 10; ++i)
    {
        firstIntVector.emplace_back(i);
    }

    EquationResultConstIterator<IntVectorConstIter> iter(firstIntVector.begin());
    const EquationResultConstIterator<IntVectorConstIter> end(firstIntVector.end());

    size_t i = 0;
    for (; iter != end; ++iter)
    {
        ASSERT_EQUAL(*iter, i);
        ++i;
    }
}
