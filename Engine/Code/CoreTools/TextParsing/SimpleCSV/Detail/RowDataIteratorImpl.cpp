///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 09:26)

#include "CoreTools/CoreToolsExport.h"

#include "RowDataIteratorImpl.h"
#include "Utilities.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/IteratorFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::RowDataIteratorImpl::RowDataIteratorImpl(const ConstXMLDocumentSharedPtr& document, const SharedStringsSharedPtr& sharedStrings, const RowDataRange& rowDataRange, IteratorLocation location)
    : document{ document },
      dataRange{ rowDataRange },
      cellNode{ GetCellNode(rowDataRange.GetRowNode(), dataRange.GetFirstColumn()) },
      currentCell{ location == IteratorLocation::End ? Cell::CreateCell() : Cell::CreateCell(document, cellNode, sharedStrings) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RowDataIteratorImpl)

CoreTools::SimpleCSV::RowDataIteratorImpl& CoreTools::SimpleCSV::RowDataIteratorImpl::operator++()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto documentSharedPtr = document.lock();

    if (!documentSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document 已被释放。"s))
    }

    const auto cellNumber = currentCell->GetCellReference().GetColumn() + 1;
    auto node = currentCell->GetXMLNode().next_sibling();

    if (dataRange.GetLastColumn() < cellNumber)
    {
        currentCell = Cell::CreateCell();
    }
    else if (cellNode.empty() || CellReference{ node.attribute(TextParsing::gAttributeR.data()).value() }.GetColumn() != cellNumber)
    {
        auto rowNode = dataRange.GetRowNode();
        node = rowNode.insert_child_after(TextParsing::gChildC.data(), currentCell->GetXMLNode());
        const CellReference cellReference{ rowNode.attribute(TextParsing::gAttributeR.data()).as_int(), cellNumber };
        node.append_attribute(TextParsing::gAttributeR.data()).set_value(cellReference.GetAddress().c_str());
        currentCell = Cell::CreateCell(documentSharedPtr, node, dataRange.GetSharedStrings());
    }
    else
    {
        CORE_TOOLS_ASSERTION_1(CellReference{ node.attribute(TextParsing::gAttributeR.data()).value() }.GetColumn() == cellNumber, "Column不对应。");

        currentCell = Cell::CreateCell(documentSharedPtr, node, dataRange.GetSharedStrings());
    }

    return *this;
}

CoreTools::SimpleCSV::RowDataIteratorImpl CoreTools::SimpleCSV::RowDataIteratorImpl::operator++(int)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto iter = *this;

    ++(*this);

    return iter;
}

CoreTools::SimpleCSV::RowDataIteratorImpl::ReferenceType CoreTools::SimpleCSV::RowDataIteratorImpl::operator*() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return *currentCell;
}

CoreTools::SimpleCSV::RowDataIteratorImpl::PointerType CoreTools::SimpleCSV::RowDataIteratorImpl::operator->() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return currentCell.get();
}

bool CoreTools::SimpleCSV::RowDataIteratorImpl::IsSame(const RowDataIteratorImpl& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return *currentCell == *rhs.currentCell;
}
