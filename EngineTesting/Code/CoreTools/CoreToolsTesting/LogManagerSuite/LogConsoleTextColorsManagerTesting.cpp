///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:10)

#include "LogConsoleTextColorsManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"

using std::cerr;
using std::cout;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogConsoleTextColorsManagerTesting)

void CoreTools::LogConsoleTextColorsManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ErrorConsoleTextColorsManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OutputConsoleTextColorsManagerTest);
}

void CoreTools::LogConsoleTextColorsManagerTesting::ErrorConsoleTextColorsManagerTest()
{
    LogConsoleTextColorsManager firstManager{ LogLevel::Error };

    CERR << SYSTEM_TEXT("������Ϣ�ڿ���̨��ʾΪ��ɫ��\n");

    LogConsoleTextColorsManager secondManager{ OStreamShared{ false }, LogLevel::Warn };

    cerr << "������Ϣ�ڿ���̨��ʾΪ��ɫ��\n";
}

void CoreTools::LogConsoleTextColorsManagerTesting::OutputConsoleTextColorsManagerTest()
{
    LogConsoleTextColorsManager firstManager{ LogLevel::Debug };

    COUT << SYSTEM_TEXT("������Ϣ�ڿ���̨��ʾΪ��ɫ��\n");

    LogConsoleTextColorsManager secondManager{ OStreamShared{ true }, LogLevel::Info };

    cout << "������Ϣ�ڿ���̨��ʾΪ��ɫ��\n";
}
