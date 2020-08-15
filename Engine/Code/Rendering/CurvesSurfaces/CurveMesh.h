// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/25 15:53)

#ifndef RENDERING_CURVES_SURFACES_CURVE_MESH_H
#define RENDERING_CURVES_SURFACES_CURVE_MESH_H

#include "Rendering/RenderingDll.h"

#include "CurveSegment.h"
#include "FloatArray.h"
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
        using ParentType = Object;

    public:
        // Construction and destruction.  The input 'vbuffer' has N >= 2 vertices
        // which are assumed to be ordered to form a continuous curve of N-1
        // curve segments.  The curve segments are stored in 'segments', an
        // array with N-1 elements.  CurveMesh assumes responsibility for deleting
        // this array, so it must be dynamically allocated.  The array 'params'
        // stores the parameter values for the curve segment endpoints.  This
        // array must have 2*(N-1) values.  Curve segment P[i] has domain
        // [params[2*i],params[2*i+1]].  Continuity requires that
        // P[i](params[2*i+1]) = P[i+1](params[2*(i+1)]).  The polysegment
        // produced by the subdivision is flagged as open.  If you want a closed
        // polysegment, you should make certain that the first endpoint of
        // P[0] matches the last endpoint of P[N-1].
        //
        // The parameter 'allowDynamicChange' should be set to 'true' when you
        // plan to dynamically modify the curve segments.  For example, you might
        // modify the control points in a Bezier curve segment.
        CurveMesh(VertexFormatSmartPointer vformat, VertexBufferSmartPointer vbuffer, CurveSegmentSmartPointer* segments, FloatArray* params, bool allowDynamicChange);

        ~CurveMesh();
        CurveMesh(const CurveMesh&) = default;
        CurveMesh& operator=(const CurveMesh&) = default;
        CurveMesh(CurveMesh&&) = default;
        CurveMesh& operator=(CurveMesh&&) = default;
        // Level of subdivision.  The 'level' value must be nonnegative.
        void SetLevel(int level);
        int GetLevel() const noexcept;

        // Call this function when one or more of your curve segments has
        // dynamically changed.
        void OnDynamicChange();

        // Free up all memory used by the object, other than the Polysegment data.
        // The intent is that the curve mesh is in its final form.  Once this
        // function is called, SetLevel is ignored.
        void Lock()  ;
        bool IsLocked() const noexcept;

    protected:
        VertexBufferSmartPointer mOrigVBuffer;
        FloatArraySmartPointer mOrigParams;
        CurveSegmentSmartPointer* mSegments;
        int mNumFullVertices, mNumSegments, mLevel;

    private:
        // Support for subdivision of the mesh.
        class Edge
        {
        public:
            Edge() noexcept;

            // Curve for subdivision evaluations.
            CurveSegmentSmartPointer Segment;

            // Indices for the vertices.
            int V[2];

            // Curve parameter values for the endpoints.
            float Param[2];
        };

        void Allocate(int& numTotalVertices, int& numTotalEdges, Edge*& edges);
        void Subdivide(int& numVertices, int& numEdges, Edge* edges);

        // Support for dynamic changes in the curve segments.
        class CurveInfo
        {
        public:
            friend class Memory;
            CurveInfo() noexcept;

            CurveSegmentSmartPointer Segment;
            float Param;
        };

        void InitializeCurveInfo() noexcept;

        bool mAllowDynamicChange;
        CurveInfo* mCInfo;
    };
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(CurveMesh);
    CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, CurveMesh);
#include STSTEM_WARNING_POP
}

#endif  // RENDERING_CURVES_SURFACES_CURVE_MESH_H
