///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 18:25)

#include "Rendering/RenderingExport.h"

#include "VisualEffectImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Shaders/ProgramFactory.h"
#include "Rendering/Shaders/ProgramSources.h"
#include "Rendering/Shaders/VisualProgram.h"

Rendering::VisualEffectImpl::VisualEffectImpl(CoreTools::DisableNotThrow disableNotThrow)
    : program{ std::make_shared<VisualProgram>(VisualProgram::Create()) },
      baseRenderer{},
      projectionViewWorldMatrixConstant{ std::make_shared<ConstantBuffer>(Mathematics::GetStreamSize<Matrix4>(), true) }
{
    System::UnusedFunction(disableNotThrow);

    SetProjectionViewWorldMatrix(Matrix4::GetIdentity());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffectImpl::VisualEffectImpl(VisualProgramSharedPtr visualProgram)
    : program{ std::move(visualProgram) },
      baseRenderer{},
      projectionViewWorldMatrixConstant{ std::make_shared<ConstantBuffer>(Mathematics::GetStreamSize<Matrix4>(), true) }
{
    SetProjectionViewWorldMatrix(Matrix4::GetIdentity());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffectImpl::VisualEffectImpl(const BaseRendererSharedPtr& baseRenderer)
    : program{ std::make_shared<VisualProgram>(VisualProgram::Create()) },
      baseRenderer{ baseRenderer },
      projectionViewWorldMatrixConstant{ std::make_shared<ConstantBuffer>(Mathematics::GetStreamSize<Matrix4>(), true) }
{
    SetProjectionViewWorldMatrix(Matrix4::GetIdentity());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffectImpl::VisualEffectImpl(const BaseRendererSharedPtr& baseRenderer, VisualProgramSharedPtr visualProgram)
    : program{ std::move(visualProgram) },
      baseRenderer{ baseRenderer },
      projectionViewWorldMatrixConstant{ std::make_shared<ConstantBuffer>(CoreTools::GetStreamSize<Matrix4>(), true) }
{
    SetProjectionViewWorldMatrix(Matrix4::GetIdentity());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffectImpl::VisualEffectImpl(ProgramFactory& factory, const BaseRendererSharedPtr& baseRenderer, const std::string& vertexShaderFile, const std::string& pixelShaderFile)
    : program{ factory.CreateFromFiles(baseRenderer->GetShaderName(vertexShaderFile), baseRenderer->GetShaderName(pixelShaderFile), "") },
      baseRenderer{ baseRenderer },
      projectionViewWorldMatrixConstant{ std::make_shared<ConstantBuffer>(CoreTools::GetStreamSize<Matrix4>(), true) }
{
    SetProjectionViewWorldMatrix(Matrix4::GetIdentity());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualEffectImpl)

int Rendering::VisualEffectImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return program->GetStreamingSize() + Rendering::GetStreamSize(projectionViewWorldMatrixConstant);
}

void Rendering::VisualEffectImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    program->Save(target);
    target.WriteObjectAssociated(projectionViewWorldMatrixConstant);
}

void Rendering::VisualEffectImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    program->Load(source);
    source.ReadObjectAssociated(projectionViewWorldMatrixConstant);
}

void Rendering::VisualEffectImpl::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    program->Link(source);
    source.ResolveLink(projectionViewWorldMatrixConstant);
}

void Rendering::VisualEffectImpl::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    program->Register(target);
    target.Register(projectionViewWorldMatrixConstant);
}

CoreTools::ObjectSharedPtr Rendering::VisualEffectImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    if (auto result = program->GetObjectByName(name);
        !result->IsNullObject())
    {
        return result;
    }

    return projectionViewWorldMatrixConstant->GetObjectByName(name);
}

Rendering::VisualEffectImpl::ObjectSharedPtrContainer Rendering::VisualEffectImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto result = program->GetAllObjectsByName(name);

    auto projectionViewWorldMatrixConstantResult = projectionViewWorldMatrixConstant->GetAllObjectsByName(name);
    result.insert(result.end(), projectionViewWorldMatrixConstantResult.begin(), projectionViewWorldMatrixConstantResult.end());

    return result;
}

CoreTools::ConstObjectSharedPtr Rendering::VisualEffectImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (auto result = program->GetConstObjectByName(name);
        !result->IsNullObject())
    {
        return result;
    }

    return projectionViewWorldMatrixConstant->GetConstObjectByName(name);
}

Rendering::VisualEffectImpl::ConstObjectSharedPtrContainer Rendering::VisualEffectImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto result = program->GetAllConstObjectsByName(name);

    auto projectionViewWorldMatrixConstantResult = projectionViewWorldMatrixConstant->GetAllConstObjectsByName(name);
    result.insert(result.end(), projectionViewWorldMatrixConstantResult.begin(), projectionViewWorldMatrixConstantResult.end());

    return result;
}

void Rendering::VisualEffectImpl::SetBaseRenderer(const BaseRendererSharedPtr& aBaseRenderer) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    baseRenderer = aBaseRenderer;
}

Rendering::VisualEffectImpl::BaseRendererSharedPtr Rendering::VisualEffectImpl::GetBaseRenderer()
{
    RENDERING_CLASS_IS_VALID_9;

    auto result = baseRenderer.lock();

    if (result == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("BaseRenderer 已被释放。"))
    }

    return result;
}

Rendering::VisualEffectImpl::ConstVisualProgramSharedPtr Rendering::VisualEffectImpl::GetProgram() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return program;
}

Rendering::VisualEffectImpl::VisualProgramSharedPtr Rendering::VisualEffectImpl::GetProgram() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return program;
}

Rendering::VisualEffectImpl::ConstShaderSharedPtr Rendering::VisualEffectImpl::GetVertexShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return program->GetVertexShader();
}

Rendering::VisualEffectImpl::ConstShaderSharedPtr Rendering::VisualEffectImpl::GetPixelShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return program->GetPixelShader();
}

Rendering::VisualEffectImpl::ConstShaderSharedPtr Rendering::VisualEffectImpl::GetGeometryShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return program->GetGeometryShader();
}

Rendering::VisualEffectImpl::ShaderSharedPtr Rendering::VisualEffectImpl::GetVertexShader() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return program->GetVertexShader();
}

Rendering::VisualEffectImpl::ShaderSharedPtr Rendering::VisualEffectImpl::GetPixelShader() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return program->GetPixelShader();
}

Rendering::VisualEffectImpl::ShaderSharedPtr Rendering::VisualEffectImpl::GetGeometryShader() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return program->GetGeometryShader();
}

void Rendering::VisualEffectImpl::SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    projectionViewWorldMatrixConstant.object = buffer;
    SetProjectionViewWorldMatrix(Matrix4::GetIdentity());
}

Rendering::VisualEffectImpl::ConstConstantBufferSharedPtr Rendering::VisualEffectImpl::GetProjectionViewWorldMatrixConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return projectionViewWorldMatrixConstant.object;
}

Rendering::VisualEffectImpl::ConstantBufferSharedPtr Rendering::VisualEffectImpl::GetProjectionViewWorldMatrixConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return projectionViewWorldMatrixConstant.object;
}

void Rendering::VisualEffectImpl::SetProjectionViewWorldMatrix(const Matrix4& projectionViewWorldMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    auto data = projectionViewWorldMatrixConstant->GetStorage();

    for (const auto container = projectionViewWorldMatrix.GetContainer();
         const auto& element : container)
    {
        data.Increase<float>(element);
    }
}

Rendering::VisualEffectImpl::Matrix4 Rendering::VisualEffectImpl::GetProjectionViewWorldMatrix() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto data = projectionViewWorldMatrixConstant->GetStorage();

    Matrix4::ContainerType container{};
    for (auto i = 0; i < Matrix4::matrixSize; ++i)
    {
        container.emplace_back(data.Increase<float>());
    }

    return Matrix4{ container, Mathematics::MatrixMajorFlags::Row };
}