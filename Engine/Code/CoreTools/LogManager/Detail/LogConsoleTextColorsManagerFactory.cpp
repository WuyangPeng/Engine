//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/15 18:35)

#include "CoreTools/CoreToolsExport.h"

#include "ErrorConsoleTextColorsManager.h"
#include "LogConsoleTextColorsManagerFactory.h"
#include "LogConsoleTextColorsManagerImpl.h"
#include "OutputConsoleTextColorsManager.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"

#include <iostream>

using std::cerr;
using std::cout;
using std::make_shared;
using std::ostream;

CoreTools::LogConsoleTextColorsManagerFactory::LogConsoleTextColorsManagerPtr CoreTools::LogConsoleTextColorsManagerFactory::Create(LogLevel logLevel)
{
    if (logLevel == LogLevel::Error || logLevel == LogLevel::Fatal)
        return make_shared<ErrorConsoleTextColorsManager>(logLevel);
    else
        return make_shared<OutputConsoleTextColorsManager>(logLevel);
}

CoreTools::LogConsoleTextColorsManagerFactory::LogConsoleTextColorsManagerPtr CoreTools::LogConsoleTextColorsManagerFactory::Create(const OStreamShared& osPtr, LogLevel logLevel)
{
    if (osPtr.IsCout())
        return make_shared<OutputConsoleTextColorsManager>(logLevel);
    else if (osPtr.IsCerr())
        return make_shared<ErrorConsoleTextColorsManager>(logLevel);
    else
        return make_shared<LogConsoleTextColorsManagerImpl>(logLevel);
}
