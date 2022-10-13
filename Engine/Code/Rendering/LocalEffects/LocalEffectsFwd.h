///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/25 13:58)

#ifndef RENDERING_LOCAL_EFFECTS_FWD_H
#define RENDERING_LOCAL_EFFECTS_FWD_H

namespace Rendering
{
    class VisualEffect;
    class LightCameraGeometry;

    class DefaultEffect;
    class LightAmbEffect;
    class LightDirPerPixEffect;
    class LightDirPerVerEffect;
    class LightPntPerPixEffect;
    class LightPntPerVerEffect;
    class LightSptPerPixEffect;
    class LightSptPerVerEffect;
    class MaterialEffect;
    class MaterialTextureEffect;
    class Texture1DEffect;
    class Texture2AddEffect;
    class Texture2ColorBlendEffect;
    class Texture2DEffect;
    class Texture2MulEffect;
    class Texture3DEffect;
    class VertexColor3Effect;
    class VertexColor4Effect;
    class VertexColor4TextureEffect;

    class TextEffect;
}

#endif  // RENDERING_LOCAL_EFFECTS_FWD_H