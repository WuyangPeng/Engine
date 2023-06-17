///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:40)

#include "Framework/FrameworkExport.h"

#include "ConsoleMainFunctionHelperBase.h"
#include "Detail/ConsoleMainFunctionHelperBaseImpl.h"
#include "Detail/DirectoryDefaultName.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iostream>

Framework::ConsoleMainFunctionHelperBase::ConsoleMainFunctionHelperBase(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
    : MainFunctionHelperBase{ environmentDirectory }, impl{}, argc{ argc }, argv{ argv }
{
    ConsoleMainFunctionHelperInit(consoleTitle);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ConsoleMainFunctionHelperBase, GetCommand, Framework::ConsoleMainFunctionHelperBase::Command)
