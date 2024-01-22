/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 20:32)

#ifndef RENDERING_SCENE_GRAPH_LIGHTING_H
#define RENDERING_SCENE_GRAPH_LIGHTING_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/DataTypes/Colour.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Lighting, LightingImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Lighting : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Lighting);
        using ParentType = Object;

        using Colour = Colour<float>;
        using Math = Mathematics::Math<float>;
        using LightSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static LightSharedPtr Create(const std::string& name);

    public:
        Lighting(const std::string& name, float epsilon);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Lighting);

        // 一个帮助函数,允许您设置angle和自动计算cosAngle和sinAngle。
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

        void SetAttenuation(float constant, float linear, float quadratic, float intensity) noexcept;

        NODISCARD float GetConstant() const noexcept;
        NODISCARD float GetLinear() const noexcept;
        NODISCARD float GetQuadratic() const noexcept;
        NODISCARD float GetIntensity() const noexcept;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Lighting);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Lighting);
}

#endif  // RENDERING_SCENE_GRAPH_LIGHTING_H
