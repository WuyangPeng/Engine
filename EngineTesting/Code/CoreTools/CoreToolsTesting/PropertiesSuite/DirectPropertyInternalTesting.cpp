///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 13:46)

#include "DirectPropertyInternalTesting.h"
#include "Detail/DirectPropertyInternal.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, DirectPropertyInternalTesting)

void CoreTools::DirectPropertyInternalTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSetTest);
}

void CoreTools::DirectPropertyInternalTesting::GetSetTest()
{
    DirectPropertyInternal directPropertyInternal{ DisableNotThrow::Disable };

    string value{ directPropertyInternal.getType };

    ASSERT_EQUAL(value, "Init");

    string setValue{ "set" };

    directPropertyInternal.SetValue(setValue);

    value = directPropertyInternal.getType;

    ASSERT_EQUAL(value, setValue);

    ASSERT_EQUAL("SetType", directPropertyInternal.GetValue());

    directPropertyInternal.setType = setValue;

    ASSERT_EQUAL(setValue, directPropertyInternal.GetValue());
}
