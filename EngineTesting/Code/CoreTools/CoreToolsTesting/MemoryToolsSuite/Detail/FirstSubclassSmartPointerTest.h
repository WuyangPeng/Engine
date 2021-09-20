// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 10:35)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_FIRST_SUBCLASS_SMART_POINTER_TEST_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_FIRST_SUBCLASS_SMART_POINTER_TEST_H

#include "CoreTools/Helper/UserMacro.h"

#include <string>

namespace CoreTools
{
    class FirstSubclassSmartPointerTest
    {
    public:
        using ClassType = FirstSubclassSmartPointerTest;

    public:
        explicit FirstSubclassSmartPointerTest(int value) noexcept;
        virtual ~FirstSubclassSmartPointerTest();
        FirstSubclassSmartPointerTest(const FirstSubclassSmartPointerTest&) noexcept = default;
        FirstSubclassSmartPointerTest& operator=(const FirstSubclassSmartPointerTest&) noexcept = default;
        FirstSubclassSmartPointerTest(FirstSubclassSmartPointerTest&&) noexcept = default;
        FirstSubclassSmartPointerTest& operator=(FirstSubclassSmartPointerTest&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        int GetValue() const noexcept;

    private:
        int m_Value;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SUITE_FIRST_SUBCLASS_SMART_POINTER_TEST_H