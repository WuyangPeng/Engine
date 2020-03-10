// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 09:42)

#ifndef RENDERING_RESOURCES_RENDER_TARGET_IMPL_H
#define RENDERING_RESOURCES_RENDER_TARGET_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Texture2D.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "CoreTools/MemoryTools/ThirdSubclassSmartPointer.h"
#include "CoreTools/MemoryTools/ConstThirdSubclassSmartPointer.h"

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
		using ConstTexture2DSmartPointer = CoreTools::ConstFourthSubclassSmartPointer<Texture2D>;
		using Texture2DSmartPointer = CoreTools::FourthSubclassSmartPointer<Texture2D>;

    public:
 		// ֧��Ŀ�������ȡ����ͼ��Ӳ�����������򡣡�numTargets����������1��
		RenderTargetImpl();
        RenderTargetImpl (int numTargets, TextureFormat format,int width,int height, bool hasMipmaps,bool hasDepthStencil);
		RenderTargetImpl(const RenderTargetImpl& rhs);
		RenderTargetImpl& operator= (const RenderTargetImpl& rhs);
        
		CLASS_INVARIANT_DECLARE;
    
        int GetNumTargets () const;
        TextureFormat GetFormat () const;
        int GetWidth () const;
        int GetHeight () const;
        ConstTexture2DSmartPointer GetColorTexture (int index) const;
		ConstTexture2DSmartPointer GetDepthStencilTexture() const;
        bool HasMipmaps () const;
        bool HasDepthStencil () const;
        
        int GetStreamingSize () const;
		void Save (BufferTarget& target) const;
		void Load (BufferSource& source);
        void Link (ObjectLink& source);
        void Register (ObjectRegister& target) const;
        
        CORE_TOOLS_NAMES_IMPL_DECLARE;

	private:
		void Swap(RenderTargetImpl& rhs);

    private:
        std::vector<Texture2DSmartPointer> m_ColorTextures;
        Texture2DSmartPointer m_DepthStencilTexture;
        bool m_HasMipmaps;
    };
}

#endif // RENDERING_RESOURCES_RENDER_TARGET_IMPL_H
