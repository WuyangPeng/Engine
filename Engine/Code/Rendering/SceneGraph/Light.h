///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/02 13:51)

#ifndef RENDERING_SCENE_GRAPH_LIGHT_H
#define RENDERING_SCENE_GRAPH_LIGHT_H

#include "Rendering/RenderingDll.h"

#include "Flags/LightFlags.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/DataTypes/Colour.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Light, LightImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Light : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Light);
        using ParentType = Object;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Math = Mathematics::Math<float>;
        using Colour = Colour<float>;

    public:
        explicit Light(LightType type, float epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Light);

        // ������,Ŀǰֻ��һ����ͳ�����͡�Ĭ��ֵ��LightType::Ambient��
        void SetType(LightType type) noexcept;
        NODISCARD LightType GetType() const noexcept;

        // һ����������,����������m_Angle���Զ�����m_CosAngle��m_SinAngle��
        void SetAngle(float angle);

        void SetExponent(float exponent) noexcept;

        NODISCARD float GetAngle() const noexcept;
        NODISCARD float GetCosAngle() const noexcept;
        NODISCARD float GetSinAngle() const noexcept;
        NODISCARD float GetExponent() const noexcept;

        void SetAmbient(const Colour& ambient) noexcept;
        void SetDiffuse(const Colour& diffuse) noexcept;
        void SetSpecular(const Colour& specular) noexcept;

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

        void SetAttenuation(float constant, float linear, float quadratic, float intensity) noexcept;

        NODISCARD float GetConstant() const noexcept;
        NODISCARD float GetLinear() const noexcept;
        NODISCARD float GetQuadratic() const noexcept;
        NODISCARD float GetIntensity() const noexcept;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Light);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Light);
}

#endif  // RENDERING_SCENE_GRAPH_LIGHT_H
