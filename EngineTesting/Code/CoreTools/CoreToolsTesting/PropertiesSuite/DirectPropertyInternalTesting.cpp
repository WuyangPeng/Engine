/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:55)

#include "DirectPropertyInternalTesting.h"
#include "Detail/DirectPropertyInternal.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::DirectPropertyInternalTesting::DirectPropertyInternalTesting(const OStreamShared& stream)
    : ParentType{ stream }, getType{ "Init" }, setType{ "SetType" }
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
    ASSERT_NOT_THROW_EXCEPTION_0(GetTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetValueTest);
}

void CoreTools::DirectPropertyInternalTesting::GetTypeTest()
{
    const DirectPropertyInternal directPropertyInternal{ getType, setType };

    const std::string value{ directPropertyInternal.getType };

    ASSERT_EQUAL(value, getType);
}

void CoreTools::DirectPropertyInternalTesting::SetValueTest()
{
    DirectPropertyInternal directPropertyInternal{ getType, setType };

    const std::string setValue{ "set" };

    directPropertyInternal.SetValue(setValue);

    const std::string value{ directPropertyInternal.getType };

    ASSERT_EQUAL(value, setValue);
}

void CoreTools::DirectPropertyInternalTesting::GetValueTest()
{
    DirectPropertyInternal directPropertyInternal{ getType, setType };

    ASSERT_EQUAL(setType, directPropertyInternal.GetValue());

    const std::string setValue{ "set" };
    directPropertyInternal.setType = setValue;

    ASSERT_EQUAL(setValue, directPropertyInternal.GetValue());
}
