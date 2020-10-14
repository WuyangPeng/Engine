// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 11:24)

#ifndef RENDERING_SCENE_GRAPH_MATERIAL_H
#define RENDERING_SCENE_GRAPH_MATERIAL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/DataTypes/Colour.h"

RENDERING_EXPORT_SHARED_PTR(MaterialImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Material : public CoreTools::Object
    {
    public:
       COPY_UNSHARE_CLASSES_TYPE_DECLARE(Material, DESTRUCTOR_STATEMENT);
        using ParentType = Object;
        using Colour = Colour<float>;

    public:
        Material();
        Material(const Colour& emissive, const Colour& ambient, const Colour& diffuse, const Colour& specular);
      

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Material);

        const Colour GetEmissive() const;
        const Colour GetAmbient() const;
        const Colour GetDiffuse() const;
        const Colour GetSpecular() const;

        void SetEmissive(const Colour& emissive);
        void SetAmbient(const Colour& ambient);
        void SetDiffuse(const Colour& diffuse);
        void SetSpecular(const Colour& specular);

        float GetAlpha() const;
        float GetSpecularExponent() const;
        ObjectInterfaceSharedPtr CloneObject() const override;
    private:
        IMPL_TYPE_DECLARE(Material);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(Material);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE(   Material);
}

#endif  // RENDERING_SCENE_GRAPH_MATERIAL_H
