///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:15)

#ifndef MATHEMATICS_MESHES_MESH_SMOOTHER_DETAIL_H
#define MATHEMATICS_MESHES_MESH_SMOOTHER_DETAIL_H

#include "MeshSmoother.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::MeshSmoother<Real>::MeshSmoother() noexcept
    : numVertices{},
      vertices{},
      numTriangles{},
      indices{},
      normals{},
      means{},
      neighborCounts{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::MeshSmoother<Real>::MeshSmoother(int numVertices, const std::vector<Vector3<Real>>& vertices, int numTriangles, const std::vector<int>& indices)
    : numVertices{},
      vertices{},
      numTriangles{},
      indices{},
      normals{},
      means{},
      neighborCounts{}
{
    Create(numVertices, vertices, numTriangles, indices);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::MeshSmoother<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::MeshSmoother<Real>::Create(int newNumVertices, const std::vector<Vector3<Real>>& newVertices, int newNumTriangles, const std::vector<int>& newIndices)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Destroy();

    numVertices = newNumVertices;
    vertices = newVertices;
    numTriangles = newNumTriangles;
    indices = newIndices;

    normals.resize(numVertices);
    means.resize(numVertices);
    neighborCounts.resize(numVertices);

    auto index = 0;
    for (auto i = 0; i < numTriangles; ++i)
    {
        neighborCounts.at(indices.at(index++)) += 2;
        neighborCounts.at(indices.at(index++)) += 2;
        neighborCounts.at(indices.at(index++)) += 2;
    }
}

template <typename Real>
void Mathematics::MeshSmoother<Real>::Destroy() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    numVertices = 0;
    vertices.clear();
    numTriangles = 0;
    indices.clear();

    normals.clear();
    means.clear();
    neighborCounts.clear();
}

template <typename Real>
void Mathematics::MeshSmoother<Real>::Update(Real t)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    normals.clear();
    means.clear();

    auto index = 0;

    for (auto i = 0; i < numTriangles; ++i)
    {
        auto v0 = indices.at(index++);
        auto v1 = indices.at(index++);
        auto v2 = indices.at(index++);

        auto& vertix0 = vertices.at(v0);
        auto& vertix1 = vertices.at(v1);
        auto& vertix2 = vertices.at(v2);

        auto edge1 = vertix1 - vertix0;
        auto edge2 = vertix2 - vertix0;
        const auto normal = Vector3Tools<Real>::CrossProduct(edge1, edge2);

        normals.at(v0) += normal;
        normals.at(v1) += normal;
        normals.at(v2) += normal;

        means.at(v0) += vertix1 + vertix2;
        means.at(v1) += vertix2 + vertix0;
        means.at(v2) += vertix0 + vertix1;
    }

    for (auto i = 0; i < numVertices; ++i)
    {
        normals.at(i).Normalize();
        means.at(i) /= Math<Real>::GetValue(neighborCounts.at(i));
    }

    for (auto i = 0; i < numVertices; ++i)
    {
        if (VertexInfluenced(i, t))
        {
            auto localDiff = means.at(i) - vertices.at(i);
            auto surfaceNormal = Vector3Tools<Real>::DotProduct(localDiff, normals.at(i)) * normals.at(i);
            auto tangent = localDiff - surfaceNormal;

            auto tanWeight = GetTangentWeight(i, t);
            auto norWeight = GetNormalWeight(i, t);
            vertices.at(i) += tanWeight * tangent + norWeight * normals.at(i);
        }
    }
}

template <typename Real>
bool Mathematics::MeshSmoother<Real>::VertexInfluenced(MAYBE_UNUSED int i, MAYBE_UNUSED Real t)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

template <typename Real>
Real Mathematics::MeshSmoother<Real>::GetTangentWeight(MAYBE_UNUSED int i, MAYBE_UNUSED Real t)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return Math<Real>::GetRational(1, 2);
}

template <typename Real>
Real Mathematics::MeshSmoother<Real>::GetNormalWeight(MAYBE_UNUSED int i, MAYBE_UNUSED Real t)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return Math<Real>::GetValue(0);
}

template <typename Real>
int Mathematics::MeshSmoother<Real>::GetNumVertices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numVertices;
}

template <typename Real>
std::vector<Mathematics::Vector3<Real>> Mathematics::MeshSmoother<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertices;
}

template <typename Real>
int Mathematics::MeshSmoother<Real>::GetNumTriangles() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numTriangles;
}

template <typename Real>
std::vector<int> Mathematics::MeshSmoother<Real>::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return indices;
}

template <typename Real>
std::vector<Mathematics::Vector3<Real>> Mathematics::MeshSmoother<Real>::GetNormals() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return normals;
}

template <typename Real>
std::vector<Mathematics::Vector3<Real>> Mathematics::MeshSmoother<Real>::GetMeans() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return means;
}

#endif  // MATHEMATICS_MESHES_MESH_SMOOTHER_DETAIL_H