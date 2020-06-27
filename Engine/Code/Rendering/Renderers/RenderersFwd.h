// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:39)

#ifndef RENDERING_RENDERERS_FWD_H
#define RENDERING_RENDERERS_FWD_H

#include <memory>

namespace Rendering
{
     class RendererBasis;
	 class RendererParameter;
	 class PlatformVertexFormat;
	 class VertexFormatManagement;
	 class PlatformIndexBuffer;
	 class PlatformVertexBuffer;

	 template <typename PlatformBufferType>
	 class BufferLockManager;

	 template <typename PlatformBufferType>
	 class BufferManagement;

	 template <typename BufferManagementType>
	 class BufferManagementLockEncapsulation;

	 class PlatformTexture1D;
	 class PlatformTexture2D;
	 class PlatformTexture3D;
	 class PlatformTextureCube;

	 template <typename PlatformTextureType>
	 class TextureLockManager;

	 template <typename TextureManagementType>
	 class TextureManagementLockEncapsulation;

	 template <typename PlatformTextureType>
	 class TextureManagement;

	 class PlatformRenderTarget;
	 class RenderTargetManagement;

	 enum class RendererTypes;

	 class Renderer;
	 using RendererSharedPtr = std::shared_ptr<Renderer>; 
	 using ConstRendererSharedPtr = std::shared_ptr<const Renderer>;
}

#endif // RENDERING_RENDERERS_FWD_H