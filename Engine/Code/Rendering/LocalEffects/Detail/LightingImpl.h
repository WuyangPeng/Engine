/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 20:30)

#ifndef RENDERING_SCENE_GRAPH_LIGHTINT_IMPL_H
#define RENDERING_SCENE_GRAPH_LIGHTINT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Rendering/DataTypes/Colour.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE LightingImpl
    {
    public:
        using ClassType = LightingImpl;

        using ColourType = Colour<float>;
        using Math = Mathematics::Math<float>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit LightingImpl(float epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 一个帮助函数,允许您设置angle和自动计算cosAngle和sinAngle。
        void SetAngle(float aAngle);

        void SetExponent(float aExponent) noexcept;

        NODISCARD float GetAngle() const noexcept;
        NODISCARD float GetCosAngle() const noexcept;
        NODISCARD float GetSinAngle() const noexcept;
        NODISCARD float GetExponent() const noexcept;

        void SetAmbient(const ColourType& aAmbient) noexcept;
        void SetDiffuse(const ColourType& aDiffuse) noexcept;
        void SetSpecular(const ColourType& aSpecular) noexcept;

        NODISCARD ColourType GetAmbient() const noexcept;
        NODISCARD ColourType GetDiffuse() const noexcept;
        NODISCARD ColourType GetSpecular() const noexcept;

        void SetAttenuation(float aConstant, float aLinear, float aQuadratic, float aIntensity) noexcept;

        NODISCARD float GetConstant() const noexcept;
        NODISCARD float GetLinear() const noexcept;
        NODISCARD float GetQuadratic() const noexcept;
        NODISCARD float GetIntensity() const noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        // 光的颜色
        ColourType ambient;  // 默认: (1,1,1,1)
        ColourType diffuse;  // 默认: (1,1,1,1)
        ColourType specular;  // 默认: (1,1,1,1)

        // 位置光源的参数。锥角必须满足在弧度0 < Angle <= pi。
        float angle;  // 默认: pi / 2
        float cosAngle;  // 默认: 0
        float sinAngle;  // 默认:  0
        float exponent;  // 默认:  1

        /// 衰减为：intensity / (constant + linear * (d + quadratic * d)。
        /// 其中d是从光位置到顶点位置的距离。
        /// 距离在模型空间中。
        /// 如果从模型空间到世界空间的转换涉及统一缩放，则可以在“强度”分量中包含缩放因子（通过乘法）。
        float constant;  // 默认: 1
        float linear;  // 默认: 0
        float quadratic;  // 默认: 0
        float intensity;  // 默认: 1

        float epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_LIGHTINT_IMPL_H
