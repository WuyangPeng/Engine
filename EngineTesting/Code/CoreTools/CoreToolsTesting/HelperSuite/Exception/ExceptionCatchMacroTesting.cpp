///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/20 14:01)

#include "ExceptionCatchMacroTesting.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ExceptionCatchMacroTesting::ExceptionCatchMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ExceptionCatchMacroTesting)

void CoreTools::ExceptionCatchMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ExceptionCatchMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Catch0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Catch1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Catch2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Catch3Test);
}

void CoreTools::ExceptionCatchMacroTesting::Catch0Test()
{
    EXCEPTION_TRY
    {
        THROW_EXCEPTION(SYSTEM_TEXT("这里测试抛出异常，并被捕获。"));
    }
    EXCEPTION_ENGINE_EXCEPTION_CATCH(CoreTools)
    EXCEPTION_STD_EXCEPTION_CATCH(CoreTools)
    EXCEPTION_UNKOWN_CATCH(CoreTools)
}

void CoreTools::ExceptionCatchMacroTesting::Catch1Test()
{
    EXCEPTION_TRY
    {
        THROW_EXCEPTION(SYSTEM_TEXT("这里测试抛出异常，并被捕获。"));
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::ExceptionCatchMacroTesting::Catch2Test()
{
    EXCEPTION_TRY
    {
        THROW_EXCEPTION(SYSTEM_TEXT("这里测试抛出异常，并被捕获。"));
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

void CoreTools::ExceptionCatchMacroTesting::Catch3Test()
{
    EXCEPTION_TRY
    {
        THROW_EXCEPTION(SYSTEM_TEXT("这里测试抛出异常，并被捕获。"));
    }
    EXCEPTION_WINDOWS_ENTRY_POINT_CATCH
}
