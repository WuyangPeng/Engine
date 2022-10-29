///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 23:44)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_PERFORMANCE_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_PERFORMANCE_UNSHARED_MACRO_IMPL_H

#include "ArtificialIntellegence/ArtificialIntellegenceDll.h"

namespace ArtificialIntellegence
{
    class ARTIFICIAL_INTELLEGENCE_HIDDEN_DECLARE ArtificialIntellegencePerformanceUnsharedMacroImpl final
    {
    public:
        using ClassType = ArtificialIntellegencePerformanceUnsharedMacroImpl;

    public:
        explicit ArtificialIntellegencePerformanceUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept; 

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_PERFORMANCE_UNSHARED_MACRO_IMPL_H