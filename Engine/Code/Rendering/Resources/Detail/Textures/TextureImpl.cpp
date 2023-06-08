///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/15 10:58)

#include "Rendering/RenderingExport.h"

#include "TextureImpl.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Base/BitHacksDetail.h"

#include <vector>

using std::vector;

Rendering::TextureImpl::TextureImpl(DataFormatType format, int numLevels) noexcept
    : textureData{ format, numLevels }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TextureImpl)

Rendering::DataFormatType Rendering::TextureImpl::GetFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureData.GetFormat();
}

int Rendering::TextureImpl::GetNumLevels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureData.GetNumLevels();
}

void Rendering::TextureImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    textureData.Load(source);

    LoadLevelData(source);
}

void Rendering::TextureImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    textureData.Save(target);

    SaveLevelData(target);
}

int Rendering::TextureImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = textureData.GetStreamingSize();

    size += GetLevelDataStreamingSize();

    return size;
}

void Rendering::TextureImpl::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    SaveBaseToFile(outFile);

    textureData.SaveToFile(outFile);
    SaveLevelDataToFile(outFile);
}

void Rendering::TextureImpl::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    textureData.ReadFromFile(inFile);
    LoadLevelDataFromFile(inFile);
}

int Rendering::TextureImpl::GetNumLevels(int dim0, int dim1, int dim2, bool hasMipmaps)
{
    if (hasMipmaps)
    {
        const auto log0 = Mathematics::BitHacks::Log2OfPowerOfTwo(Mathematics::BitHacks::RoundDownToPowerOfTwo(dim0));
        const auto log1 = Mathematics::BitHacks::Log2OfPowerOfTwo(Mathematics::BitHacks::RoundDownToPowerOfTwo(dim1));
        const auto log2 = Mathematics::BitHacks::Log2OfPowerOfTwo(Mathematics::BitHacks::RoundDownToPowerOfTwo(dim2));
        const auto numLevels = 1 + std::max(log0, std::max(log1, log2));

        return numLevels;
    }
    else
    {
        return 1;
    }
}

int Rendering::TextureImpl::GetTotalElements(int numItems, int dim0, int dim1, int dim2, bool hasMipmaps)
{
    auto numElementsPerItem = dim0 * dim1 * dim2;
    if (hasMipmaps)
    {
        const auto numLevels = GetNumLevels(dim0, dim1, dim2, hasMipmaps);
        for (auto level = 1; level < numLevels; ++level)
        {
            if (dim0 > 1)
            {
                dim0 >>= 1;
            }

            if (dim1 > 1)
            {
                dim1 >>= 1;
            }

            if (dim2 > 1)
            {
                dim2 >>= 1;
            }

            numElementsPerItem += dim0 * dim1 * dim2;
        }
    }

    const auto totalElements = numItems * numElementsPerItem;

    return totalElements;
}
