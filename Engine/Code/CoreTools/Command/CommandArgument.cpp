/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:24)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgument.h"
#include "Detail/CommandArgumentFactory.h"
#include "Detail/CommandArgumentPackage.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(CoreTools, CommandArgument)

CoreTools::CommandArgument::CommandArgument(int index, const std::string& arguments, const std::string& value)
    : impl{ ImplCreateUseFactory::Default, index, arguments, value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::CommandArgument::CommandArgument(int index, const std::string& arguments)
    : impl{ ImplCreateUseFactory::Default, index, arguments }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CommandArgument)

int CoreTools::CommandArgument::GetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetIndex();
}

std::string CoreTools::CommandArgument::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetName();
}

int CoreTools::CommandArgument::GetInteger() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetInteger();
}

float CoreTools::CommandArgument::GetFloat() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetFloat();
}

double CoreTools::CommandArgument::GetDouble() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetDouble();
}

std::string CoreTools::CommandArgument::GetString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetString();
}

bool CoreTools::CommandArgument::IsInteger() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsInteger();
}

bool CoreTools::CommandArgument::IsFloat() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsFloat();
}

bool CoreTools::CommandArgument::IsDouble() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsDouble();
}

bool CoreTools::CommandArgument::IsString() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsString();
}

bool CoreTools::CommandArgument::IsNoValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsNoValue();
}

bool CoreTools::CommandArgument::IsUsed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsUsed();
}

void CoreTools::CommandArgument::SetUsed()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetUsed();
}

void CoreTools::CommandArgument::AddEndArgumentValue(const std::string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    /// 由于重设了impl，不进行Copy调用。
    if (const auto iter = impl.GetConstImpl();
        iter->IsNoValue())
    {
        const auto index = iter->GetIndex();
        const auto arguments = iter->GetName();

        impl = PackageType{ ImplCreateUseFactory::Default, index, arguments, value };
    }
    else
    {
        impl->AddArgumentValue(value);
    }
}
