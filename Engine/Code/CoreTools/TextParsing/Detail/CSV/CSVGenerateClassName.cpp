///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 17:05)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateClassName.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/ClassNameParsing.h"
#include "CoreTools/TextParsing/Detail/SharedPtrUsingParsing.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using namespace std::literals;

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
