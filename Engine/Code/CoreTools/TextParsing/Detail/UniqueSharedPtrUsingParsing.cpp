///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 16:36)

#include "CoreTools/CoreToolsExport.h"

#include "UniqueSharedPtrUsingParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::UniqueSharedPtrUsingParsing::UniqueSharedPtrUsingParsing(int indentationCount, const String& className)
    : ParentType{ indentationCount, className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UniqueSharedPtrUsingParsing)

System::String CoreTools::UniqueSharedPtrUsingParsing::GenerateSharedPtrUsing() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateSharedPtr();

    content += GenerateIndentation();
    content += SYSTEM_TEXT("using CSVContent = CoreTools::CSVContent;\n");

    return content;
}
