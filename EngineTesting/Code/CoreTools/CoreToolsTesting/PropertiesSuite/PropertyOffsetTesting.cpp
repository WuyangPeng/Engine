///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 13:46)

#include "PropertyOffsetTesting.h"
#include "Detail/PropertyOffset.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::PropertyOffsetTesting::PropertyOffsetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, PropertyOffsetTesting)

void CoreTools::PropertyOffsetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::PropertyOffsetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetTest);
}

void CoreTools::PropertyOffsetTesting::GetTest()
{
    const PropertyOffset propertyOffset{ DisableNotThrow::Disable };

    const std::string offset{ propertyOffset.offset };

    ASSERT_EQUAL(offset, "Value");
    ASSERT_EQUAL(propertyOffset.GetInternalValue(), "Offset");
}
