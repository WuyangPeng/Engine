///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:24)

#include "CoreTools/CoreToolsExport.h"

#include "RowImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::RowImpl::RowImpl(const ConstXMLDocumentSharedPtr& document, const RowSharedPtr& row, const XMLNode& rowNode, const SharedStringsSharedPtr& sharedStrings)
    : m_Document{ document }, m_RowNode{ rowNode }, m_SharedStrings{ sharedStrings }, m_RowDataProxy{ document, row, rowNode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::RowImpl::RowImpl(const ConstXMLDocumentSharedPtr& document)
    : m_Document{ document }, m_RowNode{}, m_SharedStrings{}, m_RowDataProxy{ DisableNotThrow::Disable }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::SimpleCSV::RowImpl::Init(const RowSharedPtr& row, const XMLNode& rowNode, const SharedStringsSharedPtr& sharedStrings)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto documentSharedPtr = m_Document.lock();

    if (!documentSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }

    m_RowNode = rowNode;
    m_SharedStrings = sharedStrings;
    m_RowDataProxy = RowDataProxy{ documentSharedPtr, row, rowNode };
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RowImpl);

double CoreTools::SimpleCSV::RowImpl::GetHeight() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto node = GetRowNode();

    return node.attribute("ht").as_double(15.0);
}

void CoreTools::SimpleCSV::RowImpl::SetHeight(double height)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto node = GetRowNode();

    if (!node.attribute("ht"))
    {
        node.append_attribute("ht") = height;
    }
    else
    {
        node.attribute("ht").set_value(height);
    }

    if (!node.attribute("customHeight"))
    {
        node.append_attribute("customHeight") = 1;
    }
    else
    {
        node.attribute("customHeight").set_value(1);
    }
}

double CoreTools::SimpleCSV::RowImpl::GetDescent() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto node = GetRowNode();

    return node.attribute("x14ac:dyDescent").as_double(0.25);
}

void CoreTools::SimpleCSV::RowImpl::SetDescent(double descent)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto node = GetRowNode();

    if (!node.attribute("x14ac:dyDescent"))
    {
        node.append_attribute("x14ac:dyDescent") = descent;
    }
    else
    {
        node.attribute("x14ac:dyDescent") = descent;
    }
}

bool CoreTools::SimpleCSV::RowImpl::IsHidden() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto node = GetRowNode();

    return node.attribute("hidden").as_bool(false);
}

void CoreTools::SimpleCSV::RowImpl::SetHidden(bool state)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto node = GetRowNode();

    if (!node.attribute("hidden"))
    {
        node.append_attribute("hidden") = state ? 1 : 0;
    }
    else
    {
        node.attribute("hidden").set_value(state ? 1 : 0);
    }
}

int CoreTools::SimpleCSV::RowImpl::GetRowNumber() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto node = GetRowNode();

    return node.attribute("r").as_int();
}

int CoreTools::SimpleCSV::RowImpl::GetCellCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto node = GetRowNode();

    if (!node.last_child())
    {
        return 0;
    }
    else
    {
        return CellReference{ node.last_child().attribute("r").value() }.GetColumn();
    }
}

CoreTools::SimpleCSV::RowDataProxy& CoreTools::SimpleCSV::RowImpl::GetValues() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(RowDataProxy&, GetValues);
}

const CoreTools::SimpleCSV::RowDataProxy& CoreTools::SimpleCSV::RowImpl::GetValues() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_RowDataProxy;
}

CoreTools::SimpleCSV::RowDataRange CoreTools::SimpleCSV::RowImpl::GetCells() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto documentSharedPtr = m_Document.lock();
    auto sharedStringsSharedPtr = m_SharedStrings.lock();

    if (!documentSharedPtr || !sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document或sharedStrings已被释放。"s));
    }

    return RowDataRange{ documentSharedPtr, m_RowNode, 1, CellReference{ m_RowNode.last_child().attribute("r").value() }.GetColumn(), sharedStringsSharedPtr };
}

CoreTools::SimpleCSV::RowDataRange CoreTools::SimpleCSV::RowImpl::GetCells(int cellCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto documentSharedPtr = m_Document.lock();
    auto sharedStringsSharedPtr = m_SharedStrings.lock();

    if (!documentSharedPtr || !sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document或sharedStrings已被释放。"s));
    }

    return RowDataRange{ documentSharedPtr, m_RowNode, 1, cellCount, sharedStringsSharedPtr };
}

CoreTools::SimpleCSV::RowDataRange CoreTools::SimpleCSV::RowImpl::GetCells(int firstCell, int lastCell) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto documentSharedPtr = m_Document.lock();
    auto sharedStringsSharedPtr = m_SharedStrings.lock();

    if (!documentSharedPtr || !sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document或sharedStrings已被释放。"s));
    }

    return RowDataRange{ documentSharedPtr, m_RowNode, firstCell, lastCell, sharedStringsSharedPtr };
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::RowImpl::GetRowNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (m_Document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }

    return m_RowNode;
}

CoreTools::SimpleCSV::RowImpl::SharedStringsSharedPtr CoreTools::SimpleCSV::RowImpl::GetSharedStrings()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto sharedStringsSharedPtr = m_SharedStrings.lock();

    if (!sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("dsharedStrings已被释放。"s));
    }

    return sharedStringsSharedPtr;
}

bool CoreTools::SimpleCSV::RowImpl::IsSame(const RowImpl& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetRowNode() == rhs.GetRowNode();
}

bool CoreTools::SimpleCSV::RowImpl::IsLess(const RowImpl& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetRowNode() < rhs.GetRowNode();
}
