///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/16 17:45)

#include "Example/BookCpp/CppCommonKnowledge/CppCommonKnowledgeExport.h"

#include "CppCommonKnowledge.h"

#ifndef BUILDING_CPP_COMMON_KNOWLEDGE_STATIC

    #include "DllLib.h"

#else  // BUILDING_CPP_COMMON_KNOWLEDGE_STATIC

namespace CppCommonKnowledge
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CPP_COMMON_KNOWLEDGE_STATIC