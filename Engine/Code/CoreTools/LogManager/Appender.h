// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 18:06)

// ���λ���ⲿ�ӿ�
#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "Flags/LogManagerFlags.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(AppenderImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Appender
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Appender);
		using String = System::String;

	public:
		// ����AppenderConsole
		explicit Appender(AppenderPrint appenderFlags, LogLevel logLevel = LogLevel::Disabled);

		// ����AppenderFile
		Appender(const String& directory, const String& fileName, AppenderPrint appenderFlags, LogLevel logLevel,
				 int maxFileSize, bool backup, const String& extensionName);

		// ����AppenderFileConfiguration
		Appender(const String& directory, AppenderPrint appenderFlags, LogLevel logLevel,
				 int maxFileSize, bool backup, const String& extensionName);

		CLASS_INVARIANT_DECLARE;

		LogLevel GetLogLevel() const noexcept;
		AppenderPrint GetFlags() const noexcept;
		AppenderType GetAppenderType() const noexcept;

		void SetLogLevel(LogLevel level);
		void Write(const LogMessage& message);

		String GetDirectory() const;
		String GetExtensionName() const;
		int GetMaxFileSize() const noexcept;
		bool IsBackup() const noexcept;

		void Reload();

		bool IsDefault() const noexcept;
		void SetIsDefault(bool isDefault);

	private:
		IMPL_TYPE_DECLARE(Appender);
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_APPENDER_H
