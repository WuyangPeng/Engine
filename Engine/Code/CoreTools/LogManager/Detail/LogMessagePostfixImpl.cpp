/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:04)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderPrintFlagsExist.h"
#include "LogMessagePostfixImpl.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"

CoreTools::LogMessagePostfixImpl::LogMessagePostfixImpl(AppenderPrint appenderPrint, LogLevel level, const FunctionDescribed& functionDescribed)
    : postfix{}, appenderPrint{ appenderPrint }, level{ level }, functionDescribed{ static_cast<FunctionDescribed>(functionDescribed) }
{
    GeneratePostfix();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::LogMessagePostfixImpl::GeneratePostfix()
{
    if (level != LogLevel::Disabled)
    {
        GenerateFunctionDescribedPostfix();
    }
}

void CoreTools::LogMessagePostfixImpl::GenerateFunctionDescribedPostfix()
{
    if (AppenderPrintFlagsExist::IsExist(appenderPrint, AppenderPrint::PostfixFunctionDescribed))
    {
        boost::format format{ "【文件：%1%，函数：%2%（第%3%行）。】\n" };

        format % functionDescribed.GetFileName();
        format % functionDescribed.GetCurrentFunction();
        format % functionDescribed.GetLine();

        postfix += StringConversion::MultiByteConversionStandard(format.str());
    }
    else
    {
        postfix += SYSTEM_TEXT("\n");
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
