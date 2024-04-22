/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:23)

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
            ASSERT_EQUAL(ComparesStringReturn::GreaterThan, rhs);
            break;
        case ComparesStringReturn::GreaterThan:
            ASSERT_EQUAL(ComparesStringReturn::LessThan, rhs);
            break;
        default:
            ASSERT_EQUAL(lhs, rhs);
            break;
    }
}
