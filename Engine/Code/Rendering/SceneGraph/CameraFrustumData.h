/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/28 17:54)

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
