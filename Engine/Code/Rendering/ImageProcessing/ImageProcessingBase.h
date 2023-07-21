///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:45)

#ifndef RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING_BASE_H
#define RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING_BASE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Resources/Textures/DrawTarget.h"
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
        NODISCARD ConstDrawTargetSharedPtr GetTarget(int i) const;

        NODISCARD int Index(int col, int row) const noexcept;

        void CreateEffect(VisualEffectSharedPtr& effect) noexcept;

        void PreDraw() noexcept;
        void PostDraw() noexcept;

        NODISCARD ConstTexture2DSharedPtr GetMainTexture() const noexcept;

        void Initialize(BaseRenderer& renderer, bool openglHack = false) noexcept;
        void ExecuteStep(BaseRenderer& renderer, bool draw) noexcept;

    protected:
        void CreateVertexShader();

        void SetMainTexture(const Texture2DSharedPtr& val) noexcept;
        void SetMainEffect(const VisualEffectSharedPtr& val) noexcept;

        void SetBoundaryEffect(const VisualEffectSharedPtr& val) noexcept;

        void SetDrawEffect(const VisualEffectSharedPtr& val) noexcept;

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

        ProjectionViewWorldMatrixConstantSharedPtr pvwMatrixConstant;
        std::vector<DrawTargetSharedPtr> renderTargets;

        Texture2DSharedPtr mainTexture;
        VisualEffectSharedPtr mainEffect;

        VisualEffectSharedPtr boundaryEffect;

        VisualEffectSharedPtr drawEffect;

        VisualEffectSharedPtr drawInput;

        static constexpr auto dx9VRegisters = 0;
        static constexpr auto oglVRegisters = 1;
        static std::array<const int*, 5> vRegisters;
        static std::array<std::string, 5> vPrograms;
    };
}

#endif  // RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING_BASE_H
