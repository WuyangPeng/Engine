///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:43)

#include "Rendering/RenderingExport.h"

#include "VisualEffectImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Shaders/VisualProgram.h"

Rendering::VisualEffectImpl::VisualEffectImpl(CoreTools::DisableNotThrow disableNotThrow)
    : program{ std::make_shared<VisualProgram>(disableNotThrow) },
      pvwMatrixConstant{ std::make_shared<ConstantBuffer>(CoreTools::GetStreamSize<Matrix4F>(), true) }
{
    SetPVWMatrix(Matrix4F::GetIdentity());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualEffectImpl::VisualEffectImpl(const VisualProgramSharedPtr& visualProgram)
    : program{ visualProgram }, pvwMatrixConstant{ std::make_shared<ConstantBuffer>(CoreTools::GetStreamSize<Matrix4F>(), true) }
{
    SetPVWMatrix(Matrix4F::GetIdentity());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualEffectImpl)

int Rendering::VisualEffectImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return program->GetStreamingSize() + CoreTools::GetStreamSize(pvwMatrixConstant);
}

void Rendering::VisualEffectImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    program->Save(target);
    target.WriteObjectAssociated(pvwMatrixConstant);
}

void Rendering::VisualEffectImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    program->Load(source);
    source.ReadObjectAssociated(pvwMatrixConstant);
}

void Rendering::VisualEffectImpl::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    program->Link(source);
    source.ResolveLink(pvwMatrixConstant);
}

void Rendering::VisualEffectImpl::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    program->Register(target);
    target.Register(pvwMatrixConstant);
}

CoreTools::ObjectSharedPtr Rendering::VisualEffectImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto result = program->GetObjectByName(name);
    if (!result->IsNullObject())
    {
        return result;
    }

    return pvwMatrixConstant->GetObjectByName(name);
}

Rendering::VisualEffectImpl::ObjectSharedPtrContainer Rendering::VisualEffectImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto result = program->GetAllObjectsByName(name);

    auto pvwMatrixConstantResult = pvwMatrixConstant->GetAllObjectsByName(name);
    result.insert(result.end(), pvwMatrixConstantResult.begin(), pvwMatrixConstantResult.end());

    return result;
}

CoreTools::ConstObjectSharedPtr Rendering::VisualEffectImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto result = program->GetConstObjectByName(name);
    if (!result->IsNullObject())
    {
        return result;
    }

    return pvwMatrixConstant->GetConstObjectByName(name);
}

Rendering::VisualEffectImpl::ConstObjectSharedPtrContainer Rendering::VisualEffectImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto result = program->GetAllConstObjectsByName(name);

    auto pvwMatrixConstantResult = pvwMatrixConstant->GetAllConstObjectsByName(name);
    result.insert(result.end(), pvwMatrixConstantResult.begin(), pvwMatrixConstantResult.end());

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

void Rendering::VisualEffectImpl::SetPVWMatrixConstant(const ConstantBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    pvwMatrixConstant.object = buffer;
    SetPVWMatrix(Matrix4F::GetIdentity());
}

Rendering::VisualEffectImpl::ConstConstantBufferSharedPtr Rendering::VisualEffectImpl::GetPVWMatrixConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return pvwMatrixConstant.object;
}

void Rendering::VisualEffectImpl::SetPVWMatrix(const Matrix4F& pvwMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    auto data = pvwMatrixConstant->GetData();

    const auto container = pvwMatrix.GetContainer();
    for (const auto& value : container)
    {
        data.Increase<float>(value);
    }
}

Rendering::VisualEffectImpl::Matrix4F Rendering::VisualEffectImpl::GetPVWMatrix() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto data = pvwMatrixConstant->GetData();

    Matrix4F::ContainerType container{};
    for (auto i = 0; i < Matrix4F::matrixSize; ++i)
    {
        container.emplace_back(data.Increase<float>());
    }

    return Matrix4F{ container, Mathematics::MatrixMajorFlags::Row };
}