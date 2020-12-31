//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 14:24)

#include "CoreTools/CoreToolsExport.h"

#include "Environment.h"
#include "Detail/EnvironmentImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(CoreTools, Environment);

CoreTools::Environment::EnvironmentUniquePtr CoreTools::Environment::sm_Environment{};

void CoreTools::Environment::Create()
{
    sm_Environment = make_unique<CoreTools::Environment>(EnvironmentCreate::Init);
}

void CoreTools::Environment::Destroy() noexcept
{
    sm_Environment.reset();
}

CoreTools::Environment::Environment([[maybe_unused]] EnvironmentCreate environmentCreate)
    : m_Impl{ make_shared<ImplType>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, Environment)

int CoreTools::Environment::GetNumDirectories() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetNumDirectories();
}

bool CoreTools::Environment::InsertDirectory(const String& directory)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->InsertDirectory(directory);
}

bool CoreTools::Environment::EraseDirectory(const String& directory)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->EraseDirectory(directory);
}

void CoreTools::Environment::EraseAllDirectories()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->EraseAllDirectories();
}

System::String CoreTools::Environment::GetPathReading(const String& fileName) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPathReading(fileName);
}

System::String CoreTools::Environment::GetPathWriting(const String& fileName) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPathWriting(fileName);
}

System::String CoreTools::Environment::GetPathReadingAndWriting(const String& fileName) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPathReadingAndWriting(fileName);
}

void CoreTools::Environment::SetConfigurationPath(const String& configurationPath)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetConfigurationPath(configurationPath);
}

const System::String CoreTools::Environment::GetConfigurationPath() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetConfigurationPath();
}
