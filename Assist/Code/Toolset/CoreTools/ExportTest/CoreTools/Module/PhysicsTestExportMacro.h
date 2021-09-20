///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 16:56)

#ifndef EXPORT_TEST_PHYSICS_TEST_EXPORT_MACRO_H
#define EXPORT_TEST_PHYSICS_TEST_EXPORT_MACRO_H

#include "Physics/PhysicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

EXPORT_SHARED_PTR(Physics, PhysicsTestExportMacroImpl, PHYSICS_DEFAULT_DECLARE);
PHYSICS_EXPORT(PhysicsTestExportMacroImpl, NON_COPY);
PHYSICS_EXPORT_UNIQUE_PTR(PhysicsTestExportMacro);

namespace Physics
{
    class PHYSICS_DEFAULT_DECLARE PhysicsTestExportMacro final
    {
    public:
        NON_COPY_TYPE_DECLARE(PhysicsTestExportMacro);

    public:
        explicit PhysicsTestExportMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_PHYSICS_TEST_EXPORT_MACRO_H