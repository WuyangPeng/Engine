/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 10:00)

#include "PtrToIntTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::PtrToIntTesting::PtrToIntTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, PtrToIntTesting)

void System::PtrToIntTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::PtrToIntTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PtrToIntTest);
}

void System::PtrToIntTesting::PtrToIntTest()
{
    const int* ptr{ nullptr };
    const auto result = PtrConversionInt(ptr);

    ASSERT_EQUAL(result, 0);
}
