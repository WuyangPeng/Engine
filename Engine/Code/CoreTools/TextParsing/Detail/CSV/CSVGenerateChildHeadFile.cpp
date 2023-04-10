///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 17:19)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateChildHeadFile.h"
#include "CSVGenerateClassName.h"
#include "CSVGenerateDefaultFunction.h"
#include "CSVGenerateGetFunction.h"
#include "CSVGenerateHead.h"
#include "CSVGenerateMember.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVGenerateChildHeadFile::CSVGenerateChildHeadFile(const CSVHead& csvHead) noexcept
    : ParentType{ csvHead }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVGenerateChildHeadFile)

System::String CoreTools::CSVGenerateChildHeadFile::GetSuffix() const noexcept
{
    return String{};
}

System::String CoreTools::CSVGenerateChildHeadFile::GetFilePrefix() const
{
    return String{ TextParsing::gForwardSlash };
}

System::String CoreTools::CSVGenerateChildHeadFile::GetFileSuffix() const
{
    auto result = GetSuffix();

    result += TextParsing::gHeadFileExtensionName;

    return result;
}

System::String CoreTools::CSVGenerateChildHeadFile::GetContent() const
{
    String content{ TextParsing::gCopyright };

    content += TextParsing::gNewlineCharacter;
    content += GenerateHeaderGuard();

    CSVGenerateHead csvGenerateHead{ GetCSVHead(), GetSuffix() };
    content += csvGenerateHead.GenerateCoreToolsChildHead();
    content += TextParsing::gNewlineCharacter;

    content += GenerateNameSpace();

    CSVGenerateClassName csvGenerateClassName{ GetCSVHead(), GetSuffix() };
    content += csvGenerateClassName.GenerateChildClassName();

    CSVGenerateDefaultFunction csvGenerateDefaultFunction{ GetCSVHead(), GetSuffix() };
    content += csvGenerateDefaultFunction.GenerateChildDefaultFunction();

    CSVGenerateGetFunction csvGenerateGetFunction{ GetCSVHead(), GetKeyTypeDescribe() };
    content += csvGenerateGetFunction.GenerateChildGetFunction();

    CSVGenerateMember csvGenerateMember{ GetCSVHead(), GetKeyTypeDescribe() };
    content += csvGenerateMember.GenerateChildMember();

    content += GenerateHeaderGuardEndif();

    return content;
}
