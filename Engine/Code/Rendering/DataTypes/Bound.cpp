//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/08/30 14:22)

#include "Rendering/RenderingExport.h"

#ifdef RENDERING_EXPORT_TEMPLATE

    #ifndef RENDERING_INCLUDED_BOUND_ACHIEVE
        #define RENDERING_INCLUDED_BOUND_ACHIEVE
    #endif  // RENDERING_INCLUDED_BOUND_ACHIEVE

#endif  // RENDERING_EXPORT_TEMPLATE

#include "BoundDetail.h"

#ifdef RENDERING_EXPORT_TEMPLATE

namespace Rendering
{
    template RENDERING_TEMPLATE_DEFAULT_DECLARE class Bound<float>;
    template RENDERING_TEMPLATE_DEFAULT_DECLARE class Bound<double>;
}

#endif  // RENDERING_EXPORT_TEMPLATE

#ifdef RENDERING_TEMPLATE_TEST

using std::vector;

namespace Rendering
{
    void BoundTemplateTest()
    {
        FloatBound bound1{};
        FloatBound bound2{ Mathematics::Float::g_Origin, 1.0f };

        bound1.SetCenter(Mathematics::Float::g_Origin);
        bound2.SetRadius(2.0f);
        [[maybe_unused]] const auto& center = bound1.GetCenter();
        [[maybe_unused]] const auto radius = bound2.GetRadius();

        [[maybe_unused]] const auto streamingSize = bound1.GetStreamingSize();
        [[maybe_unused]] const auto numericalValueSymbol = bound2.WhichSide(Mathematics::FloatPlane{});
        bound1.GrowToContain(bound2);
        auto bound3 = bound1.TransformBy(FloatTransform{});

        constexpr auto numElements = 100;
        const auto step = boost::numeric_cast<int>(Mathematics::FloatAPoint::sm_APointSize * sizeof(float));
        const auto dataSize = numElements * step;
        vector<Mathematics::FloatAPoint> aPoint(numElements);
        vector<Mathematics::Vector3Df> vector3D(numElements);
        vector<char> data(dataSize);
        bound1.ComputeFromData(aPoint);
        bound2.ComputeFromData(vector3D);
        bound3.ComputeFromData(numElements, step, FloatBound::SpanConstIterator{ data.begin(), data.end(), data.begin() });

        auto intersection = bound2.TestIntersection(Mathematics::FloatAPoint{}, Mathematics::FloatAVector{}, 0.0f, 1.0f);
        intersection = TestIntersection(bound1, bound2);
        intersection = TestIntersection(bound1, Mathematics::Float::g_UnitX, bound2, Mathematics::Float::g_UnitY, 1.0f);
        [[maybe_unused]] const auto approximate = TestIntersection(bound1, bound2);
    }
}

#else  // !RENDERING_TEMPLATE_TEST

namespace Rendering
{
    void BoundTemplateTest() noexcept
    {
    }
}

#endif  // RENDERING_TEMPLATE_TEST
