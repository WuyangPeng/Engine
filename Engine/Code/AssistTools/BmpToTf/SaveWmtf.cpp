// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:16)

#include "AssistTools/AssistToolsExport.h"

#include "SaveWmtf.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "Rendering/Resources/Texture2D.h"
#include "System/Helper/PragmaWarning/Disable4996.h"

#include <windows.h>

#include "System/Helper/PragmaWarning.h"
#include "System/Helper/EnumCast.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26485)
AssistTools::SaveWmtf
	::SaveWmtf(const char* name, int width, int height, const unsigned char* texels)
{
	Rendering::Texture2D* texture = CoreTools::New0< Rendering::Texture2D>(Rendering::TextureFormat::A8R8G8B8, width,	height, 1);

const	int format = System::EnumCastUnderlying(texture->GetFormat());
const int type = System::EnumCastUnderlying(texture->GetTextureType());
const int usage = System::EnumCastUnderlying(texture->GetUsage());
const int numLevels = texture->GetNumLevels();
const int numDimensions = texture->GetNumDimensions();
const int numTotalBytes = texture->GetNumTotalBytes();

int dimension[3][Rendering::TextureMaximumMipmapLevels]{ };
  int numLevelBytes[Rendering::TextureMaximumMipmapLevels]{ };
  int levelOffsets[Rendering::TextureMaximumMipmapLevels]{ };
	for (int level = 0; level < Rendering::TextureMaximumMipmapLevels; ++level)
	{
		dimension[0][level] = texture->GetDimension(0, level);
		dimension[1][level] = texture->GetDimension(1, level);
		dimension[2][level] = texture->GetDimension(2, level);
		numLevelBytes[level] = texture->GetNumLevelBytes(level);
		levelOffsets[level] = texture->GetLevelOffset(level);
	}

	int userField[Rendering::TextureMaxUserFields]{ };
	for (int i = 0; i < Rendering::TextureMaxUserFields; ++i)
	{
		userField[i] = 0;
	}
	 
	FILE* outFile = fopen(name, "wb");
	if (!outFile)
	{
		assert(outFile);
		//DELETE1(texels);
		DELETE0(texture);
		return;
	}
	fwrite(&format, sizeof(int), 1, outFile);
	fwrite(&type, sizeof(int), 1, outFile);
	fwrite(&usage, sizeof(int), 1, outFile);
	fwrite(&numLevels, sizeof(int), 1, outFile);
	fwrite(&numDimensions, sizeof(int), 1, outFile);
	fwrite(dimension[0], sizeof(int), Rendering::TextureMaximumMipmapLevels,outFile);
	fwrite(dimension[1], sizeof(int), Rendering::TextureMaximumMipmapLevels,outFile);
	fwrite(dimension[2], sizeof(int), Rendering::TextureMaximumMipmapLevels,outFile);
	fwrite(numLevelBytes, sizeof(int), Rendering::TextureMaximumMipmapLevels,outFile);
	fwrite(&numTotalBytes, sizeof(int), 1, outFile);
	fwrite(levelOffsets, sizeof(int), Rendering::TextureMaximumMipmapLevels,outFile);
	fwrite(userField, sizeof(int), Rendering::TextureMaxUserFields, outFile);
	fwrite(texels, sizeof(unsigned char), numLevelBytes[0], outFile);
	fclose(outFile);

//	DELETE1(texels);
	DELETE0(texture);
}
 #include STSTEM_WARNING_POP