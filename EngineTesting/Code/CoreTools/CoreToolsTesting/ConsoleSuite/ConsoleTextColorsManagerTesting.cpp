///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 17:32)

#include "ConsoleTextColorsManagerTesting.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Console/ConsoleTextColorsManagerDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <iostream>

CoreTools::ConsoleTextColorsManagerTesting::ConsoleTextColorsManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ConsoleTextColorsManagerTesting)

void CoreTools::ConsoleTextColorsManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ConsoleTextColorsManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConsoleTextColorsManageTest);
}

void CoreTools::ConsoleTextColorsManagerTesting::ConsoleTextColorsManageTest()
{
    {
        ConsoleTextColorsManager<StandardHandle::Error> manager{ TextColour::Yellow, false };

        std::cerr << "������Ϣ�ڿ���̨����ʾΪ��ɫ��\n";
    }

    std::cerr << "������Ϣ�ڿ���̨����ʾΪ��ɫ��\n";
}
