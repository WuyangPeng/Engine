///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:41)

#ifndef EXPORT_TEST_IMAGICS_TEST_EXPORT_MACRO_IMPL_H
#define EXPORT_TEST_IMAGICS_TEST_EXPORT_MACRO_IMPL_H

#include "Imagics/ImagicsDll.h"

namespace Imagics
{
    class IMAGICS_HIDDEN_DECLARE ImagicsTestExportMacroImpl final
    {
    public:
        using ClassType = ImagicsTestExportMacroImpl;

    public:
        explicit ImagicsTestExportMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        int m_Count;
    };
}

#endif  // EXPORT_TEST_IMAGICS_TEST_EXPORT_MACRO_IMPL_H