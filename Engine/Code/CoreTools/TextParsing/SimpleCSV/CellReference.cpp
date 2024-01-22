/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:03)

#include "CoreTools/CoreToolsExport.h"

#include "CellReference.h"
#include "Detail/CellReferenceImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, CellReference)

CoreTools::SimpleCSV::CellReference::CellReference(const std::string& cellAddress)
    : impl{ cellAddress }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellReference::CellReference(int row, int column)
    : impl{ row, column }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellReference::CellReference(int row, const std::string& column)
    : impl{ row, column }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CellReference)

int CoreTools::SimpleCSV::CellReference::GetRow() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetRow();
}

void CoreTools::SimpleCSV::CellReference::SetRow(int row)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetRow(row);
}

int CoreTools::SimpleCSV::CellReference::GetColumn() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetColumn();
}

void CoreTools::SimpleCSV::CellReference::SetColumn(int column)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetColumn(column);
}

std::string CoreTools::SimpleCSV::CellReference::GetAddress() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetAddress();
}

void CoreTools::SimpleCSV::CellReference::SetAddress(const std::string& address)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetAddress(address);
}

void CoreTools::SimpleCSV::CellReference::SetRowAndColumn(int row, int column)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetRowAndColumn(row, column);
}

bool CoreTools::SimpleCSV::operator==(const CellReference& lhs, const CellReference& rhs) noexcept
{
    return lhs.GetRow() == rhs.GetRow() && lhs.GetColumn() == rhs.GetColumn();
}

bool CoreTools::SimpleCSV::operator<(const CellReference& lhs, const CellReference& rhs) noexcept
{
    if (lhs.GetRow() < rhs.GetRow())
        return true;
    else if (rhs.GetRow() < lhs.GetRow())
        return false;
    else
        return lhs.GetColumn() < rhs.GetColumn();
}

int CoreTools::SimpleCSV::CellReference::GetColumn(const std::string& cellAddress)
{
    const ImplType cellReference{ cellAddress };

    return cellReference.GetColumn();
}