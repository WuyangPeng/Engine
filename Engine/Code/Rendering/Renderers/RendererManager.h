// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 15:37)

#ifndef RENDERING_RENDERERS_RENDERER_MANAGE_H
#define RENDERING_RENDERERS_RENDERER_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"

#include <boost/noncopyable.hpp>

RENDERING_EXPORT_SHARED_PTR(RendererManagerImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace CoreTools
{
	class Mutex;
}

namespace Rendering
{
	class Renderer; 
	class VertexFormat;
	class VertexBuffer;
	class IndexBuffer;
	class Texture1D;
	class Texture2D;
	class Texture3D;
	class TextureCube;
	class RenderTarget;
	class VertexShader;
	class PixelShader;

	class RENDERING_DEFAULT_DECLARE RendererManager : public CoreTools::Singleton<RendererManager>
	{
	public:
		SINGLETON_INITIALIZE_DECLARE(RendererManager); 
		using RendererPtr = Renderer*;
		using VertexFormatConstPtr = const VertexFormat*;
		using VertexBufferConstPtr = const VertexBuffer*;
		using IndexBufferConstPtr = const IndexBuffer*;
		using Texture1DConstPtr = const Texture1D*;
		using Texture2DConstPtr = const Texture2D*;
		using Texture3DConstPtr = const Texture3D*;
		using TextureCubeConstPtr = const TextureCube*;
		using RenderTargetConstPtr = const RenderTarget*;
		using VertexShaderConstPtr = const VertexShader*;
		using PixelShaderConstPtr = const PixelShader*;

	public:	
		CLASS_INVARIANT_DECLARE;

 		void Insert(RendererPtr ptr);
		void Erase(RendererPtr ptr);
		
		// 资源管理。该资源被定义为顶点格式，顶点缓冲区，索引缓冲区，
		// 纹理（1D，2D，3D，立方体），
		// 渲染目标，顶点着色器和像素着色器。函数执行以下操作。
		
		// BindAll: 创建对应于系统中的所有渲染器的输入对象的资源。
		// UnbindAll:  销毁的资源对应于输入对象中所有渲染创建资源的目标。
		// 这个函数调用的对象的析构函数。
		// UpdateAll:  更新，但施加到共享资源所有渲染的源对象的。
		
		void BindAll (VertexFormatConstPtr vertexFormat);
		void UnbindAll (VertexFormatConstPtr vertexFormat);
		
		void BindAll (VertexBufferConstPtr vertexBuffer);
		void UnbindAll (VertexBufferConstPtr vertexBuffer);
		void UpdateAll (VertexBufferConstPtr vertexBuffer);
		
		void BindAll (IndexBufferConstPtr indexBuffer);
		void UnbindAll (IndexBufferConstPtr indexBuffer);
		void UpdateAll (IndexBufferConstPtr indexBuffer);
		
		void BindAll (Texture1DConstPtr texture);
		void UnbindAll (Texture1DConstPtr texture);
		void UpdateAll (Texture1DConstPtr texture, int level);
 
		void BindAll (Texture2DConstPtr texture);
		void UnbindAll (Texture2DConstPtr texture);
		void UpdateAll (Texture2DConstPtr texture, int level);
		
		void BindAll (Texture3DConstPtr texture);
		void UnbindAll (Texture3DConstPtr texture);
		void UpdateAll (Texture3DConstPtr texture, int level);
		
		void BindAll (TextureCubeConstPtr texture);
		void UnbindAll (TextureCubeConstPtr texture);
		void UpdateAll (TextureCubeConstPtr texture, int face, int level);
		
		void BindAll (RenderTargetConstPtr renderTarget);
		void UnbindAll (RenderTargetConstPtr renderTarget);
		
		void BindAll(VertexShaderConstPtr vertexShader);
		void UnbindAll(VertexShaderConstPtr vertexShader);
		
		void BindAll(PixelShaderConstPtr pixelShader);
		void UnbindAll(PixelShaderConstPtr pixelShader);
		
	private:		
		SINGLETON_INSTANCE_DECLARE(RendererManager);
		SINGLETON_IMPL_DECLARE(RendererManager);
	};
}

#define RENDERER_MANAGE_SINGLETON Rendering::RendererManager::GetSingleton()

#endif // RENDERING_RENDERERS_RENDERER_MANAGE_H



	