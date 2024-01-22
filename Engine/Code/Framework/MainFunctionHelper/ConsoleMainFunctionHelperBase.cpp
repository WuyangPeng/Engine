/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:11)

#include "Framework/FrameworkExport.h"

#include "ConsoleMainFunctionHelperBase.h"
#include "Detail/ConsoleMainFunctionHelperBaseImpl.h"
#include "Detail/DirectoryDefaultName.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <iostream>

Framework::ConsoleMainFunctionHelperBase::ConsoleMainFunctionHelperBase(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
    : MainFunctionHelperBase{ environmentDirectory }, impl{}, argc{ argc }, argv{ argv }
{
    ConsoleMainFunctionHelperInit(consoleTitle);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

void Framework::ConsoleMainFunctionHelperBase::ConsoleMainFunctionHelperInit(const System::String& consoleTitle)
{
    EXCEPTION_TRY
    {
        auto engineInstallationDirectory = GetEngineInstallationDirectory();

        impl = make_shared<ImplType>(argc, argv, consoleTitle, engineInstallationDirectory);
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::ConsoleMainFunctionHelperBase::IsValid() const noexcept
{
    if (ParentType::IsValid() && 1 <= argc && argv != nullptr && *argv != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Framework::ConsoleMainFunctionHelperBase::GetArgc() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return argc;
}

char** Framework::ConsoleMainFunctionHelperBase::GetArgv() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return argv;
}

System::String Framework::ConsoleMainFunctionHelperBase::GetApplicationProjectDirectory() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    if (impl != nullptr)
        return impl->GetApplicationProjectDirectory();
    else
        return DirectoryDefaultName::GetDefaultNullName();
}

Framework::ConsoleMainFunctionHelperBase::Command Framework::ConsoleMainFunctionHelperBase::GetCommand() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    if (impl != nullptr)
    {
        return impl->GetCommand();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("impl ��ʼ��ʧ�ܡ�"))
    }
}
