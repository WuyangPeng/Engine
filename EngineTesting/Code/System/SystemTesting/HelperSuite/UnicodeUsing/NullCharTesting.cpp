/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/07 15:23)

#include "NullCharTesting.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::NullCharTesting::NullCharTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, NullCharTesting)

void System::NullCharTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::NullCharTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullCharTest);
}

void System::NullCharTesting::NullCharTest()
{
    ASSERT_EQUAL(nullChar, SYSTEM_TEXT('\0'));
}
