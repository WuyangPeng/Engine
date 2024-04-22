/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/15 09:58)

#include "NoexceptLogTesting.h"
#include "System/Helper/Tools.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Contract/NoexceptLog.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::NoexceptLogTesting::NoexceptLogTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NoexceptLogTesting)

void CoreTools::NoexceptLogTesting::PrintTipsMessage()
{
    GetStream() << "这个测试会触发Noexcept警告断言，请按否取消。\n";

    System::SystemPause();
}

void CoreTools::NoexceptLogTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::NoexceptLogTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NoexceptUseLogTest);
}

void CoreTools::NoexceptLogTesting::NoexceptUseLogTest()
{
    NoexceptNoReturnUseLog(*this, &ClassType::Function0);
    NoexceptNoReturnUseLog(*this, &ClassType::Function1, 0);
    ASSERT_EQUAL(NoexceptUseLog<int>(*this, &ClassType::Function2, 0), 0);
    ASSERT_EQUAL((NoexceptUseLog<int>(*this, &ClassType::Function3, 3, 1)), 3);

    NoexceptNoReturnUseLog(*this, &ClassType::ConstFunction0);
    NoexceptNoReturnUseLog(*this, &ClassType::ConstFunction1, 0);
    ASSERT_EQUAL(NoexceptUseLog<int>(*this, &ClassType::ConstFunction2, 0), 0);
    ASSERT_EQUAL((NoexceptUseLog<int>(*this, &ClassType::ConstFunction3, 2, 1)), 2);

    StaticNoexceptNoReturnUseLog(&ClassType::StaticFunction0);
    StaticNoexceptNoReturnUseLog(&ClassType::StaticFunction1, 2);
    ASSERT_EQUAL(StaticNoexceptUseLog<int>(&ClassType::StaticFunction2, 0), 0);
    ASSERT_EQUAL((StaticNoexceptUseLog<int>(&ClassType::StaticFunction3, 4, 1)), 4);
}

void CoreTools::NoexceptLogTesting::Function0()
{
    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s));
}

void CoreTools::NoexceptLogTesting::Function1(int parameter)
{
    System::UnusedFunction(parameter);

    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

int CoreTools::NoexceptLogTesting::Function2()
{
    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

int CoreTools::NoexceptLogTesting::Function3(int parameter)
{
    System::UnusedFunction(parameter);

    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

void CoreTools::NoexceptLogTesting::ConstFunction0() const
{
    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

void CoreTools::NoexceptLogTesting::ConstFunction1(int parameter) const
{
    System::UnusedFunction(parameter);

    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

int CoreTools::NoexceptLogTesting::ConstFunction2() const
{
    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

int CoreTools::NoexceptLogTesting::ConstFunction3(int parameter) const
{
    System::UnusedFunction(parameter);

    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

void CoreTools::NoexceptLogTesting::StaticFunction0()
{
    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

void CoreTools::NoexceptLogTesting::StaticFunction1(int parameter)
{
    System::UnusedFunction(parameter);

    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

int CoreTools::NoexceptLogTesting::StaticFunction2()
{
    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

int CoreTools::NoexceptLogTesting::StaticFunction3(int parameter)
{
    System::UnusedFunction(parameter);

    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}
