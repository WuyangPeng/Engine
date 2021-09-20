///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/21 18:24)

#include "Example/BookCpp/CppCommonKnowledge/CppCommonKnowledgeExport.h"

#include "Overload.h"
#include "OverloadDeclaration.h"
#include "Example/BookCpp/CppCommonKnowledge/Helper/CppCommonKnowledgeClassInvariantMacro.h"

BookExperience::CppCommonKnowledge::Overload::Overload() noexcept
{
    CPP_COMMON_KNOWLEDGE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::CppCommonKnowledge, Overload)

void BookExperience::CppCommonKnowledge::Overload::Main() const noexcept
{
    CPP_COMMON_KNOWLEDGE_CLASS_IS_VALID_CONST_9;

    F("Hello");
}
