// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 10:35)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_SECOND_SUBCLASS_SMART_POINTER_TEST_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_SECOND_SUBCLASS_SMART_POINTER_TEST_H

#include "FirstSubclassSmartPointerTest.h"

#include <string>

namespace CoreTools
{
    class SecondSubclassSmartPointerTest : public FirstSubclassSmartPointerTest
    {
    public:
        using ClassType = SecondSubclassSmartPointerTest;
        using ParentType = FirstSubclassSmartPointerTest;

    public:
        explicit SecondSubclassSmartPointerTest(int value) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SUITE_SECOND_SUBCLASS_SMART_POINTER_TEST_H