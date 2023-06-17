///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:07)

#ifndef RENDERING_SCENE_GRAPH_LIGHT_IMPL_H
#define RENDERING_SCENE_GRAPH_LIGHT_IMPL_H

#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/RenderingDll.h"
#include "Rendering/SceneGraph/Flags/LightFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE LightImpl
    {
    public:
        using ClassType = LightImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Math = Mathematics::Math<float>;
        using Colour = Colour<float>;

    public:
        explicit LightImpl(LightType type = LightType::Ambient, float epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ������,Ŀǰֻ��һ����ͳ�����͡�Ĭ��ֵ��LightType::Ambient��
        void SetType(LightType type) noexcept;
        NODISCARD LightType GetType() const noexcept;

        // һ����������,����������m_Angle���Զ�����m_CosAngle��m_SinAngle��
        void SetAngle(float aAngle);

        void SetExponent(float aExponent) noexcept;

        NODISCARD float GetAngle() const noexcept;
        NODISCARD float GetCosAngle() const noexcept;
        NODISCARD float GetSinAngle() const noexcept;
        NODISCARD float GetExponent() const noexcept;

        void SetAmbient(const Colour& aAmbient) noexcept;
        void SetDiffuse(const Colour& aDiffuse) noexcept;
        void SetSpecular(const Colour& aSpecular) noexcept;

        NODISCARD Colour GetAmbient() const noexcept;
        NODISCARD Colour GetDiffuse() const noexcept;
        NODISCARD Colour GetSpecular() const noexcept;

        NODISCARD APoint GetPosition() const noexcept;
        NODISCARD AVector GetDirectionVector() const noexcept;
        NODISCARD AVector GetUpVector() const noexcept;
        NODISCARD AVector GetRightVector() const noexcept;

        void SetPosition(const APoint& point) noexcept;
        void SetVector(const AVector& up, const AVector& right, const AVector& direction) noexcept;

        // һ�������������������÷�������ʱ���Զ��������Ϻ�����������
        void SetDirection(const AVector& direction);

        void SetAttenuation(float aConstant, float aLinear, float aQuadratic, float aIntensity) noexcept;

        NODISCARD float GetConstant() const noexcept;
        NODISCARD float GetLinear() const noexcept;
        NODISCARD float GetQuadratic() const noexcept;
        NODISCARD float GetIntensity() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        // �����ɫ
        Colour ambient;  // Ĭ��: (0,0,0,1)
        Colour diffuse;  // Ĭ��: (0,0,0,1)
        Colour specular;  // Ĭ��: (0,0,0,1)

        // ˥��ͨ��ָ��Ϊһ��������
        //     m = 1 / (C + L * d + Q * d * d)
        // ����C�ǳ���ϵ����L������ϵ����Q�Ƕ���ϵ����
        // ��d�Ƕ���λ��ͬ��λ�õľ��롣
        // ����һ�����Ե���ǿ������,ѡ��ʹ��
        //     m = I / (C + L * d + Q * d * d)
        // ���棬����I��һ��ǿ�����ӡ�
        float constant;  // Ĭ��: 1
        float linear;  // Ĭ��: 0
        float quadratic;  // Ĭ��: 0
        float intensity;  // Ĭ��: 1

        // λ�ù�Դ�Ĳ�����׶�Ǳ��������ڻ���0 < Angle <= pi��
        float angle;  // Ĭ��: pi
        float cosAngle;  // Ĭ��: -1
        float sinAngle;  // Ĭ��:  0
        float exponent;  // Ĭ��:  1

        // ��Ȼ��׼�ķ����Դ��λ�ù�Դֻ��Ҫһ������������
        // ��Ϊ�����������͵�������Ĺ�Դʹ��һ������������ϵ��
        // ��Դ�ṩ������һ���洢��ܡ���Դ����������������ꡣ
        //   Ĭ�� position  P = (0,0,0)
        //   Ĭ�� direction D = (0,0,-1)
        //   Ĭ�� up        U = (0,1,0)
        //   Ĭ�� right     R = (1,0,0)
        // ����{ D,U,R }������һ�����ֱ�׼�������ϡ�
        // Ҳ����˵,ÿ�������ǳ��ȵ�λ,�������໥��ֱ,R = Cross(D,U)��
        APoint position;
        AVector directionVector;
        AVector upVector;
        AVector rightVector;

        LightType lightType;
        float epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_LIGHT_IMPL_H
