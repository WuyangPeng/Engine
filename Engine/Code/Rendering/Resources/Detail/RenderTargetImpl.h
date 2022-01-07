// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 09:42)

#ifndef RENDERING_RESOURCES_RENDER_TARGET_IMPL_H
#define RENDERING_RESOURCES_RENDER_TARGET_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Texture2D.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"



#include <vector>

namespace CoreTools
{
	class BufferTarget;
	class BufferSource;
    class ObjectLink;
    class ObjectRegister;
	class Object;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RenderTargetImpl 
    {
    public:
        using ClassType = RenderTargetImpl;
		using Object = CoreTools::Object;
		using BufferTarget = CoreTools::BufferTarget;
		using BufferSource = CoreTools::BufferSource;
		using ObjectRegister = CoreTools::ObjectRegister;
		using ObjectLink = CoreTools::ObjectLink;
		using ConstTexture2DSharedPtr = std::shared_ptr<const Texture2D>;
		using Texture2DSharedPtr = std::shared_ptr<Texture2D>;

    public:
 		// 支持目标的数量取决于图形硬件和驱动程序。“numTargets”必须至少1。
        RenderTargetImpl()  ;
        RenderTargetImpl (int numTargets, TextureFormat format,int width,int height, bool hasMipmaps,bool hasDepthStencil);
		RenderTargetImpl(const RenderTargetImpl& rhs);
		RenderTargetImpl& operator= (const RenderTargetImpl& rhs);
                RenderTargetImpl( RenderTargetImpl&& rhs) = default;
                RenderTargetImpl& operator=(RenderTargetImpl&& rhs) = default;
                ~RenderTargetImpl() = default;
        
		CLASS_INVARIANT_DECLARE;
    
        int GetNumTargets () const ;
        TextureFormat GetFormat () const;
        int GetWidth () const;
        int GetHeight () const;
        ConstTexture2DSharedPtr GetColorTexture (int index) const;
        ConstTexture2DSharedPtr GetDepthStencilTexture() const noexcept;
        bool HasMipmaps() const noexcept;
        bool HasDepthStencil() const noexcept;
        
        int GetStreamingSize () const;
		void Save (CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
                void Link(CoreTools::ObjectLink& source);
                void Register(CoreTools::ObjectRegister& target) const;
        
        CORE_TOOLS_NAMES_IMPL_DECLARE;

	private:
        void Swap(RenderTargetImpl& rhs) noexcept;

    private:
        std::vector<Texture2DSharedPtr> m_ColorTextures;
        Texture2DSharedPtr m_DepthStencilTexture;
        bool m_HasMipmaps;
    };
}

#endif // RENDERING_RESOURCES_RENDER_TARGET_IMPL_H
