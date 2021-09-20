///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/21 18:24)

#ifndef CPP_COMMON_KNOWLEDGE_PREFACE_OVERLOAD_DECLARATION_H
#define CPP_COMMON_KNOWLEDGE_PREFACE_OVERLOAD_DECLARATION_H

#include "Example/BookCpp/CppCommonKnowledge/CppCommonKnowledgeDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace CppCommonKnowledge
    {
        void F(int) noexcept;
        void F(const char*) noexcept;
    }
}

#endif  // CPP_COMMON_KNOWLEDGE_PREFACE_OVERLOAD_DECLARATION_H
