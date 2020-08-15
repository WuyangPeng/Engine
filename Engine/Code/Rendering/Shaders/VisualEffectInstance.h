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
#include "CoreTools/Helper/SubclassSmartPointerMacro.h" 

RENDERING_EXPORT_SHARED_PTR(VisualEffectInstanceImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE VisualEffectInstance : public CoreTools::Object
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(VisualEffectInstance);
		using ParentType = Object;

	public:
		VisualEffectInstance(const VisualEffectSmartPointer& effect, int techniqueIndex);
		  ~VisualEffectInstance();
                VisualEffectInstance(VisualEffectInstance&&) noexcept = default;
                  VisualEffectInstance& operator=(VisualEffectInstance&&) noexcept = default;
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VisualEffectInstance);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

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
		IMPL_TYPE_DECLARE(VisualEffectInstance);
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(VisualEffectInstance);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, VisualEffectInstance);
}
  
#endif // RENDERING_SHADERS_VISUAL_EFFECT_INSTANCE_H
