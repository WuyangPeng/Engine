///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:49)

#ifndef EXPORT_TEST_IMAGICS_MACRO_SHARED_IMPL_H
#define EXPORT_TEST_IMAGICS_MACRO_SHARED_IMPL_H

#include "Imagics/ImagicsDll.h"

namespace Imagics
{
    class IMAGICS_HIDDEN_DECLARE ImagicsMacroSharedImpl final
    {
    public:
        using ClassType = ImagicsMacroSharedImpl;

    public:
        explicit ImagicsMacroSharedImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int m_Count;
    };
}

#endif  // EXPORT_TEST_IMAGICS_MACRO_SHARED_IMPL_H