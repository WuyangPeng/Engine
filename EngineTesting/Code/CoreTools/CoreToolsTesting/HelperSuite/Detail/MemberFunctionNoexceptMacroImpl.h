///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/12 21:16)

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
        void ConstMemberFunction(const std::string& character) const noexcept;
        void ConstMemberFunction(int value) const noexcept;
        void ConstMemberFunction(const std::string* character) const noexcept;

        void NonConstCopyMemberFunction() noexcept;
        void NonConstCopyMemberFunction(const std::string& character) noexcept;
        void NonConstCopyMemberFunction(int value) noexcept;
        void NonConstCopyMemberFunction(const std::string* character) noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_NOEXCEPT_MACRO_IMPL_H