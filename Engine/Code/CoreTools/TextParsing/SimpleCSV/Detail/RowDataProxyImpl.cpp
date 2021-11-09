///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/11 11:59)

#include "CoreTools/CoreToolsExport.h"

#include "RowDataProxyImpl.h"
#include "Utilities.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueProxyDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/Constants.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/IteratorFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

#include <gsl/util>

using std::vector;

CoreTools::SimpleCSV::RowDataProxyImpl::RowDataProxyImpl(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : document{}, row{}, rowNode{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::RowDataProxyImpl::RowDataProxyImpl(const ConstXMLDocumentSharedPtr& document, const RowSharedPtr& row, const XMLNode& rowNode) noexcept
    : document{ document }, row{ row }, rowNode{ rowNode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RowDataProxyImpl);

CoreTools::SimpleCSV::RowDataProxyImpl& CoreTools::SimpleCSV::RowDataProxyImpl::operator=(const CellValueContainer& values)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto documentSharedPtr = document.lock();
    auto rowSharedPtr = row.lock();

    if (!documentSharedPtr || !rowSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document或row已被释放。"s));
    }

    auto columnSize = boost::numeric_cast<int>(values.size());
    DeleteCellValues(columnSize);

    XMLNode curNode{};
    for (auto iter = values.rbegin(); iter != values.rend(); ++iter)
    {
        curNode = rowNode.prepend_child(TextParsing::g_ChildC.data());
        CellReference cellReference{ rowSharedPtr->GetRowNumber(), columnSize };
        curNode.append_attribute(TextParsing::g_AttributeR.data()).set_value(cellReference.GetAddress().c_str());
        auto cell = Cell::CreateCell(documentSharedPtr, curNode, rowSharedPtr->GetSharedStrings());

        cell->GetValue() = *iter;
        --columnSize;
    }

    return *this;
}

CoreTools::SimpleCSV::RowDataProxyImpl& CoreTools::SimpleCSV::RowDataProxyImpl::operator=(const BoolContainer& values)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (g_MaxColumns < values.size())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Overflow, "容器大小超过最大列数。\n"s);
    }

    auto documentSharedPtr = document.lock();

    if (!documentSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }

    if (values.empty())
    {
        return *this;
    }

    RowDataRange range{ documentSharedPtr, rowNode, 1, boost::numeric_cast<int>(values.size()), GetSharedStrings() };

    auto target = range.begin();
    auto source = values.begin();

    while (true)
    {
        target->GetValue() = gsl::narrow_cast<bool>(*source);
        ++source;
        if (source == values.end() || target == range.end())
        {
            break;
        }

        ++target;
    }

    return *this;
}

CoreTools::SimpleCSV::RowDataProxyImpl::CellValueContainer CoreTools::SimpleCSV::RowDataProxyImpl::GetValues() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto documentSharedPtr = document.lock();
    auto rowSharedPtr = row.lock();

    if (!documentSharedPtr || !rowSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document或row已被释放。"s));
    }

    auto numCells = (rowNode.last_child() == XMLNode{} ? 0 : CellReference{ rowNode.last_child().attribute(TextParsing::g_AttributeR.data()).value() }.GetColumn());
    CellValueContainer result{ boost::numeric_cast<size_t>(numCells), CellValue::CreateDefault() };

    if (0 < numCells)
    {
        for (const auto& node : rowNode.children())
        {
            const auto index = CellReference{ node.attribute(TextParsing::g_AttributeR.data()).value() }.GetColumn() - 1;
            result.at(index) = Cell::CreateCell(documentSharedPtr, node, rowSharedPtr->GetSharedStrings())->GetValue().GetValue();
        }
    }

    return result;
}

CoreTools::SimpleCSV::RowDataProxyImpl::SharedStringsSharedPtr CoreTools::SimpleCSV::RowDataProxyImpl::GetSharedStrings()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto rowSharedPtr = row.lock();

    if (!rowSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("row已被释放。"s));
    }

    return rowSharedPtr->GetSharedStrings();
}

void CoreTools::SimpleCSV::RowDataProxyImpl::DeleteCellValues(int count)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto xmlNode = GetRowNode();

    vector<XMLNode> toBeDeleted{};
    for (auto cellNode : xmlNode.children())
    {
        CellReference cellReference{ cellNode.attribute(TextParsing::g_AttributeR.data()).value() };

        if (cellReference.GetColumn() <= count)
        {
            toBeDeleted.emplace_back(cellNode);
        }
    }

    for (auto cellNode : toBeDeleted)
    {
        xmlNode.remove_child(cellNode);
    }
}

void CoreTools::SimpleCSV::RowDataProxyImpl::PrependCellValue(const CellValue& value, int column)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto documentSharedPtr = document.lock();
    auto rowSharedPtr = row.lock();

    if (!documentSharedPtr || !rowSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document或row已被释放。"s));
    }

    auto curNode = rowNode.prepend_child(TextParsing::g_ChildC.data());
    curNode.append_attribute(TextParsing::g_AttributeR.data()).set_value(CellReference{ rowSharedPtr->GetRowNumber(), column }.GetAddress().c_str());
    Cell::CreateCell(documentSharedPtr, curNode, GetSharedStrings())->GetValue() = value;
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::RowDataProxyImpl::GetRowNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }

    return rowNode;
}

void CoreTools::SimpleCSV::RowDataProxyImpl::Clear()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto xmlNode = GetRowNode();

    xmlNode.remove_children();
}

CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr CoreTools::SimpleCSV::RowDataProxyImpl::GetDocument()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto documentSharedPtr = document.lock();

    if (!documentSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document 已被释放。"s));
    }

    return documentSharedPtr;
}
