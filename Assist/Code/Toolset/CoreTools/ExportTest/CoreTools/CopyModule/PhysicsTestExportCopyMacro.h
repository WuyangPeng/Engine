/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:26)

#ifndef EXPORT_TEST_PHYSICS_TEST_EXPORT_COPY_MACRO_H
#define EXPORT_TEST_PHYSICS_TEST_EXPORT_COPY_MACRO_H

#include "Physics/PhysicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

EXPORT_SHARED_PTR(Physics, PhysicsTestExportCopyMacroImpl, PHYSICS_DEFAULT_DECLARE);
PHYSICS_COPY_EXPORT(PhysicsTestExportCopyMacro, PhysicsTestExportCopyMacroImpl, COPY_UNSHARED);

namespace Physics
{
    class PHYSICS_DEFAULT_DECLARE PhysicsTestExportCopyMacro final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(PhysicsTestExportCopyMacro);

    public:
        explicit PhysicsTestExportCopyMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_PHYSICS_TEST_EXPORT_COPY_MACRO_H