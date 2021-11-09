///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/09 15:54)

#include "CoreTools/CoreToolsExport.h"

#include "CellIteratorImpl.h"
#include "Utilities.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/IteratorFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::CellIteratorImpl::CellIteratorImpl(const ConstXMLDocumentSharedPtr& document, const SharedStringsSharedPtr& sharedStrings, const CellRange& cellRange, IteratorLocation location)
    : document{ document },
      topLeft{ cellRange.GetTopLeft() },
      bottomRight{ cellRange.GetBottomRight() },
      currentCell{ GetCurrentCell(document, sharedStrings, cellRange.GetDataNode(), topLeft, location) },
      sharedStrings{ sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellIteratorImpl::CellSharedPtr
    CoreTools::SimpleCSV::CellIteratorImpl::GetCurrentCell(const ConstXMLDocumentSharedPtr& document,
                                                           const SharedStringsSharedPtr& sharedStrings,
                                                           const XMLNode& dataNode,
                                                           const CellReference& topLeft,
                                                           IteratorLocation location)
{
    if (location == IteratorLocation::End)
    {
        return Cell::CreateCell();
    }
    else
    {
        const auto rowNode = GetRowNode(dataNode, topLeft.GetRow());
        const auto cellNode = GetCellNode(rowNode, topLeft.GetColumn());

        return Cell::CreateCell(document, cellNode, sharedStrings);
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CellIteratorImpl);

CoreTools::SimpleCSV::CellReference CoreTools::SimpleCSV::CellIteratorImpl::GetNextCellReference() const
{
    auto reference = currentCell->GetCellReference();

    if (reference.GetColumn() < bottomRight.GetColumn())
    {
        return CellReference{ reference.GetRow(), reference.GetColumn() + 1 };
    }
    else if (reference.GetColumn() == bottomRight.GetColumn())
    {
        return CellReference{ reference.GetRow() + 1, topLeft.GetColumn() };
    }

    return reference;
}

CoreTools::SimpleCSV::CellIteratorImpl& CoreTools::SimpleCSV::CellIteratorImpl::operator++()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CheckDocument();

    auto nextCellReference = GetNextCellReference();

    if (nextCellReference <= bottomRight)
    {
        AddCurrentCell(nextCellReference);
    }
    else
    {
        currentCell = Cell::CreateCell();
    }

    return *this;
}

CoreTools::SimpleCSV::CellIteratorImpl CoreTools::SimpleCSV::CellIteratorImpl::operator++(int)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto iter = *this;

    ++(*this);

    return iter;
}

CoreTools::SimpleCSV::CellIteratorImpl::ReferenceType CoreTools::SimpleCSV::CellIteratorImpl::operator*() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return *currentCell;
}

CoreTools::SimpleCSV::CellIteratorImpl::PointerType CoreTools::SimpleCSV::CellIteratorImpl::operator->() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return currentCell.get();
}

bool CoreTools::SimpleCSV::CellIteratorImpl::IsSame(const CellIteratorImpl& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return *currentCell == *rhs.currentCell;
}

int CoreTools::SimpleCSV::CellIteratorImpl::Distance(const CellIteratorImpl& last) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto result = 0;
    for (auto iter = *this; !iter.IsSame(last); ++iter)
    {
        ++result;
    }

    return result;
}

void CoreTools::SimpleCSV::CellIteratorImpl::AddCurrentCell(const CellReference& nextCellReference)
{
    const auto cellReference = currentCell->GetCellReference();
    if (nextCellReference.GetRow() == cellReference.GetRow())
    {
        AddSameRowCurrentCell(nextCellReference);
    }
    else if (cellReference.GetRow() < nextCellReference.GetRow())
    {
        AddNextRowCurrentCell(nextCellReference);
    }
    else
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, "发生了内部错误"s);
    }
}

void CoreTools::SimpleCSV::CellIteratorImpl::CheckDocument()
{
    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document 已被释放。"s));
    }
}

void CoreTools::SimpleCSV::CellIteratorImpl::SetCurrentCell(const XMLNode& dataNode)
{
    auto documentSharedPtr = document.lock();
    auto sharedStringsSharedPtr = sharedStrings.lock();

    if (!documentSharedPtr || !sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document或sharedStrings已被释放。"s));
    }

    currentCell = Cell::CreateCell(documentSharedPtr, dataNode, sharedStringsSharedPtr);
}

void CoreTools::SimpleCSV::CellIteratorImpl::AddSameRowCurrentCell(const CellReference& nextCellReference)
{
    const auto xmlNode = currentCell->GetXMLNode();
    auto nextNode = xmlNode.next_sibling();

    if (!nextNode || CellReference{ nextNode.attribute(TextParsing::g_AttributeR.data()).value() } != nextCellReference)
    {
        nextNode = xmlNode.parent().insert_child_after(TextParsing::g_ChildC.data(), xmlNode);
        nextNode.append_attribute(TextParsing::g_AttributeR.data()).set_value(nextCellReference.GetAddress().c_str());
    }

    SetCurrentCell(nextNode);
}

void CoreTools::SimpleCSV::CellIteratorImpl::AddNextRowCurrentCell(const CellReference& nextCellReference)
{
    const auto xmlNode = currentCell->GetXMLNode();
    const auto xmlNodeParent = xmlNode.parent();
    auto nextNodeParent = xmlNodeParent.next_sibling();

    if (!nextNodeParent || nextNodeParent.attribute(TextParsing::g_AttributeR.data()).as_int() != nextCellReference.GetRow())
    {
        nextNodeParent = xmlNodeParent.parent().insert_child_after("row", xmlNodeParent);
        nextNodeParent.append_attribute(TextParsing::g_AttributeR.data()).set_value(nextCellReference.GetRow());
    }

    SetCurrentCell(GetCellNode(nextNodeParent, nextCellReference.GetColumn()));
}
