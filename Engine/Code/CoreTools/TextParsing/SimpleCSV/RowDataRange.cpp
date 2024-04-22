/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 11:28)

#include "CoreTools/CoreToolsExport.h"

#include "RowDataRange.h"
#include "Flags/IteratorFlags.h"
#include "Detail/RowDataRangeImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, RowDataRange)

CoreTools::SimpleCSV::RowDataRange::RowDataRange(const ConstXMLDocumentSharedPtr& document, const XMLNode& rowNode, int firstColumn, int lastColumn, const SharedStringsSharedPtr& sharedStrings)
    : impl{ document, rowNode, firstColumn, lastColumn, sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RowDataRange)

int CoreTools::SimpleCSV::RowDataRange::GetSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSize();
}

CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr CoreTools::SimpleCSV::RowDataRange::GetDocument()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetDocument();
}

CoreTools::SimpleCSV::RowDataRange::SharedStringsSharedPtr CoreTools::SimpleCSV::RowDataRange::GetSharedStrings()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetSharedStrings();
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::RowDataRange::GetRowNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetRowNode();
}

int CoreTools::SimpleCSV::RowDataRange::GetFirstColumn() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFirstColumn();
}

int CoreTools::SimpleCSV::RowDataRange::GetLastColumn() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetLastColumn();
}

CoreTools::SimpleCSV::RowDataIterator CoreTools::SimpleCSV::RowDataRange::begin()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return RowDataIterator{ impl->GetDocument(), impl->GetSharedStrings(), *this, IteratorLocation::Begin };
}

CoreTools::SimpleCSV::RowDataIterator CoreTools::SimpleCSV::RowDataRange::end()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return RowDataIterator{ impl->GetDocument(), impl->GetSharedStrings(), *this, IteratorLocation::End };
}
