/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/05/28 11:09)

#include "PropertyExternalTesting.h"
#include "Detail/PropertyExternal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Properties/PropertyGetExternalDetail.h"
#include "CoreTools/Properties/PropertyGetSetExternalDetail.h"
#include "CoreTools/Properties/PropertySetExternalDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::PropertyExternalTesting::PropertyExternalTesting(const OStreamShared& stream)
    : ParentType{ stream }, setValue{ "set" }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, PropertyExternalTesting)

void CoreTools::PropertyExternalTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::PropertyExternalTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSet0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetSet1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GetSet2Test);
}

void CoreTools::PropertyExternalTesting::GetSet0Test()
{
    const PropertyExternal simplePropertyExternal{};

    const std::string value{ simplePropertyExternal.getType };

    ASSERT_TRUE(value.empty());
}

void CoreTools::PropertyExternalTesting::GetSet1Test()
{
    PropertyExternal simplePropertyExternal{};

    simplePropertyExternal.setType = setValue;

    const std::string value{ simplePropertyExternal.getSetType };

    ASSERT_EQUAL(value, setValue);
}

void CoreTools::PropertyExternalTesting::GetSet2Test()
{
    PropertyExternal simplePropertyExternal{};
    simplePropertyExternal.getSetType = setValue + setValue;

    const std::string value{ simplePropertyExternal.getType };

    ASSERT_EQUAL(value, setValue + setValue);
}
