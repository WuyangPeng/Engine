///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 15:53)

#include "Rendering/RenderingExport.h"

#include "ShaderParameters.h"
#include "Detail/ShaderParametersImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;
using std::string;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ShaderParameters)

CORE_TOOLS_RTTI_DEFINE(Rendering, ShaderParameters);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ShaderParameters);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ShaderParameters);

Rendering::ShaderParameters::ShaderParameters(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, ShaderParameters)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, ShaderParameters)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, ShaderParameters)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, ShaderParameters)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, ShaderParameters)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, ShaderParameters)

Rendering::ShaderParameters::ShaderParameters(const ConstShaderBaseSharedPtr& shader)
    : ParentType{ "ShaderParameters" }, impl{ shader }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ShaderParameters)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderParameters, GetNumConstants, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderParameters, GetNumTextures, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderParameters, GetConstants, Rendering::ShaderParameters::ConstShaderFloatSharedPtrGather)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderParameters, GetTextures, Rendering::ShaderParameters::ConstTextureSharedPtrGather)

int Rendering::ShaderParameters::SetConstant(const string& name, const ShaderFloatSharedPtr& shaderFloat)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetConstant(name, shaderFloat);
}

void Rendering::ShaderParameters::SetConstant(int handle, const ShaderFloatSharedPtr& shaderFloat)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetConstant(handle, shaderFloat);
}

int Rendering::ShaderParameters::SetTexture(const string& name, const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetTexture(name, texture);
}

void Rendering::ShaderParameters::SetTexture(int handle, const TextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetTexture(handle, texture);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderParameters, GetConstant, string, Rendering::ConstShaderFloatSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderParameters, GetTexture, string, Rendering::ConstTextureSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderParameters, GetConstant, int, Rendering::ConstShaderFloatSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderParameters, GetTexture, int, Rendering::ConstTextureSharedPtr)

void Rendering::ShaderParameters::UpdateConstants(const Visual* visual, const Camera* camera)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateConstants(visual, camera);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::ShaderParameters::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
