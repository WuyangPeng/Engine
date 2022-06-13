///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:22)

#include "CallConstMemberFunctionMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

CoreTools::CallConstMemberFunctionMacro::CallConstMemberFunctionMacro(const std::string& macro)
    : macro{ macro }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CallConstMemberFunctionMacro)

const string& CoreTools::CallConstMemberFunctionMacro::ConstMemberFunction() const noexcept
{
    return macro;
}

const string& CoreTools::CallConstMemberFunctionMacro::ConstMemberFunction(MAYBE_UNUSED const string& character) const noexcept
{
    return macro;
}

const string& CoreTools::CallConstMemberFunctionMacro::operator[](MAYBE_UNUSED int index) const noexcept
{
    return macro;
}

const string* CoreTools::CallConstMemberFunctionMacro::operator[](MAYBE_UNUSED const string& character) const noexcept
{
    return &macro;
}

string& CoreTools::CallConstMemberFunctionMacro::operator[](int index) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return OPERATOR_SQUARE_BRACKETS(string, index);

#include STSTEM_WARNING_POP
}

string* CoreTools::CallConstMemberFunctionMacro::operator[](const string& character) noexcept
{
    return OPERATOR_SQUARE_BRACKETS_TO_POINTER(string, character);
}

string& CoreTools::CallConstMemberFunctionMacro::NonConstCopyMemberFunction() noexcept
{
    return NON_CONST_MEMBER_CALL_CONST_MEMBER(string&, ConstMemberFunction);
}

string& CoreTools::CallConstMemberFunctionMacro::NonConstCopyMemberFunction(const string& character) noexcept
{
    return NON_CONST_MEMBER_CALL_CONST_MEMBER_USE_PARAMETER(string&, ConstMemberFunction, character);
}
