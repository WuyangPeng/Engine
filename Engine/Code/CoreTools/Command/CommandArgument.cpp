//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 16:44)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgument.h"
#include "Detail/CommandArgumentFactory.h"
#include "Detail/CommandArgumentPackage.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "../Contract/Flags/ImplFlags.h"

using std::string;
COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(CoreTools, CommandArgument)
CoreTools::CommandArgument::CommandArgument(int index, const string& arguments, const string& value)
    : impl{ ImplCreateUseFactory::Default, index, arguments, value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CommandArgument::CommandArgument(int index, const string& arguments)
    : impl{ ImplCreateUseFactory::Default, index, arguments }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CommandArgument)

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

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CommandArgument, SetUsed, void)

void CoreTools::CommandArgument::AddEndArgumentValue(const string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (impl.GetConstImpl()->IsNoValue())
    {
        // ����������impl��������Copy���á�
        const auto index = impl.GetConstImpl()->GetIndex();
        auto arguments = impl.GetConstImpl()->GetName();

        impl = PackageType{ ImplCreateUseFactory::Default, index, arguments, value };
    }
    else
    {
        impl->AddArgumentValue(value);
    }
}
