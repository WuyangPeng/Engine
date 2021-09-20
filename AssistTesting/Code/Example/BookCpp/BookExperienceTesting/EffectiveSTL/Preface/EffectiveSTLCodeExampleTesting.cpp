///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/16 21:02)

#include "EffectiveSTLCodeExampleTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/EffectiveSTL/Helper/EffectiveSTLClassInvariantMacro.h"
#include "Example/BookCpp/EffectiveSTL/Preface/CodeExample.h"

BookExperience::EffectiveSTL::EffectiveSTLCodeExampleTesting::EffectiveSTLCodeExampleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EFFECTIVE_STL_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::EffectiveSTL, EffectiveSTLCodeExampleTesting)

void BookExperience::EffectiveSTL::EffectiveSTLCodeExampleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EmptyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LastGreaterThanFirstTrueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LastGreaterThanFirstFalseTest);
}

void BookExperience::EffectiveSTL::EffectiveSTLCodeExampleTesting::MainTest()
{
    const CodeExample codeExample{};

    codeExample.Main();
}

void BookExperience::EffectiveSTL::EffectiveSTLCodeExampleTesting::EmptyTest()
{
    const CodeExample codeExample{};

    std::vector<int> emptyContainer{};

    ASSERT_FALSE(codeExample.LastGreaterThanFirst(emptyContainer));
}

void BookExperience::EffectiveSTL::EffectiveSTLCodeExampleTesting::LastGreaterThanFirstTrueTest()
{
    const CodeExample codeExample{};

    std::vector<int> container{ 1, 5, 9 };

    ASSERT_TRUE(codeExample.LastGreaterThanFirst(container));
}

void BookExperience::EffectiveSTL::EffectiveSTLCodeExampleTesting::LastGreaterThanFirstFalseTest()
{
    const CodeExample codeExample{};

    std::vector<int> container{ 12, 5, 9, 11 };

    ASSERT_FALSE(codeExample.LastGreaterThanFirst(container));
}
