// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 19:11)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
#define RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H

#include "Rendering/RenderingDll.h"

#include "System/EnumOperator/EnumCastDetail.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"
#include "Rendering/SceneGraph/CameraFrustumData.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CameraFrustum
    {
    public:
		using ClassType = CameraFrustum;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
        
    public:
        explicit CameraFrustum (bool isPerspective);
        
		CLASS_INVARIANT_DECLARE;
  
        // 默认视图平截头体有一个90度的视野,
        // 宽高比为1，近值为1，远值为10000。
        bool IsPerspective () const;
 
        // 设置视图平截头体。区间[rmin,rmax] 测量在右方向R。
        // 这些都是在平截头体的“left”和“right”值。
        // 区间[umin,umax] 测量在上方向U。
        // 这些是“bottom”和“top”值。
        // 区间[dmin,dmax] 测量视图方向D。
        // 这些是“near”和“far”值。
        void SetFrustum (float directionMin, float directionMax,float upMin, float upMax,float rightMin, float rightMax);

        // 同时设置视图平截头体所有的值。
        // 输入数组必须按dmin, dmax, umin, umax, rmin, rmax的顺序。
        void SetFrustum (const float* frustum);
 
        // 设置一个对称的视图平截头体(umin = -umax, rmin = -rmax)
        // 使用一个视图字段在up方向和一个宽高比。
        // 这个调用相当于OpenGL的gluPerspective。
        // 因此，这个函数必须指定视图的度数，在区间(0,180)
        void SetFrustum (float upFieldOfViewDegrees, float aspectRatio,float directionMin,float directionMax);

        // 同时获得所有视图平截头体的值。
        const float* GetFrustum () const;
 
        // 得到一个对称视图平截头体的参数。
        // 返回值是true当且仅当平截头体是对称的，
        // 只有在这种情况下，输出参数才是有效的。
        const CameraFrustumData GetFrustumData () const;
 
        // 获得单一视图平截头体的值。
        float GetDirectionMin () const;
        float GetDirectionMax () const;
        float GetUpMin () const;
        float GetUpMax () const;
        float GetRightMin () const;
        float GetRightMax () const;
        
        void Load (BufferSource& source);
		void Save (BufferTarget& target) const;
		int GetStreamingSize () const;
        
    private:
        // 视图平截头体,存储在顺序为min (near), dmax (far),
        // umin (bottom), umax (top), rmin (left), 和 rmax (right).
        float m_Frustum[System::EnumCastUnderlying(ViewFrustum::Quantity)];
 
        // 这个成员是“true”则是透视相机，是“false”则是正交相机。
        bool m_IsPerspective;
    };
}

#endif // RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
