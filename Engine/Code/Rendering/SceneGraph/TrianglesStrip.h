///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/03 17:26)

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
        // �������������ݵĽ��͡�
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
