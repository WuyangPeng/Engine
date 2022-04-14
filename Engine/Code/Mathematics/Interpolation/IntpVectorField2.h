///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/21 21:11)

#ifndef MATHEMATICS_INTERPOLATION_INTP_VECTOR_FIELD2_H
#define MATHEMATICS_INTERPOLATION_INTP_VECTOR_FIELD2_H

#include "Mathematics/MathematicsDll.h"

#include "IntpQdrNonuniform2.h"

namespace Mathematics
{
    template <typename Real>
    class IntpVectorField2
    {
    public:
        using ClassType = IntpVectorField2<Real>;

    public:
        IntpVectorField2(const std::vector<Vector2<Real>>& domain, const std::vector<Vector2<Real>>& range, QueryType queryType);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Evaluate(const Vector2<Real>& input, Vector2<Real>& output);

    private:
        std::shared_ptr<Delaunay2<Real>> dt;
        std::shared_ptr<IntpQdrNonuniform2<Real>> xInterp;
        std::shared_ptr<IntpQdrNonuniform2<Real>> yInterp;
    };
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_VECTOR_FIELD2_H
