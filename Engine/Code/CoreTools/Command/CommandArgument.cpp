//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 16:44)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgument.h"
#include "Detail/CommandArgumentFactory.h"
#include "Detail/CommandArgumentImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

DELAY_COPY_CONSTRUCTION_CLONE_DEFINE(CoreTools, CommandArgument)

CoreTools::CommandArgument::CommandArgument(int index, const string& arguments, const string& value)
    : m_Impl{ CommandArgumentFactory::Create(index, arguments, value) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CommandArgument::CommandArgument(int index, const string& arguments)
    : m_Impl{ CommandArgumentFactory::Create(index, arguments) }
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

void CoreTools::CommandArgument::AddEndArgumentValue(const string& value)
{
    static_assert(std::is_same_v<ClassShareType::NonConstCopyMember, CoreTools::TrueType>, "Non-const copy member functions are forbidden");

    CORE_TOOLS_CLASS_IS_VALID_1;

    if (m_Impl->IsNoValue())
    {
        // ����������m_Impl��������Copy���á�
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
