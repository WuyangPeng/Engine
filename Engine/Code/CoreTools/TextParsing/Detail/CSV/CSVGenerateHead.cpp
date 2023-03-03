///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:18)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateHead.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using std::pair;
using std::vector;

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

    content += TextParsing::g_UnicodeUsing;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateCoreToolsChildHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateCoreToolsShareHead();

    content += TextParsing::g_IncludePrefix;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_Base;
    content += TextParsing::g_HeadFileSuffix;

    content += TextParsing::g_UnicodeUsing;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateCoreToolsShareHead() const
{
    String content{ TextParsing::g_CoreToolsHeadFile };
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_IncludePrefix;
    content += csvHead.GetNameSpace();
    content += TextParsing::g_Fwd;
    content += TextParsing::g_HeadFileSuffix;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateVectorHeadContent() const
{
    using CSVDataTypeIndex = pair<CSVDataType, CSVDataType>;
    using HeadContent = pair<CSVDataTypeIndex, System::StringView>;
    using HeadContentContainer = vector<HeadContent>;

    static const HeadContentContainer head{ { { CSVDataType::IntVector2, CSVDataType::IntVector2Array }, TextParsing::g_IncludeIntVector2 },
                                            { { CSVDataType::IntVector3, CSVDataType::IntVector3Array }, TextParsing::g_IncludeIntVector3 },
                                            { { CSVDataType::IntVector4, CSVDataType::IntVector4Array }, TextParsing::g_IncludeIntVector4 },
                                            { { CSVDataType::Vector2, CSVDataType::Vector2Array }, TextParsing::g_IncludeVector2 },
                                            { { CSVDataType::Vector3, CSVDataType::Vector3Array }, TextParsing::g_IncludeVector3 },
                                            { { CSVDataType::Vector4, CSVDataType::Vector4Array }, TextParsing::g_IncludeVector4 } };

    String content{};

    for (const auto& value : head)
    {
        if (csvHead.HasDataType(value.first.first) || csvHead.HasDataType(value.first.second))
        {
            content += value.second;
        }
    }

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateVectorHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateVectorHeadContent();

    content += TextParsing::g_NewlineCharacter;

    if (csvHead.HasDataType(CSVDataType::BoolArray))
    {
        content += TextParsing::g_Deque;
    }

    if (csvHead.HasMapping())
    {
        content += TextParsing::g_Memory;
    }

    if (csvHead.HasVectorArrayDataType())
    {
        content += TextParsing::g_Vector;
    }

    if (csvHead.HasArrayDataType())
    {
        content += TextParsing::g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateContainerHead() const
{
    String content{ TextParsing::g_NewlineCharacter };

    if (csvHead.GetCSVFormatType() == CSVFormatType::TreeMap)
    {
        content += TextParsing::g_Map;
    }

    content += TextParsing::g_Memory;

    if (csvHead.GetCSVFormatType() == CSVFormatType::HashMap)
    {
        content += TextParsing::g_UnorderedMap;
    }

    content += TextParsing::g_Vector;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateContainerDetailHead() const
{
    String content{ TextParsing::g_IncludePrefix };

    content += csvHead.GetCSVClassName();
    content += suffix;
    content += TextParsing::g_HeadFileSuffix;

    content += TextParsing::g_UserClassInvariantMacro;
    content += TextParsing::g_ExceptionMacro;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateBaseSourceHead() const
{
    String content{ TextParsing::g_IncludePrefix };

    content += csvHead.GetCSVClassName();
    content += suffix;
    content += TextParsing::g_HeadFileSuffix;

    content += TextParsing::g_UserClassInvariantMacro;
    content += TextParsing::g_ExceptionMacro;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateSourceHeadMappingHead() const
{
    auto mappingHead = GetMappingHead();

    String content{};

    for (const auto& value : mappingHead)
    {
        content += TextParsing::g_IncludePrefix;
        content += value;
        content += TextParsing::g_HeadFileSuffix;
    }

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateSourceHead() const
{
    auto content = GenerateSourceHeadMappingHead();

    if (csvHead.HasArrayDataType())
    {
        content += TextParsing::g_NumericCast;
    }

    content += TextParsing::g_UserClassInvariantMacro;

    if (csvHead.HasScope())
    {
        content += TextParsing::g_ExceptionMacro;
    }

    content += TextParsing::g_CSVRowDetail;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_UsingNamespaceLiterals;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

CoreTools::CSVGenerateHead::MappingType CoreTools::CSVGenerateHead::GetMappingHead() const
{
    MappingType local{ csvHead.GetCSVClassName() + suffix };

    if (csvHead.HasMapping())
    {
        local.emplace(csvHead.GetNameSpace() + TextParsing::g_Container.data());

        const auto count = csvHead.GetCount();
        for (auto index = 0; index < count; ++index)
        {
            const auto mapping = csvHead.GetMapping(index);
            if (!mapping.empty())
            {
                local.emplace(StringUtility::ToFirstLetterUpper(mapping) + TextParsing::g_Container.data());
            }
        }
    }

    return local;
}

System::String CoreTools::CSVGenerateHead::GenerateContainerSourceHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName();

    String content{ TextParsing::g_IncludePrefix };
    content += className;
    content += TextParsing::g_HeadFileSuffix;

    content += TextParsing::g_IncludePrefix;
    content += className;
    content += suffix;

    if (csvHead.GetCSVFormatType() == CSVFormatType::Unique)
    {
        content += TextParsing::g_HeadFileSuffix;
        content += TextParsing::g_UserClassInvariantMacro;
        content += TextParsing::g_ExceptionMacro;
    }
    else
    {
        content += TextParsing::g_HeadDetailFileSuffix;
    }

    content += TextParsing::g_LogMacroMacro;
    content += TextParsing::g_IncludeCSVContent;
    content += TextParsing::g_IncludeCSVHead;
    content += TextParsing::g_IncludeCSVRow;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_Algorithm;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_UsingMakeShared;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateEnumSourceHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    String content{ TextParsing::g_IncludePrefix };
    content += className;
    content += TextParsing::g_HeadFileSuffix;

    content += TextParsing::g_UserClassInvariantMacro;
    content += TextParsing::g_ExceptionMacro;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_Map;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_UsingMap;
    content += TextParsing::g_UsingNamespaceLiterals;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateEnumHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::g_CoreToolsHeadFile };
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_EnumMacro;
    content += TextParsing::g_CoreToolsClassInvariantMacro;
    content += TextParsing::g_IncludeCSVRow;

    return content;
}
