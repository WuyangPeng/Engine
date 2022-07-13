///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 14:01)

#ifndef EXPORT_TEST_PHYSICS_NON_COPY_MACRO_H
#define EXPORT_TEST_PHYSICS_NON_COPY_MACRO_H

#include "Physics/PhysicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

PHYSICS_NON_COPY_EXPORT_IMPL(PhysicsNonCopyMacroImpl);

namespace Physics
{
    class PHYSICS_DEFAULT_DECLARE PhysicsNonCopyMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(PhysicsNonCopyMacro);

    public:
        explicit PhysicsNonCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_PHYSICS_NON_COPY_MACRO_H