///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 11:00)

#include "CoreTools/CoreToolsExport.h"

#include "Environment.h"
#include "Detail/EnvironmentImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

SINGLETON_GET_PTR_DEFINE(CoreTools, Environment);

CoreTools::Environment::EnvironmentUniquePtr CoreTools::Environment::environment{};

void CoreTools::Environment::Create()
{
    environment = std::make_unique<CoreTools::Environment>(EnvironmentCreate::Init);
}

void CoreTools::Environment::Destroy() noexcept
{
    environment.reset();
}

CoreTools::Environment::Environment(EnvironmentCreate environmentCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(environmentCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Environment)

int CoreTools::Environment::GetNumDirectories() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetNumDirectories();
}

bool CoreTools::Environment::InsertDirectory(const String& directory)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->InsertDirectory(directory);
}

bool CoreTools::Environment::EraseDirectory(const String& directory)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->EraseDirectory(directory);
}

void CoreTools::Environment::EraseAllDirectories()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->EraseAllDirectories();
}

System::String CoreTools::Environment::GetPathReading(const String& fileName) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetPathReading(fileName);
}

System::String CoreTools::Environment::GetPathWriting(const String& fileName) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetPathWriting(fileName);
}

System::String CoreTools::Environment::GetPathReadingAndWriting(const String& fileName) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetPathReadingAndWriting(fileName);
}

void CoreTools::Environment::SetConfigurationPath(const String& configurationPath)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetConfigurationPath(configurationPath);
}

const System::String CoreTools::Environment::GetConfigurationPath() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetConfigurationPath();
}
