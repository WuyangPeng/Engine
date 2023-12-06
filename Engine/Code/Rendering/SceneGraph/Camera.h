/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/27 11:16)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_H
#define RENDERING_SCENE_GRAPH_CAMERA_H

#include "Rendering/RenderingDll.h"

#include "PickLine.h"
#include "ViewVolume.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Camera, CameraImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Camera : public ViewVolume
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Camera);
        using ParentType = ViewVolume;

        using CameraSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static CameraSharedPtr Create(bool isPerspective, DepthType depthType, float epsilon);

        Camera(bool isPerspective, DepthType depthType, float epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Camera);

        void SetPreViewMatrix(const Matrix& preViewMatrix);
        NODISCARD Matrix GetPreViewMatrix() const noexcept;
        NODISCARD bool PreViewIsIdentity() const noexcept;

        void SetPostProjectionMatrix(const Matrix& postProjMatrix);
        NODISCARD Matrix GetPostProjectionMatrix() const noexcept;
        NODISCARD bool PostProjectionIsIdentity() const noexcept;

        /// 支持视差投影。指定一个凸四边形视口。
        /// 这些点必须在相机坐标中，并且从眼点观察时按逆时针顺序排列。
        /// 四边形的平面是视图平面，其"extrude"值为1。
        /// nearExtrude值在(0,无穷大)中；这指定了从视点到包含立方体视图体积近面的视图平面的分数。
        /// farExtrude值为(nearExtrude,无穷大)；这指定了放置立方体视图体积的远面的视点的分数。
        void SetProjectionMatrix(const APoint& p00, const APoint& p10, const APoint& p11, const APoint& p01, float nearExtrude, float farExtrude);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        /// 根据左手屏幕坐标(x,y)、视口和摄影机计算拾取线。
        /// 输出“原点”是相机位置，“方向”是单位长度矢量，均为世界坐标。
        /// 如果(x,y)在视口中，则返回值为true。
        NODISCARD PickLine GetPickLine(int viewX, int viewY, int viewWidth, int viewHigh, int x, int y) const;

    protected:
        void UpdateProjectionViewMatrix() noexcept override;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Camera);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Camera);
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_H
