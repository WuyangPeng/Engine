///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 17:00)

#ifndef EXPORT_TEST_PHYSICS_PERFORMANCE_UNSHARED_MACRO_H
#define EXPORT_TEST_PHYSICS_PERFORMANCE_UNSHARED_MACRO_H

#include "Physics/PhysicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

PHYSICS_PERFORMANCE_UNSHARED_EXPORT_IMPL(PhysicsPerformanceUnsharedMacroImpl);

namespace Physics
{
    class PHYSICS_DEFAULT_DECLARE PhysicsPerformanceUnsharedMacro final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(PhysicsPerformanceUnsharedMacro);

    public:
        explicit PhysicsPerformanceUnsharedMacro(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // EXPORT_TEST_PHYSICS_PERFORMANCE_UNSHARED_MACRO_H