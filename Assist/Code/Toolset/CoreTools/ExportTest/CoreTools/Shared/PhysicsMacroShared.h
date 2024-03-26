/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:56)

#ifndef EXPORT_TEST_PHYSICS_MACRO_SHARED_H
#define EXPORT_TEST_PHYSICS_MACRO_SHARED_H

#include "Physics/PhysicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/SharedExportMacro.h"

PHYSICS_SHARED_EXPORT_IMPL(PhysicsMacroSharedImpl);

namespace Physics
{
    class PHYSICS_DEFAULT_DECLARE PhysicsMacroShared final
    {
    public:
        SHARED_TYPE_DECLARE(PhysicsMacroShared);

    public:
        explicit PhysicsMacroShared(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;
        void SetCount(int count) noexcept;

        NODISCARD const void* GetAddress() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_PHYSICS_MACRO_SHARED_H