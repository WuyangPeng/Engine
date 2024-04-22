/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 21:00)

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