///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:02)

#include "EquationResultConstIteratorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIteratorDetail.h"

#include <vector>

using std::vector;
Mathematics::EquationResultConstIteratorTesting::EquationResultConstIteratorTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EquationResultConstIteratorTesting)

void Mathematics::EquationResultConstIteratorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
