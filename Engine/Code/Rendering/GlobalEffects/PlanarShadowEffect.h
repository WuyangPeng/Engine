// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/25 15:29)

#ifndef RENDERING_GLOBAL_EFFECTS_PLANAR_SHADOW_EFFECT_H
#define RENDERING_GLOBAL_EFFECTS_PLANAR_SHADOW_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "GlobalEffect.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Base/Float4.h"
#include "Rendering/LocalEffects/MaterialEffect.h"
#include "Rendering/SceneGraph/Light.h"
#include "Rendering/SceneGraph/Node.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
    class PlanarShadowEffect : public GlobalEffect
    {
    public:
        using ClassType = PlanarShadowEffect;
        using ParentType = GlobalEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(PlanarShadowEffect);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

    public:
        // Construction and destruction.  The number of planes supported depends
        // on the number of stencil bits (256 for an 8-bit stencil buffer).
        PlanarShadowEffect(int numPlanes, Node* shadowCaster);
        ~PlanarShadowEffect();
        PlanarShadowEffect(const PlanarShadowEffect&) = default;
        PlanarShadowEffect& operator=(const PlanarShadowEffect&) = default;
        PlanarShadowEffect(PlanarShadowEffect&&) = default;
        PlanarShadowEffect& operator=(PlanarShadowEffect&&) = default;

        void Draw(std::shared_ptr<Renderer> renderer, VisibleSet& visibleSet) override;

        // Member access.
        int GetNumPlanes() const noexcept;
        void SetPlane(int i, TrianglesMeshSmartPointer plane);
        TrianglesMeshSmartPointer GetPlane(int i) const noexcept;
        void SetProjector(int i, Light* projector) ;
        Light* GetProjector(int i) const noexcept;
        void SetShadowColor(int i, const Mathematics::Float4& shadowColor) noexcept;
        const Mathematics::Float4& GetShadowColor(int i) const noexcept;

    protected:
        bool GetProjectionMatrix(int i, Mathematics::Matrixf& projection);

        int mNumPlanes;
        TrianglesMeshSmartPointer* mPlanes;
        LightSmartPointer* mProjectors;
        Mathematics::Float4* mShadowColors;
        NodeSmartPointer mShadowCaster;  // 可能是数组

        // Global render state for drawing.
        AlphaStateSmartPointer mAlphaState;
        DepthStateSmartPointer mDepthState;
        StencilStateSmartPointer mStencilState;

        // Override effect for drawing the shadows.
        MaterialSmartPointer mMaterial;
        MaterialEffectSmartPointer mMaterialEffect;
        VisualEffectInstanceSmartPointer mMaterialEffectInstance;
    };
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(PlanarShadowEffect);
    CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, PlanarShadowEffect);
#include STSTEM_WARNING_POP

}

#endif  // RENDERING_GLOBAL_EFFECTS_PLANAR_SHADOW_EFFECT_H
