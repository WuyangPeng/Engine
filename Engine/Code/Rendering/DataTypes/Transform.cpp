///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:57)

#include "Rendering/RenderingExport.h"

#include "TransformDetail.h"

#ifdef RENDERING_TEMPLATE_TEST

namespace Rendering
{
    template class Transform<float>;
    template class Transform<double>;
}

using std::cout;

namespace Rendering
{
    void TransformTemplateTest()
    {
        TransformF transform1{};
        const TransformF transform2{ transform1 };
        transform1.MakeIdentity();
        transform1.MakeUnitScale();

        MAYBE_UNUSED const auto isIdentity = transform1.IsIdentity();
        MAYBE_UNUSED const auto isRotationOrScaleMatrix = transform1.IsRotationOrScaleMatrix();
        MAYBE_UNUSED const auto isUniformScale = transform1.IsUniformScale();

        const auto rotate = transform1.GetRotate();
        const auto matrix = transform1.GetMatrix();
        const auto translate = transform1.GetTranslate();
        const auto scale = transform1.GetScale();
        const auto uniformScale = transform1.GetUniformScale();

        transform1.SetRotate(rotate);
        transform1.SetMatrix(matrix);
        transform1.SetTranslate(translate);
        transform1.SetScale(scale);
        transform1.SetUniformScale(uniformScale);

        MAYBE_UNUSED const auto norm = transform1.GetNorm();
        MAYBE_UNUSED const auto aPoint = transform1 * Mathematics::APointF{};
        MAYBE_UNUSED const auto aVector = transform1 * Mathematics::AVectorF::GetUnitX();
        transform1 *= transform2;
        MAYBE_UNUSED const auto homogeneousMatrix = transform1.GetHomogeneousMatrix();
        MAYBE_UNUSED const auto inverseMatrix = transform1.GetInverseMatrix();
        MAYBE_UNUSED const auto inverseTransform = transform1.GetInverseTransform();
        MAYBE_UNUSED const auto streamingSize = transform1.GetStreamingSize();

        MAYBE_UNUSED const auto transform3 = transform1 * transform2;
        MAYBE_UNUSED const auto approximate = Approximate(transform1, transform2);

        cout << transform1;
    }
}

#else  // !RENDERING_TEMPLATE_TEST

namespace Rendering
{
    void TransformTemplateTest() noexcept
    {
    }
}

#endif  // RENDERING_TEMPLATE_TEST
