// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 11:01)

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
using std::make_shared;
using std::make_unique;

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26487)
SINGLETON_GET_PTR_DEFINE(CoreTools, Log);

CoreTools::Log::LogUniquePtr CoreTools::Log
::sm_Log{ };

void CoreTools::Log
::Create()
{
	sm_Log = make_unique<CoreTools::Log>(LogCreate::Init);
}

void CoreTools::Log
::Destroy() noexcept
{
	sm_Log.reset();
}

CoreTools::Log
::Log(LogCreate logCreate)
	:m_Impl{ make_shared<ImplType>() }
{
	SYSTEM_UNUSED_ARG(logCreate);

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, Log)

void CoreTools::Log
	::InsertAppender(const String& name, const Appender& appenderPtr)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->InsertAppender(name, appenderPtr);
}

void CoreTools::Log
	::RemoveAppender(const String& name)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->RemoveAppender(name);
}

void CoreTools::Log
	::LoadConfiguration(const string& fileName)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->LoadConfiguration(fileName);
}

CoreTools::LogAppenderIOManager& CoreTools::Log
	::OutTrace() noexcept
{
	try
	{
		 
#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)
		SINGLETON_MUTEX_ENTER_MEMBER;
		#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		 
	}	

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OutTrace();
}

CoreTools::LogAppenderIOManager& CoreTools::Log
	::OutDebug() noexcept
{
	try
	{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
		SINGLETON_MUTEX_ENTER_MEMBER;
#include STSTEM_WARNING_POP
	}
	catch (...)
	{

	}

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OutDebug();
}

CoreTools::LogAppenderIOManager& CoreTools::Log
	::OutInfo() noexcept
{
	try
	{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
		SINGLETON_MUTEX_ENTER_MEMBER;
#include STSTEM_WARNING_POP
	}
	catch (...)
	{

	}

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OutInfo();
}

CoreTools::LogAppenderIOManager& CoreTools::Log
	::OutWarn() noexcept
{
	try
	{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
		SINGLETON_MUTEX_ENTER_MEMBER;
#include STSTEM_WARNING_POP
	}
	catch (...)
	{

	}

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OutWarn();
}

CoreTools::LogAppenderIOManager& CoreTools::Log
	::OutError() noexcept
{
	try
	{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
		SINGLETON_MUTEX_ENTER_MEMBER;
#include STSTEM_WARNING_POP
	}
	catch (...)
	{

	}

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OutError();
}

CoreTools::LogAppenderIOManager& CoreTools::Log
	::OutFatal() noexcept
{
	try
	{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
		SINGLETON_MUTEX_ENTER_MEMBER;
#include STSTEM_WARNING_POP
	}
	catch (...)
	{

	}

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->OutFatal();
}

void CoreTools::Log
	::ReloadAppenderFile()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ReloadAppenderFile();
}
#include STSTEM_WARNING_POP