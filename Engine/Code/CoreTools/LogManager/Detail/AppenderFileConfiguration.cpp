// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 10:14)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderFileConfiguration.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/LogMessagePrefix.h"
#include "CoreTools/LogManager/LogMessagePostfix.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

using std::make_shared;

CoreTools::AppenderFileConfiguration
	::AppenderFileConfiguration(const String& directory, AppenderPrint appenderFlags, LogLevel logLevel,
								int maxFileSize, bool backup, const String& extensionName)
	:ParentType{ appenderFlags,logLevel }, m_Directory{ directory }, m_ExtensionName{ extensionName },
	 m_MaxFileSize{ maxFileSize }, m_Backup{ backup }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::AppenderFileConfiguration
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && 0 < m_MaxFileSize)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::AppenderType CoreTools::AppenderFileConfiguration
	::GetAppenderType() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return AppenderType::FileConfiguration;
}

// private
void CoreTools::AppenderFileConfiguration
	::DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) noexcept
{
	SYSTEM_UNUSED_ARG(message);
	SYSTEM_UNUSED_ARG(prefix);
	SYSTEM_UNUSED_ARG(postfix);
}

const CoreTools::AppenderFileConfiguration::AppenderImplPtr CoreTools::AppenderFileConfiguration
	::Clone() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return make_shared<ClassType>(*this);
}

System::String CoreTools::AppenderFileConfiguration
	::GetDirectory() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Directory;
}

System::String CoreTools::AppenderFileConfiguration
	::GetExtensionName() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_ExtensionName;
}

int CoreTools::AppenderFileConfiguration
	::GetMaxFileSize() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_MaxFileSize;
}

bool CoreTools::AppenderFileConfiguration
	::IsBackup() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Backup;
}

