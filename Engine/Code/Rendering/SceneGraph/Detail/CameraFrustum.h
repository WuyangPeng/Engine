///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:06)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
#define RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/SceneGraph/CameraFrustumData.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CameraFrustum
    {
    public:
        using ClassType = CameraFrustum;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit CameraFrustum(bool isPerspective) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 默认视图平截头体有一个90度的视野,
        // 宽高比为1，近值为1，远值为10000。
        NODISCARD bool IsPerspective() const noexcept;

        // 设置视图平截头体。区间[rmin,rmax] 测量在右方向R。
        // 这些都是在平截头体的“left”和“right”值。
        // 区间[umin,umax] 测量在上方向U。
        // 这些是“bottom”和“top”值。
        // 区间[dmin,dmax] 测量视图方向D。
        // 这些是“near”和“far”值。
        void SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax) noexcept;

        // 同时设置视图平截头体所有的值。
        // 输入数组必须按dmin, dmax, umin, umax, rmin, rmax的顺序。
        void SetFrustum(const float* aFrustum) noexcept;

        // 设置一个对称的视图平截头体(umin = -umax, rmin = -rmax)
        // 使用一个视图字段在up方向和一个宽高比。
        // 这个调用相当于OpenGL的gluPerspective。
        // 因此，这个函数必须指定视图的度数，在区间(0,180)
        void SetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax) noexcept;

        // 同时获得所有视图平截头体的值。
        NODISCARD const float* GetFrustum() const noexcept;

        // 得到一个对称视图平截头体的参数。
        // 返回值是true当且仅当平截头体是对称的，
        // 只有在这种情况下，输出参数才是有效的。
        NODISCARD CameraFrustumData GetFrustumData() const noexcept;

        // 获得单一视图平截头体的值。
        NODISCARD float GetDirectionMin() const noexcept;
        NODISCARD float GetDirectionMax() const noexcept;
        NODISCARD float GetUpMin() const noexcept;
        NODISCARD float GetUpMax() const noexcept;
        NODISCARD float GetRightMin() const noexcept;
        NODISCARD float GetRightMax() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        // 视图平截头体,存储在顺序为min (near), dmax (far),
        // umin (bottom), umax (top), rmin (left), 和 rmax (right).
        std::array<float, System::EnumCastUnderlying(ViewFrustum::Quantity)> frustum;

        // 这个成员是“true”则是透视相机，是“false”则是正交相机。
        bool isPerspective;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
