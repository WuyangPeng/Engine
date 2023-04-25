///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/12 15:07)

#include "LogConsoleTextColorsManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LogConsoleTextColorsManagerTesting::LogConsoleTextColorsManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogConsoleTextColorsManagerTesting)

void CoreTools::LogConsoleTextColorsManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void CoreTools::LogConsoleTextColorsManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ErrorConsoleTextColorsManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OutputConsoleTextColorsManagerTest);
}

void CoreTools::LogConsoleTextColorsManagerTesting::ErrorConsoleTextColorsManagerTest()
{
    LogConsoleTextColorsManager manager0{ LogLevel::Error };

    CERR << SYSTEM_TEXT("������Ϣ�ڿ���̨��ʾΪ��ɫ��\n");

    LogConsoleTextColorsManager manager1{ OStreamShared{ false }, LogLevel::Warn };

    std::cerr << "������Ϣ�ڿ���̨��ʾΪ��ɫ��\n";
}

void CoreTools::LogConsoleTextColorsManagerTesting::OutputConsoleTextColorsManagerTest()
{
    LogConsoleTextColorsManager manager0{ LogLevel::Debug };

    COUT << SYSTEM_TEXT("������Ϣ�ڿ���̨��ʾΪ��ɫ��\n");

    LogConsoleTextColorsManager manager1{ OStreamShared{ true }, LogLevel::Info };

    std::cout << "������Ϣ�ڿ���̨��ʾΪ��ɫ��\n";
}
