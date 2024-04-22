/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 20:36)

#ifndef CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_NOEXCEPT_MACRO_H
#define CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_NOEXCEPT_MACRO_H

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/HelperSuiteFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

namespace CoreTools
{
    class MemberFunctionNoexceptMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(MemberFunctionNoexceptMacro);

    public:
        NODISCARD static MemberFunctionNoexceptMacro Create();

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
        explicit MemberFunctionNoexceptMacro(DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_NOEXCEPT_MACRO_H