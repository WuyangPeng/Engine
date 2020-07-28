// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 11:01)

#include "CoreTools/CoreToolsExport.h"

#include "LogAppenderIOManager.h"
#include "Detail/LogAppenderIOManagerImplDetail.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::wstring;
using std::make_shared;

CoreTools::LogAppenderIOManager
::LogAppenderIOManager(LogLevel logLevel, const AppenderManagerPtr& appenderManager)
	:m_Impl{ make_shared<ImplType>(logLevel,appenderManager) }, m_LogAppenderIOManagerMutex{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::LogAppenderIOManager
::LogAppenderIOManager()
	:m_Impl{ make_shared<ImplType>() }, m_LogAppenderIOManagerMutex{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP
CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, LogAppenderIOManager)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(CoreTools, LogAppenderIOManager, SetAppenderManager, AppenderManagerPtr, void)

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26447)
CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(int32_t value) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	try
	{
		ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

		*m_Impl << value;
	}
	catch (...)
	{

	}

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(uint32_t value) noexcept
{
	try
	{
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

		ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

		*m_Impl << value;
	}
	catch (...)
	{

	}

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(int64_t value) noexcept
{
	try
	{
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

		ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

		*m_Impl << value;
	}
	catch (...)
	{

	}

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(uint64_t value) noexcept
{
	try
	{
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

		ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

		*m_Impl << value;
	}
	catch (...)
	{

	}

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(float value) noexcept
{
	try
	{
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

		ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

		*m_Impl << value;
	}
	catch (...)
	{

	}

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(double value) noexcept
{
	try
	{
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

		ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

		*m_Impl << value;
	}
	catch (...)
	{

	}

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(const string& message) noexcept
{
	try
	{
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

		ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

		*m_Impl << message;
	}
	catch (...)
	{

	}
	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(const wstring& message) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	try
	{
		ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

		*m_Impl << message;
	}
	catch (...)
	{

	}
	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(const FunctionDescribed& functionDescribed) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	try
	{
		ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

		*m_Impl << functionDescribed;
	}
	catch (...)
	{

	}
	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(const Error& error) noexcept
{
	try
	{
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

		ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

		*m_Impl << error;
	}
	catch (...)
	{

	}
	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(const std::exception& error) noexcept
{
	try
	{
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

		ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

		*m_Impl << error;
	}
	catch (...)
	{

	}
	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(LogFilter filterType) noexcept
{
	try
	{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << filterType;
	}
	catch (...)
	{

	}
	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(LogAppenderIOManageSign sign) noexcept
{
	try
	{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << sign;
	}
	catch (...)
	{

	}
	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(const LogFileName& logFileName) noexcept
{
	try
	{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << logFileName;
	}
	catch (...)
	{

	}
	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(const char* message) noexcept
{
	try
	{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << message;
	}
	catch (...)
	{

	}
	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
::operator<<(const wchar_t* message) noexcept
{
	try
	{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << message;
	}
	catch (...)
	{

	}
	return *this;
}
#include STSTEM_WARNING_POP