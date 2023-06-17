///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:07)

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

        // 光类型,目前只有一个传统的类型。默认值是LightType::Ambient。
        void SetType(LightType type) noexcept;
        NODISCARD LightType GetType() const noexcept;

        // 一个帮助函数,允许您设置m_Angle和自动计算m_CosAngle和m_SinAngle。
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

        // 一个帮助函数，当你设置方向向量时，自动计算向上和向右向量。
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
        // 光的颜色
        Colour ambient;  // 默认: (0,0,0,1)
        Colour diffuse;  // 默认: (0,0,0,1)
        Colour specular;  // 默认: (0,0,0,1)

        // 衰减通常指定为一个调节器
        //     m = 1 / (C + L * d + Q * d * d)
        // 这里C是常量系数，L是线性系数，Q是二次系数，
        // 和d是顶点位置同光位置的距离。
        // 允许一个线性调整强度因子,选择使用
        //     m = I / (C + L * d + Q * d * d)
        // 代替，这里I是一个强度因子。
        float constant;  // 默认: 1
        float linear;  // 默认: 0
        float quadratic;  // 默认: 0
        float intensity;  // 默认: 1

        // 位置光源的参数。锥角必须满足在弧度0 < Angle <= pi。
        float angle;  // 默认: pi
        float cosAngle;  // 默认: -1
        float sinAngle;  // 默认:  0
        float exponent;  // 默认:  1

        // 虽然标准的方向光源和位置光源只需要一个方向向量，
        // 但为了允许新类型的派生类的光源使用一个完整的坐标系，
        // 光源提供了这样一个存储框架。光源框架总是在世界坐标。
        //   默认 position  P = (0,0,0)
        //   默认 direction D = (0,0,-1)
        //   默认 up        U = (0,1,0)
        //   默认 right     R = (1,0,0)
        // 集合{ D,U,R }必须是一个右手标准正交集合。
        // 也就是说,每个向量是长度单位,向量是相互垂直,R = Cross(D,U)。
        APoint position;
        AVector directionVector;
        AVector upVector;
        AVector rightVector;

        LightType lightType;
        float epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_LIGHT_IMPL_H
