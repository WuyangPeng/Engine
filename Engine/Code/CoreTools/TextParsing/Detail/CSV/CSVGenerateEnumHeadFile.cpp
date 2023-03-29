///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 17:36)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateClassName.h"
#include "CSVGenerateEnumHeadFile.h"
#include "CSVGenerateGetFunction.h"
#include "CSVGenerateHead.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/Detail/EnumHeadFileParsing.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateEnumHeadFile::CSVGenerateEnumHeadFile(const CSVContent& csvContent)
    : ParentType{ csvContent.GetCSVHead() }, csvContent{ csvContent }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateEnumHeadFile)

System::String CoreTools::CSVGenerateEnumHeadFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateEnumHeadFile::GetFilePrefix() const
{
    return String{ TextParsing::gEnumFilePrefix };
}

System::String CoreTools::CSVGenerateEnumHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gHeadFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateEnumHeadFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += TextParsing::gNewlineCharacter;
    content += GenerateHeaderGuard();

    CSVGenerateHead csvGenerateHead{ GetCSVHead(), GetSuffix() };
    content += csvGenerateHead.GenerateEnumHead();
    content += TextParsing::gNewlineCharacter;

    EnumHeadFileParsing enumHeadFileParsing{ GetCSVHead(), csvContent, GetCSVClassName() + GetSuffix() };

    content += GenerateNameSpace();

    CSVGenerateClassName csvGenerateClassName{ GetCSVHead(), GetSuffix() };
    content += csvGenerateClassName.GenerateEnumClassName();

    content += enumHeadFileParsing.GenerateEnumContent();
    content += enumHeadFileParsing.GenerateEnumFunction();
    content += enumHeadFileParsing.GenerateEnumOperator();

    CSVGenerateGetFunction csvGenerateGetFunction{ GetCSVHead(), GetSuffix() };
    content += csvGenerateGetFunction.GenerateStringCastEnumFunction();

    content += GenerateHeaderGuardEndif();

    return content;
}
