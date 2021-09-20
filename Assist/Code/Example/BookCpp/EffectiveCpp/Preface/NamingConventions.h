///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/16 17:46)

#ifndef EFFECTIVE_CPP_PREFACE_NAMING_CONVENTIONS_H
#define EFFECTIVE_CPP_PREFACE_NAMING_CONVENTIONS_H

#include "Example/BookCpp/EffectiveCpp/EffectiveCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveCpp
    {
        class EFFECTIVE_CPP_DEFAULT_DECLARE NamingConventions final
        {
        public:
            using ClassType = NamingConventions;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            NamingConventions() noexcept;

            void Main() const noexcept;           
        };
    }
}

#endif  // EFFECTIVE_CPP_PREFACE_NAMING_CONVENTIONS_H
