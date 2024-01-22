/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:41)

#include "CoreTools/CoreToolsExport.h"

#include "ErrorConsoleTextColorsManager.h"
#include "LogConsoleTextColorsManagerFactory.h"
#include "LogConsoleTextColorsManagerImpl.h"
#include "OutputConsoleTextColorsManager.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"

CoreTools::LogConsoleTextColorsManagerFactory::LogConsoleTextColorsManagerPtr CoreTools::LogConsoleTextColorsManagerFactory::Create(LogLevel logLevel)
{
    if (logLevel == LogLevel::Error || logLevel == LogLevel::Fatal)
        return std::make_shared<ErrorConsoleTextColorsManager>(logLevel);
    else
        return std::make_shared<OutputConsoleTextColorsManager>(logLevel);
}

CoreTools::LogConsoleTextColorsManagerFactory::LogConsoleTextColorsManagerPtr CoreTools::LogConsoleTextColorsManagerFactory::Create(const OStreamShared& streamShared, LogLevel logLevel)
{
    if (streamShared.IsCout())
        return std::make_shared<OutputConsoleTextColorsManager>(logLevel);
    else if (streamShared.IsCerr())
        return std::make_shared<ErrorConsoleTextColorsManager>(logLevel);
    else
        return std::make_shared<LogConsoleTextColorsManagerImpl>(logLevel);
}
