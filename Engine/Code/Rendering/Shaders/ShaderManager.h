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
RENDERING_EXPORT_UNIQUE_PTR(ShaderManager);
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
		NON_COPY_CLASSES_TYPE_DECLARE(ShaderManager);
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
        
        void SetVertexProfile (VertexShaderProfile profile);
        VertexShaderProfile GetVertexProfile () const;
        
        void SetPixelProfile (PixelShaderProfile profile);
        PixelShaderProfile GetPixelProfile () const;
        
	private:
		using ShaderManagerUniquePtr = std::unique_ptr<ShaderManager>;

	private:
		static ShaderManagerUniquePtr sm_ShaderManager;
		IMPL_TYPE_DECLARE(ShaderManager);
    };
}

#define SHADER_MANAGE_SINGLETON Rendering::ShaderManager::GetSingleton()

#endif // RENDERING_SHADERS_SHADER_MANAGE_H
