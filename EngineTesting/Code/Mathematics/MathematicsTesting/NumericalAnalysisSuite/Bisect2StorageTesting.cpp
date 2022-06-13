///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/02 16:21)

#include "Bisect2StorageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect2Detail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Bisect2StorageTesting)

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
 
