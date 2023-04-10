///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 15:12)

#include "CoreTools/CoreToolsExport.h"

#include "CellValueImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueProxy.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"

using namespace std::literals;

CoreTools::SimpleCSV::CellValueImpl::CellValueImpl() noexcept
    : cellValue{ std::string{} }, cellType{ ValueType::Empty }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValueImpl::CellValueImpl(bool value) noexcept
    : cellValue{ value }, cellType{ ValueType::Boolean }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValueImpl::CellValueImpl(int64_t value) noexcept
    : cellValue{ value }, cellType{ ValueType::Integer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValueImpl::CellValueImpl(double value) noexcept
    : cellValue{ value }, cellType{ ValueType::Float }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValueImpl::CellValueImpl(const std::string& value)
    : cellValue{ value }, cellType{ ValueType::String }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValueImpl::CellValueImpl(int value) noexcept
    : CellValueImpl{ static_cast<int64_t>(value) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CellValueImpl)

void CoreTools::SimpleCSV::CellValueImpl::Clear() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    cellType = ValueType::Empty;
    cellValue = std::string{};
}

void CoreTools::SimpleCSV::CellValueImpl::SetError() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    cellType = ValueType::Error;
    cellValue = std::string{};
}

CoreTools::SimpleCSV::ValueType CoreTools::SimpleCSV::CellValueImpl::GetType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return cellType;
}

std::string CoreTools::SimpleCSV::CellValueImpl::GetTypeAsString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    switch (GetType())
    {
        case ValueType::Empty:
            return "empty"s;
        case ValueType::Boolean:
            return "boolean"s;
        case ValueType::Integer:
            return "integer"s;
        case ValueType::Float:
            return "float"s;
        case ValueType::String:
            return "string"s;
        default:
            return "error"s;
    }
}

bool CoreTools::SimpleCSV::CellValueImpl::IsEqual(const CellValueImpl& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return cellValue == rhs.cellValue;
}

bool CoreTools::SimpleCSV::CellValueImpl::IsLess(const CellValueImpl& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return cellValue < rhs.cellValue;
}
