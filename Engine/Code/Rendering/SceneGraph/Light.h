// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/22 11:21)

#ifndef RENDERING_SCENE_GRAPH_LIGHT_H
#define RENDERING_SCENE_GRAPH_LIGHT_H

#include "Rendering/RenderingDll.h"

#include "Flags/LightFlags.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/DataTypes/Colour.h"

 
EXPORT_SHARED_PTR(Rendering, LightImpl, RENDERING_DEFAULT_DECLARE);
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Light : public CoreTools::Object
    {
    public:
        void Swap(Light& rhs) noexcept;
         
             public:
                 TYPE_DECLARE(Light);
                 using ClassShareType = CoreTools::CopyUnsharedClasses;
                 ~Light() noexcept;
                 Light(const Light& rhs);
                 Light& operator=(const Light& rhs);
                 Light(Light&& rhs) noexcept;
                 Light& operator=(Light&& rhs) noexcept;
        using ParentType = Object;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Math = Mathematics::Math<float>;
        using Colour = Colour<float>;

    public:
        explicit Light(LightType type = LightType::Ambient, float epsilon = Math::GetZeroTolerance());
        

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Light);

        // 光类型,目前只有一个传统的类型。默认值是LightType::Ambient。
        void SetType(LightType type);
        LightType GetType() const;

        // 一个帮助函数,允许您设置m_Angle和自动计算m_CosAngle和m_SinAngle。
        void SetAngle(float angle);

        void SetExponent(float exponent);

        float GetAngle() const;
        float GetCosAngle() const;
        float GetSinAngle() const;
        float GetExponent() const;

        void SetAmbient(const Colour& ambient);
        void SetDiffuse(const Colour& diffuse);
        void SetSpecular(const Colour& specular);

        const Colour GetAmbient() const;
        const Colour GetDiffuse() const;
        const Colour GetSpecular() const;

        const APoint GetPosition() const;
        const AVector GetDirectionVector() const;
        const AVector GetUpVector() const;
        const AVector GetRightVector() const;

        void SetPosition(const APoint& point);
        void SetVector(const AVector& up, const AVector& right, const AVector& direction);

        // 一个帮助函数，当你设置方向向量时，自动计算向上和向右向量。
        void SetDirection(const AVector& direction);

        void SetAttenuation(float constant, float linear, float quadratic, float intensity);

        float GetConstant() const;
        float GetLinear() const;
        float GetQuadratic() const;
        float GetIntensity() const;
        ObjectInterfaceSharedPtr CloneObject() const override;
    private:
        using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(Light);
#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE( Light);
}

#endif  // RENDERING_SCENE_GRAPH_LIGHT_H
