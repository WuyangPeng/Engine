// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:25)

#ifndef RENDERING_SHADERS_SHADER_MANAGE_H
#define RENDERING_SHADERS_SHADER_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "Flags/ShaderFlags.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"

#include <boost/noncopyable.hpp>

RENDERING_EXPORT_SHARED_PTR(ShaderManagerImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace CoreTools
{
	class Mutex;
}

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderManager : public CoreTools::Singleton<ShaderManager>
    {
    public:
		SINGLETON_INITIALIZE_DECLARE(ShaderManager); 
        using VertexShaderProfile = ShaderFlags::VertexShaderProfile;
        using PixelShaderProfile = ShaderFlags::PixelShaderProfile;
        
    public:
		CLASS_INVARIANT_DECLARE;
        
        void SetVertexProfile (VertexShaderProfile profile);
        VertexShaderProfile GetVertexProfile () const;
        
        void SetPixelProfile (PixelShaderProfile profile);
        PixelShaderProfile GetPixelProfile () const;
        
    private:
        SINGLETON_INSTANCE_DECLARE(ShaderManager);
		SINGLETON_IMPL_DECLARE(ShaderManager);
    };
}

#define SHADER_MANAGE_SINGLETON Rendering::ShaderManager::GetSingleton()

#endif // RENDERING_SHADERS_SHADER_MANAGE_H
