///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/01 10:06)

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

        // ֻ�е�������true�ǣ�����ֵ������Ч�ġ�
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
