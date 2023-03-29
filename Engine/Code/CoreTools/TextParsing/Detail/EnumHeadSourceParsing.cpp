///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 09:50)

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

CoreTools::EnumHeadSourceParsing::EnumHeadSourceParsing(CSVHead csvHead, CSVContent csvContent, String className) noexcept
    : ParentType{ 0 }, csvHead{ csvHead }, csvContent{ csvContent }, className{ className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EnumHeadSourceParsing)

System::String CoreTools::EnumHeadSourceParsing::GenerateEnumFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto nameIndex = csvHead.GetDataIndex(TextParsing::gEnumNameDescribe);
    const auto describeIndex = csvHead.GetDataIndex(TextParsing::gEnumDescribe);

    const StringCastEnumParsing stringCastEnumParsing{ csvHead, csvContent, className, nameIndex };
    auto content = stringCastEnumParsing.GenerateEnumFunctionDefinition();

    const EnumCastStringParsing enumCastStringParsing{ csvHead, csvContent, className, nameIndex };
    content += enumCastStringParsing.GenerateEnumFunctionDefinition();

    const EnumDescribeParsing enumDescribeParsing{ csvHead, csvContent, className, nameIndex, describeIndex };
    content += enumDescribeParsing.GenerateEnumFunctionDefinition();

    return content;
}
