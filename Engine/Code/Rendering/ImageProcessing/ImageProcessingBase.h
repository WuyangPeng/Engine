///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/18 16:46)

#ifndef RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING_BASE_H
#define RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING_BASE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/RenderTarget.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"
#include "Rendering/ShaderFloats/ProjectionViewWorldMatrixConstant.h"

namespace Rendering
{
    class ImageProcessingBase
    {
    public:
        using ClassType = ImageProcessingBase;

    public:
        ImageProcessingBase(int numCols, int numRows, int numTargets);
        virtual ~ImageProcessingBase() noexcept = default;
        ImageProcessingBase(const ImageProcessingBase& rhs) = default;
        ImageProcessingBase& operator=(const ImageProcessingBase& rhs) = default;
        ImageProcessingBase(ImageProcessingBase&& rhs) noexcept = default;
        ImageProcessingBase& operator=(ImageProcessingBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD int GetNumCols() const noexcept;
        NODISCARD int GetNumRows() const noexcept;
        NODISCARD int GetNumTargets() const noexcept;
        NODISCARD float GetColSpacing() const noexcept;
        NODISCARD float GetRowSpacing() const noexcept;
        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;
        NODISCARD ConstTrianglesMeshSharedPtr GetRectangle() const noexcept;
        NODISCARD ConstRenderTargetSharedPtr GetTarget(int i) const;

        NODISCARD int Index(int col, int row) const noexcept;

        void CreateEffect(const PixelShaderSharedPtr& pshader, VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance);

        void PreDraw();
        void PostDraw();

        NODISCARD ConstTexture2DSharedPtr GetMainTexture() const noexcept;
        NODISCARD ConstVisualEffectInstanceSharedPtr GetMainEffectInstance() const noexcept;
        void Initialize(Renderer& renderer, bool openglHack = false);
        void ExecuteStep(Renderer& renderer, bool draw);

    protected:
        void CreateVertexShader();

        void SetMainTexture(const Texture2DSharedPtr& val) noexcept;
        void SetMainEffect(const VisualEffectSharedPtr& val) noexcept;
        void SetMainEffectInstance(const VisualEffectInstanceSharedPtr& val) noexcept;
        void SetBoundaryEffect(const VisualEffectSharedPtr& val) noexcept;
        void SetBoundaryEffectInstance(const VisualEffectInstanceSharedPtr& val) noexcept;
        void SetDrawEffect(const VisualEffectSharedPtr& val) noexcept;
        void SetDrawEffectInstance(const VisualEffectInstanceSharedPtr& val) noexcept;
        NODISCARD TextureSharedPtr GetColorTexture(int index);

    private:
        int numCols;
        int numRows;
        int numColsM1;
        int numRowsM1;
        int numTargets;
        float colSpacing;
        float rowSpacing;
        CameraSharedPtr camera;
        TrianglesMeshSharedPtr rectangle;
        VertexShaderSharedPtr vertexShader;
        ProjectionViewWorldMatrixConstantSharedPtr pvwMatrixConstant;
        std::vector<RenderTargetSharedPtr> renderTargets;

        Texture2DSharedPtr mainTexture;
        VisualEffectSharedPtr mainEffect;
        VisualEffectInstanceSharedPtr mainEffectInstance;
        VisualEffectSharedPtr boundaryEffect;
        VisualEffectInstanceSharedPtr boundaryEffectInstance;
        VisualEffectSharedPtr drawEffect;
        VisualEffectInstanceSharedPtr drawEffectInstance;
        VisualEffectSharedPtr drawInput;
        VisualEffectInstanceSharedPtr drawInputInstance;

        static constexpr auto dx9VRegisters = 0;
        static constexpr auto oglVRegisters = 1;
        static std::array<const int*, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> vRegisters;
        static std::array<std::string, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> vPrograms;
    };
}

#endif  // RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING_BASE_H
