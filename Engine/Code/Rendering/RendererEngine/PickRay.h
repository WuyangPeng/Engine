///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 15:32)

#ifndef RENDERING_RENDERER_ENGINE_PICK_RAY_H
#define RENDERING_RENDERER_ENGINE_PICK_RAY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"

RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(PickRayImpl);

/// 根据指定的左手屏幕坐标（x，y）并使用当前相机来计算光线。
/// 输出的“原点”是相机位置，而“方向”是单位长度矢量。
/// 两者都在世界坐标中。 如果（x，y）在当前视口中的则返回值为'true'。
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PickRay
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(PickRay);

        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;

    public:
        PickRay(bool result, const APoint& origin, const AVector& direction);
        NODISCARD static PickRay Create();

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsResult() const noexcept;
        NODISCARD APoint GetOrigin() const noexcept;
        NODISCARD AVector GetDirection() const noexcept;

    private:
        enum class PickRayCreate
        {
            Init,
        };

    public:
        explicit PickRay(PickRayCreate pickRayCreate);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_PICK_RAY_H
