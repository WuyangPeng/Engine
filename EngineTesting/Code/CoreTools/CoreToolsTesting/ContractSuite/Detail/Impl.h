///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/26 15:07)

#ifndef CORE_TOOLS_CONTRACT_SUITE_IMPL_H
#define CORE_TOOLS_CONTRACT_SUITE_IMPL_H

#include "CoreTools/Helper/UserMacro.h"

#include <memory>

namespace CoreTools
{
    class Impl final
    {
    public:
        using ClassType = Impl;
        using FactoryType = ClassType;
        using ImplSharedPtr = std::shared_ptr<ClassType>;

    public:
        Impl() noexcept;
        explicit Impl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;
        NODISCARD size_t GetAddress() const noexcept;

        NODISCARD static ImplSharedPtr Create(int count);
        NODISCARD static ImplSharedPtr Create();

    private:
        int m_Count;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_IMPL_H