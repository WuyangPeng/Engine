// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 15:40)

#ifndef RENDERING_RENDERERS_NON_CUBE_TEXTURE_MANAGEMENT_H
#define RENDERING_RENDERERS_NON_CUBE_TEXTURE_MANAGEMENT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Buffer.h"

#include <map>
#include "../Shaders/ShaderParameters.h"

namespace Rendering
{
	class Renderer;

    template <typename TextureFlags,typename PdrTextureType>
	class ShaderManagement
	{
	public:
		using ClassType = ShaderManagement <TextureFlags, PdrTextureType>;
		using TextureConstWeakPtr = std::shared_ptr<const TextureFlags>;
		using PdrTextureSharedPtr = std::shared_ptr<PdrTextureType>;
	    using RendererWeakPtr = std::weak_ptr<Renderer>;

	public:
		explicit ShaderManagement(RendererWeakPtr ptr);

		CLASS_INVARIANT_DECLARE;
	
       // 1D、2D、3D纹理管理。纹理对象必须是已经由应用程序代码分配。
       void Bind (TextureConstWeakPtr texture); 
       void Unbind (TextureConstWeakPtr texture);
 
       void Enable (TextureConstWeakPtr texture, const ConstShaderParametersSharedPtr& parameters);
       void Disable (TextureConstWeakPtr texture, const ConstShaderParametersSharedPtr& parameters);

       void* Lock (TextureConstWeakPtr texture,int level, BufferLocking mode);
       void Unlock (TextureConstWeakPtr texture,int level);
       void Update (TextureConstWeakPtr texture,int level);

       PdrTextureSharedPtr GetResource (TextureConstWeakPtr buffer);

	private:
       using TextureMap = std::map<TextureConstWeakPtr, PdrTextureSharedPtr>; 

	private:
	   RendererWeakPtr m_Renderer;
	   TextureMap m_Textures;	 
	};
}

#endif // RENDERING_RENDERERS_NON_CUBE_TEXTURE_MANAGEMENT_H



	