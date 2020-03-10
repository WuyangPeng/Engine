// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 09:32)

#ifndef RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING2_H
#define RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING2_H

#include "Rendering/RenderingDll.h"

#include "ImageProcessingBase.h"
#include "Mathematics/Base/Float4.h"

namespace Rendering
{
	class   ImageProcessing2 : public ImageProcessingBase
	{
	public:
		// Construction and destruction.  Objects of this class should not be
		// instantiated until the shader profile is known.  Thus, do not create
		// such an object in an application constructor, but do so in
		// OnInitialize or later.

		// Use this constructor for the standard image processing pipeline.
		ImageProcessing2 (int bound0, int bound1,Mathematics:: Float4* imageData, PixelShaderSmartPointer mainPShader, bool useDirichlet);

		// Use this constructor when you want to set up your own pipeline for
		// processing the image.
		ImageProcessing2 (int bound0, int bound1, int numTargets);

		virtual ~ImageProcessing2 ();

		// Member access.
		int GetBound0 () const;
		int GetBound1 () const;
		float GetDx () const;
		float GetDy () const;

		// Create a texture corresponding to the 2D image data.
		Texture2DSmartPointer CreateImage (Mathematics::Float4* imageData);

		// Set boundary pixels to (0,0,0,0).
		void CreateBoundaryDirichletEffect (VisualEffectSmartPointer& effect, VisualEffectInstanceSmartPointer& instance);

		// Set boundary pixels so that boundary derivatives are zero.
		void CreateBoundaryNeumannEffect (VisualEffectSmartPointer& effect, VisualEffectInstanceSmartPointer& instance);

		// Draw the image.
		void CreateDrawEffect (VisualEffectSmartPointer& effect,VisualEffectInstanceSmartPointer& instance);

	private:
		void CreateVertexShader ();

		int mBound0, mBound1, mBound0M1, mBound1M1;
		float mDx, mDy;

		// Profile information for BoundaryDirichlet.fx.
		static int msAllDirichletPTextureUnits[2];
		static int* msDirichletPTextureUnits[ShaderFlags::MaxProfiles];
		static std::string msDirichletPPrograms[ShaderFlags::MaxProfiles];

		// Profile information for BoundaryNeumann.fx.
		static int msAllNeumannPTextureUnits[2];
		static int* msNeumannPTextureUnits[ShaderFlags::MaxProfiles];
		static std::string msNeumannPPrograms[ShaderFlags::MaxProfiles];

		// Profile information for ScreenShader.fx, function v_ScreenShader and
		// p_ScreenShader2.
		static int msAllDrawPTextureUnits[2];
		static int* msDrawPTextureUnits[ShaderFlags::MaxProfiles];
		static std::string msDrawPPrograms[ShaderFlags::MaxProfiles];
	};
}

#endif // RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING2_H
