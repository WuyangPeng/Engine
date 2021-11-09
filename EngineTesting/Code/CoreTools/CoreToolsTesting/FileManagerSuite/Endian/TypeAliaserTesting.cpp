///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/03 16:23)

#include "TypeAliaserTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/TypeAliaser.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::TypeAliaserTesting::TypeAliaserTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TypeAliaserTesting)

void CoreTools::TypeAliaserTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::TypeAliaserTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TypeAliaserTest);
}

void CoreTools::TypeAliaserTesting::TypeAliaserTest()
{
    constexpr auto value = 10;
    const TypeAliaser<int32_t, uint32_t> typeAliaser{ value };

    ASSERT_EQUAL(typeAliaser.Get(), boost::numeric_cast<uint32_t>(value));
}
