/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:42)

#include "TypeAliasTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/TypeAlias.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::TypeAliasTesting::TypeAliasTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TypeAliasTesting)

void CoreTools::TypeAliasTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::TypeAliasTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TypeAliasTest);
}

void CoreTools::TypeAliasTesting::TypeAliasTest()
{
    constexpr auto value = 10;
    const TypeAlias<int32_t, uint32_t> typeAlias{ value };

    ASSERT_EQUAL(typeAlias.Get(), boost::numeric_cast<uint32_t>(value));
}
