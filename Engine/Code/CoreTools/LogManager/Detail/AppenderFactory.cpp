//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/15 17:57)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderConsole.h"
#include "AppenderFactory.h"
#include "AppenderFile.h"
#include "AppenderFileConfiguration.h"
#include "AppenderImpl.h"

using std::make_shared;

// static
CoreTools::AppenderFactory::AppenderImplPtr CoreTools::AppenderFactory::Create(AppenderPrint appenderFlags, LogLevel logLevel)
{
    return make_shared<AppenderConsole>(appenderFlags, logLevel);
}

// static
CoreTools::AppenderFactory::AppenderImplPtr CoreTools::AppenderFactory::Create(const String& directory, const String& fileName, AppenderPrint appenderFlags, LogLevel logLevel,
                                                                                           int maxFileSize, bool backup, const String& extensionName)
{
    return make_shared<AppenderFile>(directory, fileName, appenderFlags, logLevel, maxFileSize, backup, extensionName);
}

CoreTools::AppenderFactory::AppenderImplPtr CoreTools::AppenderFactory::Create(const String& directory, AppenderPrint appenderFlags, LogLevel logLevel, int maxFileSize, bool backup, const String& extensionName)
{
    return make_shared<AppenderFileConfiguration>(directory, appenderFlags, logLevel, maxFileSize, backup, extensionName);
}
