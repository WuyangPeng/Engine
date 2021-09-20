// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 11:07)

#ifndef RENDERING_RESOURCES_RENDER_TARGET_H
#define RENDERING_RESOURCES_RENDER_TARGET_H

#include "Rendering/RenderingDll.h"

#include "Texture2D.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"

 
EXPORT_SHARED_PTR(Rendering, RenderTargetImpl, RENDERING_DEFAULT_DECLARE);
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RenderTarget : public CoreTools::Object 
    {
    public:
    public:
        void Swap(RenderTarget& rhs) noexcept;

    public:
        TYPE_DECLARE(RenderTarget);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~RenderTarget() noexcept;
        RenderTarget(const RenderTarget& rhs);
        RenderTarget& operator=(const RenderTarget& rhs);
        RenderTarget(RenderTarget&& rhs) noexcept;
        RenderTarget& operator=(RenderTarget&& rhs) noexcept;
		using ParentType = Object;
     	using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
		using ConstTexture2DSharedPtr = std::shared_ptr< const Texture2D>;
		using RenderTargetSharedPtr = std::shared_ptr<ClassType>;
		using ConstRenderTargetSharedPtr =std::shared_ptr<const ClassType>; 

    public:
		// ֧��Ŀ�������ȡ����ͼ��Ӳ�����������򡣡�numTargets����������1��
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
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(RenderTarget);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( RenderTarget); 
}

#endif // RENDERING_RESOURCES_RENDER_TARGET_H
