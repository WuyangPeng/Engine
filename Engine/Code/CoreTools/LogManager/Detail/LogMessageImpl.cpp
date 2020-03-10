// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 10:37)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessageImpl.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/Format.h" 

#include <boost/numeric/conversion/cast.hpp>

CoreTools::LogMessageImpl
	::LogMessageImpl(LogLevel level, LogFilter filter, const String& message, const FunctionDescribed& functionDescribed)
	:m_Level{ level }, m_Filter{ filter }, m_Message{ message }, m_FunctionDescribed{ functionDescribed }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessageImpl)

System::String CoreTools::LogMessageImpl
	::GetMessageDescribe() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Message;
}

CoreTools::LogLevel CoreTools::LogMessageImpl
	::GetLogLevel() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Level;
}

CoreTools::LogFilter CoreTools::LogMessageImpl
	::GetLogFilterType() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Filter;
}

int CoreTools::LogMessageImpl
	::GetMessageSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Message.size());
}

CoreTools::FunctionDescribed CoreTools::LogMessageImpl
	::GetFunctionDescribed() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_FunctionDescribed;
}
