///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 14:44)

#ifndef EXPORT_TEST_FRAMEWORK_MACRO_SHARED_IMPL_H
#define EXPORT_TEST_FRAMEWORK_MACRO_SHARED_IMPL_H

#include "Framework/FrameworkDll.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE FrameworkMacroSharedImpl final
    {
    public:
        using ClassType = FrameworkMacroSharedImpl;

    public:
        explicit FrameworkMacroSharedImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_FRAMEWORK_MACRO_SHARED_IMPL_H