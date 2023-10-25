///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 15:34)

#include "CoreTools/CoreToolsExport.h"

#include "CellRange.h"
#include "Flags/IteratorFlags.h"
#include "Detail/CellRangeImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, CellRange)

CoreTools::SimpleCSV::CellRange::CellRange(const ConstXMLDocumentSharedPtr& document, const XMLNode& dataNode, const CellReference& topLeft, const CellReference& bottomRight, const SharedStringsSharedPtr& sharedStrings)
    : impl{ document, dataNode, topLeft, bottomRight, sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CellRange)

int CoreTools::SimpleCSV::CellRange::GetNumRows() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetNumRows();
}

int CoreTools::SimpleCSV::CellRange::GetNumColumns() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetNumColumns();
}

CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr CoreTools::SimpleCSV::CellRange::GetDocument()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetDocument();
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::CellRange::GetDataNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDataNode();
}

CoreTools::SimpleCSV::CellReference CoreTools::SimpleCSV::CellRange::GetTopLeft() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetTopLeft();
}

CoreTools::SimpleCSV::CellReference CoreTools::SimpleCSV::CellRange::GetBottomRight() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetBottomRight();
}

CoreTools::SimpleCSV::CellRange::SharedStringsSharedPtr CoreTools::SimpleCSV::CellRange::GetSharedStrings()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetSharedStrings();
}

CoreTools::SimpleCSV::CellIterator CoreTools::SimpleCSV::CellRange::begin()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return CellIterator{ impl->GetDocument(), impl->GetSharedStrings(), *this, IteratorLocation::Begin };
}

CoreTools::SimpleCSV::CellIterator CoreTools::SimpleCSV::CellRange::end()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return CellIterator{ impl->GetDocument(), impl->GetSharedStrings(), *this, IteratorLocation::End };
}
