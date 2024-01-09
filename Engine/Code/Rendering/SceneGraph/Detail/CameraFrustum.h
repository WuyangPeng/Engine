/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:31)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
#define RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/SceneGraph/CameraFrustumData.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"

#include <array>

namespace Rendering
{
    /// 默认的透视视锥体具有90度的视野、1.0的宽高比、近值1和远值10000。
    /// 默认正交视图截头体的(r,u,d)为[-1,1]^2 x [0,1]。
    class RENDERING_HIDDEN_DECLARE CameraFrustum
    {
    public:
        using ClassType = CameraFrustum;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

        static constexpr auto quantity = System::EnumCastUnderlying(ViewFrustum::Quantity);
        using Container = std::array<float, quantity>;

    public:
        CameraFrustum() noexcept;
        CameraFrustum(bool isPerspective, float epsilon);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsPerspective() const noexcept;

        /// 设置视图平截头体。区间[rMin,rMax] 测量在右方向R。
        /// 这些都是在平截头体的“left”和“right”值。
        /// 区间[uMin,uMax] 测量在上方向U。
        /// 这些是“bottom”和“top”值。
        /// 区间[dMin,dMax] 测量视图方向D。
        /// 这些是“near”和“far”值。
        void SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax);

        /// 同时设置视图平截头体所有的值。
        /// 输入数组必须按dMin, dMax, uMin, uMax, rMin, rMax的顺序。
        void SetFrustum(const Container& aFrustum) noexcept;

        /// 设置一个对称的视图平截头体(uMin = -uMax, rMin = -rMax)
        /// 使用一个视图字段在up方向和一个宽高比。
        /// 这个调用相当于OpenGL的gluPerspective。
        /// 因此，这个函数必须指定视图的度数，在区间(0,180)
        void SetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax);

        /// 同时获得所有视图平截头体的值。
        NODISCARD Container GetFrustum() const noexcept;

        /// 得到一个对称视图平截头体的参数。
        /// 返回的CameraFrustumData调用IsSymmetric是true当且仅当平截头体是对称的，
        /// 只有在这种情况下，返回值才是有效的。
        NODISCARD CameraFrustumData GetSymmetricFrustum() const;

        /// 获得单一视图平截头体的值。
        NODISCARD float GetDirectionMin() const;
        NODISCARD float GetDirectionMax() const;
        NODISCARD float GetUpMin() const;
        NODISCARD float GetUpMax() const;
        NODISCARD float GetRightMin() const;
        NODISCARD float GetRightMax() const;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        NODISCARD float& GetFrustum(ViewFrustum viewFrustum);
        NODISCARD float GetFrustum(ViewFrustum viewFrustum) const;

    private:
        /// 视图平截头体,存储在顺序为dMin (near), dMax (far),uMin (bottom), uMax (top), rMin (left), 和 rMax (right)的顺序存储。
        Container frustum;

        /// 这个成员是“true”则是透视相机，是“false”则是正交相机。
        bool isPerspective;

        float epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
