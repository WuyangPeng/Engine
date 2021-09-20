// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:26)

#ifndef RENDERING_SHADERS_SHADER_SAMPLER_DATA_H
#define RENDERING_SHADERS_SHADER_SAMPLER_DATA_H

#include "Rendering/RenderingDll.h"

#include "Flags/ShaderFlags.h"
#include "Rendering/DataTypes/Colour.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>
#include <vector>
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(ShaderSamplerData,ShaderSamplerDataImpl);

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;		
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ShaderSamplerData 
	{	
	public:
            DELAY_COPY_UNSHARED_TYPE_DECLARE(ShaderSamplerData);
		using Colour = Colour<float>;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
	
	public:		
		ShaderSamplerData();
		explicit ShaderSamplerData (int numSamplers);	

		CLASS_INVARIANT_DECLARE;

		void Resize(int number);
		
		void SetSampler (int index, const std::string& name,ShaderFlags::SamplerType type);
		void SetFilter (int index, ShaderFlags::SamplerFilter filter);
		void SetCoordinate(int index, int dimension,ShaderFlags::SamplerCoordinate coordinate);
		void SetLodBias (int index, float lodBias);
		void SetAnisotropy (int index, float anisotropy);
		void SetBorderColor (int index, const Colour& borderColor);

		int GetNumSamplers () const;
		const std::string GetSamplerName (int index) const;
		ShaderFlags::SamplerType GetSamplerType (int index) const;
		ShaderFlags::SamplerFilter GetFilter (int index) const;
		ShaderFlags::SamplerCoordinate GetCoordinate(int index, int dimension) const;
		float GetLodBias (int index) const;
		float GetAnisotropy (int index) const;
		Colour GetBorderColor (int index) const;

		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save (const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize () const;
		
	private:
                PackageType impl;
	};
}

#endif // RENDERING_SHADERS_SHADER_SAMPLER_DATA_H
