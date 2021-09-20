///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/16 21:23)

#ifndef CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_NOEXCEPT_MACRO_IMPL_H
#define CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_NOEXCEPT_MACRO_IMPL_H

#include "CoreTools/Helper/UserMacro.h"

#include <string>

namespace CoreTools
{
    class MemberFunctionNoexceptMacroImpl final
    {
    public:
        using ClassType = MemberFunctionNoexceptMacroImpl;

    public:
        MemberFunctionNoexceptMacroImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void ConstMemberFunction() const noexcept;
        void ConstMemberFunction(MAYBE_UNUSED const std::string& character) const noexcept;
        void ConstMemberFunction(MAYBE_UNUSED int value) const noexcept;
        void ConstMemberFunction(MAYBE_UNUSED const std::string* character) const noexcept;

        void NonConstCopyMemberFunction() noexcept;
        void NonConstCopyMemberFunction(MAYBE_UNUSED const std::string& character) noexcept;
        void NonConstCopyMemberFunction(MAYBE_UNUSED int value) noexcept;
        void NonConstCopyMemberFunction(MAYBE_UNUSED const std::string* character) noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_NOEXCEPT_MACRO_IMPL_H