///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:16)

#ifndef MATHEMATICS_MESHES_MESH_SMOOTHER_H
#define MATHEMATICS_MESHES_MESH_SMOOTHER_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    template <typename Real>
    class MeshSmoother
    {
    public:
        using ClassType = MeshSmoother<Real>;

    public:
        MeshSmoother(int numVertices, const std::vector<Vector3<Real>>& vertices, int numTriangles, const std::vector<int>& indices);

        MeshSmoother() noexcept;

        virtual ~MeshSmoother() noexcept = default;
        MeshSmoother(const MeshSmoother& rhs) = default;
        MeshSmoother& operator=(const MeshSmoother& rhs) = default;
        MeshSmoother(MeshSmoother&& rhs) noexcept = default;
        MeshSmoother& operator=(MeshSmoother&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        void Create(int newNumVertices, const std::vector<Vector3<Real>>& newVertices, int newNumTriangles, const std::vector<int>& newIndices);
        void Destroy() noexcept;

        NODISCARD int GetNumVertices() const noexcept;
        NODISCARD std::vector<Vector3<Real>> GetVertices() const;
        NODISCARD int GetNumTriangles() const noexcept;
        NODISCARD std::vector<int> GetIndices() const;

        NODISCARD std::vector<Vector3<Real>> GetNormals() const;
        NODISCARD std::vector<Vector3<Real>> GetMeans() const;

        void Update(Real t = Math<Real>::GetValue(0));

    protected:
        NODISCARD virtual bool VertexInfluenced(MAYBE_UNUSED int i, MAYBE_UNUSED Real t);
        NODISCARD virtual Real GetTangentWeight(MAYBE_UNUSED int i, MAYBE_UNUSED Real t);
        NODISCARD virtual Real GetNormalWeight(MAYBE_UNUSED int i, MAYBE_UNUSED Real t);

    private:
        int numVertices;
        std::vector<Vector3<Real>> vertices;
        int numTriangles;
        std::vector<int> indices;

        std::vector<Vector3<Real>> normals;
        std::vector<Vector3<Real>> means;
        std::vector<int> neighborCounts;
    };
}

#endif  // MATHEMATICS_MESHES_MESH_SMOOTHER_H
