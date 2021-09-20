///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.0 (2021/02/21 18:33)

#include "CppCommonKnowledgeOverloadTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/CppCommonKnowledge/Helper/CppCommonKnowledgeClassInvariantMacro.h"
#include "Example/BookCpp/CppCommonKnowledge/Preface/Overload.h"

BookExperience::CppCommonKnowledge::CppCommonKnowledgeOverloadTesting::CppCommonKnowledgeOverloadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_COMMON_KNOWLEDGE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::CppCommonKnowledge, CppCommonKnowledgeOverloadTesting)

void BookExperience::CppCommonKnowledge::CppCommonKnowledgeOverloadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::CppCommonKnowledge::CppCommonKnowledgeOverloadTesting::MainTest() noexcept
{
    const Overload overload{};

    overload.Main();
}
