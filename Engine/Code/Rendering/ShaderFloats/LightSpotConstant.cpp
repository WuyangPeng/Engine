// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 17:59)

#include "Rendering/RenderingExport.h"

#include "LightSpotConstant.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
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

void Rendering::LightSpotConstant::Update([[maybe_unused]] const Visual* visual, [[maybe_unused]] const Camera* camera)
{
    RENDERING_CLASS_IS_VALID_1;

    auto light = GetLight();

    vector<float> data{ light->GetAngle(), light->GetCosAngle(), light->GetSinAngle(), light->GetExponent() };

    SetRegister(0, data);

    ;
}

Rendering::ShaderFloatSharedPtr Rendering::LightSpotConstant::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ShaderFloatSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP