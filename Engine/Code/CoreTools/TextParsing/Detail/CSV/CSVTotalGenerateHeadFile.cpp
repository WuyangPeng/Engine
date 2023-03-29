///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 18:09)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateHeadFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVTotalGenerateHeadFile::CSVTotalGenerateHeadFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer)
    : ParentType{ nameSpace, csvHeadContainer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVTotalGenerateHeadFile)

System::String CoreTools::CSVTotalGenerateHeadFile::GetFileSuffix() const
{
    return TextParsing::gHeadFileExtensionName.data();
}

System::String CoreTools::CSVTotalGenerateHeadFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += GenerateNewLine();
    content += GenerateHeaderGuard();

    content += GenerateHead();

    content += GenerateHeaderGuardEndif();

    return content;
}
