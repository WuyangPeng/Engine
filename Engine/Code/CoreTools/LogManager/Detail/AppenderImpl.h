///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:44)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogManagerInternalFwd.h"
#include "CoreTools/Threading/Mutex.h"

#include <fstream>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AppenderImpl
    {
    public:
        using ClassType = AppenderImpl;
        using FactoryType = AppenderFactory;

        using AppenderImplSharedPtr = std::shared_ptr<ClassType>;
        using String = System::String;
        using PosType = System::OFileStream::pos_type;

    public:
        explicit AppenderImpl(AppenderPrint appenderFlags, LogLevel logLevel = LogLevel::Disabled) noexcept;
        virtual ~AppenderImpl() noexcept = default;

        AppenderImpl(const AppenderImpl& rhs) noexcept = default;
        AppenderImpl& operator=(const AppenderImpl& rhs) noexcept = default;
        AppenderImpl(AppenderImpl&& rhs) noexcept = default;
        AppenderImpl& operator=(AppenderImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual const AppenderImplSharedPtr Clone() const = 0;

        NODISCARD LogLevel GetLogLevel() const noexcept;
        NODISCARD AppenderPrint GetFlags() const noexcept;

        void SetLogLevel(LogLevel level) noexcept;
        void Write(const LogMessage& message) const;

        NODISCARD virtual AppenderType GetAppenderType() const noexcept = 0;

        NODISCARD virtual String GetDirectory() const;
        NODISCARD virtual String GetExtensionName() const;
        NODISCARD virtual int GetMaxFileSize() const noexcept;
        NODISCARD virtual bool IsBackup() const noexcept;

        NODISCARD bool IsDefault() const noexcept;
        void SetIsDefault(bool isDefault) noexcept;

    private:
        virtual void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) const = 0;

    private:
        AppenderPrint appenderFlags;
        LogLevel logLevel;
        bool isDefaultAppender;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_IMPL_H
