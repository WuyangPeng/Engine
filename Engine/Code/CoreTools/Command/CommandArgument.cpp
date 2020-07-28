// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 11:16)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgument.h"
#include "Detail/CommandArgumentImpl.h"
#include "Detail/CommandArgumentFactory.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

DELAY_COPY_CONSTRUCTION_CLONE_DEFINE(CoreTools, CommandArgument)

CoreTools::CommandArgument
	::CommandArgument(int index, const string& arguments, const string& value)
	:m_Impl{ CommandArgumentFactory::Create(index,arguments,value) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CommandArgument
	::CommandArgument(int index, const string& arguments)
	:m_Impl{ CommandArgumentFactory::Create(index,arguments) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, CommandArgument)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CommandArgument, GetIndex, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandArgument, GetName, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandArgument, GetInteger, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandArgument, GetFloat, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandArgument, GetDouble, double)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandArgument, GetString, const string)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CommandArgument, IsInteger, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CommandArgument, IsFloat, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CommandArgument, IsDouble, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CommandArgument, IsString, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CommandArgument, IsNoValue, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CommandArgument, IsUsed, bool)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandArgument, SetUsed, void)

void CoreTools::CommandArgument
	::AddEndArgumentValue(const string& value)
{
	static_assert(std::is_same_v<ClassShareType::NonConstCopyMember, CoreTools::TrueType>, "Non-const copy member functions are forbidden");

	CORE_TOOLS_CLASS_IS_VALID_1;

	if (m_Impl->IsNoValue())
	{
		// 由于重设了m_Impl，不进行Copy调用。
		const auto index = m_Impl->GetIndex();
		auto arguments = m_Impl->GetName();

		m_Impl = CommandArgumentFactory::Create(index, arguments, value);
	}
	else
	{
		Copy();

		m_Impl->AddArgumentValue(value);
	}
}

