///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 15:47)

#ifndef RENDERING_SHADERS_SHADER_MANAGE_H
#define RENDERING_SHADERS_SHADER_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "Flags/ShaderFlags.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

RENDERING_EXPORT_UNIQUE_PTR(ShaderManager);
RENDERING_NON_COPY_EXPORT_IMPL(ShaderManagerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderManager : public CoreTools::Singleton<ShaderManager>
    {
    public:
        NON_COPY_TYPE_DECLARE(ShaderManager);
        using ParentType = Singleton<ShaderManager>;
        using VertexShaderProfile = ShaderFlags::VertexShaderProfile;
        using PixelShaderProfile = ShaderFlags::PixelShaderProfile;

    private:
        enum class ShaderManagerCreate
        {
            Init,
        };

    public:
        explicit ShaderManager(ShaderManagerCreate shaderManagerCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(ShaderManager);

        CLASS_INVARIANT_DECLARE;

        void SetVertexProfile(VertexShaderProfile profile);
        NODISCARD VertexShaderProfile GetVertexProfile() const;

        void SetPixelProfile(PixelShaderProfile profile);
        NODISCARD PixelShaderProfile GetPixelProfile() const;

    private:
        using ShaderManagerUniquePtr = std::unique_ptr<ShaderManager>;

    private:
        static ShaderManagerUniquePtr shaderManager;
        PackageType impl;
    };
}

#define SHADER_MANAGE_SINGLETON Rendering::ShaderManager::GetSingleton()

#endif  // RENDERING_SHADERS_SHADER_MANAGE_H
