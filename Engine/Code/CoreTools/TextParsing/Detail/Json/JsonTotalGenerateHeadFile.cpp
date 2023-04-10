///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:27)

#include "CoreTools/CoreToolsExport.h"

#include "JsonTotalGenerateHeadFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVTotalGenerateHeadFile.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::JsonTotalGenerateHeadFile::JsonTotalGenerateHeadFile(const String& nameSpace, const JsonHeadContainer& jsonHeadContainer)
    : ParentType{ nameSpace, jsonHeadContainer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonTotalGenerateHeadFile)

System::String CoreTools::JsonTotalGenerateHeadFile::GetFileSuffix() const
{
    return TextParsing::gHeadFileExtensionName.data();
}

System::String CoreTools::JsonTotalGenerateHeadFile::GetContent() const
{
    String content{ TextParsing::gCopyright };

    content += GenerateNewLine();
    content += GenerateHeaderGuard();

    content += GenerateHead();

    content += GenerateHeaderGuardEndif();

    return content;
}
