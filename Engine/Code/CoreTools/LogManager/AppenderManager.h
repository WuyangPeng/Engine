//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/15 11:38)

// ���λ�ù��������ⲿ�ӿ�
#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(AppenderManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE AppenderManager final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(AppenderManager);
        using String = System::String;

    public:
        explicit AppenderManager(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsAppenderExist(const String& name) const;

        [[nodiscard]] bool InsertLogger(const Logger& logger);
        [[nodiscard]] bool RemoveLogger(LogFilter logFilter);
        [[nodiscard]] bool InsertAppender(const String& name, const Appender& appender);
        [[nodiscard]] bool InsertConsoleAppender(const Appender& appender);
        [[nodiscard]] bool RemoveAppender(const String& name);
        void Clear() noexcept;

        void Write(const LogMessage& message);
        void Write(const String& name, const LogMessage& message);
        void WriteToConsole(const LogMessage& message);

        void ReloadAppenderFile();

        [[nodiscard]] static const String GetConsoleAppenderName();
        [[nodiscard]] static const String GetDefaultAppenderName();

    private:
        IMPL_TYPE_DECLARE(AppenderManager);
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_H
