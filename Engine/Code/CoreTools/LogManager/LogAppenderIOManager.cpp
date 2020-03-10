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

CoreTools::LogAppenderIOManager
	::LogAppenderIOManager()
	:m_Impl{ make_shared<ImplType>() }, m_LogAppenderIOManagerMutex{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, LogAppenderIOManager)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, LogAppenderIOManager, SetAppenderManager, AppenderManagerPtr, void)

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(int32_t value) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << value;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(uint32_t value) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << value;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(int64_t value) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << value;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(uint64_t value) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << value;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(float value) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << value;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(double value) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << value;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(const string& message) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << message;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(const wstring& message) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << message;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(const FunctionDescribed& functionDescribed) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << functionDescribed;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(const Error& error) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << error;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(LogFilter filterType) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << filterType;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(LogAppenderIOManageSign sign) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << sign;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(const LogFileName& logFileName) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << logFileName;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(const char* message) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << message;

	return *this;
}

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager
	::operator<<(const wchar_t* message) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ScopedMutex scopedMutex{ m_LogAppenderIOManagerMutex };

	*m_Impl << message;

	return *this;
}
