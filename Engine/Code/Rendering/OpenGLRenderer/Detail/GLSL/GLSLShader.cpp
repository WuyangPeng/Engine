/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 17:12)

#include "Rendering/RenderingExport.h"

#include "GLSLShader.h"
#include "System/Helper/PragmaWarning/PolymorphicCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Resources/Buffers/RawBuffer.h"
#include "Rendering/Resources/Buffers/StructuredBuffer.h"
#include "Rendering/Resources/Buffers/TextureBuffer.h"
#include "Rendering/Resources/Flags/CounterType.h"
#include "Rendering/Resources/Flags/UsageType.h"
#include "Rendering/Resources/Textures/TextureArray.h"
#include "Rendering/Resources/Textures/TextureSingle.h"
#include "Rendering/Shaders/Detail/ShaderImplDetail.h"
#include "Rendering/Shaders/Flags/ReferenceType.h"
#include "Rendering/Shaders/Reflection.h"
#include "Rendering/Shaders/ReflectionAtomicCounterBuffer.h"
#include "Rendering/Shaders/ReflectionBufferVariable.h"
#include "Rendering/Shaders/ReflectionDataBlock.h"
#include "Rendering/Shaders/ReflectionUniform.h"
#include "Rendering/State/SamplerState.h"

Rendering::GLSLShader::GLSLShader(const Reflection& reflector, ReferenceType referenceType)
    : ParentType{ CoreTools::DisableNotThrow::Disable }
{
    if (ReferenceType::Compute == referenceType)
    {
        auto size = reflector.GetComputeShaderWorkGroupSize();
        SetNumThreads(size.at(0), size.at(1), size.at(2));
    }

    const auto uniforms = reflector.GetUniforms();

    for (const auto& uniform : uniforms)
    {
        if (uniform.GetReferencedBy(System::EnumCastUnderlying(referenceType)))
        {
            switch (uniform.GetType())
            {
                case System::GLSLReflectionEnumType::Sampler1D:
                case System::GLSLReflectionEnumType::IntSampler1D:
                case System::GLSLReflectionEnumType::UnsignedIntSampler1D:
                {
                    AddLookupData(TextureSingle::GetShaderDataLookup(), GraphicsObjectType::TextureSingle, uniform.GetName(), uniform.GetLocation(), 0, 1, false);
                    AddLookupData(SamplerState::GetShaderDataLookup(), GraphicsObjectType::SamplerState, uniform.GetName(), uniform.GetLocation(), 0, System::EnumCastUnderlying(GraphicsObjectType::Texture1), false);
                    break;
                }

                case System::GLSLReflectionEnumType::Sampler2D:
                case System::GLSLReflectionEnumType::IntSampler2D:
                case System::GLSLReflectionEnumType::UnsignedIntSampler2D:
                {
                    AddLookupData(TextureSingle::GetShaderDataLookup(), GraphicsObjectType::TextureSingle, uniform.GetName(), uniform.GetLocation(), 0, 2, false);
                    AddLookupData(SamplerState::GetShaderDataLookup(), GraphicsObjectType::SamplerState, uniform.GetName(), uniform.GetLocation(), 0, System::EnumCastUnderlying(GraphicsObjectType::Texture2), false);
                    break;
                }

                case System::GLSLReflectionEnumType::Sampler3D:
                case System::GLSLReflectionEnumType::IntSampler3D:
                case System::GLSLReflectionEnumType::UnsignedIntSampler3D:
                {
                    AddLookupData(TextureSingle::GetShaderDataLookup(), GraphicsObjectType::TextureSingle, uniform.GetName(), uniform.GetLocation(), 0, 3, false);
                    AddLookupData(SamplerState::GetShaderDataLookup(), GraphicsObjectType::SamplerState, uniform.GetName(), uniform.GetLocation(), 0, System::EnumCastUnderlying(GraphicsObjectType::Texture3), false);
                    break;
                }

                case System::GLSLReflectionEnumType::Sampler1DArray:
                case System::GLSLReflectionEnumType::IntSampler1DArray:
                case System::GLSLReflectionEnumType::UnsignedIntSampler1DArray:
                {
                    AddLookupData(TextureArray::GetShaderDataLookup(), GraphicsObjectType::TextureArray, uniform.GetName(), uniform.GetLocation(), 0, 1, false);
                    AddLookupData(SamplerState::GetShaderDataLookup(), GraphicsObjectType::SamplerState, uniform.GetName(), uniform.GetLocation(), 0, System::EnumCastUnderlying(GraphicsObjectType::Texture1Array), false);
                    break;
                }

                case System::GLSLReflectionEnumType::Sampler2DArray:
                case System::GLSLReflectionEnumType::IntSampler2DArray:
                case System::GLSLReflectionEnumType::UnsignedIntSampler2DArray:
                {
                    AddLookupData(TextureArray::GetShaderDataLookup(), GraphicsObjectType::TextureArray, uniform.GetName(), uniform.GetLocation(), 0, 2, false);
                    AddLookupData(SamplerState::GetShaderDataLookup(), GraphicsObjectType::SamplerState, uniform.GetName(), uniform.GetLocation(), 0, System::EnumCastUnderlying(GraphicsObjectType::Texture2Array), false);
                    break;
                }

                case System::GLSLReflectionEnumType::SamplerCube:
                case System::GLSLReflectionEnumType::IntSamplerCube:
                case System::GLSLReflectionEnumType::UnsignedIntSamplerCube:
                {
                    AddLookupData(TextureArray::GetShaderDataLookup(), GraphicsObjectType::TextureArray, uniform.GetName(), uniform.GetLocation(), 0, 2, false);
                    AddLookupData(SamplerState::GetShaderDataLookup(), GraphicsObjectType::SamplerState, uniform.GetName(), uniform.GetLocation(), 0, System::EnumCastUnderlying(GraphicsObjectType::TextureCube), false);
                    break;
                }

                case System::GLSLReflectionEnumType::SamplerCubeMapArray:
                case System::GLSLReflectionEnumType::IntSamplerCubeMapArray:
                case System::GLSLReflectionEnumType::UnsignedIntSamplerCubeMapArray:
                {
                    AddLookupData(TextureArray::GetShaderDataLookup(), GraphicsObjectType::TextureArray, uniform.GetName(), uniform.GetLocation(), 0, 3, false);
                    AddLookupData(SamplerState::GetShaderDataLookup(), GraphicsObjectType::SamplerState, uniform.GetName(), uniform.GetLocation(), 0, System::EnumCastUnderlying(GraphicsObjectType::TextureCubeArray), false);
                    break;
                }

                case System::GLSLReflectionEnumType::Image1D:
                case System::GLSLReflectionEnumType::IntImage1D:
                case System::GLSLReflectionEnumType::UnsignedIntImage1D:
                {
                    AddLookupData(TextureSingle::GetShaderDataLookup(), GraphicsObjectType::TextureSingle, uniform.GetName(), uniform.GetLocation(), 0, 1, true);

                    break;
                }

                case System::GLSLReflectionEnumType::Image2D:
                case System::GLSLReflectionEnumType::IntImage2D:
                case System::GLSLReflectionEnumType::UnsignedIntImage2D:
                {
                    AddLookupData(TextureSingle::GetShaderDataLookup(), GraphicsObjectType::TextureSingle, uniform.GetName(), uniform.GetLocation(), 0, 2, true);

                    break;
                }

                case System::GLSLReflectionEnumType::Image3D:
                case System::GLSLReflectionEnumType::IntImage3D:
                case System::GLSLReflectionEnumType::UnsignedIntImage3D:
                {
                    AddLookupData(TextureSingle::GetShaderDataLookup(), GraphicsObjectType::TextureSingle, uniform.GetName(), uniform.GetLocation(), 0, 3, true);

                    break;
                }

                case System::GLSLReflectionEnumType::Image1DArray:
                case System::GLSLReflectionEnumType::IntImage1DArray:
                case System::GLSLReflectionEnumType::UnsignedIntImage1DArray:
                {
                    AddLookupData(TextureArray::GetShaderDataLookup(), GraphicsObjectType::TextureArray, uniform.GetName(), uniform.GetLocation(), 0, 1, true);

                    break;
                }

                case System::GLSLReflectionEnumType::Image2DArray:
                case System::GLSLReflectionEnumType::IntImage2DArray:
                case System::GLSLReflectionEnumType::UnsignedIntImage2DArray:
                {
                    AddLookupData(TextureArray::GetShaderDataLookup(), GraphicsObjectType::TextureArray, uniform.GetName(), uniform.GetLocation(), 0, 2, true);

                    break;
                }

                case System::GLSLReflectionEnumType::ImageCube:
                case System::GLSLReflectionEnumType::IntImageCube:
                case System::GLSLReflectionEnumType::UnsignedIntImageCube:
                {
                    AddLookupData(TextureArray::GetShaderDataLookup(), GraphicsObjectType::TextureArray, uniform.GetName(), uniform.GetLocation(), 0, 2, true);

                    break;
                }

                case System::GLSLReflectionEnumType::ImageCubeMapArray:
                case System::GLSLReflectionEnumType::IntImageCubeMapArray:
                case System::GLSLReflectionEnumType::UnsignedIntImageCubeMapArray:
                {
                    AddLookupData(TextureArray::GetShaderDataLookup(), GraphicsObjectType::TextureArray, uniform.GetName(), uniform.GetLocation(), 0, 3, true);

                    break;
                }

                default:
                {
                    break;
                }
            }
        }
    }

    const auto uniformBlocks = reflector.GetUniformBlocks();
    auto numUniformBlockReferences = 0;
    for (auto const& block : uniformBlocks)
    {
        if (block.GetReferencedBy(System::EnumCastUnderlying(referenceType)))
        {
            ++numUniformBlockReferences;
        }
    }
    if (numUniformBlockReferences > 0)
    {
        ResizeConstantBufferLayouts(numUniformBlockReferences);

        auto blockIndex = 0;
        auto layoutIndex = 0;
        for (auto const& block : uniformBlocks)
        {
            if (block.GetReferencedBy(System::EnumCastUnderlying(referenceType)))
            {
                AddLookupData(ConstantBuffer::GetShaderDataLookup(), GraphicsObjectType::ConstantBuffer, block.GetName(), block.GetBufferBinding(), block.GetBufferDataSize(), 0, false);

                for (const auto& uniform : uniforms)
                {
                    if (uniform.GetBlockIndex() != blockIndex)
                    {
                        continue;
                    }
                    MemberLayout item{ uniform.GetName(), uniform.GetOffset(), (uniform.GetArraySize() > 1 ? uniform.GetArraySize() : 0) };

                    AddConstantBufferLayouts(layoutIndex, item);
                }

                ++layoutIndex;
            }

            ++blockIndex;
        }
    }

    const auto atomicCounterBuffers = reflector.GetAtomicCounterBuffers();
    auto numAtomicCounterBufferReferences = 0;
    for (const auto& block : atomicCounterBuffers)
    {
        if (block.GetReferencedBy(System::EnumCastUnderlying(referenceType)))
        {
            ++numAtomicCounterBufferReferences;
        }
    }
    if (numAtomicCounterBufferReferences > 0)
    {
        auto blockIndex = 0;
        for (const auto& block : atomicCounterBuffers)
        {
            if (block.GetReferencedBy(System::EnumCastUnderlying(referenceType)))
            {
                auto bufferDataSize = block.GetBufferDataSize();
                for (auto i = 0; i < block.GetActiveVariablesCount(); ++i)
                {
                    auto const& ac = uniforms.at(block.GetActiveVariables(i));
                    const auto lastByte = ac.GetOffset() + 4;

                    bufferDataSize = std::max(bufferDataSize, lastByte);
                }

                AddLookupData(System::EnumCastUnderlying(ShaderDataLookup::AtomicCounterBufferShaderDataLookup), GraphicsObjectType::Resource, "atomicCounterBuffer" + std::to_string(blockIndex), block.GetBufferBinding(), bufferDataSize, 0, true);
            }
            ++blockIndex;
        }
    }

    const auto bufferBlocks = reflector.GetBufferBlocks();
    auto numBufferBlockReferences = 0;
    for (auto const& block : bufferBlocks)
    {
        if (block.GetReferencedBy(System::EnumCastUnderlying(referenceType)))
        {
            ++numBufferBlockReferences;
        }
    }
    if (numBufferBlockReferences > 0)
    {
        const auto& bufferVariables = reflector.GetBufferVariables();
        ResizeStructuredBufferLayouts(numBufferBlockReferences);

        auto blockIndex = 0;
        auto layoutIndex = 0;
        for (auto const& block : bufferBlocks)
        {
            if (block.GetReferencedBy(System::EnumCastUnderlying(referenceType)))
            {
                const auto counterName = block.GetName() + "Counter";
                auto hasAtomicCounter = false;
                auto idAtomicCounter = ~0;
                for (const auto& uniform : uniforms)
                {
                    if ((counterName == uniform.GetName()) && (uniform.GetAtomicCounterBufferIndex() >= 0))
                    {
                        hasAtomicCounter = true;
                        idAtomicCounter = GetStructuredBufferCounter(System::EnumCastUnderlying(ShaderDataLookup::AtomicCounterShaderDataLookup));

                        AddLookupData(System::EnumCastUnderlying(ShaderDataLookup::AtomicCounterShaderDataLookup),
                                      GraphicsObjectType::StructuredBuffer,
                                      uniform.GetName(),
                                      uniform.GetAtomicCounterBufferIndex(),
                                      4,
                                      uniform.GetOffset(),
                                      false);

                        break;
                    }
                }

                auto structSize = 0;
                for (auto v = 0; v < block.GetActiveVariablesCount(); ++v)
                {
                    auto const& bufferVar = bufferVariables.at(block.GetActiveVariables(v));

                    if (bufferVar.GetTopLevelArrayStride() != structSize)
                    {
                        if (0 != structSize)
                        {
                            break;
                        }
                        structSize = bufferVar.GetTopLevelArrayStride();
                    }

                    if (structSize > 0)
                    {
                        MemberLayout item{ bufferVar.GetName(), bufferVar.GetOffset(), (bufferVar.GetArraySize() > 1 ? bufferVar.GetArraySize() : 0) };

                        AddConstantBufferLayouts(layoutIndex, item);
                    }
                }

                AddLookupData(StructuredBuffer::GetShaderDataLookup(),
                              GraphicsObjectType::StructuredBuffer,
                              block.GetName(),
                              block.GetBufferBinding(),
                              structSize,
                              idAtomicCounter,
                              hasAtomicCounter);

                SortConstantBufferLayouts(layoutIndex);

                ++layoutIndex;
            }

            ++blockIndex;
        }
    }

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GLSLShader)

void Rendering::GLSLShader::Set(const std::string& textureName, const TextureSingleSharedPtr& texture, const std::string& samplerName, const SamplerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    // GLSL textureName没有使用
    System::UnusedFunction(textureName);

    ParentType::Set(samplerName, texture);
    ParentType::Set(samplerName, state);
}

void Rendering::GLSLShader::Set(const std::string& textureName, const TextureArraySharedPtr& texture, const std::string& samplerName, const SamplerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    // GLSL textureName没有使用
    System::UnusedFunction(textureName);

    ParentType::Set(samplerName, texture);
    ParentType::Set(samplerName, state);
}

bool Rendering::GLSLShader::IsValid(const ShaderData& goal, const ConstantBuffer* resource) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (!resource)
    {
        return false;
    }

    if (goal.GetType() != GraphicsObjectType::ConstantBuffer)
    {
        return false;
    }

    if (resource->GetNumBytes() >= goal.GetNumBytes())
    {
        return true;
    }

    return false;
}

bool Rendering::GLSLShader::IsValid(const ShaderData& goal, const SamplerState* state) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (!state)
    {
        return false;
    }

    if (goal.GetType() != GraphicsObjectType::SamplerState)
    {
        return false;
    }

    return true;
}

bool Rendering::GLSLShader::IsValid(const ShaderData& goal, const TextureArray* resource) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (!resource)
    {
        return false;
    }

    if (goal.GetType() != GraphicsObjectType::TextureArray)
    {
        return false;
    }

    if (goal.GetExtra() != resource->GetNumDimensions())
    {
        return false;
    }

    return true;
}

bool Rendering::GLSLShader::IsValid(const ShaderData& goal, const TextureSingle* resource) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (!resource)
    {
        return false;
    }

    if (goal.GetType() != GraphicsObjectType::TextureSingle)
    {
        return false;
    }

    if (goal.GetExtra() != resource->GetNumDimensions())
    {
        return false;
    }

    return true;
}

bool Rendering::GLSLShader::IsValid(const ShaderData& goal, const RawBuffer* resource) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (!resource)
    {
        return false;
    }

    if (goal.GetType() != GraphicsObjectType::RawBuffer)
    {
        return false;
    }

    if (goal.IsGpuWritable() && resource->GetUsage() != UsageType::ShaderOutput)
    {
        return false;
    }

    return true;
}

bool Rendering::GLSLShader::IsValid(const ShaderData& goal, const StructuredBuffer* resource) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (!resource)
    {
        return false;
    }

    if (goal.GetType() != GraphicsObjectType::StructuredBuffer)
    {
        return false;
    }

    if (goal.IsGpuWritable() && (CounterType::None == resource->GetCounterType()))
    {
        return false;
    }

    return true;
}

bool Rendering::GLSLShader::IsValid(const ShaderData& goal, const TextureBuffer* resource) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (!resource)
    {
        return false;
    }

    if (goal.GetType() != GraphicsObjectType::TextureBuffer)
    {
        return false;
    }

    if (resource->GetNumBytes() >= goal.GetNumBytes())
    {
        return true;
    }

    return false;
}

Rendering::GLSLShader::ShaderSharedPtr Rendering::GLSLShader::Clone() const
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    return std::make_shared<ClassType>(*this);
}