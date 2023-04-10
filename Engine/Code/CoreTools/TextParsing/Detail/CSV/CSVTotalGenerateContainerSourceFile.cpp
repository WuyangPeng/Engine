///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:22)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateContainerSourceFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::CSVTotalGenerateContainerSourceFile::CSVTotalGenerateContainerSourceFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer)
    : ParentType{ nameSpace, csvHeadContainer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVTotalGenerateContainerSourceFile)

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetFileSuffix() const
{
    return TextParsing::gContainerSourceFileExtensionName.data();
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetContent() const
{
    String content{ TextParsing::gCopyright };

    content += GenerateNewLine();
    content += GenerateContainerSourceHead();
    content += GenerateContainerDefaultFunctionDefinition();
    content += GenerateContainerFunctionDefinition();

    return content;
}
