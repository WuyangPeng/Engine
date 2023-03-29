///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 09:33)

#include "CoreTools/CoreToolsExport.h"

#include "RowImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::RowImpl::RowImpl(const ConstXMLDocumentSharedPtr& document, const RowSharedPtr& row, const XMLNode& rowNode, const SharedStringsSharedPtr& sharedStrings)
    : document{ document }, rowNode{ rowNode }, sharedStrings{ sharedStrings }, rowDataProxy{ document, row, rowNode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::RowImpl::RowImpl(const ConstXMLDocumentSharedPtr& document)
    : document{ document }, rowNode{}, sharedStrings{}, rowDataProxy{ DisableNotThrow::Disable }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::SimpleCSV::RowImpl::Init(const RowSharedPtr& row, const XMLNode& aRowNode, const SharedStringsSharedPtr& aSharedStrings)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto documentSharedPtr = document.lock();

    if (!documentSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s))
    }

    rowNode = aRowNode;
    sharedStrings = aSharedStrings;
    rowDataProxy = RowDataProxy{ documentSharedPtr, row, aRowNode };
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

    if (auto node = GetRowNode(); !node.attribute("x14ac:dyDescent"))
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

    if (auto node = GetRowNode(); !node.attribute("hidden"))
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

    if (const auto node = GetRowNode(); !node.last_child())
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

    return rowDataProxy;
}

CoreTools::SimpleCSV::RowDataRange CoreTools::SimpleCSV::RowImpl::GetCells() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto documentSharedPtr = document.lock();
    const auto sharedStringsSharedPtr = sharedStrings.lock();

    if (!documentSharedPtr || !sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document或sharedStrings已被释放。"s))
    }

    return RowDataRange{ documentSharedPtr, rowNode, 1, CellReference{ rowNode.last_child().attribute("r").value() }.GetColumn(), sharedStringsSharedPtr };
}

CoreTools::SimpleCSV::RowDataRange CoreTools::SimpleCSV::RowImpl::GetCells(int cellCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto documentSharedPtr = document.lock();
    const auto sharedStringsSharedPtr = sharedStrings.lock();

    if (!documentSharedPtr || !sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document或sharedStrings已被释放。"s))
    }

    return RowDataRange{ documentSharedPtr, rowNode, 1, cellCount, sharedStringsSharedPtr };
}

CoreTools::SimpleCSV::RowDataRange CoreTools::SimpleCSV::RowImpl::GetCells(int firstCell, int lastCell) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto documentSharedPtr = document.lock();
    const auto sharedStringsSharedPtr = sharedStrings.lock();

    if (!documentSharedPtr || !sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document或sharedStrings已被释放。"s))
    }

    return RowDataRange{ documentSharedPtr, rowNode, firstCell, lastCell, sharedStringsSharedPtr };
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::RowImpl::GetRowNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s))
    }

    return rowNode;
}

CoreTools::SimpleCSV::RowImpl::SharedStringsSharedPtr CoreTools::SimpleCSV::RowImpl::GetSharedStrings()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto sharedStringsSharedPtr = sharedStrings.lock();

    if (!sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("dsharedStrings已被释放。"s))
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
