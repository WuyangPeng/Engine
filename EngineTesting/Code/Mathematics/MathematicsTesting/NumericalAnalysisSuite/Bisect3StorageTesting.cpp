///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/02 16:37)

#include "Bisect3StorageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect3Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
Mathematics::Bisect3StorageTesting::Bisect3StorageTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Bisect3StorageTesting)

void Mathematics::Bisect3StorageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Bisect3StorageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TestValuesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetStorageValueTest);
}

void Mathematics::Bisect3StorageTesting::TestValuesTest() noexcept
{
}

void Mathematics::Bisect3StorageTesting::SetStorageValueTest() noexcept
{
}
