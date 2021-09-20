// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/05 17:34)

#include "LogConsoleTextColorsManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"

using std::cout;
using std::cerr;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogConsoleTextColorsManagerTesting)

void CoreTools::LogConsoleTextColorsManagerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ErrorConsoleTextColorsManagerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OutputConsoleTextColorsManagerTest);
}

void CoreTools::LogConsoleTextColorsManagerTesting
	::ErrorConsoleTextColorsManagerTest()
{
	LogConsoleTextColorsManager firstManager{ LogLevel::Error };

	CERR << SYSTEM_TEXT("������Ϣ�ڿ���̨��ʾΪ��ɫ��\n");

	LogConsoleTextColorsManager secondManager{ OStreamShared{false},LogLevel::Warn };

	cerr << "������Ϣ�ڿ���̨��ʾΪ��ɫ��\n";
}

void CoreTools::LogConsoleTextColorsManagerTesting
	::OutputConsoleTextColorsManagerTest()
{
	LogConsoleTextColorsManager firstManager{ LogLevel::Debug };

	COUT << SYSTEM_TEXT("������Ϣ�ڿ���̨��ʾΪ��ɫ��\n");

	LogConsoleTextColorsManager secondManager{ OStreamShared{}, LogLevel::Info };

	cout << "������Ϣ�ڿ���̨��ʾΪ��ɫ��\n";
}





