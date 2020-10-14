// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 15:09)

#ifndef RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_IMPL_H
#define RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/VisualEffect.h"
#include "Rendering/Shaders/ShaderParameters.h"


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
	class RENDERING_HIDDEN_DECLARE VisualEffectInstanceImpl
	{
	public:
		using ClassType = VisualEffectInstanceImpl;
		using Object = CoreTools::Object;
		using BufferTarget = CoreTools::BufferTarget;
		using BufferSource = CoreTools::BufferSource;
		using ObjectLink = CoreTools::ObjectLink;
		using ObjectRegister = CoreTools::ObjectRegister;

	public:
		VisualEffectInstanceImpl();
		VisualEffectInstanceImpl(const VisualEffectSharedPtr& effect, int techniqueIndex);

		VisualEffectInstanceImpl(const VisualEffectInstanceImpl& rhs);
		VisualEffectInstanceImpl& operator=(const VisualEffectInstanceImpl& rhs);
                ~VisualEffectInstanceImpl() = default;
                VisualEffectInstanceImpl(VisualEffectInstanceImpl&&) noexcept = default;
                VisualEffectInstanceImpl& operator=(VisualEffectInstanceImpl&&) noexcept = default;
		CLASS_INVARIANT_DECLARE;

		int GetStreamingSize() const;
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Link(const CoreTools:: ObjectLinkSharedPtr& source);
                void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;
		
		CORE_TOOLS_NAMES_IMPL_DECLARE;

		// ����ͼԪ���ƹ�������Щ��Rendererʹ�á�
		const ConstVisualEffectSharedPtr GetEffect() const;
		int GetTechniqueIndex() const;
		int GetNumPasses() const;
		const ConstVisualPassSharedPtr GetConstPass(int pass) const;
		const ConstShaderParametersSharedPtr GetConstVertexParameters(int pass) const;
		const ConstShaderParametersSharedPtr GetConstPixelParameters(int pass) const;
	 
		const ShaderParametersSharedPtr GetVertexParameters(int pass);
		const ShaderParametersSharedPtr GetPixelParameters(int pass);

		// ��Щ�����趨����/����
		// ����ɹ�������ֵ�ǷǸ�ֵ�����Ҹ�����ָ����Ӧ�����顣
		// ��ָ�������ܻᴫ�ݵ�Set*�������в������������
		// �û���������ֱ��ͨ���������ã�����ʹ�ò�����const std::string& name'Set*�������ֵ����ֱȽϡ�
		int SetVertexConstant(int pass, const std::string& name,const ShaderFloatSharedPtr& shaderFloat);

		int SetPixelConstant(int pass, const std::string& name,const ShaderFloatSharedPtr& shaderFloat);

		int SetVertexTexture(int pass, const std::string& name,const TextureSharedPtr& texture);

		int SetPixelTexture(int pass, const std::string& name,const TextureSharedPtr& texture);

		// ���������������Set*�����ķ���ֵ��
		void SetVertexConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat);
		void SetPixelConstant(int pass, int handle, const ShaderFloatSharedPtr& shaderFloat);
		void SetVertexTexture(int pass, int handle, const TextureSharedPtr& texture);
		void SetPixelTexture(int pass, int handle, const TextureSharedPtr& texture);

 		const ConstShaderFloatSharedPtr GetVertexConstant(int pass, const std::string& name) const;
		const ConstShaderFloatSharedPtr GetPixelConstant(int pass, const std::string& name) const;
		const ConstTextureSharedPtr GetVertexTexture(int pass, const std::string& name) const;
		const ConstTextureSharedPtr GetPixelTexture(int pass, const std::string& name) const;

		const ConstShaderFloatSharedPtr GetVertexConstant(int pass, int handle) const;
		const ConstShaderFloatSharedPtr GetPixelConstant(int pass, int handle) const;
		const ConstTextureSharedPtr GetVertexTexture(int pass, int handle) const;
		const ConstTextureSharedPtr GetPixelTexture(int pass, int handle) const;

	private:
		void Swap( VisualEffectInstanceImpl& rhs);

	private:
		VisualEffectSharedPtr m_Effect;
		int m_TechniqueIndex;
		int m_NumPasses;
		std::vector<ShaderParametersSharedPtr> m_VertexParameters;
		std::vector<ShaderParametersSharedPtr> m_PixelParameters;
	};	 
}
 
#endif // RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_IMPL_H
