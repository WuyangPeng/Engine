///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 21:23)

#include "CoreTools/CoreToolsExport.h"

#include "CellValueImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueProxy.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"

using std::string;
using namespace std::literals;

CoreTools::SimpleCSV::CellValueImpl::CellValueImpl() noexcept
    : m_Value{ string{} }, m_Type{ ValueType::Empty }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValueImpl::CellValueImpl(bool value) noexcept
    : m_Value{ value }, m_Type{ ValueType::Boolean }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValueImpl::CellValueImpl(int64_t value) noexcept
    : m_Value{ value }, m_Type{ ValueType::Integer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValueImpl::CellValueImpl(double value) noexcept
    : m_Value{ value }, m_Type{ ValueType::Float }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValueImpl::CellValueImpl(const string& value)
    : m_Value{ value }, m_Type{ ValueType::String }
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

    m_Type = ValueType::Empty;
    m_Value = string{};
}

void CoreTools::SimpleCSV::CellValueImpl::SetError() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Type = ValueType::Error;
    m_Value = string{};
}

CoreTools::SimpleCSV::ValueType CoreTools::SimpleCSV::CellValueImpl::GetType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Type;
}

string CoreTools::SimpleCSV::CellValueImpl::GetTypeAsString() const
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

    return m_Value == rhs.m_Value;
}

bool CoreTools::SimpleCSV::CellValueImpl::IsLess(const CellValueImpl& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Value < rhs.m_Value;
}
