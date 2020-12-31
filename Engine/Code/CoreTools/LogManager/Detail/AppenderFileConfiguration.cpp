//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 18:24)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderFileConfiguration.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/LogMessagePostfix.h"
#include "CoreTools/LogManager/LogMessagePrefix.h"

using std::make_shared;

CoreTools::AppenderFileConfiguration::AppenderFileConfiguration(const String& directory, AppenderPrint appenderFlags, LogLevel logLevel,
                                                                int maxFileSize, bool backup, const String& extensionName)
    : ParentType{ appenderFlags, logLevel }, m_Directory{ directory }, m_ExtensionName{ extensionName },
      m_MaxFileSize{ maxFileSize }, m_Backup{ backup }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::AppenderFileConfiguration::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 < m_MaxFileSize)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

CoreTools::AppenderType CoreTools::AppenderFileConfiguration::GetAppenderType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return AppenderType::FileConfiguration;
}

// private
void CoreTools::AppenderFileConfiguration::DoWrite([[maybe_unused]] const LogMessage& message, [[maybe_unused]] const LogMessagePrefix& prefix, [[maybe_unused]] const LogMessagePostfix& postfix) noexcept
{
}

const CoreTools::AppenderFileConfiguration::AppenderImplPtr CoreTools::AppenderFileConfiguration::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return make_shared<ClassType>(*this);
}

System::String CoreTools::AppenderFileConfiguration::GetDirectory() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Directory;
}

System::String CoreTools::AppenderFileConfiguration::GetExtensionName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_ExtensionName;
}

int CoreTools::AppenderFileConfiguration::GetMaxFileSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_MaxFileSize;
}

bool CoreTools::AppenderFileConfiguration::IsBackup() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Backup;
}
