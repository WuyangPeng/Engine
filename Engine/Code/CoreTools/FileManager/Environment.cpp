/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 23:06)

#include "CoreTools/CoreToolsExport.h"

#include "Environment.h"
#include "Detail/EnvironmentImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Environment CoreTools::Environment::Create()
{
    return Environment{ EnvironmentCreate::Init };
}

CoreTools::Environment::Environment(EnvironmentCreate environmentCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(environmentCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Environment)

int CoreTools::Environment::GetNumDirectories() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetNumDirectories();
}

System::String CoreTools::Environment::GetDirectory(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDirectory(index);
}

bool CoreTools::Environment::InsertDirectory(const String& directory)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->InsertDirectory(directory);
}

bool CoreTools::Environment::EraseDirectory(const String& directory)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->EraseDirectory(directory);
}

void CoreTools::Environment::EraseAllDirectories() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->EraseAllDirectories();
}

System::String CoreTools::Environment::GetPathReading(const String& fileName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetPathReading(fileName);
}

System::String CoreTools::Environment::GetPathWriting(const String& fileName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetPathWriting(fileName);
}

System::String CoreTools::Environment::GetPathReadingAndWriting(const String& fileName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetPathReadingAndWriting(fileName);
}
