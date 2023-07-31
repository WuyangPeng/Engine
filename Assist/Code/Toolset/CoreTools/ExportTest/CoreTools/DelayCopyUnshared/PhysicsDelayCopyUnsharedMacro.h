///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:56)

#ifndef EXPORT_TEST_PHYSICS_DELAY_COPY_UNSHARED_MACRO_H
#define EXPORT_TEST_PHYSICS_DELAY_COPY_UNSHARED_MACRO_H

#include "Physics/PhysicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

PHYSICS_DELAY_COPY_UNSHARED_EXPORT_IMPL(PhysicsDelayCopyUnsharedMacro, PhysicsDelayCopyUnsharedMacroImpl);

namespace Physics
{
    class PHYSICS_DEFAULT_DECLARE PhysicsDelayCopyUnsharedMacro final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(PhysicsDelayCopyUnsharedMacro);

    public:
        explicit PhysicsDelayCopyUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count);

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_PHYSICS_DELAY_COPY_UNSHARED_MACRO_H