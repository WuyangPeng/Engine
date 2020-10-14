// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 15:33)

#ifndef RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_H
#define RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"
#include "VisualTechnique.h"
#include "Rendering/Shaders/ShaderParameters.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/Helper/ExportMacro.h"
 

RENDERING_EXPORT_SHARED_PTR(VisualEffectInstanceImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE VisualEffectInstance : public CoreTools::Object
	{
	public:
             COPY_UNSHARE_CLASSES_TYPE_DECLARE(VisualEffectInstance, DESTRUCTOR_STATEMENT);
		using ParentType = Object;

	public:
		VisualEffectInstance(const VisualEffectSharedPtr& effect, int techniqueIndex); 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VisualEffectInstance);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

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
                ObjectInterfaceSharedPtr CloneObject() const override;
	private:
		IMPL_TYPE_DECLARE(VisualEffectInstance);
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(VisualEffectInstance);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( VisualEffectInstance);
}
  
#endif // RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_H
