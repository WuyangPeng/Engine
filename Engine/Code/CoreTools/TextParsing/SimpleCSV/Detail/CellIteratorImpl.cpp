///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 15:26)

#include "CoreTools/CoreToolsExport.h"

#include "CellIteratorImpl.h"
#include "Utilities.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/IteratorFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::CellIteratorImpl::CellIteratorImpl(const ConstXMLDocumentSharedPtr& document,
                                                         const SharedStringsSharedPtr& sharedStrings,
                                                         const CellRange& cellRange,
                                                         IteratorLocation location)
    : document{ document },
      topLeft{ cellRange.GetTopLeft() },
      bottomRight{ cellRange.GetBottomRight() },
      currentCell{ GetCurrentCell(document, sharedStrings, cellRange.GetDataNode(), topLeft, location) },
      sharedStrings{ sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellIteratorImpl::CellSharedPtr CoreTools::SimpleCSV::CellIteratorImpl::GetCurrentCell(const ConstXMLDocumentSharedPtr& document,
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

    if (const auto nextCellReference = GetNextCellReference(); nextCellReference <= bottomRight)
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
    if (const auto cellReference = currentCell->GetCellReference(); nextCellReference.GetRow() == cellReference.GetRow())
    {
        AddSameRowCurrentCell(nextCellReference);
    }
    else if (cellReference.GetRow() < nextCellReference.GetRow())
    {
        AddNextRowCurrentCell(nextCellReference);
    }
    else
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, "�������ڲ�����"s)
    }
}

void CoreTools::SimpleCSV::CellIteratorImpl::CheckDocument() const
{
    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document �ѱ��ͷš�"s))
    }
}

void CoreTools::SimpleCSV::CellIteratorImpl::SetCurrentCell(const XMLNode& dataNode)
{
    const auto documentSharedPtr = document.lock();
    const auto sharedStringsSharedPtr = sharedStrings.lock();

    if (!documentSharedPtr || !sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document��sharedStrings�ѱ��ͷš�"s))
    }

    currentCell = Cell::CreateCell(documentSharedPtr, dataNode, sharedStringsSharedPtr);
}

void CoreTools::SimpleCSV::CellIteratorImpl::AddSameRowCurrentCell(const CellReference& nextCellReference)
{
    const auto xmlNode = currentCell->GetXMLNode();
    auto nextNode = xmlNode.next_sibling();

    if (!nextNode || CellReference{ nextNode.attribute(TextParsing::gAttributeR.data()).value() } != nextCellReference)
    {
        nextNode = xmlNode.parent().insert_child_after(TextParsing::gChildC.data(), xmlNode);
        nextNode.append_attribute(TextParsing::gAttributeR.data()).set_value(nextCellReference.GetAddress().c_str());
    }

    SetCurrentCell(nextNode);
}

void CoreTools::SimpleCSV::CellIteratorImpl::AddNextRowCurrentCell(const CellReference& nextCellReference)
{
    const auto xmlNode = currentCell->GetXMLNode();
    const auto xmlNodeParent = xmlNode.parent();
    auto nextNodeParent = xmlNodeParent.next_sibling();

    if (!nextNodeParent || nextNodeParent.attribute(TextParsing::gAttributeR.data()).as_int() != nextCellReference.GetRow())
    {
        nextNodeParent = xmlNodeParent.parent().insert_child_after("row", xmlNodeParent);
        nextNodeParent.append_attribute(TextParsing::gAttributeR.data()).set_value(nextCellReference.GetRow());
    }

    SetCurrentCell(GetCellNode(nextNodeParent, nextCellReference.GetColumn()));
}
