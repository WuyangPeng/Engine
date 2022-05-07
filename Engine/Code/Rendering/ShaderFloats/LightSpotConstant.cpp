///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/08 14:37)

#include "Rendering/RenderingExport.h"

#include "LightSpotConstant.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

using std::vector;

CORE_TOOLS_RTTI_DEFINE(Rendering, LightSpotConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightSpotConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightSpotConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, LightSpotConstant);

Rendering::LightSpotConstant::LightSpotConstant(const LightSharedPtr& light)
    : ParentType{ light }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, LightSpotConstant)

void Rendering::LightSpotConstant::Update(MAYBE_UNUSED const Visual* visual, MAYBE_UNUSED const Camera* camera)
{
    RENDERING_CLASS_IS_VALID_1;

    auto light = GetLight();

    vector<float> data{ light->GetAngle(), light->GetCosAngle(), light->GetSinAngle(), light->GetExponent() };

    SetRegister(0, data);
}

Rendering::ShaderFloatSharedPtr Rendering::LightSpotConstant::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
