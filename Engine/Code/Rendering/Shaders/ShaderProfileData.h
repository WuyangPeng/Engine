// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:26)

#ifndef RENDERING_SHADERS_SHADER_PROFILE_DATA_H
#define RENDERING_SHADERS_SHADER_PROFILE_DATA_H

#include "Rendering/RenderingDll.h"

#include "Flags/ShaderFlags.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

#include <string>

RENDERING_EXPORT_SHARED_PTR(ShaderProfileDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderProfileData : public CoreTools::Object
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(ShaderProfileData);
        using ParentType = Object;

    public:
        ShaderProfileData(int numConstants, int numSamplers);
        ~ShaderProfileData();
        ShaderProfileData(ShaderProfileData&&) noexcept = default;
        ShaderProfileData& operator=(ShaderProfileData&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ShaderProfileData);

        void SetBaseRegister(int profile, int index, int baseRegister);
        void SetTextureUnit(int profile, int index, int textureUnit);
        void SetProgram(int profile, const std::string& program);

        int GetBaseRegister(int profile, int index) const;
        int GetTextureUnit(int profile, int index) const;
        const std::string GetProgram(int profile) const;

        int GetBaseRegisterSize() const noexcept;
        int GetTextureUnitSize() const noexcept;

    private:
        IMPL_TYPE_DECLARE(ShaderProfileData);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(ShaderProfileData);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, ShaderProfileData);
}

#endif  // RENDERING_SHADERS_SHADER_PROFILE_DATA_H
