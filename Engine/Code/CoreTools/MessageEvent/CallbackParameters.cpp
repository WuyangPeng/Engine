///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/26 18:30)

#include "CoreTools/CoreToolsExport.h"

#include "CallbackParameters.h"
#include "Detail/CallbackParametersImplDetail.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;
using std::wstring;

CoreTools::CallbackParameters::CallbackParameters(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, CallbackParameters)

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CallbackParameters)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CallbackParameters, GetContainerSize, int)

bool CoreTools::CallbackParameters::GetBoolValue(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<bool>(index);
}

int8_t CoreTools::CallbackParameters::GetInt8Value(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<int8_t>(index);
}

uint8_t CoreTools::CallbackParameters::GetUInt8Value(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<uint8_t>(index);
}

int16_t CoreTools::CallbackParameters::GetInt16Value(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<int16_t>(index);
}

uint16_t CoreTools::CallbackParameters::GetUInt16Value(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<uint16_t>(index);
}

int32_t CoreTools::CallbackParameters::GetInt32Value(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<int32_t>(index);
}

uint32_t CoreTools::CallbackParameters::GetUInt32Value(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<uint32_t>(index);
}

int64_t CoreTools::CallbackParameters::GetInt64Value(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<int64_t>(index);
}

uint64_t CoreTools::CallbackParameters::GetUInt64Value(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<uint64_t>(index);
}

float CoreTools::CallbackParameters::GetFloatValue(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<float>(index);
}

double CoreTools::CallbackParameters::GetDoubleValue(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<double>(index);
}

CoreTools::ConstParametersInterfaceSharedPtr CoreTools::CallbackParameters::GetParametersInterfaceValue(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<ConstParametersInterfaceSharedPtr>(index);
}

void CoreTools::CallbackParameters::SetValue(int index, bool value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetValue(index, value);
}

void CoreTools::CallbackParameters::SetValue(int index, const ParametersInterface& parameters)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    // ����һ�ݣ�ȷ��CallbackParameters�ڱ����smartPointer�޷��������޸ġ�
    return impl->SetValue<ConstParametersInterfaceSharedPtr>(index, parameters.Clone());
}

void CoreTools::CallbackParameters::SetValue(int index, double value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetValue(index, value);
}

void CoreTools::CallbackParameters::SetValue(int index, float value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetValue(index, value);
}

void CoreTools::CallbackParameters::SetValue(int index, uint64_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetValue(index, value);
}

void CoreTools::CallbackParameters::SetValue(int index, int64_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetValue(index, value);
}

void CoreTools::CallbackParameters::SetValue(int index, uint32_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetValue(index, value);
}

void CoreTools::CallbackParameters::SetValue(int index, int32_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetValue(index, value);
}

void CoreTools::CallbackParameters::SetValue(int index, uint16_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetValue(index, value);
}

void CoreTools::CallbackParameters::SetValue(int index, int16_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetValue(index, value);
}

void CoreTools::CallbackParameters::SetValue(int index, uint8_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetValue(index, value);
}

void CoreTools::CallbackParameters::SetValue(int index, int8_t value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetValue(index, value);
}

void CoreTools::CallbackParameters::SetValue(int index, const string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetValue(index, value);
}

void CoreTools::CallbackParameters::SetValue(int index, const wstring& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetValue(index, value);
}

string CoreTools::CallbackParameters::GetStringValue(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<string>(index);
}

wstring CoreTools::CallbackParameters::GetWStringValue(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<wstring>(index);
}

System::String CoreTools::CallbackParameters::GetTStringValue(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetValue<System::String>(index);
}
