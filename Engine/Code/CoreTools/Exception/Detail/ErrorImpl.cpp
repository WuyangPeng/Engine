// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 10:46)

#include "CoreTools/CoreToolsExport.h"

#include "ErrorImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::ErrorImpl
	::ErrorImpl(const FunctionDescribed& functionDescribed, const String& message)
	:m_FunctionDescribed{ functionDescribed }, m_ErrorMessage{ message }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ErrorImpl
	::~ErrorImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ErrorImpl)

const System::String CoreTools::ErrorImpl
	::GetError() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_ErrorMessage;
}

const char* CoreTools::ErrorImpl
	::GetCurrentFunction() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_FunctionDescribed.GetCurrentFunction();
}

const char* CoreTools::ErrorImpl
	::GetFileName() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_FunctionDescribed.GetFileName();
}

int CoreTools::ErrorImpl
	::GetLine() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_FunctionDescribed.GetLine();
}

const CoreTools::FunctionDescribed& CoreTools::ErrorImpl
	::GetFunctionDescribed() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_FunctionDescribed;
}

