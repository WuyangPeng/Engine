///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/22 16:59)

#ifndef MATHEMATICS_MESHES_CONFORMAL_MAP_H
#define MATHEMATICS_MESHES_CONFORMAL_MAP_H

#include "Mathematics/MathematicsDll.h"

#include "BasicMesh.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"
#include "Mathematics/NumericalAnalysis/PolynomialRoots.h"

namespace Mathematics
{
    template <typename Real>
    class ConformalMap
    {
    public:
        using ClassType = ConformalMap<Real>;

    public:
        ConformalMap(int numPoints, const std::vector<Vector3<Real>>& points, int numTriangles, const std::vector<int>& indices, int punctureTriangle = 0);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::vector<Vector2<Real>> GetPlaneCoordinates() const;
        NODISCARD const Vector2<Real>& GetPlaneMin() const noexcept;
        NODISCARD const Vector2<Real>& GetPlaneMax() const noexcept;

        NODISCARD std::vector<Vector3<Real>> GetSphereCoordinates() const;
        NODISCARD Real GetSphereRadius() const noexcept;

    private:
        NODISCARD Real ComputeRadius(const Vector2<Real>& v0, const Vector2<Real>& v1, const Vector2<Real>& v2, Real areaFraction) const;

    private:
        std::vector<Vector2<Real>> planes;
        Vector2<Real> planeMin;
        Vector2<Real> planeMax;

        std::vector<Vector3<Real>> spheres;
        Real radius;
    };
}

#endif  // MATHEMATICS_MESHES_CONFORMAL_MAP_H
