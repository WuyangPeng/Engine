///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/24 18:12)

#include "Rendering/RenderingExport.h"

#include "VisualProgramImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLVisualProgram.h"
#include "Rendering/Shaders/Shader.h"

using std::string;
using std::vector;

Rendering::VisualProgramImpl::VisualProgramSharedPtr Rendering::VisualProgramImpl::Create(OpenGLUInt programHandle, OpenGLUInt vertexShaderHandle, OpenGLUInt pixelShaderHandle, OpenGLUInt geometryShaderHandle)
{
    return std::make_shared<GLSLVisualProgram>(programHandle, vertexShaderHandle, pixelShaderHandle, geometryShaderHandle);
}

Rendering::VisualProgramImpl::VisualProgramImpl() noexcept
    : vertexShader{}, pixelShader{}, geometryShader{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualProgramImpl)

Rendering::VisualProgramImpl::ConstShaderSharedPtr Rendering::VisualProgramImpl::GetVertexShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexShader.object;
}

Rendering::VisualProgramImpl::ConstShaderSharedPtr Rendering::VisualProgramImpl::GetPixelShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return pixelShader.object;
}

Rendering::VisualProgramImpl::ConstShaderSharedPtr Rendering::VisualProgramImpl::GetGeometryShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return geometryShader.object;
}

Rendering::VisualProgramImpl::ShaderSharedPtr Rendering::VisualProgramImpl::GetVertexShader() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexShader.object;
}

Rendering::VisualProgramImpl::ShaderSharedPtr Rendering::VisualProgramImpl::GetPixelShader() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return pixelShader.object;
}

Rendering::VisualProgramImpl::ShaderSharedPtr Rendering::VisualProgramImpl::GetGeometryShader() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return geometryShader.object;
}

void Rendering::VisualProgramImpl::SetVertexShader(const ShaderSharedPtr& shader)
{
    RENDERING_CLASS_IS_VALID_9;

    if (shader->GetType() != GraphicsObjectType::VertexShader)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入必须是顶点着色器。"));
    }

    vertexShader.object = shader;
}

void Rendering::VisualProgramImpl::SetPixelShader(const ShaderSharedPtr& shader)
{
    RENDERING_CLASS_IS_VALID_9;

    if (shader->GetType() != GraphicsObjectType::PixelShader)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入必须是像素着色器。"));
    }

    pixelShader.object = shader;
}

void Rendering::VisualProgramImpl::SetGeometryShader(const ShaderSharedPtr& shader)
{
    RENDERING_CLASS_IS_VALID_9;

    if (shader->GetType() != GraphicsObjectType::GeometryShader)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入必须是几何着色器。"));
    }

    geometryShader.object = shader;
}

int Rendering::VisualProgramImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(vertexShader);

    size += CoreTools::GetStreamSize(pixelShader);
    size += CoreTools::GetStreamSize(geometryShader);

    return size;
}

void Rendering::VisualProgramImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociated(vertexShader);
    target.WriteObjectAssociated(pixelShader);
    target.WriteObjectAssociated(geometryShader);
}

void Rendering::VisualProgramImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociated(vertexShader);
    source.ReadObjectAssociated(pixelShader);
    source.ReadObjectAssociated(geometryShader);
}

void Rendering::VisualProgramImpl::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(vertexShader);
    source.ResolveLink(pixelShader);
    source.ResolveLink(geometryShader);
}

void Rendering::VisualProgramImpl::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Register(vertexShader);
    target.Register(pixelShader);
    target.Register(geometryShader);
}

Rendering::GLSLReflection Rendering::VisualProgramImpl::GetReflector() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GLSLReflection{ 0 };
}

Rendering::VisualProgramImpl::VisualProgramSharedPtr Rendering::VisualProgramImpl::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectSharedPtr Rendering::VisualProgramImpl::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto result = vertexShader->GetObjectByName(name);
    if (!result->IsNullObject())
    {
        return result;
    }

    result = pixelShader->GetObjectByName(name);
    if (!result->IsNullObject())
    {
        return result;
    }

    return geometryShader->GetObjectByName(name);
}

Rendering::VisualProgramImpl::ObjectSharedPtrContainer Rendering::VisualProgramImpl::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto result = vertexShader->GetAllObjectsByName(name);

    auto pixelResult = pixelShader->GetAllObjectsByName(name);
    result.insert(result.end(), pixelResult.begin(), pixelResult.end());

    auto geometryResult = geometryShader->GetAllObjectsByName(name);
    result.insert(result.end(), geometryResult.begin(), geometryResult.end());

    return result;
}

CoreTools::ConstObjectSharedPtr Rendering::VisualProgramImpl::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto result = vertexShader->GetConstObjectByName(name);
    if (!result->IsNullObject())
    {
        return result;
    }

    result = pixelShader->GetConstObjectByName(name);
    if (!result->IsNullObject())
    {
        return result;
    }

    return geometryShader->GetConstObjectByName(name);
}

Rendering::VisualProgramImpl::ConstObjectSharedPtrContainer Rendering::VisualProgramImpl::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto result = vertexShader->GetAllConstObjectsByName(name);

    auto pixelResult = pixelShader->GetAllConstObjectsByName(name);
    result.insert(result.end(), pixelResult.begin(), pixelResult.end());

    auto geometryResult = geometryShader->GetAllConstObjectsByName(name);
    result.insert(result.end(), geometryResult.begin(), geometryResult.end());

    return result;
}
