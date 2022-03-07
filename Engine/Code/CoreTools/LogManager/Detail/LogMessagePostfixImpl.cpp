///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/07 22:42)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderPrintFlagsExist.h"
#include "LogMessagePostfixImpl.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"

using namespace std::literals;

CoreTools::LogMessagePostfixImpl::LogMessagePostfixImpl(AppenderPrint appenderFlags, LogLevel level, const FunctionDescribed& functionDescribed)
    : postfix{}, appenderFlags{ appenderFlags }, level{ level }, functionDescribed{ functionDescribed }
{
    GeneratePostfix();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::LogMessagePostfixImpl::GeneratePostfix()
{
    if (level != LogLevel::Disabled)
    {
        GenerateFunctionDescribedPostfix();
    }
}

// private
void CoreTools::LogMessagePostfixImpl::GenerateFunctionDescribedPostfix()
{
    if (AppenderPrintFlagsExist::IsExist(appenderFlags, AppenderPrint::PostfixFunctionDescribed))
    {
        boost::format format{ "���ļ���%1%��������%2%����%3%�У�����\n"s };

        format % functionDescribed.GetFileName();
        format % functionDescribed.GetCurrentFunction();
        format % functionDescribed.GetLine();

        postfix += StringConversion::MultiByteConversionStandard(format.str());
    }
    else
    {
        postfix += SYSTEM_TEXT("\n"s);
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogMessagePostfixImpl)

System::String CoreTools::LogMessagePostfixImpl::GetPostfix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return postfix;
}

int CoreTools::LogMessagePostfixImpl::GetPostfixSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(postfix.size());
}
