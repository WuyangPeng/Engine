//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/09/06 10:46)

#include "Rendering/RenderingExport.h"

#ifdef RENDERING_EXPORT_TEMPLATE

    #ifndef RENDERING_INCLUDED_TRANSFORM_ACHIEVE
        #define RENDERING_INCLUDED_TRANSFORM_ACHIEVE
    #endif  // RENDERING_INCLUDED_TRANSFORM_ACHIEVE

#endif  // RENDERING_EXPORT_TEMPLATE

#include "TransformDetail.h"

#ifdef RENDERING_EXPORT_TEMPLATE

namespace Rendering
{
    template RENDERING_TEMPLATE_DEFAULT_DECLARE class Transform<float>;
    template RENDERING_TEMPLATE_DEFAULT_DECLARE class Transform<double>;
}

#endif  // RENDERING_EXPORT_TEMPLATE

#ifdef RENDERING_TEMPLATE_TEST

using std::cout;

namespace Rendering
{
    void TransformTemplateTest()
    {
        FloatTransform transform1{};
        FloatTransform transform2{ transform1 };
        transform1.MakeIdentity();
        transform1.MakeUnitScale();

        [[maybe_unused]] const auto isIdentity = transform1.IsIdentity();
        [[maybe_unused]] const auto isRotationOrScaleMatrix = transform1.IsRotationOrScaleMatrix();
        [[maybe_unused]] const auto isUniformScale = transform1.IsUniformScale();

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

        [[maybe_unused]] const auto norm = transform1.GetNorm();
        [[maybe_unused]] const auto aPoint = transform1 * Mathematics::Float::g_Origin;
        [[maybe_unused]] const auto aVector = transform1 * Mathematics::Float::g_UnitX;
        transform1 *= transform2;
        [[maybe_unused]] const auto homogeneousMatrix = transform1.GetHomogeneousMatrix();
        [[maybe_unused]] const auto inverseMatrix = transform1.GetInverseMatrix();
        [[maybe_unused]] const auto inverseTransform = transform1.GetInverseTransform();
        [[maybe_unused]] const auto streamingSize = transform1.GetStreamingSize();

        [[maybe_unused]] const auto transform3 = transform1 * transform2;
        [[maybe_unused]] const auto approximate = Approximate(transform1, transform2);

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
