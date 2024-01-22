/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:01)

#include "CoreTools/CoreToolsExport.h"

#include "RowRange.h"
#include "Flags/IteratorFlags.h"
#include "Detail/RowRangeImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, RowRange)

CoreTools::SimpleCSV::RowRange::RowRange(const ConstXMLDocumentSharedPtr& document, const XMLNode& dataNode, int first, int last, const SharedStringsSharedPtr& sharedStrings)
    : impl{ document, dataNode, first, last, sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RowRange)

int CoreTools::SimpleCSV::RowRange::GetRowCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetRowCount();
}

int CoreTools::SimpleCSV::RowRange::GetFirstRow() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFirstRow();
}

int CoreTools::SimpleCSV::RowRange::GetLastRow() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetLastRow();
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::RowRange::GetDataNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDataNode();
}

CoreTools::SimpleCSV::RowRange::SharedStringsSharedPtr CoreTools::SimpleCSV::RowRange::GetSharedStrings()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetSharedStrings();
}

CoreTools::SimpleCSV::RowIterator CoreTools::SimpleCSV::RowRange::begin()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return RowIterator{ impl->GetDocument(), impl->GetSharedStrings(), *this, IteratorLocation::Begin };
}

CoreTools::SimpleCSV::RowIterator CoreTools::SimpleCSV::RowRange::end()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return RowIterator{ impl->GetDocument(), impl->GetSharedStrings(), *this, IteratorLocation::End };
}
