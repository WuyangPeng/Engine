///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/09 14:05)

#ifndef RENDERING_RESOURCES_MEMBER_LAYOUT_H
#define RENDERING_RESOURCES_MEMBER_LAYOUT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

#include <string>
#include <vector>

RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(MemberLayoutImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE MemberLayout final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(MemberLayout);

    public:
        MemberLayout(const std::string& name, int offset, int numElements);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetName() const;
        NODISCARD int GetOffset() const noexcept;
        NODISCARD int GetNumElements() const noexcept;

        NODISCARD int GetStreamingSize() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RESOURCES_MEMBER_LAYOUT_H