///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 16:37)

#include "CoreTools/CoreToolsExport.h"

#include "DefaultSharedPtrUsingParsing.h"
#include "MapSharedPtrUsingParsing.h"
#include "SharedPtrUsingParsing.h"
#include "UniqueSharedPtrUsingParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::SharedPtrUsingParsing::SharedPtrUsingParsingUniquePtr CoreTools::SharedPtrUsingParsing::Create(CSVFormatType csvFormatType, int indentationCount, const String& className, const String& keyTypeDescribe)
{
    switch (csvFormatType)
    {
        case CSVFormatType::TreeMap:
        {
            return std::make_unique<MapSharedPtrUsingParsing>(indentationCount, className, keyTypeDescribe, TextParsing::gMap);
        }
        case CSVFormatType::HashMap:
        {
            return std::make_unique<MapSharedPtrUsingParsing>(indentationCount, className, keyTypeDescribe, TextParsing::gUnorderedMap);
        }
        case CSVFormatType::Unique:
        {
            return std::make_unique<UniqueSharedPtrUsingParsing>(indentationCount, className);
        }
        default:
        {
            return std::make_unique<DefaultSharedPtrUsingParsing>(indentationCount, className);
        }
    }
}

CoreTools::SharedPtrUsingParsing::SharedPtrUsingParsing(int indentationCount, String className) noexcept
    : ParentType{ indentationCount }, className{ std::move(className) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SharedPtrUsingParsing)

System::String CoreTools::SharedPtrUsingParsing::GenerateSharedPtr(StringView suffix) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gUsingConst;
    content += className;
    content += suffix;
    content += TextParsing::gSharedPtrEqualTo;
    content += className;
    content += suffix;
    content += TextParsing::gRightAngleBracketSemicolonNewline;

    return content;
}

System::String CoreTools::SharedPtrUsingParsing::GenerateSharedPtrContainer(StringView suffix) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += TextParsing::gUsing;
    content += TextParsing::gSpace;
    content += TextParsing::gContainerEqualTo;
    content += className;
    content += suffix;
    content += TextParsing::gSharedPtr;
    content += TextParsing::gRightAngleBracketSemicolonNewline;

    return content;
}

System::String CoreTools::SharedPtrUsingParsing::GenerateSharedPtrMappingContainer(const String& keyTypeDescribe, StringView mappingName) const
{
    auto content = GenerateIndentation();

    content += TextParsing::gMappingContainerEqualTo;
    content += mappingName;
    content += TextParsing::gLeftAngleBracket;
    content += keyTypeDescribe;
    content += TextParsing::gComma;
    content += TextParsing::gSpace;
    content += TextParsing::gCapitalConst;
    content += className;
    content += TextParsing::gSharedPtr;
    content += TextParsing::gRightAngleBracketSemicolonNewline;

    return content;
}
