///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:00)

#include "Bisect2StorageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect2Detail.h"

Mathematics::Bisect2StorageTesting::Bisect2StorageTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Bisect2StorageTesting)

void Mathematics::Bisect2StorageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Bisect2StorageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TestValuesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetStorageValueTest);
}

void Mathematics::Bisect2StorageTesting::TestValuesTest() noexcept
{
}

void Mathematics::Bisect2StorageTesting::SetStorageValueTest() noexcept
{
}
