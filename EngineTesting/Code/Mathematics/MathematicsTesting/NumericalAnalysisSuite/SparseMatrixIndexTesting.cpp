///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/03 16:25)

#include "SparseMatrixIndexTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixIndex.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
Mathematics::SparseMatrixIndexTesting::SparseMatrixIndexTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, SparseMatrixIndexTesting)

void Mathematics::SparseMatrixIndexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::SparseMatrixIndexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
}

void Mathematics::SparseMatrixIndexTesting::OperatorTest()
{
    const SparseMatrixIndex firstIndex(5, 6);
    const SparseMatrixIndex secondIndex(2, 6);
    const SparseMatrixIndex thirdIndex(7, 6);
    const SparseMatrixIndex fourthIndex(5, 4);

    ASSERT_FALSE(firstIndex < firstIndex);
    ASSERT_FALSE(secondIndex < secondIndex);
    ASSERT_FALSE(thirdIndex < thirdIndex);
    ASSERT_FALSE(fourthIndex < fourthIndex);

    ASSERT_TRUE(secondIndex < firstIndex);
    ASSERT_TRUE(firstIndex < thirdIndex);
    ASSERT_TRUE(fourthIndex < firstIndex);
}
