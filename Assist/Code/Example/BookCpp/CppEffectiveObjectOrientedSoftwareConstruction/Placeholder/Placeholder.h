///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/24 15:21)

#ifndef CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_PLACEHOLDER_PLACEHOLDER_H
#define CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/CppEffectiveObjectOrientedSoftwareConstruction/CppEffectiveObjectOrientedSoftwareConstructionDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CppEffectiveObjectOrientedSoftwareConstruction
{
    class CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_PLACEHOLDER_PLACEHOLDER_H
