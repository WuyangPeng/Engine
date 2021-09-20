///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.0 (2021/02/21 18:33)

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
