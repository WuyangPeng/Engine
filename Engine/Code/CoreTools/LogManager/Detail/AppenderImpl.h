// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 18:03)

// 输出位置基类内部接口
#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"

#include <string>
#include <fstream>

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
		virtual ~AppenderImpl();

		AppenderImpl(const AppenderImpl& rhs);
		AppenderImpl& operator=(const AppenderImpl& rhs); 

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual const AppenderImplPtr Clone() const = 0;

		LogLevel GetLogLevel() const noexcept;
		AppenderPrint GetFlags() const noexcept;

		void SetLogLevel(LogLevel level) noexcept;
		void Write(const LogMessage& message);

		virtual void Reload();

		virtual AppenderType GetAppenderType() const noexcept = 0;

		virtual String GetDirectory() const;
		virtual String GetExtensionName() const;
		virtual int GetMaxFileSize() const noexcept;
		virtual bool IsBackup() const noexcept;

		bool IsDefault() const noexcept;
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

#endif // CORE_TOOLS_LOG_MANAGER_APPENDER_IMPL_H
