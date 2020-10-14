// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 15:27)

#ifndef RENDERING_SHADERS_SINGLE_SHADER_BASE_DATA_H
#define RENDERING_SHADERS_SINGLE_SHADER_BASE_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

#include <string>
#include "CoreTools/ObjectSystems/BufferTarget.h"

RENDERING_EXPORT_SHARED_PTR(SingleShaderBaseDataImpl);

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;		
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE SingleShaderBaseData
	{	
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(SingleShaderBaseData);
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
	
	public:		
		SingleShaderBaseData();
		SingleShaderBaseData (const std::string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic);	

		CLASS_INVARIANT_DECLARE;

		void SetData (const std::string& name,ShaderFlags::VariableType type,ShaderFlags::VariableSemantic semantic);		
		
		const std::string GetName () const;
		ShaderFlags::VariableType GetType () const noexcept;
                ShaderFlags::VariableSemantic GetSemantic() const noexcept;	

		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save (const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize () const;
		
	private:
		IMPL_TYPE_DECLARE(SingleShaderBaseData);
	};
}

#endif // RENDERING_SHADERS_SINGLE_SHADER_BASE_DATA_H
