///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 18:12)

#include "CoreTools/CoreToolsExport.h"

#include "Row.h"
#include "Detail/RowImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::SimpleCSV::Row::RowSharedPtr CoreTools::SimpleCSV::Row::CreateRow(const ConstXMLDocumentSharedPtr& document)
{
    return make_shared<Row>(document, RowCreate::Init);
}

CoreTools::SimpleCSV::Row::RowSharedPtr CoreTools::SimpleCSV::Row::CreateRow(const ConstXMLDocumentSharedPtr& document, const XMLNode& rowNode, const SharedStringsSharedPtr& sharedStrings)
{
    auto row = CreateRow(document);
    row->impl->Init(row, rowNode, sharedStrings);

    return row;
}

CoreTools::SimpleCSV::Row::Row(const ConstXMLDocumentSharedPtr& document, RowCreate cellCreate)
    : impl{ document }
{
    System::UnusedFunction(cellCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, Row)

double CoreTools::SimpleCSV::Row::GetHeight() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetHeight();
}

void CoreTools::SimpleCSV::Row::SetHeight(double height)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetHeight(height);
}

double CoreTools::SimpleCSV::Row::GetDescent() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDescent();
}

void CoreTools::SimpleCSV::Row::SetDescent(double descent)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetDescent(descent);
}

bool CoreTools::SimpleCSV::Row::IsHidden() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsHidden();
}

void CoreTools::SimpleCSV::Row::SetHidden(bool state)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetHidden(state);
}

int CoreTools::SimpleCSV::Row::GetRowNumber() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetRowNumber();
}

int CoreTools::SimpleCSV::Row::GetCellCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCellCount();
}

CoreTools::SimpleCSV::RowDataProxy& CoreTools::SimpleCSV::Row::GetValues() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetValues();
}

const CoreTools::SimpleCSV::RowDataProxy& CoreTools::SimpleCSV::Row::GetValues() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetValues();
}

CoreTools::SimpleCSV::RowDataRange CoreTools::SimpleCSV::Row::GetCells() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCells();
}

CoreTools::SimpleCSV::RowDataRange CoreTools::SimpleCSV::Row::GetCells(int cellCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCells(cellCount);
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::Row::GetRowNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetRowNode();
}

CoreTools::SimpleCSV::Row::SharedStringsSharedPtr CoreTools::SimpleCSV::Row::GetSharedStrings()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetSharedStrings();
}

CoreTools::SimpleCSV::RowDataRange CoreTools::SimpleCSV::Row::GetCells(int firstCell, int lastCell) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCells(firstCell, lastCell);
}

bool CoreTools::SimpleCSV::Row::IsSame(const Row& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsSame(*rhs.impl);
}

bool CoreTools::SimpleCSV::Row::IsLess(const Row& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsLess(*rhs.impl);
}

bool CoreTools::SimpleCSV::operator==(const Row& lhs, const Row& rhs)
{
    return lhs.IsSame(rhs);
}

bool CoreTools::SimpleCSV::operator<(const Row& lhs, const Row& rhs)
{
    return lhs.IsLess(rhs);
}
