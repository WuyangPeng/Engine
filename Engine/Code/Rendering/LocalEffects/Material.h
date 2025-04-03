/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 20:36)

#ifndef RENDERING_LOCAL_EFFECTS_MATERIAL_H
#define RENDERING_LOCAL_EFFECTS_MATERIAL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/DataTypes/Colour.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Material, MaterialImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Material final : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Material);
        using ParentType = Object;

        using ColourType = Colour<float>;
        using MaterialSharedPtr = std::shared_ptr<ClassType>;
        using ConstMaterialSharedPtr = std::shared_ptr<const ClassType>;

    public:
        NODISCARD static MaterialSharedPtr Create(const std::string& name);
        NODISCARD static MaterialSharedPtr Create(const std::string& name, const ColourType& emissive, const ColourType& ambient, const ColourType& diffuse, const ColourType& specular);

    protected:
        enum class MaterialCreate
        {
            Init,
        };

    public:
        Material(MaterialCreate materialCreate, const std::string& name);
        Material(MaterialCreate materialCreate, const std::string& name, const ColourType& emissive, const ColourType& ambient, const ColourType& diffuse, const ColourType& specular);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Material);

        NODISCARD ColourType GetEmissive() const noexcept;
        NODISCARD ColourType GetAmbient() const noexcept;
        NODISCARD ColourType GetDiffuse() const noexcept;
        NODISCARD ColourType GetSpecular() const noexcept;

        void SetEmissive(const ColourType& emissive) noexcept;
        void SetAmbient(const ColourType& ambient) noexcept;
        void SetDiffuse(const ColourType& diffuse) noexcept;
        void SetSpecular(const ColourType& specular) noexcept;

        NODISCARD float GetAlpha() const noexcept;
        NODISCARD float GetSpecularExponent() const noexcept;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Material);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Material);
}

#endif  // RENDERING_LOCAL_EFFECTS_MATERIAL_H
