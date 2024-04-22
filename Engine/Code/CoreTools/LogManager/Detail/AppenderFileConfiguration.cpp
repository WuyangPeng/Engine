/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 13:58)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderFileConfiguration.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/LogMessagePostfix.h"
#include "CoreTools/LogManager/LogMessagePrefix.h"

CoreTools::AppenderFileConfiguration::AppenderFileConfiguration(String directory,
                                                                AppenderPrint appenderFlags,
                                                                LogLevel logLevel,
                                                                int maxFileSize,
                                                                bool backup,
                                                                String extensionName) noexcept
    : ParentType{ appenderFlags, logLevel },
      directory{ std::move(directory) },
      extensionName{ std::move(extensionName) },
      maxFileSize{ maxFileSize },
      backup{ backup }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::AppenderFileConfiguration::IsValid() const noexcept
{
    return ParentType::IsValid() && 0 < maxFileSize;
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::AppenderType CoreTools::AppenderFileConfiguration::GetAppenderType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return AppenderType::FileConfiguration;
}

void CoreTools::AppenderFileConfiguration::DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) const noexcept
{
    System::UnusedFunction(message, prefix, postfix);
}

const CoreTools::AppenderFileConfiguration::AppenderImplSharedPtr CoreTools::AppenderFileConfiguration::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
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
