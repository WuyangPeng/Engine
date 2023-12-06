///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:11)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_FAN_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_FAN_H

#include "Rendering/RenderingDll.h"

#include "Triangles.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TrianglesFan : public Triangles
    {
    public:
        using ClassType = TrianglesFan;
        using ParentType = Triangles;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        TrianglesFan(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, int indexSize);
        TrianglesFan(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(TrianglesFan);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    public:
        // 索引缓冲区数据的解释。
        NODISCARD int GetNumTriangles() const noexcept override;
        NODISCARD TriangleIndex GetTriangle(int index) const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD ControllerSharedPtr Clone() const override;

    private:
        void InitIndexBuffer(IndexBuffer& indexBuffer);
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(TrianglesFan);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TrianglesFan);
}

#endif  // RENDERING_SCENE_GRAPH_TRIANGLES_FAN_H
