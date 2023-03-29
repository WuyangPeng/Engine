///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 14:57)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderConsole.h"
#include "AppenderFactory.h"
#include "AppenderFile.h"
#include "AppenderFileConfiguration.h"
#include "AppenderImpl.h"

CoreTools::AppenderFactory::AppenderImplSharedPtr CoreTools::AppenderFactory::Create(AppenderPrint appenderFlags,
                                                                                     LogLevel logLevel)
{
    return std::make_shared<AppenderConsole>(appenderFlags, logLevel);
}

CoreTools::AppenderFactory::AppenderImplSharedPtr CoreTools::AppenderFactory::Create(const String& directory,
                                                                                     const String& fileName,
                                                                                     AppenderPrint appenderFlags,
                                                                                     LogLevel logLevel,
                                                                                     int maxFileSize,
                                                                                     bool backup,
                                                                                     const String& extensionName)
{
    return make_shared<AppenderFile>(directory, fileName, appenderFlags, logLevel, maxFileSize, backup, extensionName);
}

CoreTools::AppenderFactory::AppenderImplSharedPtr CoreTools::AppenderFactory::Create(const String& directory,
                                                                                     AppenderPrint appenderFlags,
                                                                                     LogLevel logLevel,
                                                                                     int maxFileSize,
                                                                                     bool backup,
                                                                                     const String& extensionName)
{
    return make_shared<AppenderFileConfiguration>(directory, appenderFlags, logLevel, maxFileSize, backup, extensionName);
}
