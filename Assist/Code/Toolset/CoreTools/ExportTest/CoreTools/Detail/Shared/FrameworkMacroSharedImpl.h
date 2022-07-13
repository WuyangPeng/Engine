///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 22:24)

#ifndef EXPORT_TEST_FRAMEWORK_MACRO_SHARED_IMPL_H
#define EXPORT_TEST_FRAMEWORK_MACRO_SHARED_IMPL_H

#include "Framework/FrameworkDll.h"

#include <memory>

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
        void SetCount(int count) noexcept;

    private:
        int mCount;
    };
}

#endif  // EXPORT_TEST_FRAMEWORK_MACRO_SHARED_IMPL_H