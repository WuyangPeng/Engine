///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 16:19)

#ifndef RENDERING_SHADERS_SHADER_PROFILE_DATA_H
#define RENDERING_SHADERS_SHADER_PROFILE_DATA_H

#include "Rendering/RenderingDll.h"

#include "Flags/ShaderFlags.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ShaderProfileData, ShaderProfileDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderProfileData : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ShaderProfileData);
        using ParentType = Object;

    public:
        ShaderProfileData(int numConstants, int numSamplers);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ShaderProfileData);

        void SetBaseRegister(int profile, int index, int baseRegister);
        void SetTextureUnit(int profile, int index, int textureUnit);
        void SetProgram(int profile, const std::string& program);

        NODISCARD int GetBaseRegister(int profile, int index) const;
        NODISCARD int GetTextureUnit(int profile, int index) const;
        NODISCARD std::string GetProgram(int profile) const;

        NODISCARD int GetBaseRegisterSize() const noexcept;
        NODISCARD int GetTextureUnitSize() const noexcept;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ShaderProfileData);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ShaderProfileData);
}

#endif  // RENDERING_SHADERS_SHADER_PROFILE_DATA_H
