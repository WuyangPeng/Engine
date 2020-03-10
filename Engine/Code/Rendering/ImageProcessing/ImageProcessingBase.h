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

		// Member access.
		 int GetNumCols() const;
		 int GetNumRows() const;
		 int GetNumTargets() const;
		 float GetColSpacing() const;
		 float GetRowSpacing() const;
		 const Camera* GetCamera() const;
		 const TrianglesMesh* GetRectangle() const;
		 const RenderTarget* GetTarget(int i) const;

		// The lexicographical mapping into linear memory.
		 int Index(int col, int row) const;

		// Allow the caller to create an effect that shares the vertex shader
		// managed by this class.
		 void CreateEffect(PixelShaderSmartPointer pshader, VisualEffectSmartPointer& effect,
			VisualEffectInstanceSmartPointer& instance);

		// These function calls bound the drawing of the processed image to the
		// backbuffer.
		void PreDraw();
		void PostDraw();

		// Support for the standard image processing pipeline.
		const Texture2D* GetMainTexture() const;
		 const VisualEffectInstance* GetMainEffectInstance() const;
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
		static int* msVRegisters[ShaderFlags::MaxProfiles];
		static std::string msVPrograms[ShaderFlags::MaxProfiles];
	};
}

#endif // RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING_BASE_H
