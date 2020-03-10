// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 13:35)

#ifndef RENDERING_RESOURCES_LOAD_TEXTURE_DETAIL_H
#define RENDERING_RESOURCES_LOAD_TEXTURE_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "LoadTexture.h"
#include "Detail/TextureImpl.h"
#include "Detail/TextureData.h"
#include "TextureLevelDataDetail.h"
#include "CoreTools/FileManager/ReadFileManager.h"

template<typename TexturePtrType,int WindowSize>
TexturePtrType Rendering::LoadTexture
	::CreateTexture1DPtr( const TextureData& data,ReadFileManager& inFile)
{
	static_assert(WindowSize == 1,"WindowSize == 1");

	auto numDimensions =	TextureImpl::CalculateNumDimensions (data.GetTextureType()); 
	
	TextureLevelData<WindowSize> levelData{ numDimensions };
	levelData.ReadFromFile(inFile);
	auto dimension0 = levelData.GetDimension(0,0);
	TexturePtrType texture{ NEW0 Texture1D{ data.GetFormat(),dimension0,data.GetNumLevels(), data.GetUsage() } };
	
	texture->ReadFromFile(inFile); 	
	
	return texture;
}

template<typename TexturePtrType,int WindowSize>
TexturePtrType Rendering::LoadTexture
	::CreateTexture2DPtr( const TextureData& data,ReadFileManager& inFile)
{
	static_assert(WindowSize == 2, "WindowSize == 2");

	auto numDimensions = TextureImpl::CalculateNumDimensions (data.GetTextureType());
	
	TextureLevelData<WindowSize> levelData{ numDimensions };
	levelData.ReadFromFile(inFile);
	auto dimension0 = levelData.GetDimension(0,0);
	auto dimension1 = levelData.GetDimension(1,0);
	TexturePtrType texture{ NEW0 Texture2D{ data.GetFormat(),dimension0, dimension1,data.GetNumLevels(),data.GetUsage() } };
	
	texture->ReadFromFile(inFile); 	
	
	return texture;
}

template<typename TexturePtrType,int WindowSize>
TexturePtrType Rendering::LoadTexture
	::CreateTexture3DPtr( const TextureData& data, ReadFileManager& inFile )
{
	static_assert(WindowSize == 3, "WindowSize == 3");

	auto numDimensions = TextureImpl::CalculateNumDimensions (data.GetTextureType()); 
	
	TextureLevelData<WindowSize> levelData{ numDimensions };
	levelData.ReadFromFile(inFile);
	auto dimension0 = levelData.GetDimension(0,0);
	auto dimension1 = levelData.GetDimension(1,0);
	auto dimension2 = levelData.GetDimension(2,0);
	TexturePtrType texture{ NEW0 Texture3D{ data.GetFormat(),dimension0, dimension1,dimension2,  data.GetNumLevels(), data.GetUsage()} };
	
	texture->ReadFromFile(inFile); 	
	
	return texture;
}

template<typename TexturePtrType,int WindowSize>
TexturePtrType Rendering::LoadTexture
	::CreateTextureCubePtr( const TextureData& data, ReadFileManager& inFile )
{
	static_assert(WindowSize == 2, "WindowSize == 2");

	auto numDimensions = TextureImpl::CalculateNumDimensions (data.GetTextureType()); 
	
	TextureLevelData<WindowSize> levelData{ numDimensions };
	levelData.ReadFromFile(inFile);
	auto dimension = levelData.GetDimension(0,0);
	TexturePtrType texture{ NEW0 TextureCube{ data.GetFormat(),dimension,data.GetNumLevels(),data.GetUsage() } };
	
	texture->ReadFromFile(inFile); 	
	
	return texture;
}

#endif // RENDERING_RESOURCES_LOAD_TEXTURE_DETAIL_H
