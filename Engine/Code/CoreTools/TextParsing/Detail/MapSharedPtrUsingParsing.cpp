///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 16:51)

#include "CoreTools/CoreToolsExport.h"

#include "MapSharedPtrUsingParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::MapSharedPtrUsingParsing::MapSharedPtrUsingParsing(int indentationCount, const String& className, const String& keyTypeDescribe, StringView mappingName)
    : ParentType{ indentationCount, className }, keyTypeDescribe{ keyTypeDescribe }, mappingName{ mappingName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MapSharedPtrUsingParsing)

System::String CoreTools::MapSharedPtrUsingParsing::GenerateSharedPtrUsing() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateSharedPtr();

    content += GenerateSharedPtrMappingContainer(keyTypeDescribe, mappingName);
    content += GenerateSharedPtrContainer();
    content += GenerateIndentation();
    content += SYSTEM_TEXT("using CSVContent = CoreTools::CSVContent;\n");

    return content;
}
