///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:15)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateClassName.h"
#include "CSVGenerateDataHeadFile.h"
#include "CSVGenerateDefaultFunction.h"
#include "CSVGenerateGetFunction.h"
#include "CSVGenerateHead.h"
#include "CSVGenerateMember.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateDataHeadFile::CSVGenerateDataHeadFile(const CSVHead& csvHead) noexcept
    : ParentType{ csvHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateDataHeadFile)

System::String CoreTools::CSVGenerateDataHeadFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateDataHeadFile::GetFilePrefix() const
{
    return String{ TextParsing::g_ForwardSlash };
}

System::String CoreTools::CSVGenerateDataHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::g_HeadFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateDataHeadFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += TextParsing::g_NewlineCharacter;
    content += GenerateHeaderGuard();

    CSVGenerateHead csvGenerateHead{ GetCSVHead(), GetSuffix() };
    content += csvGenerateHead.GenerateCoreToolsHead();
    content += csvGenerateHead.GenerateVectorHead();

    content += GenerateNameSpace();

    CSVGenerateClassName csvGenerateClassName{ GetCSVHead(), GetSuffix() };
    content += csvGenerateClassName.GenerateClassName();

    CSVGenerateDefaultFunction csvGenerateDefaultFunction{ GetCSVHead(), GetSuffix() };
    content += csvGenerateDefaultFunction.GenerateDefaultFunction();

    CSVGenerateGetFunction csvGenerateGetFunction{ GetCSVHead(), GetKeyTypeDescribe() };
    content += csvGenerateGetFunction.GenerateGetFunction();

    CSVGenerateMember csvGenerateMember{ GetCSVHead(), GetKeyTypeDescribe() };
    content += csvGenerateMember.GenerateChildMember();

    content += GenerateHeaderGuardEndif();

    return content;
}
