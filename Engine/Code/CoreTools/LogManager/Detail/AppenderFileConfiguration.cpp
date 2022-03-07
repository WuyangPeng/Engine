///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:30)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderFileConfiguration.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/LogMessagePostfix.h"
#include "CoreTools/LogManager/LogMessagePrefix.h"

using std::make_shared;

CoreTools::AppenderFileConfiguration::AppenderFileConfiguration(const String& directory,
                                                                AppenderPrint appenderFlags,
                                                                LogLevel logLevel,
                                                                int maxFileSize,
                                                                bool backup,
                                                                const String& extensionName)
    : ParentType{ appenderFlags, logLevel },
      directory{ directory },
      extensionName{ extensionName },
      maxFileSize{ maxFileSize },
      backup{ backup }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::AppenderFileConfiguration::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 < maxFileSize)
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
void CoreTools::AppenderFileConfiguration::DoWrite(MAYBE_UNUSED const LogMessage& message, MAYBE_UNUSED const LogMessagePrefix& prefix, MAYBE_UNUSED const LogMessagePostfix& postfix) noexcept
{
}

const CoreTools::AppenderFileConfiguration::AppenderImplSharedPtr CoreTools::AppenderFileConfiguration::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return make_shared<ClassType>(*this);
}

System::String CoreTools::AppenderFileConfiguration::GetDirectory() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return directory;
}

System::String CoreTools::AppenderFileConfiguration::GetExtensionName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return extensionName;
}

int CoreTools::AppenderFileConfiguration::GetMaxFileSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return maxFileSize;
}

bool CoreTools::AppenderFileConfiguration::IsBackup() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return backup;
}
