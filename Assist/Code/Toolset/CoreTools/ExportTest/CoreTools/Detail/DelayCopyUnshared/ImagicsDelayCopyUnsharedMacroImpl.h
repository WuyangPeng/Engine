///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:37)

#ifndef EXPORT_TEST_IMAGICS_DELAY_COPY_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_IMAGICS_DELAY_COPY_UNSHARED_MACRO_IMPL_H

#include "Imagics/ImagicsDll.h"

namespace Imagics
{
    class IMAGICS_HIDDEN_DECLARE ImagicsDelayCopyUnsharedMacroImpl final
    {
    public:
        using ClassType = ImagicsDelayCopyUnsharedMacroImpl;

    public:
        explicit ImagicsDelayCopyUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int m_Count;
    };
}

#endif  // EXPORT_TEST_IMAGICS_DELAY_COPY_UNSHARED_MACRO_IMPL_H