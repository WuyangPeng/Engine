///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/16 17:44)

#include "Example/BookCpp/CppCommonKnowledge/CppCommonKnowledgeExport.h"

#include "CppCommonKnowledgeFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_COMMON_KNOWLEDGE_STATIC

DLL_MAIN_FUNCTION(CppCommonKnowledge);

#else  // BUILDING_CPP_COMMON_KNOWLEDGE_STATIC

CORE_TOOLS_MUTEX_INIT(CppCommonKnowledge);

#endif  // !BUILDING_CPP_COMMON_KNOWLEDGE_STATIC
