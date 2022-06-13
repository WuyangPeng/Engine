///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 18:40)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TEST_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TEST_H

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/TemplateTools/ExplicitCast.h"

#include <string>

namespace CoreTools
{
    class ExplicitCastTest
    {
    public:
        using ClassType = ExplicitCastTest;

    public:
        explicit ExplicitCastTest(MAYBE_UNUSED DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator ExplicitCast<int>() const noexcept;
        NODISCARD operator ExplicitCast<const std::string&>() const noexcept;
        NODISCARD operator ExplicitCast<const std::string*>() const noexcept;

        operator ExplicitCast<short*>() = delete;
        operator ExplicitCast<short&>() = delete;

    private:
        int integer;
        std::string stringValue;
        short shortValue;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TEST_H
