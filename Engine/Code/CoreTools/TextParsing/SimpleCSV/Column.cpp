/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:02)

#include "CoreTools/CoreToolsExport.h"

#include "Column.h"
#include "Detail/ColumnImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, Column)

CoreTools::SimpleCSV::Column::Column(const ConstXMLDocumentSharedPtr& document, const XMLNode& columnNode)
    : impl{ document, columnNode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, Column)

float CoreTools::SimpleCSV::Column::GetWidth() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetWidth();
}

void CoreTools::SimpleCSV::Column::SetWidth(float width)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetWidth(width);
}

bool CoreTools::SimpleCSV::Column::IsHidden() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsHidden();
}

void CoreTools::SimpleCSV::Column::SetHidden(bool state)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetHidden(state);
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::Column::GetColumnNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetColumnNode();
}
