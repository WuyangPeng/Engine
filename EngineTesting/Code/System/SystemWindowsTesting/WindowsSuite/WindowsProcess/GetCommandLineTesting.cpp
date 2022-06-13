///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/16 14:43)

#include "GetCommandLineTesting.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetCommandLineTesting::GetCommandLineTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetCommandLineTesting)

void System::GetCommandLineTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetCommandLineTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetCommandLineTest);
}

void System::GetCommandLineTesting::GetCommandLineTest()
{
    MAYBE_UNUSED auto command = GetSystemCommandLine();
}
