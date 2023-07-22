///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/05 15:36)

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

        using Colour = Colour<float>;
        using MaterialSharedPtr = std::shared_ptr<ClassType>;
        using ConstMaterialSharedPtr = std::shared_ptr<const ClassType>;

    public:
        NODISCARD static MaterialSharedPtr Create();
        NODISCARD static MaterialSharedPtr Create(const Colour& emissive, const Colour& ambient, const Colour& diffuse, const Colour& specular);

    protected:
        enum class MaterialCreate
        {
            Init,
        };

    public:
        explicit Material(MaterialCreate materialCreate);
        Material(MaterialCreate materialCreate, const Colour& emissive, const Colour& ambient, const Colour& diffuse, const Colour& specular);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Material);

        NODISCARD Colour GetEmissive() const noexcept;
        NODISCARD Colour GetAmbient() const noexcept;
        NODISCARD Colour GetDiffuse() const noexcept;
        NODISCARD Colour GetSpecular() const noexcept;

        void SetEmissive(const Colour& emissive) noexcept;
        void SetAmbient(const Colour& ambient) noexcept;
        void SetDiffuse(const Colour& diffuse) noexcept;
        void SetSpecular(const Colour& specular) noexcept;

        NODISCARD float GetAlpha() const noexcept;
        NODISCARD float GetSpecularExponent() const noexcept;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Material);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Material);
}

#endif  // RENDERING_LOCAL_EFFECTS_MATERIAL_H