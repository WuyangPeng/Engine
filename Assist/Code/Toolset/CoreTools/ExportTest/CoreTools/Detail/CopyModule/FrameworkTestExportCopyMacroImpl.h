///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 16:37)

#ifndef EXPORT_TEST_FRAMEWORK_TEST_EXPORT_COPY_MACRO_IMPL_H
#define EXPORT_TEST_FRAMEWORK_TEST_EXPORT_COPY_MACRO_IMPL_H

#include "Framework/FrameworkDll.h"

#include <memory>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE FrameworkTestExportCopyMacroImpl final
    {
    public:
        using ClassType = FrameworkTestExportCopyMacroImpl;

    public:
        explicit FrameworkTestExportCopyMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_FRAMEWORK_TEST_EXPORT_COPY_MACRO_IMPL_H