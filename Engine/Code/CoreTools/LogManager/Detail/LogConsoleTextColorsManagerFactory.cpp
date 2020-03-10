// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 10:26)

#include "CoreTools/CoreToolsExport.h"

#include "LogConsoleTextColorsManagerFactory.h"
#include "LogConsoleTextColorsManagerImpl.h"
#include "ErrorConsoleTextColorsManager.h"
#include "OutputConsoleTextColorsManager.h"  

#include <iostream>

using std::ostream;
using std::cout;
using std::cerr;
using std::make_shared;

CoreTools::LogConsoleTextColorsManagerFactory::LogConsoleTextColorsManagerPtr CoreTools::LogConsoleTextColorsManagerFactory
	::Create(LogLevel logLevel)
{
	if (logLevel == LogLevel::Error || logLevel == LogLevel::Fatal)
		return make_shared<ErrorConsoleTextColorsManager>(logLevel);
	else
		return make_shared<OutputConsoleTextColorsManager>(logLevel);
}

CoreTools::LogConsoleTextColorsManagerFactory::LogConsoleTextColorsManagerPtr CoreTools::LogConsoleTextColorsManagerFactory
	::Create(ostream* osPtr, LogLevel logLevel)
{
	if (osPtr == &cout)
		return make_shared<OutputConsoleTextColorsManager>(logLevel);
	else if (osPtr == &cerr)
		return make_shared<ErrorConsoleTextColorsManager>(logLevel);
	else
		return make_shared<LogConsoleTextColorsManagerImpl>(logLevel);
}

