///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:15)

#ifndef CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_NOEXCEPT_MACRO_H
#define CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_NOEXCEPT_MACRO_H

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

namespace CoreTools
{
    class MemberFunctionNoexceptMacroImpl;

    class MemberFunctionNoexceptMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(MemberFunctionNoexceptMacro);

    public:
        explicit MemberFunctionNoexceptMacro(MAYBE_UNUSED DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        void ConstMemberFunction() const noexcept;
        void ConstMemberFunction(const std::string& character) const noexcept;
        void ConstMemberFunction(int value) const noexcept;
        void ConstMemberFunction(const std::string* character) const noexcept;

        void NonConstCopyMemberFunction() noexcept;
        void NonConstCopyMemberFunction(const std::string& character) noexcept;
        void NonConstCopyMemberFunction(int value) noexcept;
        void NonConstCopyMemberFunction(const std::string* character) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_NOEXCEPT_MACRO_H