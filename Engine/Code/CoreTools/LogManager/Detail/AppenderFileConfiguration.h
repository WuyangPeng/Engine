// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 18:03)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_CONFIGURATION_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_CONFIGURATION_H

#include "CoreTools/CoreToolsDll.h"

#include "AppenderImpl.h"
#include "System/Helper/UnicodeUsing.h" 

#include <string>
#include <fstream>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE AppenderFileConfiguration : public AppenderImpl
	{
	public:
		using ClassType = AppenderFileConfiguration;
		using ParentType = AppenderImpl;

	public:
		AppenderFileConfiguration(const String& directory, AppenderPrint appenderFlags, LogLevel logLevel,
								  int maxFileSize, bool backup, const String& extensionName);

		virtual ~AppenderFileConfiguration();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual AppenderType GetAppenderType() const noexcept override;

		virtual const AppenderImplPtr Clone() const override;

		virtual String GetDirectory() const override;
		virtual String GetExtensionName() const override;
		virtual int GetMaxFileSize() const noexcept override;
		virtual bool IsBackup() const noexcept override;

	private:
		virtual void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) override;

	private:
		String m_Directory;
		String m_ExtensionName;
		int m_MaxFileSize;
		bool m_Backup;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_CONFIGURATION_H
