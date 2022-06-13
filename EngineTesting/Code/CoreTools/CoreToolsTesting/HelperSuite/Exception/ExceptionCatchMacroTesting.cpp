///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:25)

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
        THROW_EXCEPTION(SYSTEM_TEXT("��������׳��쳣����������"));
    }
    EXCEPTION_ENGINE_EXCEPTION_CATCH(CoreTools)
    EXCEPTION_STD_EXCEPTION_CATCH(CoreTools)
    EXCEPTION_UNKOWN_CATCH(CoreTools)
}

void CoreTools::ExceptionCatchMacroTesting::Catch1Test()
{
    EXCEPTION_TRY
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��������׳��쳣����������"));
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::ExceptionCatchMacroTesting::Catch2Test()
{
    EXCEPTION_TRY
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��������׳��쳣����������"));
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

void CoreTools::ExceptionCatchMacroTesting::Catch3Test()
{
    EXCEPTION_TRY
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��������׳��쳣����������"));
    }
    EXCEPTION_WINDOWS_ENTRY_POINT_CATCH
}
