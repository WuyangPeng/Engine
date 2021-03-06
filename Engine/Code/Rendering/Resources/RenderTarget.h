// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 11:07)

#ifndef RENDERING_RESOURCES_RENDER_TARGET_H
#define RENDERING_RESOURCES_RENDER_TARGET_H

#include "Rendering/RenderingDll.h"

#include "Texture2D.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"

RENDERING_EXPORT_SHARED_PTR(RenderTargetImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RenderTarget : public CoreTools::Object 
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(RenderTarget, DESTRUCTOR_STATEMENT);
		using ParentType = Object;
     	using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
		using ConstTexture2DSharedPtr = std::shared_ptr< const Texture2D>;
		using RenderTargetSharedPtr = std::shared_ptr<ClassType>;
		using ConstRenderTargetSharedPtr =std::shared_ptr<const ClassType>; 

    public:
		// 支持目标的数量取决于图形硬件和驱动程序。“numTargets”必须至少1。
        RenderTarget (int numTargets, TextureFormat format,int width,int height, bool hasMipmaps,bool hasDepthStencil);
         
		  
		CLASS_INVARIANT_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(RenderTarget);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
 
        int GetNumTargets () const;
        TextureFormat GetFormat () const;
        int GetWidth () const;
        int GetHeight () const;
		ConstTexture2DSharedPtr GetColorTexture(int index) const ;
		ConstTexture2DSharedPtr GetDepthStencilTexture() const noexcept;
        bool HasMipmaps () const noexcept;
        bool HasDepthStencil () const noexcept;
        ObjectInterfaceSharedPtr CloneObject() const override;
    private:
		IMPL_TYPE_DECLARE(RenderTarget);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(RenderTarget);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( RenderTarget); 
}

#endif // RENDERING_RESOURCES_RENDER_TARGET_H
