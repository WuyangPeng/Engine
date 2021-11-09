///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/27 11:50)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateContainerHeadFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using namespace std::literals;

CoreTools::CSVTotalGenerateContainerHeadFile::CSVTotalGenerateContainerHeadFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer)
    : ParentType{ nameSpace, csvHeadContainer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVTotalGenerateContainerHeadFile)

System::String CoreTools::CSVTotalGenerateContainerHeadFile::GetFileSuffix() const
{
    return SYSTEM_TEXT("Container.h"s);
}

System::String CoreTools::CSVTotalGenerateContainerHeadFile::GetContent() const
{
    auto content = GenerateCopyright();

    content += GenerateNewLine();
    content += GenerateContainerHeaderGuard();

    content += GenerateContainerHead();
    content += GenerateNameSpace();
    content += GenerateContainerClassName();
    content += GenerateContainerDefaultFunction();
    content += GenerateContainerFunction();
    content += GenerateContainerMember();

    content += GenerateHeaderGuardEndif();

    return content;
}
