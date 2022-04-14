///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 16:46)

#ifndef RENDERING_SCENE_GRAPH_PROJECTOR_H
#define RENDERING_SCENE_GRAPH_PROJECTOR_H

#include "Camera.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Projector : public Camera
    {
    public:
        using ClassType = Projector;
        using ParentType = Camera;
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        using ProjectorSharedPtr = std::shared_ptr<ClassType>;
        using ConstProjectorSharedPtr = std::shared_ptr<ClassType>;
        using Matrix = Mathematics::MatrixF;

    public:
        // 这类和Camera类的唯一区别是,你可以显式地指定深度的类型。
        // Camera类被迫使用默认的深度类型(即符合当前启用图形API)。
        Projector(DepthType depthType, bool isPerspective = true, float epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Projector);

        // 索引0矩阵映射 x' = (1 + x) / 2 和 y' = (1 - y) / 2。
        // 索引1矩阵映射 x' = (1 + x) / 2 和 y' = (1 + y) / 2。
        NODISCARD static Matrix GetBiasScaleMatrix(int index);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(Projector);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Projector);
}

#endif  // RENDERING_SCENE_GRAPH_PROJECTOR_H
