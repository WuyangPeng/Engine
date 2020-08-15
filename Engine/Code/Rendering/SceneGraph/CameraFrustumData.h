// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 11:16)

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
  
        float GetUpFieldOfViewDegrees() const;
        float GetAspectRatio() const;
        float GetDirectionMin() const;
        float GetDirectionMax() const;
        
        // 只有当返回是true是，其它值才是有效的。
        bool IsSymmetric() const noexcept;
        
    private:
        float m_UpFieldOfViewDegrees;
        float m_AspectRatio;
        float m_DirectionMin;
        float m_DirectionMax;
        bool m_Symmetric;
    };
}

#endif // RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
