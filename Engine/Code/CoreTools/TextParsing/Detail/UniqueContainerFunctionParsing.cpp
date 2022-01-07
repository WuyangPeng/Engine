///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:33)

#include "CoreTools/CoreToolsExport.h"

#include "UniqueContainerFunctionParsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

CoreTools::UniqueContainerFunctionParsing::UniqueContainerFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe)
    : ParentType{ csvHead, keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UniqueContainerFunctionParsing)

System::String CoreTools::UniqueContainerFunctionParsing::GenerateGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto csvHead = GetCSVHead();

    auto content = GenerateIndentation();

    content += TextParsing::g_NodiscardConst;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_GetSharedPtr;
    content += csvHead.GetCSVClassName();
    content += TextParsing::g_ConstNoexcept;
    content += TextParsing::g_NewlineCharacter;

    return content;
}
