///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/03 17:26)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_STRIP_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_STRIP_H

#include "Rendering/RenderingDll.h"

#include "Triangles.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TrianglesStrip : public Triangles
    {
    public:
        using ClassType = TrianglesStrip;
        using ParentType = Triangles;
        using ClassShareType = CoreTools::CopyUnsharedClasses;

    public:
        TrianglesStrip(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, int indexSize);
        TrianglesStrip(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(TrianglesStrip);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    public:
        // 索引缓冲区数据的解释。
        NODISCARD int GetNumTriangles() const noexcept override;
        NODISCARD TriangleIndex GetTriangle(int index) const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD ControllerInterfaceSharedPtr Clone() const override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(TrianglesStrip);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TrianglesStrip);
}

#endif  // RENDERING_SCENE_GRAPH_TRIANGLES_STRIP_H
