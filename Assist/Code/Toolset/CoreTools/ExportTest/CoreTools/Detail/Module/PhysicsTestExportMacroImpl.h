/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:39)

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