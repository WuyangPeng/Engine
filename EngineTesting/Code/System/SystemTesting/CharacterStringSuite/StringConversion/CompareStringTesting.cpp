///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:16)

#include "CompareStringTesting.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CompareStringTesting::CompareStringTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CompareStringTesting)

void System::CompareStringTesting::CompareTest(ComparesStringReturn lhs, ComparesStringReturn rhs)
{
    switch (lhs)
    {
        case ComparesStringReturn::LessThan:
            ASSERT_ENUM_EQUAL(ComparesStringReturn::GreaterThan, rhs);
            break;
        case ComparesStringReturn::GreaterThan:
            ASSERT_ENUM_EQUAL(ComparesStringReturn::LessThan, rhs);
            break;
        default:
            ASSERT_ENUM_EQUAL(lhs, rhs);
            break;
    }
}
