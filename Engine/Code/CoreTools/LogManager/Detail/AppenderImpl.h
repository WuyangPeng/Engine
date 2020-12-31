//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 9:56)

// 输出位置基类内部接口
#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/Threading/Mutex.h"

#include <fstream>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AppenderImpl
    {
    public:
        using ClassType = AppenderImpl;
        using AppenderImplPtr = std::shared_ptr<ClassType>;
        using String = System::String;
        using PosType = System::OFileStream::pos_type;

    public:
        explicit AppenderImpl(AppenderPrint appenderFlags, LogLevel logLevel = LogLevel::Disabled);
        virtual ~AppenderImpl() = default;

        AppenderImpl(const AppenderImpl& rhs);
        AppenderImpl& operator=(const AppenderImpl& rhs) noexcept;
        AppenderImpl(AppenderImpl&& rhs) noexcept;
        AppenderImpl& operator=(AppenderImpl&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] virtual const AppenderImplPtr Clone() const = 0;

        [[nodiscard]] LogLevel GetLogLevel() const noexcept;
        [[nodiscard]] AppenderPrint GetFlags() const noexcept;

        void SetLogLevel(LogLevel level) noexcept;
        void Write(const LogMessage& message);

        virtual void Reload();

        [[nodiscard]] virtual AppenderType GetAppenderType() const noexcept = 0;

        [[nodiscard]] virtual String GetDirectory() const;
        [[nodiscard]] virtual String GetExtensionName() const;
        [[nodiscard]] virtual int GetMaxFileSize() const noexcept;
        [[nodiscard]] virtual bool IsBackup() const noexcept;

        [[nodiscard]] bool IsDefault() const noexcept;
        void SetIsDefault(bool isDefault) noexcept;

    private:
        virtual void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) = 0;

    private:
        AppenderPrint m_AppenderFlags;
        LogLevel m_LogLevel;
        bool m_IsDefault;
        Mutex m_AppenderImplMutex;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_IMPL_H
