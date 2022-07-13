///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 22:02)

#ifndef EXPORT_TEST_IMAGICS_COPY_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_IMAGICS_COPY_UNSHARED_MACRO_IMPL_H

#include "Imagics/ImagicsDll.h"

namespace Imagics
{
    class IMAGICS_HIDDEN_DECLARE ImagicsCopyUnsharedMacroImpl final
    {
    public:
        using ClassType = ImagicsCopyUnsharedMacroImpl;

    public:
        explicit ImagicsCopyUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int mCount;
    };
}

#endif  // EXPORT_TEST_IMAGICS_COPY_UNSHARED_MACRO_IMPL_H