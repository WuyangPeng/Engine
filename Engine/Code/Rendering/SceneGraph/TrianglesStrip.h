// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/22 15:06)

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
        int GetNumTriangles() const noexcept override;
        const TriangleIndex GetTriangle(int index) const override;
        ObjectInterfaceSharedPtr CloneObject() const override;
        ControllerInterfaceSharedPtr Clone() const override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(TrianglesStrip);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE(TrianglesStrip);
}

#endif  // RENDERING_SCENE_GRAPH_TRIANGLES_STRIP_H
