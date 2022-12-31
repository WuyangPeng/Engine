///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/30 14:54)

#include "StrstrTesting.h"
#include "System/CharacterString/FormatString.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::StrstrTesting::StrstrTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StrstrTesting)

void System::StrstrTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StrstrTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StrstrTest);
}

void System::StrstrTesting::StrstrTest()
{
    auto str = "asubStra";
    auto subStr = "subStr";

    auto result = Strstr(str, subStr);

    ASSERT_UNEQUAL_NULL_PTR(result);

    result = Strstr(subStr, str);

    ASSERT_EQUAL_NULL_PTR(result);
}
