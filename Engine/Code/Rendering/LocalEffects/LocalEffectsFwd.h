///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/05 15:27)

#ifndef RENDERING_LOCAL_EFFECTS_FWD_H
#define RENDERING_LOCAL_EFFECTS_FWD_H

namespace Rendering
{
    class Material;
    class Light;
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

    enum class FontType;
    enum class LightType;
}

#endif  // RENDERING_LOCAL_EFFECTS_FWD_H