///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:28)

#include "CoreTools/CoreToolsExport.h"

#include "DefaultSharedPtrUsingParsing.h"
#include "MapSharedPtrUsingParsing.h"
#include "SharedPtrUsingParsing.h"
#include "UniqueSharedPtrUsingParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using namespace std::literals;

CoreTools::SharedPtrUsingParsing::SharedPtrUsingParsingUniquePtr CoreTools::SharedPtrUsingParsing::Create(CSVFormatType csvFormatType, int indentationCount, const String& className, const String& keyTypeDescribe)
{
    switch (csvFormatType)
    {
        case CSVFormatType::TreeMap:
        {
            return std::make_unique<MapSharedPtrUsingParsing>(indentationCount, className, keyTypeDescribe, TextParsing::g_OriginalMap);
        }
        break;
        case CSVFormatType::HashMap:
        {
            return std::make_unique<MapSharedPtrUsingParsing>(indentationCount, className, keyTypeDescribe, TextParsing::g_OriginalUnorderedMap);
        }
        break;
        case CSVFormatType::Unique:
        {
            return std::make_unique<UniqueSharedPtrUsingParsing>(indentationCount, className);
        }
        break;
        default:
        {
            return std::make_unique<DefaultSharedPtrUsingParsing>(indentationCount, className);
        }
        break;
    }
}

CoreTools::SharedPtrUsingParsing::SharedPtrUsingParsing(int indentationCount, const String& className)
    : ParentType{ indentationCount }, className{ className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SharedPtrUsingParsing)

System::String CoreTools::SharedPtrUsingParsing::GenerateSharedPtr(StringView suffix) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += SYSTEM_TEXT("using Const"s);
    content += className;
    content += suffix;
    content += SYSTEM_TEXT("SharedPtr = std::shared_ptr<const "s);
    content += className;
    content += suffix;
    content += TextParsing::g_RightAngleBracketSemicolonNewline;

    return content;
}

System::String CoreTools::SharedPtrUsingParsing::GenerateSharedPtrContainer(StringView suffix) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateIndentation();

    content += SYSTEM_TEXT("using Container = std::vector<Const"s);
    content += className;
    content += suffix;
    content += TextParsing::g_SharedPtr;
    content += TextParsing::g_RightAngleBracketSemicolonNewline;

    return content;
}

System::String CoreTools::SharedPtrUsingParsing::GenerateSharedPtrMappingContainer(const String& keyTypeDescribe, StringView mappingName) const
{
    auto content = GenerateIndentation();

    content += SYSTEM_TEXT("using MappingContainer = std::"s);
    content += mappingName;
    content += TextParsing::g_LeftAngleBracket;
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(", Const"s);
    content += className;
    content += TextParsing::g_SharedPtr;
    content += TextParsing::g_RightAngleBracketSemicolonNewline;

    return content;
}
