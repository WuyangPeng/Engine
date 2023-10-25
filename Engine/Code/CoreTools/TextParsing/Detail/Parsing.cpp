///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:10)

#include "CoreTools/CoreToolsExport.h"

#include "Parsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::Parsing::Parsing() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Parsing)

CoreTools::Parsing::SplitType CoreTools::Parsing::GetSplitComma(const String& column)
{
    SplitType result{};

    split(result, column, boost::is_any_of(TextParsing::gComma), boost::token_compress_off);

    return result;
}
