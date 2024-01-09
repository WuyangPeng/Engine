/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:49)

#ifndef RENDERING_RESOURCES_MEMBER_LAYOUT_H
#define RENDERING_RESOURCES_MEMBER_LAYOUT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

#include <string>

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