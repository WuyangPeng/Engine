// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 17:12)

#include "CoreTools/CoreToolsExport.h"

#include "Environment.h"
#include "Detail/EnvironmentImpl.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

SINGLETON_MUTEX_DEFINE_USE_SHARED(CoreTools, Environment);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder{ GetCoreToolsMutex() }
#define MUTEX_ENTER_MEMBER std::unique_lock<std::shared_mutex> holder{ *sm_EnvironmentMutex }
#define MUTEX_ENTER_MEMBER_SHARED std::shared_lock<std::shared_mutex> holder{ *sm_EnvironmentMutex }

SINGLETON_INITIALIZE_DEFINE_USE_SHARED(CoreTools, Environment);

SINGLETON_DEFINE(CoreTools, Environment);

SINGLETON_GET_PTR_DEFINE(CoreTools, Environment);

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, Environment)

int CoreTools::Environment
	::GetNumDirectories() const
{
	MUTEX_ENTER_MEMBER_SHARED;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetNumDirectories();
}

bool CoreTools::Environment
	::InsertDirectory(const String& directory)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->InsertDirectory(directory);
}

bool CoreTools::Environment
	::EraseDirectory(const String& directory)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->EraseDirectory(directory);
}

void CoreTools::Environment
	::EraseAllDirectories()
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->EraseAllDirectories();
}

System::String CoreTools::Environment
	::GetPathReading(const String& fileName) const
{
	MUTEX_ENTER_MEMBER_SHARED;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetPathReading(fileName);
}

System::String CoreTools::Environment
	::GetPathWriting(const String& fileName) const
{
	MUTEX_ENTER_MEMBER_SHARED;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetPathWriting(fileName);
}

System::String CoreTools::Environment
	::GetPathReadingAndWriting(const String& fileName) const
{
	MUTEX_ENTER_MEMBER_SHARED;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetPathReadingAndWriting(fileName);
}

void CoreTools::Environment
	::SetConfigurationPath(const String& configurationPath)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetConfigurationPath(configurationPath);
}

const System::String CoreTools::Environment
	::GetConfigurationPath() const
{
	MUTEX_ENTER_MEMBER_SHARED;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetConfigurationPath();
}





