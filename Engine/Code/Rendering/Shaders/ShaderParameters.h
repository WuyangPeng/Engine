// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 15:25)

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

		// 这些函数设定常理/纹理。
		// 如果成功，返回值为非负值，并且是到相应的阵列的索引。
		// 该索引可能会传递到Set*函数具有参数“handle”。
		// 该机制允许您直接通过索引设置，
		// 避免与Set*函数出现与参数“const std::string& name”的名字比较。
		int SetConstant(const std::string& name, const ShaderFloatSmartPointer& shaderFloat);
		int SetTexture(const std::string& name, const TextureSmartPointer& texture);

		// “handle”是上述的Set*函数的返回值。
		void SetConstant(int handle, const ShaderFloatSmartPointer& shaderFloat);
		void SetTexture(int handle, const TextureSmartPointer& texture);

		const ConstShaderFloatSmartPointer GetConstant(const std::string& name) const;
		const ConstTextureSmartPointer GetTexture(const std::string& name) const;

		// “handle”是上述的Set*函数的返回值。
		const ConstShaderFloatSmartPointer GetConstant(int handle) const;
		const ConstTextureSmartPointer GetTexture(int handle) const;

		// 更新着色器常量在绘制调用期间。
		void UpdateConstants(const Visual* visual, const Camera* camera);

	private:
		IMPL_TYPE_DECLARE(ShaderParameters);
	};

	CORE_TOOLS_STREAM_REGISTER(ShaderParameters);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, ShaderParameters);
}

#endif // RENDERING_SHADERS_SHADER_PARAMETERS_H
