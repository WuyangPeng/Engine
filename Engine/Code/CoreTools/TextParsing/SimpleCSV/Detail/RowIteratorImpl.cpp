///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:24)

#include "CoreTools/CoreToolsExport.h"

#include "RowIteratorImpl.h"
#include "Utilities.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/IteratorFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/TextParsing/SimpleCSV/RowRange.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::RowIteratorImpl::RowIteratorImpl(const ConstXMLDocumentSharedPtr& document, const SharedStringsSharedPtr& sharedStrings, const RowRange& rowRange, IteratorLocation location)
    : document{ document },
      sharedStrings{ sharedStrings },
      dataNode{ rowRange.GetDataNode() },
      firstRow{ rowRange.GetFirstRow() },
      lastRow{ rowRange.GetLastRow() },
      currentRow{ location == IteratorLocation::End ? Row::CreateRow(document) : Row::CreateRow(document, GetRowNode(dataNode, firstRow), sharedStrings) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RowIteratorImpl)

CoreTools::SimpleCSV::RowIteratorImpl& CoreTools::SimpleCSV::RowIteratorImpl::operator++()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto documentSharedPtr = document.lock();
    auto sharedStringsSharedPtr = sharedStrings.lock();

    if (!documentSharedPtr || !sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document或sharedStrings已被释放。"s));
    }

    const auto rowNumber = currentRow->GetRowNumber() + 1;
    const auto currentRowNode = currentRow->GetRowNode();
    auto rowNode = currentRowNode.next_sibling();

    if (lastRow < rowNumber)
    {
        currentRow = Row::CreateRow(documentSharedPtr);
    }
    else if (!rowNode || rowNode.attribute("r").as_int() != rowNumber)
    {
        rowNode = dataNode.insert_child_after("row", currentRowNode);
        rowNode.append_attribute("r").set_value(rowNumber);
        currentRow = Row::CreateRow(documentSharedPtr, rowNode, sharedStringsSharedPtr);
    }
    else
    {
        currentRow = Row::CreateRow(documentSharedPtr, rowNode, sharedStringsSharedPtr);
    }

    return *this;
}

CoreTools::SimpleCSV::RowIteratorImpl CoreTools::SimpleCSV::RowIteratorImpl::operator++(int)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto iter = *this;

    ++(*this);

    return iter;
}

CoreTools::SimpleCSV::RowIteratorImpl::ReferenceType CoreTools::SimpleCSV::RowIteratorImpl::operator*() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return *currentRow;
}

CoreTools::SimpleCSV::RowIteratorImpl::PointerType CoreTools::SimpleCSV::RowIteratorImpl::operator->() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return currentRow.get();
}

bool CoreTools::SimpleCSV::RowIteratorImpl::IsSame(const RowIteratorImpl& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return *currentRow == *rhs.currentRow;
}
