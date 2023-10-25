///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:43)

#include "DirectPropertyInternalTesting.h"
#include "Detail/DirectPropertyInternal.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::DirectPropertyInternalTesting::DirectPropertyInternalTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DirectPropertyInternalTesting)

void CoreTools::DirectPropertyInternalTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::DirectPropertyInternalTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSetTest);
}

void CoreTools::DirectPropertyInternalTesting::GetSetTest()
{
    DirectPropertyInternal directPropertyInternal{ DisableNotThrow::Disable };

    std::string value{ directPropertyInternal.getType };

    ASSERT_EQUAL(value, "Init");

    const std::string setValue{ "set" };

    directPropertyInternal.SetValue(setValue);

    value = directPropertyInternal.getType;

    ASSERT_EQUAL(value, setValue);

    ASSERT_EQUAL("SetType", directPropertyInternal.GetValue());

    directPropertyInternal.setType = setValue;

    ASSERT_EQUAL(setValue, directPropertyInternal.GetValue());
}
