///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 18:09)

#include "CoreTools/CoreToolsExport.h"

#include "JsonTotalGenerateFwdHeadFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::JsonTotalGenerateFwdHeadFile::JsonTotalGenerateFwdHeadFile(const String& nameSpace, const JsonHeadContainer& jsonHeadContainer)
    : ParentType{ nameSpace, jsonHeadContainer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonTotalGenerateFwdHeadFile)

System::String CoreTools::JsonTotalGenerateFwdHeadFile::GetFileSuffix() const
{
    return TextParsing::gFwdHeadFileExtensionName.data();
}

System::String CoreTools::JsonTotalGenerateFwdHeadFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += GenerateNewLine();
    content += GenerateHeaderGuard();

    content += GenerateFwdHead();
    content += GenerateNameSpace();
    content += GenerateFwd();

    content += GenerateHeaderGuardEndif();

    return content;
}
