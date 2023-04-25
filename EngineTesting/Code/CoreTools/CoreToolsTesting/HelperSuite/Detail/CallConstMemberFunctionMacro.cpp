///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 21:02)

#include "CallConstMemberFunctionMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::CallConstMemberFunctionMacro::CallConstMemberFunctionMacro(const std::string& macro)
    : macro{ macro }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CallConstMemberFunctionMacro)

const std::string& CoreTools::CallConstMemberFunctionMacro::ConstMemberFunction() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return macro;
}

const std::string& CoreTools::CallConstMemberFunctionMacro::ConstMemberFunction(const std::string& character) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(character);

    return macro;
}

const std::string& CoreTools::CallConstMemberFunctionMacro::operator[](int index) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    return macro;
}

const std::string* CoreTools::CallConstMemberFunctionMacro::operator[](const std::string& character) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(character);

    return &macro;
}

std::string& CoreTools::CallConstMemberFunctionMacro::operator[](int index) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return OPERATOR_SQUARE_BRACKETS(std::string, index);

#include STSTEM_WARNING_POP
}

std::string* CoreTools::CallConstMemberFunctionMacro::operator[](const std::string& character) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS_TO_POINTER(std::string, character);
}

std::string& CoreTools::CallConstMemberFunctionMacro::NonConstCopyMemberFunction() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(std::string&, ConstMemberFunction);
}

std::string& CoreTools::CallConstMemberFunctionMacro::NonConstCopyMemberFunction(const std::string& character) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER_USE_PARAMETER(std::string&, ConstMemberFunction, character);
}
