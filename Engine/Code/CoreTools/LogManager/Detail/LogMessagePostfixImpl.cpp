// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 10:38)

#include "CoreTools/CoreToolsExport.h"

#include "LogMessagePostfixImpl.h"
#include "AppenderPrintFlagsExist.h"
#include "System/Helper/PragmaWarning/Format.h" 
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

CoreTools::LogMessagePostfixImpl
	::LogMessagePostfixImpl(AppenderPrint appenderFlags, LogLevel level, const FunctionDescribed& functionDescribed)
	:m_Postfix{}, m_AppenderFlags{ appenderFlags }, m_Level{ level }, m_FunctionDescribed{ functionDescribed }
{
	GeneratePostfix();

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::LogMessagePostfixImpl
	::GeneratePostfix()
{
	if (m_Level != LogLevel::Disabled)
	{
		GenerateFunctionDescribedPostfix();
	}
}

// private
void CoreTools::LogMessagePostfixImpl
	::GenerateFunctionDescribedPostfix()
{
	if (AppenderPrintFlagsExist::IsExist(m_AppenderFlags, AppenderPrint::PostfixFunctionDescribed))
	{
		boost::format functionDescribed{ "���ļ���%1%��������%2%����%3%�У�����\n" };

		functionDescribed % m_FunctionDescribed.GetFileName();
		functionDescribed % m_FunctionDescribed.GetCurrentFunction();
		functionDescribed % m_FunctionDescribed.GetLine();

		m_Postfix += StringConversion::MultiByteConversionStandard(functionDescribed.str());
	}
	else
	{
		m_Postfix += SYSTEM_TEXT("\n");
	}
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessagePostfixImpl)

System::String CoreTools::LogMessagePostfixImpl
	::GetPostfix() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Postfix;
}

int CoreTools::LogMessagePostfixImpl
	::GetPostfixSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Postfix.size());
}


