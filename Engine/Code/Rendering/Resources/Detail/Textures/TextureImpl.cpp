/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/29 14:30)

#include "Rendering/RenderingExport.h"

#include "TextureImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Base/BitHacksDetail.h"

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

int Rendering::TextureImpl::GetNumLevels(int dim0, int dim1, int dim2, bool hasMipMaps)
{
    if (hasMipMaps)
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

int Rendering::TextureImpl::GetTotalElements(int numItems, int dim0, int dim1, int dim2, bool hasMipMaps)
{
    auto numElementsPerItem = dim0 * dim1 * dim2;
    if (hasMipMaps)
    {
        const auto numLevels = GetNumLevels(dim0, dim1, dim2, hasMipMaps);
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
