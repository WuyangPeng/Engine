///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:15)

#ifndef MATHEMATICS_MESHES_MESH_CURVATURE_DETAIL_H
#define MATHEMATICS_MESHES_MESH_CURVATURE_DETAIL_H

#include "MeshCurvature.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::MeshCurvature<Real>::MeshCurvature(int numVertices, const std::vector<Vector3<Real>>& vertices, int numTriangles, const std::vector<int>& indices)
    : numVertices{ numVertices },
      vertices{ vertices },
      numTriangles{ numTriangles },
      indices{ indices },
      normals(numVertices),
      minCurvatures(numVertices),
      maxCurvatures(numVertices),
      minDirections(numVertices),
      maxDirections(numVertices)
{
    auto index = 0;
    for (auto i = 0; i < numTriangles; ++i)
    {
        auto v0 = indices.at(index++);
        auto v1 = indices.at(index++);
        auto v2 = indices.at(index++);

        auto edge1 = vertices.at(v1) - vertices.at(v0);
        auto edge2 = vertices.at(v2) - vertices.at(v0);
        const auto normal = Vector3Tools<Real>::CrossProduct(edge1, edge2);

        normals.at(v0) += normal;
        normals.at(v1) += normal;
        normals.at(v2) += normal;
    }

    for (auto i = 0; i < numVertices; ++i)
    {
        normals.at(i).Normalize();
    }

    std::vector<Matrix3<Real>> dNormal(numVertices);
    std::vector<Matrix3<Real>> wwTrn(numVertices);
    std::vector<Matrix3<Real>> dwTrn(numVertices);
    std::vector<bool> dwTrnZero(numVertices);

    index = 0;
    for (auto i = 0; i < numTriangles; ++i)
    {
        std::array<int, 3> v{};
        v.at(0) = indices.at(index++);
        v.at(1) = indices.at(index++);
        v.at(2) = indices.at(index++);

        for (auto j = 0; j < 3; j++)
        {
            auto v0 = v.at(j);
            auto v1 = v.at((j + 1) % 3);
            auto v2 = v.at((j + 2) % 3);

            auto e = vertices.at(v1) - vertices.at(v0);
            auto w = e - (Vector3Tools<Real>::DotProduct(e, normals.at(v0))) * normals.at(v0);
            auto d = normals.at(v1) - normals.at(v0);
            for (auto row = 0; row < 3; ++row)
            {
                for (auto col = 0; col < 3; ++col)
                {
                    wwTrn.at(v0)[row][col] += w[row] * w[col];
                    dwTrn.at(v0)[row][col] += d[row] * w[col];
                }
            }

            e = vertices.at(v2) - vertices.at(v0);
            w = e - (Vector3Tools<Real>::DotProduct(e, normals.at(v0))) * normals.at(v0);
            d = normals.at(v2) - normals.at(v0);
            for (auto row = 0; row < 3; ++row)
            {
                for (auto col = 0; col < 3; ++col)
                {
                    wwTrn.at(v0)[row][col] += w[row] * w[col];
                    dwTrn.at(v0)[row][col] += d[row] * w[col];
                }
            }
        }
    }

    for (auto i = 0; i < numVertices; ++i)
    {
        for (auto row = 0; row < 3; ++row)
        {
            for (auto col = 0; col < 3; ++col)
            {
                wwTrn.at(i)[row][col] = Math<Real>::GetRational(1, 2) * wwTrn.at(i)[row][col] + normals.at(i)[row] * normals.at(i)[col];
                dwTrn.at(i)[row][col] *= Math<Real>::GetRational(1, 2);
            }
        }

        auto maxAbs = Math<Real>::GetValue(0);
        for (auto row = 0; row < 3; ++row)
        {
            for (auto col = 0; col < 3; ++col)
            {
                Real absEntry = Math<Real>::FAbs(dwTrn.at(i)[row][col]);
                if (absEntry > maxAbs)
                {
                    maxAbs = absEntry;
                }
            }
        }
        if (maxAbs < static_cast<Real>(1e-07))
        {
            dwTrnZero.at(i) = true;
        }

        dNormal.at(i) = dwTrn.at(i) * wwTrn.at(i).Inverse();
    }

    for (auto i = 0; i < numVertices; ++i)
    {
        const auto vector3OrthonormalBasis = Vector3Tools<Real>::GenerateComplementBasis(normals.at(i));
        const auto u = vector3OrthonormalBasis.GetUVector();
        const auto v = vector3OrthonormalBasis.GetVVector();

        if (dwTrnZero.at(i))
        {
            minCurvatures.at(i) = Math<Real>::GetValue(0);
            maxCurvatures.at(i) = Math<Real>::GetValue(0);
            minDirections.at(i) = u;
            maxDirections.at(i) = v;
            continue;
        }

        auto s01 = Vector3Tools<Real>::DotProduct(u, dNormal.at(i) * v);
        auto s10 = Vector3Tools<Real>::DotProduct(v, dNormal.at(i) * u);
        auto sAvr = Math<Real>::GetRational(1, 2) * (s01 + s10);
        Matrix2<Real> s{ Vector3Tools<Real>::DotProduct(u, dNormal.at(i) * u), sAvr, sAvr, Vector3Tools<Real>::DotProduct(v, dNormal.at(i) * v) };

        auto trace = s[0][0] + s[1][1];
        auto det = s[0][0] * s[1][1] - s[0][1] * s[1][0];
        auto discr = trace * trace - (Math<Real>::GetValue(4)) * det;
        auto rootDiscr = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
        minCurvatures.at(i) = Math<Real>::GetRational(1, 2) * (trace - rootDiscr);
        maxCurvatures.at(i) = Math<Real>::GetRational(1, 2) * (trace + rootDiscr);

        Vector2<Real> w0{ s[0][1], minCurvatures.at(i) - s[0][0] };
        Vector2<Real> w1{ minCurvatures.at(i) - s[1][1], s[1][0] };
        if (Vector2Tools<Real>::GetLengthSquared(w0) >= Vector2Tools<Real>::GetLengthSquared(w1))
        {
            w0.Normalize();
            minDirections.at(i) = w0.GetX() * u + w0.GetY() * v;
        }
        else
        {
            w1.Normalize();
            minDirections.at(i) = w1.GetX() * u + w1.GetY() * v;
        }

        w0 = Vector2<Real>(s[0][1], maxCurvatures.at(i) - s[0][0]);
        w1 = Vector2<Real>(maxCurvatures.at(i) - s[1][1], s[1][0]);
        if (Vector2Tools<Real>::GetLengthSquared(w0) >= Vector2Tools<Real>::GetLengthSquared(w1))
        {
            w0.Normalize();
            maxDirections.at(i) = w0.GetX() * u + w0.GetY() * v;
        }
        else
        {
            w1.Normalize();
            maxDirections.at(i) = w1.GetX() * u + w1.GetY() * v;
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::MeshCurvature<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::MeshCurvature<Real>::GetNumVertices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numVertices;
}

template <typename Real>
std::vector<Mathematics::Vector3<Real>> Mathematics::MeshCurvature<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertices;
}

template <typename Real>
int Mathematics::MeshCurvature<Real>::GetNumTriangles() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numTriangles;
}

template <typename Real>
std::vector<int> Mathematics::MeshCurvature<Real>::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return indices;
}

template <typename Real>
std::vector<Mathematics::Vector3<Real>> Mathematics::MeshCurvature<Real>::GetNormals() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return normals;
}

template <typename Real>
std::vector<Real> Mathematics::MeshCurvature<Real>::GetMinCurvatures() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minCurvatures;
}

template <typename Real>
std::vector<Real> Mathematics::MeshCurvature<Real>::GetMaxCurvatures() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxCurvatures;
}

template <typename Real>
std::vector<Mathematics::Vector3<Real>> Mathematics::MeshCurvature<Real>::GetMinDirections() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minDirections;
}

template <typename Real>
std::vector<Mathematics::Vector3<Real>> Mathematics::MeshCurvature<Real>::GetMaxDirections() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxDirections;
}

#endif  // MATHEMATICS_MESHES_MESH_CURVATURE_DETAIL_H