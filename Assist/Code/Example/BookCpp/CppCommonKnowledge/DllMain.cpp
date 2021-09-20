///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/16 17:44)

#include "Example/BookCpp/CppCommonKnowledge/CppCommonKnowledgeExport.h"

#include "CppCommonKnowledgeFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_COMMON_KNOWLEDGE_STATIC

DLL_MAIN_FUNCTION(CppCommonKnowledge);

#else  // BUILDING_CPP_COMMON_KNOWLEDGE_STATIC

CORE_TOOLS_MUTEX_INIT(CppCommonKnowledge);

#endif  // !BUILDING_CPP_COMMON_KNOWLEDGE_STATIC
