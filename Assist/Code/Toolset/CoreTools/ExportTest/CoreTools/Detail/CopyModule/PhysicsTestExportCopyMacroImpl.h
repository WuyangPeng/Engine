///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/17 11:43)

#ifndef EXPORT_TEST_PHYSICS_TEST_EXPORT_COPY_MACRO_IMPL_H
#define EXPORT_TEST_PHYSICS_TEST_EXPORT_COPY_MACRO_IMPL_H

#include "Physics/PhysicsDll.h"

namespace Physics
{
    class PHYSICS_HIDDEN_DECLARE PhysicsTestExportCopyMacroImpl final
    {
    public:
        using ClassType = PhysicsTestExportCopyMacroImpl;

    public:
        explicit PhysicsTestExportCopyMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int aCount) noexcept;

    private:
        int count;
    };
}

#endif  // EXPORT_TEST_PHYSICS_TEST_EXPORT_COPY_MACRO_IMPL_H