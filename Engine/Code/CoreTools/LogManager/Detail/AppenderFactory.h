///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/05 0:13)

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
        NODISCARD static AppenderImplSharedPtr Create(AppenderPrint appenderFlags, LogLevel logLevel);

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
