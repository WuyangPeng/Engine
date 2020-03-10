// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:03)

#ifndef RENDERING_RENDERERS_RENDERER_MANAGE_IMPL_H
#define RENDERING_RENDERERS_RENDERER_MANAGE_IMPL_H

#include "Rendering/RenderingDll.h"

#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <set>

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

	class RendererManagerImpl 
	{
	public:
		using ClassType = RendererManagerImpl;
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
		RendererManagerImpl();

		CLASS_INVARIANT_DECLARE;
		
		void Insert(RendererPtr ptr);
		void Erase(RendererPtr ptr);
		
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
		using RendererSet = std::set<RendererPtr>; 

	private:
		RendererSet m_Renderers;	 
	};
}

#endif // RENDERING_RENDERERS_RENDERER_MANAGE_IMPL_H



	