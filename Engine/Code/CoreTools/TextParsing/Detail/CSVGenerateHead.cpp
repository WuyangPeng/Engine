///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/02 10:56)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateHead.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

#include <tuple>

using std::set;
using std::tuple;
using std::vector;
using namespace std::literals;
using namespace CoreTools::TextParsing;

CoreTools::CSVGenerateHead::CSVGenerateHead(const CSVHead& csvHead, const String& suffix)
    : csvHead{ csvHead }, suffix{ suffix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateHead)

System::String CoreTools::CSVGenerateHead::GenerateCoreToolsHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateCoreToolsShareHead();

    content += g_UnicodeUsing;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateCoreToolsChildHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateCoreToolsShareHead();

    content += g_IncludePrefix;
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("Base.h\"\n"s);

    content += g_UnicodeUsing;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateCoreToolsShareHead() const
{
    String content{ g_CoreToolsHeadFile };
    content += g_NewlineCharacter;

    content += g_IncludePrefix;
    content += csvHead.GetNameSpace();
    content += SYSTEM_TEXT("Fwd.h\"\n"s);

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateVectorHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    static vector<tuple<CSVDataType, CSVDataType, System::StringView>>
        head{ { CSVDataType::IntVector2, CSVDataType::IntVector2Array, SYSTEM_TEXT("#include \"CoreTools/TextParsing/Data/IntVector2.h\"\n") },
              { CSVDataType::IntVector3, CSVDataType::IntVector3Array, SYSTEM_TEXT("#include \"CoreTools/TextParsing/Data/IntVector3.h\"\n") },
              { CSVDataType::IntVector4, CSVDataType::IntVector4Array, SYSTEM_TEXT("#include \"CoreTools/TextParsing/Data/IntVector4.h\"\n") },
              { CSVDataType::Vector2, CSVDataType::Vector2Array, SYSTEM_TEXT("#include \"CoreTools/TextParsing/Data/Vector2.h\"\n") },
              { CSVDataType::Vector3, CSVDataType::Vector3Array, SYSTEM_TEXT("#include \"CoreTools/TextParsing/Data/Vector3.h\"\n") },
              { CSVDataType::Vector4, CSVDataType::Vector4Array, SYSTEM_TEXT("#include \"CoreTools/TextParsing/Data/Vector4.h\"\n") } };

    String content{};

    for (const auto& value : head)
    {
        if (csvHead.HasDataType(std::get<0>(value)) || csvHead.HasDataType(std::get<1>(value)))
        {
            content += std::get<2>(value);
        }
    }

    content += g_NewlineCharacter;

    if (csvHead.HasDataType(CSVDataType::BoolArray))
    {
        content += g_Deque;
    }

    if (csvHead.HasMapping())
    {
        content += g_Memory;
    }

    if (csvHead.HasVectorArrayDataType())
    {
        content += g_Vector;
    }

    if (csvHead.HasArrayDataType())
    {
        content += g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateContainerHead() const
{
    String content{ g_NewlineCharacter };

    if (csvHead.GetCSVFormatType() == CSVFormatType::TreeMap)
    {
        content += g_Map;
    }

    content += g_Memory;

    if (csvHead.GetCSVFormatType() == CSVFormatType::HashMap)
    {
        content += g_UnorderedMap;
    }

    content += g_Vector;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateContainerDetailHead() const
{
    auto content = g_IncludePrefix.data() + csvHead.GetCSVClassName() + suffix + g_HeadFileSuffix.data();

    content += g_UserClassInvariantMacro;
    content += g_ExceptionMacro;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateBaseSourceHead() const
{
    auto content = g_IncludePrefix.data() + csvHead.GetCSVClassName() + suffix + g_HeadFileSuffix.data();

    content += g_UserClassInvariantMacro;
    content += g_ExceptionMacro;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateSourceHead() const
{
    auto mappingHead = GetMappingHead();

    String content{};

    for (const auto& value : mappingHead)
    {
        content += g_IncludePrefix;
        content += value;
        content += g_HeadFileSuffix;
    }

    if (csvHead.HasArrayDataType())
    {
        content += SYSTEM_TEXT("#include \"System/Helper/PragmaWarning/NumericCast.h\"\n"s);
    }

    content += g_UserClassInvariantMacro;

    if (csvHead.HasScope())
    {
        content += g_ExceptionMacro;
    }

    content += SYSTEM_TEXT("#include \"CoreTools/TextParsing/CSVRowDetail.h\"\n"s);
    content += g_NewlineCharacter;

    content += SYSTEM_TEXT("using namespace std::literals;\n"s);
    content += g_NewlineCharacter;

    return content;
}

set<System::String> CoreTools::CSVGenerateHead::GetMappingHead() const
{
    set<String> local{ csvHead.GetCSVClassName() + suffix };

    if (csvHead.HasMapping())
    {
        local.emplace(csvHead.GetNameSpace() + g_Container.data());

        const auto count = csvHead.GetCount();
        for (auto i = 0; i < count; ++i)
        {
            const auto mapping = csvHead.GetMapping(i);
            if (!mapping.empty())
            {
                local.emplace(StringConversion::ToFirstLetterUpper(mapping) + g_Container.data());
            }
        }
    }

    return local;
}

System::String CoreTools::CSVGenerateHead::GenerateContainerSourceHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName();

    auto content = g_IncludePrefix.data() + className + g_HeadFileSuffix.data();

    content += g_IncludePrefix;
    content += className;
    content += suffix;

    if (csvHead.GetCSVFormatType() == CSVFormatType::Unique)
    {
        content += g_HeadFileSuffix;
        content += g_UserClassInvariantMacro;
        content += g_ExceptionMacro;
    }
    else
    {
        content += SYSTEM_TEXT("Detail.h\"\n"s);
    }

    content += SYSTEM_TEXT("#include \"CoreTools/Helper/LogMacro.h\"\n"s);
    content += SYSTEM_TEXT("#include \"CoreTools/TextParsing/CSVContent.h\"\n"s);
    content += SYSTEM_TEXT("#include \"CoreTools/TextParsing/CSVHead.h\"\n"s);
    content += SYSTEM_TEXT("#include \"CoreTools/TextParsing/CSVRow.h\"\n"s);
    content += g_NewlineCharacter;

    content += SYSTEM_TEXT("#include <algorithm>\n"s);
    content += g_NewlineCharacter;

    content += SYSTEM_TEXT("using std::make_shared;\n"s);
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateEnumSourceHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    auto content = g_IncludePrefix.data() + className + g_HeadFileSuffix.data();

    content += g_UserClassInvariantMacro;
    content += g_ExceptionMacro;
    content += g_NewlineCharacter;

    content += g_Map;
    content += g_NewlineCharacter;

    content += SYSTEM_TEXT("using std::map;\n"s);
    content += SYSTEM_TEXT("using namespace std::literals;\n"s);
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateEnumHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ g_CoreToolsHeadFile };
    content += g_NewlineCharacter;

    content += SYSTEM_TEXT("#include \"System/Helper/EnumMacro.h\"\n"s);
    content += SYSTEM_TEXT("#include \"CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h\"\n");
    content += SYSTEM_TEXT("#include \"CoreTools/TextParsing/CSVRow.h\"\n"s);

    return content;
}
