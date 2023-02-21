///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 16:47)

#ifndef EXPORT_TEST_PHYSICS_TEST_EXPORT_MACRO_IMPL_H
#define EXPORT_TEST_PHYSICS_TEST_EXPORT_MACRO_IMPL_H

#include "Physics/PhysicsDll.h"

namespace Physics
{
    class PHYSICS_HIDDEN_DECLARE PhysicsTestExportMacroImpl final
    {
    public:
        using ClassType = PhysicsTestExportMacroImpl;

    public:
        explicit PhysicsTestExportMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_PHYSICS_TEST_EXPORT_MACRO_IMPL_H