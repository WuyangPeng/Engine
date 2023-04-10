///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:21)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateHead.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateHead::CSVGenerateHead(CSVHead csvHead, String suffix) noexcept
    : csvHead{ std::move(csvHead) }, suffix{ std::move(suffix) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateHead)

System::String CoreTools::CSVGenerateHead::GenerateCoreToolsHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateCoreToolsShareHead();

    content += TextParsing::gUnicodeUsing;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateCoreToolsChildHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateCoreToolsShareHead();

    content += TextParsing::gIncludePrefix;
    content += csvHead.GetCSVClassName();
    content += TextParsing::gBase;
    content += TextParsing::gHeadFileSuffix;

    content += TextParsing::gUnicodeUsing;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateCoreToolsShareHead() const
{
    String content{ TextParsing::gCoreToolsHeadFile };
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIncludePrefix;
    content += csvHead.GetNameSpace();
    content += TextParsing::gFwd;
    content += TextParsing::gHeadFileSuffix;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateVectorHeadContent() const
{
    using CSVDataTypeIndex = std::pair<CSVDataType, CSVDataType>;
    using HeadContent = std::pair<CSVDataTypeIndex, System::StringView>;
    using HeadContentContainer = std::vector<HeadContent>;

    static const HeadContentContainer head{ { { CSVDataType::IntVector2, CSVDataType::IntVector2Array }, TextParsing::gIncludeIntVector2 },
                                            { { CSVDataType::IntVector3, CSVDataType::IntVector3Array }, TextParsing::gIncludeIntVector3 },
                                            { { CSVDataType::IntVector4, CSVDataType::IntVector4Array }, TextParsing::gIncludeIntVector4 },
                                            { { CSVDataType::Vector2, CSVDataType::Vector2Array }, TextParsing::gIncludeVector2 },
                                            { { CSVDataType::Vector3, CSVDataType::Vector3Array }, TextParsing::gIncludeVector3 },
                                            { { CSVDataType::Vector4, CSVDataType::Vector4Array }, TextParsing::gIncludeVector4 } };

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

    content += TextParsing::gNewlineCharacter;

    if (csvHead.HasDataType(CSVDataType::BoolArray))
    {
        content += TextParsing::gDequeInclude;
    }

    if (csvHead.HasMapping())
    {
        content += TextParsing::gMemoryInclude;
    }

    if (csvHead.HasVectorArrayDataType())
    {
        content += TextParsing::gVectorInclude;
    }

    if (csvHead.HasArrayDataType())
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateContainerHead() const
{
    String content{ TextParsing::gNewlineCharacter };

    if (csvHead.GetCSVFormatType() == CSVFormatType::TreeMap)
    {
        content += TextParsing::gMapInclude;
    }

    content += TextParsing::gMemoryInclude;

    if (csvHead.GetCSVFormatType() == CSVFormatType::HashMap)
    {
        content += TextParsing::gUnorderedMapInclude;
    }

    content += TextParsing::gVectorInclude;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateContainerDetailHead() const
{
    String content{ TextParsing::gIncludePrefix };

    content += csvHead.GetCSVClassName();
    content += suffix;
    content += TextParsing::gHeadFileSuffix;

    content += TextParsing::gUserClassInvariantMacro;
    content += TextParsing::gExceptionMacro;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateBaseSourceHead() const
{
    String content{ TextParsing::gIncludePrefix };

    content += csvHead.GetCSVClassName();
    content += suffix;
    content += TextParsing::gHeadFileSuffix;

    content += TextParsing::gUserClassInvariantMacro;
    content += TextParsing::gExceptionMacro;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateSourceHeadMappingHead() const
{
    const auto mappingHead = GetMappingHead();

    String content{};

    for (const auto& value : mappingHead)
    {
        content += TextParsing::gIncludePrefix;
        content += value;
        content += TextParsing::gHeadFileSuffix;
    }

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateSourceHead() const
{
    auto content = GenerateSourceHeadMappingHead();

    if (csvHead.HasArrayDataType())
    {
        content += TextParsing::gNumericCast;
    }

    content += TextParsing::gUserClassInvariantMacro;

    if (csvHead.HasScope())
    {
        content += TextParsing::gExceptionMacro;
    }

    content += TextParsing::gCSVRowDetail;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gUsingNamespaceLiterals;
    content += TextParsing::gNewlineCharacter;

    return content;
}

CoreTools::CSVGenerateHead::MappingType CoreTools::CSVGenerateHead::GetMappingHead() const
{
    MappingType local{ csvHead.GetCSVClassName() + suffix };

    if (csvHead.HasMapping())
    {
        local.emplace(csvHead.GetNameSpace() + TextParsing::gContainer.data());

        const auto count = csvHead.GetCount();
        for (auto index = 0; index < count; ++index)
        {
            if (const auto mapping = csvHead.GetMapping(index); !mapping.empty())
            {
                local.emplace(StringUtility::ToFirstLetterUpper(mapping) + TextParsing::gContainer.data());
            }
        }
    }

    return local;
}

System::String CoreTools::CSVGenerateHead::GenerateContainerSourceHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName();

    String content{ TextParsing::gIncludePrefix };
    content += className;
    content += TextParsing::gHeadFileSuffix;

    content += TextParsing::gIncludePrefix;
    content += className;
    content += suffix;

    if (csvHead.GetCSVFormatType() == CSVFormatType::Unique)
    {
        content += TextParsing::gHeadFileSuffix;
        content += TextParsing::gUserClassInvariantMacro;
        content += TextParsing::gExceptionMacro;
    }
    else
    {
        content += TextParsing::gHeadDetailFileSuffix;
    }

    content += TextParsing::gLogMacro;
    content += TextParsing::gIncludeCSVContent;
    content += TextParsing::gIncludeCSVHead;
    content += TextParsing::gIncludeCSVRow;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gAlgorithmInclude;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateEnumSourceHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    String content{ TextParsing::gIncludePrefix };
    content += className;
    content += TextParsing::gHeadFileSuffix;

    content += TextParsing::gUserClassInvariantMacro;
    content += TextParsing::gExceptionMacro;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gMapInclude;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gUsingNamespaceLiterals;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateHead::GenerateEnumHead()
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gCoreToolsHeadFile };
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gEnumMacro;
    content += TextParsing::gIncludeCSVRow;

    return content;
}
