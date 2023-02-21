///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 16:57)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_MACRO_SHARED_IMPL_H
#define EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_MACRO_SHARED_IMPL_H

#include "ArtificialIntellegence/ArtificialIntellegenceDll.h"

namespace ArtificialIntellegence
{
    class ARTIFICIAL_INTELLEGENCE_HIDDEN_DECLARE ArtificialIntellegenceMacroSharedImpl final
    {
    public:
        using ClassType = ArtificialIntellegenceMacroSharedImpl;

    public:
        explicit ArtificialIntellegenceMacroSharedImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_MACRO_SHARED_IMPL_H