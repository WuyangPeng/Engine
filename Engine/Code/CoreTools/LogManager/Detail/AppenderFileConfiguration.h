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

		

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		  AppenderType GetAppenderType() const noexcept override;
 
		  const AppenderImplPtr Clone() const override;

		  String GetDirectory() const override;
		  String GetExtensionName() const override;
		  int GetMaxFileSize() const noexcept override;
		  bool IsBackup() const noexcept override;

	private:
		  void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) noexcept override;

	private:
		String m_Directory;
		String m_ExtensionName;
		int m_MaxFileSize;
		bool m_Backup;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_CONFIGURATION_H
