// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 15:40)

#ifndef RENDERING_RENDERERS_TEXTURE_MANAGEMENT_H
#define RENDERING_RENDERERS_TEXTURE_MANAGEMENT_H

#include "Rendering/RenderingDll.h"

#include <map>
#include <memory>

namespace Rendering
{
	class Renderer;

    template <typename PlatformTextureType>
	class TextureManagement 
	{
	public:
		using ClassType = TextureManagement <PlatformTextureType>;
		using TextureType = typename PlatformTextureType::TextureType;
		using TextureConstPtr = const TextureType*;
		using PlatformTextureSharedPtr = std::shared_ptr<PlatformTextureType>;
	    using RendererPtr = Renderer*;

	public:
		explicit TextureManagement(RendererPtr ptr);

		CLASS_INVARIANT_DECLARE;
	
       // 1D、2D、3D、Cube纹理管理。纹理对象必须是已经由应用程序代码分配。
       void Bind (TextureConstPtr texture); 
       void Unbind (TextureConstPtr texture);
 
       void Enable (TextureConstPtr texture, int textureUnit);
       void Disable (TextureConstPtr texture, int textureUnit);

       void* Lock (TextureConstPtr texture,int level,BufferLocking mode);
       void Unlock (TextureConstPtr texture,int level);
       void Update (TextureConstPtr texture,int level);

       void* LockCube (TextureConstPtr texture,int face,int level,BufferLocking mode);
       void UnlockCube (TextureConstPtr texture,int face,int level);
       void UpdateCube (TextureConstPtr texture,int face,int level);

       PlatformTextureSharedPtr GetResource (TextureConstPtr buffer);

	   bool IsInTextureMap (TextureConstPtr texture);	  
	   void InsertTextureMap (TextureConstPtr texture,const PlatformTextureSharedPtr& platformTexture);
	   void RemoveTextureMap(TextureConstPtr texture);

	private:
       using TextureMap = std::map<TextureConstPtr, PlatformTextureSharedPtr>;

	private:
	   RendererPtr m_Renderer;
	   TextureMap m_Textures;	 
	};
}

#endif // RENDERING_RENDERERS_TEXTURE_MANAGEMENT_H



	