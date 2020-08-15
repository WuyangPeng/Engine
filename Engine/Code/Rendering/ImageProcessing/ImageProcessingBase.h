// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 09:40)

#ifndef RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING_BASE_H
#define RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING_BASE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"
#include "Rendering/Resources/RenderTarget.h"
#include "Rendering/ShaderFloats/ProjectionViewWorldMatrixConstant.h" 

namespace Rendering
{
	class Renderer;

	class  ImageProcessingBase
	{
	public:
		// Construction and destruction.
		ImageProcessingBase(int numCols, int numRows, int numTargets);
		virtual ~ImageProcessingBase();
		ImageProcessingBase(const ImageProcessingBase&)=default;
		ImageProcessingBase& operator=(const ImageProcessingBase&)=default;
		ImageProcessingBase(ImageProcessingBase&&)=default;
		ImageProcessingBase& operator=(ImageProcessingBase&&)=default;

		// Member access.
		 int GetNumCols() const noexcept;
		 int GetNumRows() const noexcept;
		 int GetNumTargets() const noexcept;
		 float GetColSpacing() const noexcept;
		 float GetRowSpacing() const noexcept;
		 const Camera* GetCamera() const noexcept;
		 const TrianglesMesh* GetRectangle() const noexcept;
		 const RenderTarget* GetTarget(int i) const noexcept;

		// The lexicographical mapping into linear memory.
		 int Index(int col, int row) const noexcept; 

		// Allow the caller to create an effect that shares the vertex shader
		// managed by this class.
		 void CreateEffect(PixelShaderSmartPointer pshader, VisualEffectSmartPointer& effect,
			VisualEffectInstanceSmartPointer& instance);

		// These function calls bound the drawing of the processed image to the
		// backbuffer.
		void PreDraw();
		void PostDraw();

		// Support for the standard image processing pipeline.
		const Texture2D* GetMainTexture() const noexcept;
		 const VisualEffectInstance* GetMainEffectInstance() const noexcept;
		void Initialize(Renderer* renderer, bool openglHack = false);
		void ExecuteStep(Renderer* renderer, bool draw);

	protected:
		void CreateVertexShader();

		int mNumCols, mNumRows, mNumColsM1, mNumRowsM1;
		int mNumTargets;
		float mColSpacing, mRowSpacing;
		CameraSmartPointer mCamera;
		TrianglesMeshSmartPointer mRectangle;
		VertexShaderSmartPointer mVertexShader;
		ProjectionViewWorldMatrixConstantSmartPointer mPVWMatrixConstant;
		RenderTargetSmartPointer* mTargets;

		// Support for the standard image processing pipeline.
		Texture2DSmartPointer mMainTexture;
		VisualEffectSmartPointer mMainEffect;
		VisualEffectInstanceSmartPointer mMainEffectInstance;
		VisualEffectSmartPointer mBoundaryEffect;
		VisualEffectInstanceSmartPointer mBoundaryEffectInstance;
		VisualEffectSmartPointer mDrawEffect;
		VisualEffectInstanceSmartPointer mDrawEffectInstance;
		VisualEffectSmartPointer mDrawInput;
		VisualEffectInstanceSmartPointer mDrawInputInstance;

		static int msDx9VRegisters[1];
		static int msOglVRegisters[1];
		static int* msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
		static std::string msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
	};
}

#endif // RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING_BASE_H
