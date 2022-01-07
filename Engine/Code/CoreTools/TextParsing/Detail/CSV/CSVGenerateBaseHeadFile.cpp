///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:13)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateBaseHeadFile.h"
#include "CSVGenerateClassName.h"
#include "CSVGenerateDefaultFunction.h"
#include "CSVGenerateGetFunction.h"
#include "CSVGenerateHead.h"
#include "CSVGenerateMember.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using namespace std::literals;

CoreTools::CSVGenerateBaseHeadFile::CSVGenerateBaseHeadFile(const CSVHead& csvHead) noexcept
    : ParentType{ csvHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateBaseHeadFile)

System::String CoreTools::CSVGenerateBaseHeadFile::GetSuffix() const
{
    return String{ TextParsing::g_Base };
}

System::String CoreTools::CSVGenerateBaseHeadFile::GetFilePrefix() const
{
    return String{ TextParsing::g_ForwardSlash };
}

System::String CoreTools::CSVGenerateBaseHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::g_HeadFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateBaseHeadFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += TextParsing::g_NewlineCharacter;
    content += GenerateHeaderGuard();

    CSVGenerateHead csvGenerateHead{ GetCSVHead(), GetSuffix() };
    content += csvGenerateHead.GenerateCoreToolsHead();
    content += csvGenerateHead.GenerateVectorHead();

    content += GenerateNameSpace();

    CSVGenerateClassName csvGenerateClassName{ GetCSVHead(), GetSuffix() };
    content += csvGenerateClassName.GenerateParentClassName();

    CSVGenerateDefaultFunction csvGenerateDefaultFunction{ GetCSVHead(), GetSuffix() };
    content += csvGenerateDefaultFunction.GenerateBaseDefaultFunction();

    CSVGenerateGetFunction csvGenerateGetFunction{ GetCSVHead(), GetKeyTypeDescribe() };
    content += csvGenerateGetFunction.GenerateBaseGetFunction();

    CSVGenerateMember csvGenerateMember{ GetCSVHead(), GetKeyTypeDescribe() };
    content += csvGenerateMember.GenerateBaseMember();

    content += GenerateHeaderGuardEndif();

    return content;
}
