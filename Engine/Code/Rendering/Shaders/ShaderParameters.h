// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 15:25)

#ifndef RENDERING_SHADERS_SHADER_PARAMETERS_H
#define RENDERING_SHADERS_SHADER_PARAMETERS_H

#include "Rendering/RenderingDll.h"

#include "ShaderBase.h"
#include "Rendering/Resources/Texture.h"
#include "Rendering/ShaderFloats/ShaderFloat.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"

RENDERING_EXPORT_SHARED_PTR(ShaderParametersImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ShaderParameters : public CoreTools::Object
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(ShaderParameters);
		using ParentType = Object;
		using ConstShaderFloatSmartPointerGather = std::vector<ConstShaderFloatSmartPointer>;
		using ConstTextureSmartPointerGather = std::vector<ConstTextureSmartPointer>;

	public:
		explicit ShaderParameters(const ConstShaderBaseSmartPointer& shader);
		virtual ~ShaderParameters();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ShaderParameters); 

		int GetNumConstants() const;
		int GetNumTextures() const;
		const ConstShaderFloatSmartPointerGather GetConstants() const;
		const ConstTextureSmartPointerGather GetTextures() const;

		// ��Щ�����趨����/����
		// ����ɹ�������ֵΪ�Ǹ�ֵ�������ǵ���Ӧ�����е�������
		// ���������ܻᴫ�ݵ�Set*�������в�����handle����
		// �û���������ֱ��ͨ���������ã�
		// ������Set*���������������const std::string& name�������ֱȽϡ�
		int SetConstant(const std::string& name, const ShaderFloatSmartPointer& shaderFloat);
		int SetTexture(const std::string& name, const TextureSmartPointer& texture);

		// ��handle����������Set*�����ķ���ֵ��
		void SetConstant(int handle, const ShaderFloatSmartPointer& shaderFloat);
		void SetTexture(int handle, const TextureSmartPointer& texture);

		const ConstShaderFloatSmartPointer GetConstant(const std::string& name) const;
		const ConstTextureSmartPointer GetTexture(const std::string& name) const;

		// ��handle����������Set*�����ķ���ֵ��
		const ConstShaderFloatSmartPointer GetConstant(int handle) const;
		const ConstTextureSmartPointer GetTexture(int handle) const;

		// ������ɫ�������ڻ��Ƶ����ڼ䡣
		void UpdateConstants(const Visual* visual, const Camera* camera);

	private:
		IMPL_TYPE_DECLARE(ShaderParameters);
	};

	CORE_TOOLS_STREAM_REGISTER(ShaderParameters);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, ShaderParameters);
}

#endif // RENDERING_SHADERS_SHADER_PARAMETERS_H
