// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 18:02)

// 输出位置子类：文件类
#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "AppenderImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE AppenderFile : public AppenderImpl
	{
	public:
		using ClassType = AppenderFile;
		using ParentType = AppenderImpl;

	public:
		AppenderFile(const String& directory, const String& fileName, AppenderPrint appenderFlags, LogLevel logLevel,
					 int maxFileSize, bool backup, const String& extensionName);

 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		AppenderType GetAppenderType() const noexcept override;

		const AppenderImplPtr Clone() const override;

		void Reload() override;

		String GetDirectory() const override;
		String GetExtensionName() const override;
		int GetMaxFileSize() const noexcept override;
		bool IsBackup() const noexcept override;

	private:
		bool IsExceedMaxSize(PosType increaseSize);
		void BackupFile();

		void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) override;

	private:
		using OStreamManagerPtr = std::shared_ptr<OFStreamManager>;

	private:
		static String GetPrefixName(const String& directory, const String& fileName);
		static String GetFullName(const String& prefixName, const String& extensionName);
		static void NewDirectory(const String& directory) noexcept;

		void Init(const String& directory);

	private:
		String m_Directory;
		String m_PrefixName;
		String m_ExtensionName;
		String m_FullName;
		int m_MaxFileSize;
		bool m_Backup;
		OStreamManagerPtr m_OStreamManager;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_H
