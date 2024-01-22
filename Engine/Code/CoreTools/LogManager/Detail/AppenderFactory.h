/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:35)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_FACTORY_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerInternalFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AppenderFactory final
    {
    public:
        using ClassType = AppenderFactory;

        using AppenderImplSharedPtr = std::shared_ptr<AppenderImpl>;
        using String = System::String;

    public:
        NODISCARD static AppenderImplSharedPtr Create(AppenderPrint appenderFlags,
                                                      LogLevel logLevel);

        NODISCARD static AppenderImplSharedPtr Create(const String& directory,
                                                      const String& fileName,
                                                      AppenderPrint appenderFlags,
                                                      LogLevel logLevel,
                                                      int maxFileSize,
                                                      bool backup,
                                                      const String& extensionName);

        NODISCARD static AppenderImplSharedPtr Create(const String& directory,
                                                      AppenderPrint appenderFlags,
                                                      LogLevel logLevel,
                                                      int maxFileSize,
                                                      bool backup,
                                                      const String& extensionName);
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_FACTORY_H
