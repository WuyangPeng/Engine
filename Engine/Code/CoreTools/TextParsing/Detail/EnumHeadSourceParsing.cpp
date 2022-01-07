///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:23)

#include "CoreTools/CoreToolsExport.h"

#include "CSV/CSVGenerateHelper.h"
#include "EnumCastStringParsing.h"
#include "EnumDescribeParsing.h"
#include "EnumHeadSourceParsing.h"
#include "StringCastEnumParsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::EnumHeadSourceParsing::EnumHeadSourceParsing(const CSVHead& csvHead, const CSVContent& csvContent, const String& className)
    : ParentType{ 0 }, csvHead{ csvHead }, csvContent{ csvContent }, className{ className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EnumHeadSourceParsing)

System::String CoreTools::EnumHeadSourceParsing::GenerateEnumFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameIndex = csvHead.GetDataIndex(TextParsing::g_EnumNameDescribe);
    const auto describeIndex = csvHead.GetDataIndex(TextParsing::g_EnumDescribe);

    const StringCastEnumParsing stringCastEnumParsing{ csvHead, csvContent, className, nameIndex };
    auto content = stringCastEnumParsing.GenerateEnumFunctionDefinition();

    const EnumCastStringParsing enumCastStringParsing{ csvHead, csvContent, className, nameIndex };
    content += enumCastStringParsing.GenerateEnumFunctionDefinition();

    const EnumDescribeParsing enumDescribeParsing{ csvHead, csvContent, className, nameIndex, describeIndex };
    content += enumDescribeParsing.GenerateEnumFunctionDefinition();

    return content;
}
