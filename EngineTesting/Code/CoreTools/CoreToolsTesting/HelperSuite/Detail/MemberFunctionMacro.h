///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/16 21:23)

#ifndef CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_MACRO_H
#define CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_MACRO_H

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

namespace CoreTools
{
    class MemberFunctionMacroImpl;

    class MemberFunctionMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(MemberFunctionMacro);

    public:
        explicit MemberFunctionMacro(MAYBE_UNUSED DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string ConstMemberFunction() const;
        NODISCARD std::string ConstMemberFunction(const std::string& character) const;
        NODISCARD std::string ConstMemberFunction(int value) const;
        NODISCARD std::string ConstMemberFunction(const std::string* character) const;

        void NonConstCopyMemberFunction();
        void NonConstCopyMemberFunction(const std::string& character);
        void NonConstCopyMemberFunction(int value);
        void NonConstCopyMemberFunction(const std::string* character);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_MACRO_H