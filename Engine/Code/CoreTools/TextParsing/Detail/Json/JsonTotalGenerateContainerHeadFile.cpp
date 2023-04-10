///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 17:27)

#include "CoreTools/CoreToolsExport.h"

#include "JsonTotalGenerateContainerHeadFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::JsonTotalGenerateContainerHeadFile::JsonTotalGenerateContainerHeadFile(const String& nameSpace, const JsonHeadContainer& jsonHeadContainer)
    : ParentType{ nameSpace, jsonHeadContainer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonTotalGenerateContainerHeadFile)

System::String CoreTools::JsonTotalGenerateContainerHeadFile::GetFileSuffix() const
{
    return TextParsing::gContainerHeadFileExtensionName.data();
}

System::String CoreTools::JsonTotalGenerateContainerHeadFile::GetContent() const
{
    String content{ TextParsing::gCopyright };

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
