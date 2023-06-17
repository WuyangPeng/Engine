///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:39)

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

// private
// static
System::String Framework::ConsoleMainFunctionHelperBaseImpl::ProduceApplicationProjectDirectory(const String& consoleTitle, const String& engineInstallationDirectory)
{
    return engineInstallationDirectory + consoleTitle + DirectoryDefaultName::GetDefaultNullName();
}

Framework::ConsoleMainFunctionHelperBaseImpl::Command Framework::ConsoleMainFunctionHelperBaseImpl::GetCommand() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return command;
}
