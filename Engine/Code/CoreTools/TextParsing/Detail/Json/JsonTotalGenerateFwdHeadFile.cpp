///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:27)

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
    String content{ TextParsing::gCopyright };

    content += GenerateNewLine();
    content += GenerateHeaderGuard();

    content += GenerateFwdHead();
    content += GenerateNameSpace();
    content += GenerateFwd();

    content += GenerateHeaderGuardEndif();

    return content;
}
