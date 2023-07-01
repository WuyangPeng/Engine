///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:20)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateClassName.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/ClassNameParsing.h"
#include "CoreTools/TextParsing/Detail/SharedPtrUsingParsing.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateClassName::CSVGenerateClassName(const CSVHead& csvHead, const String& suffix)
    : csvHead{ csvHead }, suffix{ suffix }, className{ csvHead.GetCSVClassName() + suffix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateClassName)

System::String CoreTools::CSVGenerateClassName::GenerateParentClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    constexpr auto indentationCount = 1;
    const ClassNameParsing classNameParsing{ indentationCount, className };

    auto content = classNameParsing.GenerateParentClassName();

    content += classNameParsing.GenerateFunctionBeginBrackets();
    content += classNameParsing.GeneratePublic();
    content += classNameParsing.GenerateClassType();
    content += TextParsing::gNewlineCharacter;

    auto isOtherUsing = false;
    if (csvHead.HasDataType(CSVDataType::String))
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using String = System::String;\n");

        isOtherUsing = true;
    }

    if (csvHead.HasDataType(CSVDataType::StringArray))
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using StringContainer = std::vector<String>;\n");
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using StringContainerConstIter = StringContainer::const_iterator;\n");

        isOtherUsing = true;
    }

    if (csvHead.HasDataType(CSVDataType::IntArray))
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using IntContainer = std::vector<int>;\n");
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using IntContainerConstIter = IntContainer::const_iterator;\n");

        isOtherUsing = true;
    }

    if (csvHead.HasDataType(CSVDataType::Int64Array))
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using Int64Container = std::vector<int64_t>;\n");
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using Int64ContainerConstIter = Int64Container::const_iterator;\n");

        isOtherUsing = true;
    }

    if (csvHead.HasDataType(CSVDataType::BoolArray))
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using BoolContainer = std::deque<bool>;\n");
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using BoolContainerConstIter = BoolContainer::const_iterator;\n");

        isOtherUsing = true;
    }

    if (csvHead.HasDataType(CSVDataType::CharArray))
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using CharContainer = std::vector<System::TChar>;\n");
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using CharContainerConstIter = CharContainer::const_iterator;\n");

        isOtherUsing = true;
    }

    if (csvHead.HasMapping())
    {
        for (auto i = 0; i < csvHead.GetCount(); ++i)
        {
            const auto mapping = csvHead.GetMapping(i);
            if (!mapping.empty())
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("using Const");
                content += StringUtility::ToFirstLetterUpper(mapping);
                content += SYSTEM_TEXT("SharedPtr = std::shared_ptr<const ");
                content += StringUtility::ToFirstLetterUpper(mapping);
                content += SYSTEM_TEXT("MappingType>;\n");

                if (CSVDataType::BoolArray <= csvHead.GetDataType(i))
                {
                    content += TextParsing::gIndentation;
                    content += TextParsing::gIndentation;
                    content += SYSTEM_TEXT("using ");
                    content += StringUtility::ToFirstLetterUpper(mapping);
                    content += SYSTEM_TEXT("Container = std::vector<Const");
                    content += StringUtility::ToFirstLetterUpper(mapping);
                    content += SYSTEM_TEXT("SharedPtr>;\n");
                }
            }
        }
    }

    if (isOtherUsing)
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateClassName::GenerateChildClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    constexpr auto indentationCount = 1;
    const ClassNameParsing classNameParsing{ indentationCount, className };

    auto content = classNameParsing.GenerateChildClassName();

    content += classNameParsing.GenerateFunctionBeginBrackets();
    content += classNameParsing.GeneratePublic();
    content += classNameParsing.GenerateClassType();
    content += classNameParsing.GenerateParentType();
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("using CSVRow = CoreTools::CSVRow;\n");

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateClassName::GenerateClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    constexpr auto indentationCount = 1;
    const ClassNameParsing classNameParsing{ indentationCount, className };

    auto content = classNameParsing.GenerateClassName();

    content += classNameParsing.GenerateFunctionBeginBrackets();
    content += classNameParsing.GeneratePublic();
    content += classNameParsing.GenerateClassType();
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("using CSVRow = CoreTools::CSVRow;\n");

    if (csvHead.HasDataType(CSVDataType::String))
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using String = System::String;\n");
    }

    if (csvHead.HasDataType(CSVDataType::StringArray))
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using StringContainer = std::vector<String>;\n");
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using StringContainerConstIter = StringContainer::const_iterator;\n");
    }

    if (csvHead.HasDataType(CSVDataType::IntArray))
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using IntContainer = std::vector<int>;\n");
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using IntContainerConstIter = IntContainer::const_iterator;\n");
    }

    if (csvHead.HasDataType(CSVDataType::Int64Array))
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using Int64Container = std::vector<int64_t>;\n");
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using Int64ContainerConstIter = Int64Container::const_iterator;\n");
    }

    if (csvHead.HasDataType(CSVDataType::BoolArray))
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using BoolContainer = std::deque<bool>;\n");
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using BoolContainerConstIter = BoolContainer::const_iterator;\n");
    }

    if (csvHead.HasDataType(CSVDataType::CharArray))
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using CharContainer = std::vector<System::TChar>;\n");
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("using CharContainerConstIter = CharContainer::const_iterator;\n");
    }

    if (csvHead.HasMapping())
    {
        for (auto i = 0; i < csvHead.GetCount(); ++i)
        {
            const auto mapping = csvHead.GetMapping(i);
            if (!mapping.empty())
            {
                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += SYSTEM_TEXT("using Const");
                content += StringUtility::ToFirstLetterUpper(mapping);
                content += SYSTEM_TEXT("SharedPtr = std::shared_ptr<const ");
                content += StringUtility::ToFirstLetterUpper(mapping);
                content += SYSTEM_TEXT("MappingType>;\n");

                if (CSVDataType::BoolArray <= csvHead.GetDataType(i))
                {
                    content += TextParsing::gIndentation;
                    content += TextParsing::gIndentation;
                    content += SYSTEM_TEXT("using ");
                    content += StringUtility::ToFirstLetterUpper(mapping);
                    content += SYSTEM_TEXT("Container = std::vector<Const");
                    content += StringUtility::ToFirstLetterUpper(mapping);
                    content += SYSTEM_TEXT("SharedPtr>;\n");
                }
            }
        }
    }

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateClassName::GenerateContainerClassName(const String& keyTypeDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    constexpr auto indentationCount = 1;
    const ClassNameParsing classNameParsing{ indentationCount, className };

    auto content = classNameParsing.GenerateClassName();

    content += classNameParsing.GenerateFunctionBeginBrackets();
    content += classNameParsing.GeneratePublic();
    content += classNameParsing.GenerateClassType();
    content += TextParsing::gNewlineCharacter;

    content += GenerateSharedPtrUsing(keyTypeDescribe);

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateClassName::GenerateSharedPtrUsing(const String& keyTypeDescribe) const
{
    constexpr auto indentationCount = 2;
    const auto csvFormatType = csvHead.GetCSVFormatType();

    const auto sharedPtrUsingParsing = SharedPtrUsingParsing::Create(csvFormatType, indentationCount, csvHead.GetCSVClassName(), keyTypeDescribe);

    return sharedPtrUsingParsing->GenerateSharedPtrUsing();
}

System::String CoreTools::CSVGenerateClassName::GenerateEnumClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    constexpr auto indentationCount = 1;
    const ClassNameParsing classNameParsing{ indentationCount, className };

    auto content = classNameParsing.GenerateEnumClassName();

    content += classNameParsing.GenerateFunctionBeginBrackets();

    return content;
}
