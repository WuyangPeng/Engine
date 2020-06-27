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
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"

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
		VisualEffectInstanceImpl(const VisualEffectSmartPointer& effect, int techniqueIndex);

		VisualEffectInstanceImpl(const VisualEffectInstanceImpl& rhs);
		VisualEffectInstanceImpl& operator=(const VisualEffectInstanceImpl& rhs);

		CLASS_INVARIANT_DECLARE;

		int GetStreamingSize() const;
		void Save(BufferTarget& target) const;
		void Load(BufferSource& source);
		void Link(ObjectLink& source);
		void Register(ObjectRegister& target) const;
		
		CORE_TOOLS_NAMES_IMPL_DECLARE;

		// ����ͼԪ���ƹ�������Щ��Rendererʹ�á�
		const ConstVisualEffectSmartPointer GetEffect() const;
		int GetTechniqueIndex() const;
		int GetNumPasses() const;
		const ConstVisualPassSmartPointer GetConstPass(int pass) const;
		const ConstShaderParametersSmartPointer GetConstVertexParameters(int pass) const;
		const ConstShaderParametersSmartPointer GetConstPixelParameters(int pass) const;
	 
		const ShaderParametersSmartPointer GetVertexParameters(int pass);
		const ShaderParametersSmartPointer GetPixelParameters(int pass);

		// ��Щ�����趨����/����
		// ����ɹ�������ֵ�ǷǸ�ֵ�����Ҹ�����ָ����Ӧ�����顣
		// ��ָ�������ܻᴫ�ݵ�Set*�������в������������
		// �û���������ֱ��ͨ���������ã�����ʹ�ò�����const std::string& name'Set*�������ֵ����ֱȽϡ�
		int SetVertexConstant(int pass, const std::string& name,const ShaderFloatSmartPointer& shaderFloat);

		int SetPixelConstant(int pass, const std::string& name,const ShaderFloatSmartPointer& shaderFloat);

		int SetVertexTexture(int pass, const std::string& name,const TextureSmartPointer& texture);

		int SetPixelTexture(int pass, const std::string& name,const TextureSmartPointer& texture);

		// ���������������Set*�����ķ���ֵ��
		void SetVertexConstant(int pass, int handle, const ShaderFloatSmartPointer& shaderFloat);
		void SetPixelConstant(int pass, int handle, const ShaderFloatSmartPointer& shaderFloat);
		void SetVertexTexture(int pass, int handle, const TextureSmartPointer& texture);
		void SetPixelTexture(int pass, int handle, const TextureSmartPointer& texture);

 		const ConstShaderFloatSmartPointer GetVertexConstant(int pass, const std::string& name) const;
		const ConstShaderFloatSmartPointer GetPixelConstant(int pass, const std::string& name) const;
		const ConstTextureSmartPointer GetVertexTexture(int pass, const std::string& name) const;
		const ConstTextureSmartPointer GetPixelTexture(int pass, const std::string& name) const;

		const ConstShaderFloatSmartPointer GetVertexConstant(int pass, int handle) const;
		const ConstShaderFloatSmartPointer GetPixelConstant(int pass, int handle) const;
		const ConstTextureSmartPointer GetVertexTexture(int pass, int handle) const;
		const ConstTextureSmartPointer GetPixelTexture(int pass, int handle) const;

	private:
		void Swap( VisualEffectInstanceImpl& rhs);

	private:
		VisualEffectSmartPointer m_Effect;
		int m_TechniqueIndex;
		int m_NumPasses;
		std::vector<ShaderParametersSmartPointer> m_VertexParameters;
		std::vector<ShaderParametersSmartPointer> m_PixelParameters;
	};	 
}
 
#endif // RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_IMPL_H
