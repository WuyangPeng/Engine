///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/23 11:14)

#include "OutputDebugStringTesting.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OutputDebugStringTesting::OutputDebugStringTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OutputDebugStringTesting)

void System::OutputDebugStringTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OutputDebugStringTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OutputCharToDebugTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OutputWCharToDebugTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OutputTCharToDebugTest);
}

void System::OutputDebugStringTesting::OutputCharToDebugTest() noexcept
{
    OutputDebugStringWithChar("������Ϣ��������Դ��ڡ�\n");
}

void System::OutputDebugStringTesting::OutputWCharToDebugTest() noexcept
{
    OutputDebugStringWithWChar(L"������Ϣ��������Դ��ڡ�\n");
}

void System::OutputDebugStringTesting ::OutputTCharToDebugTest() noexcept
{
    OutputDebugStringWithTChar(SYSTEM_TEXT("������Ϣ��������Դ��ڡ�\n"));
}
