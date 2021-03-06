// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/24 15:26)

#ifndef RENDERING_SHADERS_SHADER_PROFILE_DATA_H
#define RENDERING_SHADERS_SHADER_PROFILE_DATA_H

#include "Rendering/RenderingDll.h"

#include "Flags/ShaderFlags.h"
#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/ObjectSystems/Object.h"

#include <string>

RENDERING_EXPORT_SHARED_PTR(ShaderProfileDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderProfileData : public CoreTools::Object
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(ShaderProfileData, DESTRUCTOR_STATEMENT);
        using ParentType = Object;

    public:
        ShaderProfileData(int numConstants, int numSamplers);
    

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ShaderProfileData);

        void SetBaseRegister(int profile, int index, int baseRegister);
        void SetTextureUnit(int profile, int index, int textureUnit);
        void SetProgram(int profile, const std::string& program);

        int GetBaseRegister(int profile, int index) const;
        int GetTextureUnit(int profile, int index) const;
        const std::string GetProgram(int profile) const;

        int GetBaseRegisterSize() const noexcept;
        int GetTextureUnitSize() const noexcept;
        ObjectInterfaceSharedPtr CloneObject() const override;
    private:
        IMPL_TYPE_DECLARE(ShaderProfileData);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(ShaderProfileData);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( ShaderProfileData);
}

#endif  // RENDERING_SHADERS_SHADER_PROFILE_DATA_H
