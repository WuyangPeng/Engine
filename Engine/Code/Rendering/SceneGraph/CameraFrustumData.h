///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:09)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_DATA_H
#define RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_DATA_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE CameraFrustumData
    {
    public:
        using ClassType = CameraFrustumData;

    public:
        CameraFrustumData() noexcept;
        CameraFrustumData(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax, bool symmetric = true) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD float GetUpFieldOfViewDegrees() const;
        NODISCARD float GetAspectRatio() const;
        NODISCARD float GetDirectionMin() const;
        NODISCARD float GetDirectionMax() const;

        // 只有当返回是true是，其它值才是有效的。
        NODISCARD bool IsSymmetric() const noexcept;

    private:
        float upFieldOfViewDegrees;
        float aspectRatio;
        float directionMin;
        float directionMax;
        bool symmetric;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
