// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 17:12)

#include "CoreTools/CoreToolsExport.h"

#include "CallbackParameters.h"
#include "Detail/CallbackParametersImplDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"

using std::string;
using std::wstring;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::CallbackParameters
	::CallbackParameters(int count)
	:m_Impl(make_shared<ImplType>(count))
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP
DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, CallbackParameters)

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, CallbackParameters)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CallbackParameters, GetContainerSize, int)

bool CoreTools::CallbackParameters
	::GetBoolValue(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<bool>(index);
}

int8_t CoreTools::CallbackParameters
	::GetInt8Value(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<int8_t>(index);
}

uint8_t CoreTools::CallbackParameters
	::GetUInt8Value(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<uint8_t>(index);
}

int16_t CoreTools::CallbackParameters
	::GetInt16Value(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<int16_t>(index);
}

uint16_t CoreTools::CallbackParameters
	::GetUInt16Value(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<uint16_t>(index);
}

int CoreTools::CallbackParameters
	::GetInt32Value(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<int>(index);
}

uint32_t CoreTools::CallbackParameters
	::GetUInt32Value(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<uint32_t>(index);
}

int64_t CoreTools::CallbackParameters
	::GetInt64Value(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<int64_t>(index);
}

uint64_t CoreTools::CallbackParameters
	::GetUInt64Value(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<uint64_t>(index);
}

float CoreTools::CallbackParameters
	::GetFloatValue(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<float>(index);
}

double CoreTools::CallbackParameters
	::GetDoubleValue(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<double>(index);
}

const CoreTools::ConstParametersInterfaceSharedPtr CoreTools::CallbackParameters
	::GetParametersInterfaceValue(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<ConstParametersInterfaceSharedPtr>(index);
}

void CoreTools::CallbackParameters
	::SetValue(int index, bool value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetValue<bool>(index, value);
}

void CoreTools::CallbackParameters
	::SetValue(int index, const ParametersInterface& parameters)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	// 复制一份，确保CallbackParameters内保存的smartPointer无法被二次修改。
	return m_Impl->SetValue<ConstParametersInterfaceSharedPtr>(index, parameters.Clone());
}

void CoreTools::CallbackParameters
	::SetValue(int index, double value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetValue<double>(index, value);
}

void CoreTools::CallbackParameters
	::SetValue(int index, float value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetValue<float>(index, value);
}

void CoreTools::CallbackParameters
	::SetValue(int index, uint64_t value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetValue<uint64_t>(index, value);
}

void CoreTools::CallbackParameters
	::SetValue(int index, int64_t value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetValue<int64_t>(index, value);
}

void CoreTools::CallbackParameters
	::SetValue(int index, uint32_t value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetValue<uint32_t>(index, value);
}

void CoreTools::CallbackParameters
	::SetValue(int index, int value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetValue<int>(index, value);
}

void CoreTools::CallbackParameters
	::SetValue(int index, uint16_t value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetValue<uint16_t>(index, value);
}

void CoreTools::CallbackParameters
	::SetValue(int index, int16_t value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetValue<int16_t>(index, value);
}

void CoreTools::CallbackParameters
	::SetValue(int index, uint8_t value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetValue<uint8_t>(index, value);
}

void CoreTools::CallbackParameters
	::SetValue(int index, int8_t value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetValue<int8_t>(index, value);
}

void CoreTools::CallbackParameters
	::SetValue(int index, const string& value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetValue<string>(index, value);
}

void CoreTools::CallbackParameters
	::SetValue(int index, const wstring& value)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetValue<wstring>(index, value);
}

string CoreTools::CallbackParameters
	::GetStringValue(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<string>(index);
}

wstring CoreTools::CallbackParameters
	::GetWStringValue(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<wstring>(index);
}

System::String CoreTools::CallbackParameters
	::GetTStringValue(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetValue<System::String>(index);
}

