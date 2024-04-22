/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 15:03)

#include "GameErrorTesting.h"
#include "Detail/GameErrorType.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Exception/GameErrorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::GameErrorTesting::GameErrorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, GameErrorTesting)

void CoreTools::GameErrorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::GameErrorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LastErrorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ComErrorTest);
}

void CoreTools::GameErrorTesting::LastErrorTest()
{
    const LastError lastError{};
    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;
    const auto message = SYSTEM_TEXT("message"s);
    constexpr auto gameErrorType = GameErrorType::Error;
    const GameError gameError{ functionDescribed, lastError, gameErrorType, message };

    ASSERT_EQUAL(functionDescribed.GetCurrentFunction(), gameError.GetCurrentFunction());
    ASSERT_EQUAL(functionDescribed.GetFileName(), gameError.GetFileName());
    ASSERT_EQUAL(functionDescribed.GetLine(), gameError.GetLine());

    ASSERT_EQUAL(functionDescribed, gameError.GetFunctionDescribed());

    ASSERT_EQUAL(gameErrorType, gameError.GetErrorCode());

    ASSERT_UNEQUAL(gameError.GetError().find(message), System::String::npos);
}

void CoreTools::GameErrorTesting::ComErrorTest()
{
    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;
    const auto message = SYSTEM_TEXT("message"s);
    constexpr auto gameErrorType = GameErrorType::Error;
    const GameError gameError{ functionDescribed, System::WindowError::EUnexpected, gameErrorType, message };

    ASSERT_EQUAL(functionDescribed.GetCurrentFunction(), gameError.GetCurrentFunction());
    ASSERT_EQUAL(functionDescribed.GetFileName(), gameError.GetFileName());
    ASSERT_EQUAL(functionDescribed.GetLine(), gameError.GetLine());

    ASSERT_EQUAL(functionDescribed, gameError.GetFunctionDescribed());

    ASSERT_EQUAL(gameErrorType, gameError.GetErrorCode());

    ASSERT_UNEQUAL(gameError.GetError().find(message), System::String::npos);
}
