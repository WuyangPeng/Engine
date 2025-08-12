/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:36)

#include "LiteralCastTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define LITERAL_CAST_COMPILE_ERROR

#undef LITERAL_CAST_COMPILE_ERROR

CoreTools::LiteralCastTesting::LiteralCastTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LiteralCastTesting)

void CoreTools::LiteralCastTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LiteralCastTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Int8CastTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UInt8CastTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UInt32CastTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Int64CastTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UInt64CastTest);
}

void CoreTools::LiteralCastTesting::Int8CastTest() noexcept
{
}

void CoreTools::LiteralCastTesting::UInt8CastTest() noexcept
{
}

void CoreTools::LiteralCastTesting::UInt32CastTest() noexcept
{
}

void CoreTools::LiteralCastTesting::Int64CastTest() noexcept
{ 
}

void CoreTools::LiteralCastTesting::UInt64CastTest() noexcept
{
}
