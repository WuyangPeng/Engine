///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:37)

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

CoreTools::LogConsoleTextColorsManagerFactory::LogConsoleTextColorsManagerPtr CoreTools::LogConsoleTextColorsManagerFactory::Create(const OStreamShared& streamShared, LogLevel logLevel)
{
    if (streamShared.IsCout())
        return make_shared<OutputConsoleTextColorsManager>(logLevel);
    else if (streamShared.IsCerr())
        return make_shared<ErrorConsoleTextColorsManager>(logLevel);
    else
        return make_shared<LogConsoleTextColorsManagerImpl>(logLevel);
}
