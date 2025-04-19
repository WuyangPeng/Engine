/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/09 20:30)

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

        // һ����������,����������angle���Զ�����cosAngle��sinAngle��
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
        // �����ɫ
        ColourType ambient;  // Ĭ��: (1,1,1,1)
        ColourType diffuse;  // Ĭ��: (1,1,1,1)
        ColourType specular;  // Ĭ��: (1,1,1,1)

        // λ�ù�Դ�Ĳ�����׶�Ǳ��������ڻ���0 < Angle <= pi��
        float angle;  // Ĭ��: pi / 2
        float cosAngle;  // Ĭ��: 0
        float sinAngle;  // Ĭ��:  0
        float exponent;  // Ĭ��:  1

        /// ˥��Ϊ��intensity / (constant + linear * (d + quadratic * d)��
        /// ����d�Ǵӹ�λ�õ�����λ�õľ��롣
        /// ������ģ�Ϳռ��С�
        /// �����ģ�Ϳռ䵽����ռ��ת���漰ͳһ���ţ�������ڡ�ǿ�ȡ������а����������ӣ�ͨ���˷�����
        float constant;  // Ĭ��: 1
        float linear;  // Ĭ��: 0
        float quadratic;  // Ĭ��: 0
        float intensity;  // Ĭ��: 1

        float epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_LIGHTINT_IMPL_H
