///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/23 10:49)

#ifndef MATHEMATICS_MESHES_MESH_CURVATURE_H
#define MATHEMATICS_MESHES_MESH_CURVATURE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix2.h"
#include "Mathematics/Algebra/Matrix3.h"

namespace Mathematics
{
    template <typename Real>
    class MeshCurvature
    {
    public:
        using ClassType = MeshCurvature<Real>;

    public:
        MeshCurvature(int numVertices, const std::vector<Vector3<Real>>& vertices, int numTriangles, const std::vector<int>& indices);

        virtual ~MeshCurvature() noexcept = default;
        MeshCurvature(const MeshCurvature& rhs) = default;
        MeshCurvature& operator=(const MeshCurvature& rhs) = default;
        MeshCurvature(MeshCurvature&& rhs) noexcept = default;
        MeshCurvature& operator=(MeshCurvature&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD int GetNumVertices() const noexcept;
        NODISCARD std::vector<Vector3<Real>> GetVertices() const;
        NODISCARD int GetNumTriangles() const noexcept;
        NODISCARD std::vector<int> GetIndices() const;

        NODISCARD std::vector<Vector3<Real>> GetNormals() const;
        NODISCARD std::vector<Real> GetMinCurvatures() const;
        NODISCARD std::vector<Real> GetMaxCurvatures() const;
        NODISCARD std::vector<Vector3<Real>> GetMinDirections() const;
        NODISCARD std::vector<Vector3<Real>> GetMaxDirections() const;

    private:
        int numVertices;
        std::vector<Vector3<Real>> vertices;
        int numTriangles;
        std::vector<int> indices;

        std::vector<Vector3<Real>> normals;
        std::vector<Real> minCurvatures;
        std::vector<Real> maxCurvatures;
        std::vector<Vector3<Real>> minDirections;
        std::vector<Vector3<Real>> maxDirections;
    };
}

#endif  // MATHEMATICS_MESHES_MESH_CURVATURE_H
