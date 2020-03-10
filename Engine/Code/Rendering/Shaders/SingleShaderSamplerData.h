// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:29)

#ifndef RENDERING_SHADERS_SINGLES_SHADER_SAMPLER_DATA_H
#define RENDERING_SHADERS_SINGLES_SHADER_SAMPLER_DATA_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

RENDERING_EXPORT_SHARED_PTR(SingleShaderSamplerDataImpl);

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;		
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE SingleShaderSamplerData
	{	
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(SingleShaderSamplerData);
		using Colour = Colour<float>;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
	
	public:		
		SingleShaderSamplerData();

		CLASS_INVARIANT_DECLARE;
		
		void SetSampler (const std::string& name,ShaderFlags::SamplerType type);
		void SetFilter (ShaderFlags::SamplerFilter filter);
		void SetCoordinate(int dimension, ShaderFlags::SamplerCoordinate coordinate);
		void SetLodBias (float lodBias);
		void SetAnisotropy (float anisotropy);
		void SetBorderColor (const Colour& borderColor);

		const std::string GetSamplerName () const;
		ShaderFlags::SamplerType GetSamplerType () const;
		ShaderFlags::SamplerFilter GetFilter () const;
		ShaderFlags::SamplerCoordinate GetCoordinate(int dimension) const;
		float GetLodBias () const;
		float GetAnisotropy () const;
		Colour GetBorderColor () const;

		void Load (BufferSource& source);
		void Save (BufferTarget& target) const;
		int GetStreamingSize () const;
		
	private:
		IMPL_TYPE_DECLARE(SingleShaderSamplerData);
	};
}

#endif // RENDERING_SHADERS_SINGLES_SHADER_SAMPLER_DATA_H
