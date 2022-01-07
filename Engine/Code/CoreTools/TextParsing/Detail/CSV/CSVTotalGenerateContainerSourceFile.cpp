///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:02)

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
    return TextParsing::g_ContainerSourceFileExtensionName.data();
}

System::String CoreTools::CSVTotalGenerateContainerSourceFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += GenerateNewLine();
    content += GenerateContainerSourceHead();
    content += GenerateContainerDefaultFunctionDefinition();
    content += GenerateContainerFunctionDefinition();

    return content;
}
