// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 16:23)

#ifndef IMAGICS_RASTER_DRAWING_FAST_MARCH3_H
#define IMAGICS_RASTER_DRAWING_FAST_MARCH3_H

#include "Imagics/ImagicsDll.h"

#include "FastMarch.h"

namespace Imagics
{
	class IMAGICS_HIDDEN_DECLARE FastMarch3 : public FastMarch
	{
	public:
		// Construction and destruction.
		FastMarch3 (int xBound, int yBound, int zBound, float xSpacing,
                    float ySpacing, float zSpacing, const float* speeds,
					const std::vector<int>& seeds);
		
		FastMarch3 (int xBound, int yBound, int zBound, float xSpacing,
                    float ySpacing, float zSpacing, const float speed,
					const std::vector<int>& seeds);
		
	 
		
		// Member access.
		int GetXBound () const noexcept; 
		int GetYBound () const noexcept;
		int GetZBound () const noexcept;
		float GetXSpacing () const noexcept;
		float GetYSpacing () const noexcept;
		float GetZSpacing () const noexcept;
		int Index (int x, int y, int z) const noexcept;
		
		// Voxel classification.
		  void GetBoundary (std::vector<int>& rkBoundary) const override;
                bool IsBoundary(int i) const noexcept override;
		
		// Run one step of the fast marching algorithm.
		  void Iterate () override;
		
	protected:
		// Called by the constructors.
		void Initialize (int xBound, int yBound, int zBound, float xSpacing,float ySpacing, float zSpacing);
		
		// Called by Iterate().
		void ComputeTime (int i);
		
		int mXBound, mYBound, mZBound, mXYBound;
		int mXBm1, mYBm1, mZBm1;
		float mXSpacing, mYSpacing, mZSpacing;
		float mInvXSpacing, mInvYSpacing, mInvZSpacing;
		
		static const float msOneThird;
	};
}

#endif // IMAGICS_RASTER_DRAWING_FAST_MARCH3_H
