///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:16)

#ifndef MATHEMATICS_MESHES_FWD_H
#define MATHEMATICS_MESHES_FWD_H

namespace Mathematics
{
    class EdgeKey;
    class TriangleKey;

    class BasicMesh;
    class BasicMeshEdge;
    class BasicMeshTriangle;
    class BasicMeshVertex;

    template <typename Real>
    class ConformalMap;

    class ETManifoldMesh;
    class ETNonmanifoldMesh;

    template <typename Real>
    class MeshCurvature;

    template <typename Real>
    class MeshSmoother;

    template <typename Point2>
    class PlanarGraph;

    class OrderedEdgeKey;
    class TetrahedronKey;

    class ETManifoldMesh;

    template <int N, typename Real>
    class UniqueVerticesTriangles;

    class UnorderedTriangleKey;
}

#endif  // MATHEMATICS_MESHES_FWD_H