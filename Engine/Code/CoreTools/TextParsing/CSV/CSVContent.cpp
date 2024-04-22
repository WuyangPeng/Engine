/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/03 00:13)

#include "CoreTools/CoreToolsExport.h"

#include "CSVContent.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/CSV/CSVContentImpl.h"

CoreTools::CSVContent::CSVContent(const String& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVContent)

CoreTools::CSVHead CoreTools::CSVContent::GetCSVHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCSVHead();
}

int CoreTools::CSVContent::GetCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

CoreTools::CSVContent::String CoreTools::CSVContent::GetContent(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetContent(index);
}

CoreTools::CSVContent::String CoreTools::CSVContent::GetCSVClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCSVClassName();
}
