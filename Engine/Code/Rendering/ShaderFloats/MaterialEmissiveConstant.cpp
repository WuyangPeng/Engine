///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/08 14:47)

#include "Rendering/RenderingExport.h"

#include "MaterialEmissiveConstant.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, MaterialEmissiveConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, MaterialEmissiveConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, MaterialEmissiveConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, MaterialEmissiveConstant);

Rendering::MaterialEmissiveConstant::MaterialEmissiveConstant(const MaterialSharedPtr& material)
    : ParentType{ material }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, MaterialEmissiveConstant)

void Rendering::MaterialEmissiveConstant::Update(MAYBE_UNUSED const Visual* visual, MAYBE_UNUSED const Camera* camera)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto colour = GetMaterial()->GetEmissive();
    SetRegister(0, colour);
}

Rendering::ShaderFloatSharedPtr Rendering::MaterialEmissiveConstant::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
