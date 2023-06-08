///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/02 17:13)

#include "EquationResultConstIteratorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIteratorDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
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
