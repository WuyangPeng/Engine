///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 14:08)

#include "CoreTools/CoreToolsExport.h"

#include "FormatTypeParsing.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::FormatTypeParsing::FormatTypeParsing(const String& formatTypeContent)
    : formatType{ CSVFormatType::Default }
{
    Parsing(formatTypeContent);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::FormatTypeParsing::Parsing(const String& formatTypeContent)
{
    const auto commaPosition = formatTypeContent.find(TextParsing::gComma);
    const auto equalSignPosition = formatTypeContent.find(TextParsing::gEqualSign);

    auto column = formatTypeContent.substr(0, commaPosition < equalSignPosition ? commaPosition : equalSignPosition);
    boost::algorithm::trim(column);

    if (!column.empty())
    {
        formatType = CSVTypeConversion::GetFormatType(column);

        if (formatType == CSVFormatType::Ignore)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("CSV��ʽ���Ͳ���ΪIgnore��"s))
        }
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FormatTypeParsing)

CoreTools::CSVFormatType CoreTools::FormatTypeParsing::GetCSVFormatType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return formatType;
}
