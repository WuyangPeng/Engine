///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 16:53)

#include "CoreTools/CoreToolsExport.h"

#include "DefaultSharedPtrUsingParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::DefaultSharedPtrUsingParsing::DefaultSharedPtrUsingParsing(int indentationCount, const String& className)
    : ParentType{ indentationCount, className }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DefaultSharedPtrUsingParsing)

System::String CoreTools::DefaultSharedPtrUsingParsing::GenerateSharedPtrUsing() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = GenerateSharedPtr(TextParsing::gBase);
    content += GenerateSharedPtrContainer(TextParsing::gBase);

    return content;
}
