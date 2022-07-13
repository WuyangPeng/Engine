///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:08)

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

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_PHYSICS_DELAY_COPY_UNSHARED_MACRO_H