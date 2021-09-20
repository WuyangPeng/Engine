///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/16 17:46)

#ifndef MORE_EFFECTIVE_CPP_PREFACE_TERMINOLOGY_H
#define MORE_EFFECTIVE_CPP_PREFACE_TERMINOLOGY_H

#include "Example/BookCpp/MoreEffectiveCpp/MoreEffectiveCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace MoreEffectiveCpp
    {
        class MORE_EFFECTIVE_CPP_DEFAULT_DECLARE Terminology final
        {
        public:
            using ClassType = Terminology;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            Terminology() noexcept;

            void Main() const;
        };
    }
}

#endif  // MORE_EFFECTIVE_CPP_PREFACE_TERMINOLOGY_H
