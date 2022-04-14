// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 09:29)

#ifndef RENDERING_LOCAL_EFFECTS_LIGHT_SPT_PER_VER_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_LIGHT_SPT_PER_VER_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Light.h"
#include "Rendering/SceneGraph/Material.h"
#include "Rendering/Shaders/VisualEffectInstance.h"

namespace Rendering
{
    class LightSptPerVerEffect : public VisualEffect
    {
    public:
        using ClassType = LightSptPerVerEffect;
        using ParentType = VisualEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(LightSptPerVerEffect);

    public:
        // Construction and destruction.
        LightSptPerVerEffect();

        // Create an instance of the effect with unique parameters.
        VisualEffectInstance* CreateInstance(Light* light, Material* material) const;

        // Convenience for creating an instance.  The application does not have to
        // create the effect explicitly in order to create an instance from it.
        static VisualEffectInstance* CreateUniqueInstance(Light* light, Material* material) noexcept;

    private:
        static int msDx9VRegisters[14];
        static int msOglVRegisters[14];
        static int* msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
        static std::string msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
        static std::string msPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
    };
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(LightSptPerVerEffect);
    CORE_TOOLS_SHARED_PTR_DECLARE(LightSptPerVerEffect);
#include STSTEM_WARNING_POP
}

#endif  // RENDERING_LOCAL_EFFECTS_LIGHT_SPT_PER_VER_EFFECT_H
