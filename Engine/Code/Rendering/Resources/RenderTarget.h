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
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(RenderTarget);
		using ParentType = Object;
     	using Texture2DSmartPointer = CoreTools::FourthSubclassSmartPointer<Texture2D>;
		using ConstTexture2DSmartPointer = CoreTools::ConstFourthSubclassSmartPointer<Texture2D>;
		using RenderTargetSmartPointer = CoreTools::FourthSubclassSmartPointer<ClassType>;
		using ConstRenderTargetSmartPointer = CoreTools::ConstFourthSubclassSmartPointer<ClassType>; 

    public:
		// 支持目标的数量取决于图形硬件和驱动程序。“numTargets”必须至少1。
        RenderTarget (int numTargets, TextureFormat format,int width,int height, bool hasMipmaps,bool hasDepthStencil);
        
        virtual ~RenderTarget ();
        
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(RenderTarget);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
 
        int GetNumTargets () const;
        TextureFormat GetFormat () const;
        int GetWidth () const;
        int GetHeight () const;
		ConstTexture2DSmartPointer GetColorTexture(int index) const;
		ConstTexture2DSmartPointer GetDepthStencilTexture() const;
        bool HasMipmaps () const;
        bool HasDepthStencil () const;

    private:
		IMPL_TYPE_DECLARE(RenderTarget);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(RenderTarget);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, RenderTarget); 
}

#endif // RENDERING_RESOURCES_RENDER_TARGET_H
