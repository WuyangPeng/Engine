/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 12:19)

#include "OutputDebugStringTesting.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OutputDebugStringTesting::OutputDebugStringTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

void System::OutputDebugStringTesting::OutputCharToDebugTest() const noexcept
{
    OutputDebugStringWithChar("������Ϣ��������Դ��ڡ�\n");
}

void System::OutputDebugStringTesting::OutputWCharToDebugTest() const noexcept
{
    OutputDebugStringWithWChar(L"������Ϣ��������Դ��ڡ�\n");
}

void System::OutputDebugStringTesting::OutputTCharToDebugTest() const noexcept
{
    OutputDebugStringWithTChar(SYSTEM_TEXT("������Ϣ��������Դ��ڡ�\n"));
}
