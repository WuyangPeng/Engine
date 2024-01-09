/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 19:07)

#ifndef RENDERING_LOCAL_EFFECTS_FWD_H
#define RENDERING_LOCAL_EFFECTS_FWD_H

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
}

#endif  // RENDERING_LOCAL_EFFECTS_FWD_H