// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 10:08)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderFactory.h"
#include "AppenderImpl.h"
#include "AppenderFile.h"
#include "AppenderConsole.h"
#include "AppenderFileConfiguration.h"

using std::make_shared;

// static
CoreTools::AppenderFactory::AppenderImplPtr CoreTools::AppenderFactory
	::CreateAppenderConsole(AppenderPrint appenderFlags, LogLevel logLevel)
{
	return make_shared<AppenderConsole>(appenderFlags, logLevel);
}

// static
CoreTools::AppenderFactory::AppenderImplPtr CoreTools::AppenderFactory
	::CreateAppenderFile(const String& directory, const String& fileName, AppenderPrint appenderFlags, LogLevel logLevel,
						 int maxFileSize, bool backup, const String& extensionName)
{
	return make_shared<AppenderFile>(directory, fileName, appenderFlags, logLevel, maxFileSize, backup, extensionName);
}

CoreTools::AppenderFactory::AppenderImplPtr CoreTools::AppenderFactory
	::CreateAppenderFile(const String& directory, AppenderPrint appenderFlags, LogLevel logLevel, int maxFileSize, bool backup, const String& extensionName)
{
	return make_shared<AppenderFileConfiguration>(directory, appenderFlags, logLevel, maxFileSize, backup, extensionName);
}
