///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/17 13:46)

#ifndef EXPORT_TEST_PHYSICS_COPY_UNSHARED_MACRO_IMPL_H
#define EXPORT_TEST_PHYSICS_COPY_UNSHARED_MACRO_IMPL_H

#include "Physics/PhysicsDll.h"

namespace Physics
{
    class PHYSICS_HIDDEN_DECLARE PhysicsCopyUnsharedMacroImpl final
    {
    public:
        using ClassType = PhysicsCopyUnsharedMacroImpl;

    public:
        explicit PhysicsCopyUnsharedMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_PHYSICS_COPY_UNSHARED_MACRO_IMPL_H