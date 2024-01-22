/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 09:22)

#ifndef RENDERING_LOCAL_EFFECTS_FWD_H
#define RENDERING_LOCAL_EFFECTS_FWD_H

#include "CoreTools/Helper/SharedPtrMacro.h"

namespace Rendering
{
    class Lighting;
    class Material;
    class VisualEffect;
    class LightCameraGeometry;
    class LightEffect;
    class AmbientLightEffect;
    class AreaLightEffect;
    class AreaLightEffectParameters;
    class BumpMapEffect;
    class ConstantColorEffect;
    class CubeMapEffect;
    class DirectionalLightEffect;
    class DirectionalLightTextureEffect;
    class Font;
    class GlossMapEffect;
    class OverlayEffect;
    class PointLightEffect;
    class PointLightTextureEffect;
    class ProjectedTextureEffect;
    class SphereMapEffect;
    class SpotLightEffect;
    class TextEffect;
    class Texture2DEffect;
    class Texture3DEffect;
    class VertexColorEffect;
    class VolumeFogEffect;

    enum class FontType;
    enum class LightType;

    CORE_TOOLS_SHARED_PTR_DECLARE(ConstantColorEffect);
}

#endif  // RENDERING_LOCAL_EFFECTS_FWD_H