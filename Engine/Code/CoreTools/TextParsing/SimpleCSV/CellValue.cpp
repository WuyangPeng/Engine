///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:26)

#include "CoreTools/CoreToolsExport.h"

#include "CellValueDetail.h"
#include "CellValueProxy.h"
#include "SimpleCSVException.h"
#include "Detail/CellValueImplDetail.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::ostream;
using std::string;

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, CellValue)

CoreTools::SimpleCSV::CellValue::CellValue(bool value)
    : impl{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValue::CellValue(int64_t value)
    : impl{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValue::CellValue(int value)
    : impl{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValue::CellValue(double value)
    : impl{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValue::CellValue(const string& value)
    : impl{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValue::CellValue(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValue::CellValue(const char* value)
    : CellValue{ string{ value } }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CellValue)

bool CoreTools::SimpleCSV::CellValue::GetBool() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->Get<bool>();
}

int64_t CoreTools::SimpleCSV::CellValue::GetIntegral() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->Get<int64_t>();
}

double CoreTools::SimpleCSV::CellValue::GetDouble() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->Get<double>();
}

string CoreTools::SimpleCSV::CellValue::GetString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->Get<string>();
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellValue, Clear, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellValue, SetError, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, CellValue, GetType, CoreTools::SimpleCSV::ValueType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellValue, GetTypeAsString, string)

bool CoreTools::SimpleCSV::CellValue::IsEqual(const CellValue& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsEqual(*rhs.impl);
}

bool CoreTools::SimpleCSV::CellValue::IsLess(const CellValue& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsLess(*rhs.impl);
}

CoreTools::SimpleCSV::CellValue CoreTools::SimpleCSV::CellValue::CreateDefault()
{
    return CellValue{ DisableNotThrow::Disable };
}

CoreTools::SimpleCSV::CellValue CoreTools::SimpleCSV::CellValue::CreateError()
{
    CellValue cellValue{ DisableNotThrow::Disable };
    cellValue.SetError();

    return cellValue;
}

bool CoreTools::SimpleCSV::operator==(const CellValue& lhs, const CellValue& rhs) noexcept
{
    return lhs.IsEqual(rhs);
}

bool CoreTools::SimpleCSV::operator<(const CellValue& lhs, const CellValue& rhs) noexcept
{
    return lhs.IsLess(rhs);
}

ostream& CoreTools::SimpleCSV::operator<<(ostream& os, const CellValue& value)
{
    switch (value.GetType())
    {
        case ValueType::Empty:
            return os << "";
        case ValueType::Boolean:
            return os << value.Get<bool>();
        case ValueType::Integer:
            return os << value.Get<int64_t>();
        case ValueType::Float:
            return os << value.Get<double>();
        case ValueType::String:
            return os << value.Get<string>();
        default:
            return os << "";
    }
}
