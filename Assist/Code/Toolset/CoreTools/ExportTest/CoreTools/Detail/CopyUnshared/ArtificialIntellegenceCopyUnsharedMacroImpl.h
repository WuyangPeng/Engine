///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:35)

#ifndef EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_COPY_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_COPY_UNSHARED_MACRO_IMPL_H

#include "ArtificialIntellegence/ArtificialIntellegenceDll.h"

namespace ArtificialIntellegence
{
    class ARTIFICIAL_INTELLEGENCE_HIDDEN_DECLARE ArtificialIntellegenceCopyUnsharedMacroImpl final
    {
    public:
        using ClassType = ArtificialIntellegenceCopyUnsharedMacroImpl;

    public:
        explicit ArtificialIntellegenceCopyUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int m_Count;
    };
}

#endif  // EXPORT_TEST_ARTIFICIAL_INTELLEGENCE_COPY_UNSHARED_MACRO_IMPL_H