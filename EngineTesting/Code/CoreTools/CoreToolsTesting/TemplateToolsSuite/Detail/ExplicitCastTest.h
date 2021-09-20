// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 15:35)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TEST_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TEST_H

#include "CoreTools/TemplateTools/ExplicitCast.h"

#include <string>

namespace CoreTools
{
    class ExplicitCastTest
    {
    public:
        using ClassType = ExplicitCastTest;

        ExplicitCastTest();

        CLASS_INVARIANT_DECLARE;

        operator ExplicitCast<int>() const noexcept;
        operator ExplicitCast<const std::string&>() const noexcept;
        operator ExplicitCast<const std::string*>() const noexcept;

        operator ExplicitCast<short*>() = delete;
        operator ExplicitCast<short&>() = delete;

    private:
        int m_Integer;
        std::string m_StringValue;
        short m_ShortValue;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TEST_H
