// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/02/27 13:18)

#include "CoreTools/CoreToolsExport.h"

#include "Error.h"
#include "LastError.h"
#include "Detail/ErrorImpl.h"
#include "Detail/ErrorFactory.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::Error
	::Error(const FunctionDescribed& functionDescribed, const LastError& lastError, const System::String& message)
	:m_Impl{ ErrorFactory::CreateError(functionDescribed,lastError,message) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Error
	::Error(const FunctionDescribed& functionDescribed, WindowError lastError, const System::String& message)
	:m_Impl{ ErrorFactory::CreateError(functionDescribed,lastError,message) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Error
	::~Error()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, Error)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Error, GetError, const System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Error, GetCurrentFunction, const char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Error, GetFileName, const char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Error, GetLine, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Error, GetFunctionDescribed, const CoreTools::FunctionDescribed&)

void CoreTools::Error
	::ThrowError(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message)
{
	throw ClassType{ functionDescribed ,lastError,message };
}

void CoreTools::Error
	::ThrowError(const FunctionDescribed& functionDescribed, const String& message)
{
	LastError lastError{};

	throw ClassType{ functionDescribed ,lastError,message };
}

