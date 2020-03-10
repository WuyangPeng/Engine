// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 10:08)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderFile.h"
#include "System/Helper/UnusedMacro.h"
#include "System/FileManager/FileTools.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/LogMessagePrefix.h"
#include "CoreTools/LogManager/LogMessagePostfix.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/FileManager/OFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::AppenderFile
	::AppenderFile(const String& directory, const String& fileName, AppenderPrint appenderFlags, LogLevel logLevel,
				   int maxFileSize, bool backup, const String& extensionName)
	:ParentType{ appenderFlags,logLevel }, m_Directory{ directory }, m_PrefixName{ GetPrefixName(m_Directory,fileName) },
	 m_ExtensionName{ extensionName }, m_FullName{ GetFullName(m_PrefixName, extensionName) }, m_MaxFileSize{ maxFileSize },
	 m_Backup{ backup }, m_OStreamManager{}
{
	Init(directory);

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::AppenderFile
	::Init(const String& directory)
{
	NewDirectory(directory);

	m_OStreamManager = make_shared<OFStreamManager>(m_FullName, true);
	m_OStreamManager->SetSimplifiedChinese();

	if (IsExceedMaxSize(0))
	{
		BackupFile();
	}
}

CoreTools::AppenderFile
	::~AppenderFile()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::AppenderFile
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && 0 < m_MaxFileSize && m_OStreamManager != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::AppenderType CoreTools::AppenderFile
	::GetAppenderType() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return AppenderType::File;
}

// private
void CoreTools::AppenderFile
	::DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix)
{
	auto messageDescribe = message.GetMessageDescribe();

	auto fullMessage = prefix.GetPrefix() + messageDescribe + postfix.GetPostfix();

	if (IsExceedMaxSize(fullMessage.size()))
	{
		BackupFile();
	}

	*m_OStreamManager << fullMessage;
}

// private
bool CoreTools::AppenderFile
	::IsExceedMaxSize(System::OFileStream::pos_type increaseSize)
{
	auto fileSize = m_OStreamManager->GetOFStreamSize();

	return (m_MaxFileSize < fileSize + increaseSize);
}

// private
void CoreTools::AppenderFile
	::BackupFile()
{
	if (m_Backup)
	{
		CoreTools::IFStreamManager manager{ m_FullName };
		manager.BackupFile();
	}

	m_OStreamManager = make_shared<OFStreamManager>(m_FullName, false);
	m_OStreamManager->SetSimplifiedChinese();
}

const CoreTools::AppenderFile::AppenderImplPtr CoreTools::AppenderFile
	::Clone() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return make_shared<ClassType>(*this);
}

void CoreTools::AppenderFile
	::Reload()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_FullName = GetFullName(m_PrefixName, m_ExtensionName);

	m_OStreamManager = make_shared<OFStreamManager>(m_FullName, true);
}

System::String CoreTools::AppenderFile
	::GetFullName(const String& prefixName, const String& extensionName)
{
	return prefixName + SYSTEM_TEXT("(") + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(").") + extensionName;
}

System::String CoreTools::AppenderFile
	::GetPrefixName(const String& directory, const String& fileName)
{
	return directory + SYSTEM_TEXT("/") + fileName;
}

void CoreTools::AppenderFile
	::NewDirectory(const String& directory)
{
	System::CreateFileDirectory(directory, nullptr);
}

System::String CoreTools::AppenderFile
	::GetDirectory() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Directory;
}

System::String CoreTools::AppenderFile
	::GetExtensionName() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_ExtensionName;
}

int CoreTools::AppenderFile
	::GetMaxFileSize() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_MaxFileSize;
}

bool CoreTools::AppenderFile
	::IsBackup() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Backup;
}

