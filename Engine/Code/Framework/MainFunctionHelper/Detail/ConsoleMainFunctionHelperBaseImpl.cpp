/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:12)

#include "Framework/FrameworkExport.h"

#include "ConsoleMainFunctionHelperBaseImpl.h"
#include "DirectoryDefaultName.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::ConsoleMainFunctionHelperBaseImpl::ConsoleMainFunctionHelperBaseImpl(int argc, char** argv, const String& consoleTitle, const String& engineInstallationDirectory)
    : consoleTitle{ consoleTitle },
      command{ argc, argv },
      applicationProjectDirectory{ ProduceApplicationProjectDirectory(consoleTitle, engineInstallationDirectory) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ConsoleMainFunctionHelperBaseImpl);

System::String Framework::ConsoleMainFunctionHelperBaseImpl::GetApplicationProjectDirectory() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return applicationProjectDirectory;
}

System::String Framework::ConsoleMainFunctionHelperBaseImpl::ProduceApplicationProjectDirectory(const String& consoleTitle, const String& engineInstallationDirectory)
{
    return engineInstallationDirectory + consoleTitle + DirectoryDefaultName::GetDefaultNullName();
}

Framework::ConsoleMainFunctionHelperBaseImpl::Command Framework::ConsoleMainFunctionHelperBaseImpl::GetCommand() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return command;
}
