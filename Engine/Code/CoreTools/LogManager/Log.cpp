// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.1 (2020/01/20 11:01)

#include "CoreTools/CoreToolsExport.h"

#include "Log.h"
#include "Appender.h"
#include "Detail/LogImpl.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

SINGLETON_MUTEX_DEFINE(CoreTools, Log);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder{ g_CoreToolsMutex }

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *sm_LogMutex }

SINGLETON_INITIALIZE_DEFINE(CoreTools, Log)

SINGLETON_DEFINE(CoreTools, Log)

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::Log
	::IsValid() const noexcept
{
	MUTEX_ENTER_MEMBER;

	if (m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void CoreTools::Log
	::InsertAppender(const String& name, const Appender& appenderPtr)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->InsertAppender(name, appenderPtr);
}

void CoreTools::Log
	::RemoveAppender(const String& name)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->RemoveAppender(name);
}

void CoreTools::Log
	::LoadConfiguration(const string& fileName)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->LoadConfiguration(fileName);
}

CoreTools::LogAppenderIOManager& CoreTools::Log
	::OutTrace() noexcept
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OutTrace();
}

CoreTools::LogAppenderIOManager& CoreTools::Log
	::OutDebug() noexcept
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OutDebug();
}

CoreTools::LogAppenderIOManager& CoreTools::Log
	::OutInfo() noexcept
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OutInfo();
}

CoreTools::LogAppenderIOManager& CoreTools::Log
	::OutWarn() noexcept
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OutWarn();
}

CoreTools::LogAppenderIOManager& CoreTools::Log
	::OutError() noexcept
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OutError();
}

CoreTools::LogAppenderIOManager& CoreTools::Log
	::OutFatal() noexcept
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OutFatal();
}

void CoreTools::Log
	::ReloadAppenderFile()
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ReloadAppenderFile();
}
