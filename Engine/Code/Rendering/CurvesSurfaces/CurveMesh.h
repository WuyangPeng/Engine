///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/16 13:58)

#ifndef RENDERING_CURVES_SURFACES_CURVE_MESH_H
#define RENDERING_CURVES_SURFACES_CURVE_MESH_H

#include "Rendering/RenderingDll.h"

#include "CurveSegment.h"
#include "FloatArray.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Rendering/SceneGraph/Polysegment.h"

namespace Rendering
{
    class CurveMesh : public Polysegment
    {
    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(CurveMesh);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

    public:
        using ClassType = CurveMesh;
        using ParentType = Polysegment;

    public:
        CurveMesh(const VertexFormatSharedPtr& vformat, const VertexBufferSharedPtr& vbuffer, const std::vector<CoreTools::ObjectAssociated<CurveSegment>>& segments, const FloatArraySharedPtr& params, bool allowDynamicChange);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetLevel(int aLevel);
        NODISCARD int GetLevel() const noexcept;

        void OnDynamicChange();

        void Lock() noexcept;
        NODISCARD bool IsLocked() const noexcept;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        class Edge
        {
        public:
            Edge() noexcept;

            CurveSegmentSharedPtr segment;

            std::array<int, 2> v;

            std::array<float, 2> param;
        };

        NODISCARD std::vector<Edge> Allocate(int& numTotalVertices, int& numTotalEdges);
        void Subdivide(int& numVertices, int& numEdges, std::vector<Edge>& edges);

        class CurveInfo
        {
        public:
            CurveInfo() noexcept;

            CoreTools::ObjectAssociated<CurveSegment> segment;
            float param;
        };

        void InitializeCurveInfo();

    private:
        CoreTools::ObjectAssociated<VertexBuffer> origVBuffer;
        CoreTools::ObjectAssociated<FloatArray> origParams;
        std::vector<CoreTools::ObjectAssociated<CurveSegment>> segments;
        int numFullVertices;
        int numSegments;
        int level;

        bool allowDynamicChange;
        std::vector<CurveInfo> cInfo;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(CurveMesh);
}

#endif  // RENDERING_CURVES_SURFACES_CURVE_MESH_H
