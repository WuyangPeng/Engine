// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/19 19:15)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_NODE_IMPL_H
#define RENDERING_SCENE_GRAPH_CAMERA_NODE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/SceneGraph/Camera.h"

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
    class ObjectRegister;
    class ObjectLink;
    class Object;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CameraNodeImpl
    {
    public:
        using ClassType = CameraNodeImpl;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;
        using Object = CoreTools::Object;

    public:
        // 节点的世界坐标使用相机的位置。
        // 节点的世界旋转矩阵使用相机的坐标轴。
        // 世界旋转矩阵的列0是相机的direction向量,
        // 世界旋转矩阵的列1是相机的up向量,
        // 世界旋转矩阵的列2是相机的right向量。

        // 节点的局部变换将设置为相机的当前坐标系统。
        //   local translation       = camera location
        //   local rotation column 0 = camera direction
        //   local rotation column 1 = camera up
        //   local rotation column 2 = camera right
        explicit CameraNodeImpl(const CameraSharedPtr& camera) noexcept;

        CLASS_INVARIANT_DECLARE;

        bool IsNullPtr() const noexcept;

        // 当你设置摄像机，节点的本地转换将设置为当前相机的当前坐标系统。
        // 节点的世界变换将被计算,
        // 和相机的坐标系使用节点的世界转换。
        void SetCamera(const CameraSharedPtr& camera) noexcept;
        const ConstCameraSharedPtr GetCamera() const noexcept;

        const FloatTransform GetLocalTransform() const;

        void SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        int GetStreamingSize() const noexcept;
        uint64_t Register(CoreTools::ObjectRegister& target) const;
        void Link(CoreTools::ObjectLink& source);

        CORE_TOOLS_NAMES_IMPL_DECLARE;

    private:
        CameraSharedPtr m_Camera;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_NODE_IMPL_H
