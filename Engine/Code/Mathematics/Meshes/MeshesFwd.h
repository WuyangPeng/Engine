///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/22 12:59)

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