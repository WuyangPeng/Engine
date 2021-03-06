// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/30 16:23)

#ifndef IMAGICS_RASTER_DRAWING_FAST_MARCH2_H
#define IMAGICS_RASTER_DRAWING_FAST_MARCH2_H

#include "Imagics/ImagicsDll.h"

#include "FastMarch.h"

namespace Imagics
{
	class IMAGICS_HIDDEN_DECLARE FastMarch2 : public FastMarch
	{
	public:
		// Construction and destruction.
		FastMarch2 (int xBound, int yBound, float xSpacing, float ySpacing,const float* speeds, const std::vector<int>& seeds);
		
		FastMarch2 (int xBound, int yBound, float xSpacing, float ySpacing,const float speed, const std::vector<int>& seeds);
		
	 
		
		// Member access.
		int GetXBound () const noexcept;
		int GetYBound () const noexcept;
		float GetXSpacing () const noexcept;
		float GetYSpacing () const noexcept; 
		int Index (int x, int y) const noexcept;
		
		// Pixel classification.
		  void GetBoundary (std::vector<int>& boundary) const override;
                bool IsBoundary(int i) const noexcept override;
		
		// Run one step of the fast marching algorithm.
		  void Iterate () override;
		
	protected:
		// Called by the constructors.
		void Initialize (int xBound, int yBound, float xSpacing, float ySpacing);
		
		// Called by Iterate().
		void ComputeTime (int i);
		
		int mXBound, mYBound, mXBm1, mYBm1;
		float mXSpacing, mYSpacing, mInvXSpacing, mInvYSpacing;
	}; 
}

#endif // IMAGICS_RASTER_DRAWING_FAST_MARCH2_H
