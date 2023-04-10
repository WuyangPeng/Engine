///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 17:27)

#include "CoreTools/CoreToolsExport.h"

#include "JsonTotalGenerateContainerSourceFile.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::JsonTotalGenerateContainerSourceFile::JsonTotalGenerateContainerSourceFile(const String& nameSpace, const JsonHeadContainer& jsonHeadContainer)
    : ParentType{ nameSpace, jsonHeadContainer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonTotalGenerateContainerSourceFile)

System::String CoreTools::JsonTotalGenerateContainerSourceFile::GetFileSuffix() const
{
    return TextParsing::gContainerSourceFileExtensionName.data();
}

System::String CoreTools::JsonTotalGenerateContainerSourceFile::GetContent() const
{
    String content{ TextParsing::gCopyright };

    content += GenerateNewLine();
    content += GenerateContainerSourceHead();
    content += GenerateContainerDefaultFunctionDefinition();
    content += GenerateContainerFunctionDefinition();

    return content;
}
