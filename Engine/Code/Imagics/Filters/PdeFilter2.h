// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/30 15:55)

#ifndef IMAGICS_FILTERS_PDE_FILTER2_H
#define IMAGICS_FILTERS_PDE_FILTER2_H

#include "Imagics/ImagicsDll.h"

#include "PdeFilter.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Imagics
{
	class IMAGICS_DEFAULT_DECLARE PdeFilter2 : public PdeFilter
	{
	public:
		// Abstract base class.
		PdeFilter2 (int xBound, int yBound, float xSpacing, float ySpacing,const float* data, const bool* mask, float borderValue,ScaleType scaleType);
		
		  ~PdeFilter2 ();
		  PdeFilter2(const PdeFilter2&) =default;
		  PdeFilter2& operator=(const PdeFilter2&) =default;
		  PdeFilter2(PdeFilter2&&) =default;
		  PdeFilter2& operator=(PdeFilter2&&) =default;
		
		// Member access.  The internal 2D images for "data" and "mask" are
		// copies of the inputs to the constructor but padded with a 1-pixel
		// thick border to support filtering on the image boundary.  These images
		// are of size (xbound+2)-by-(ybound+2).  The inputs (x,y) to GetData and
		// GetMask are constrained to 0 <= x < xbound and 0 <= y < ybound.  The
		// correct lookups into the padded arrays are handled internally.
		int GetXBound () const noexcept;
		int GetYBound () const noexcept;
		float GetXSpacing () const noexcept;
		float GetYSpacing () const noexcept; 
		
		// Pixel access and derivative estimation.  The lookups into the padded
		// data are handled correctly.  The estimation involves only the 3-by-3
		// neighborhood of (x,y), where 0 <= x < xbound and 0 <= y < ybound.
		// [If larger neighborhoods are desired at a later date, the padding and
		// associated code must be adjusted accordingly.]
		float GetU (int x, int y) const noexcept;
		float GetUx (int x, int y) const noexcept;
		float GetUy (int x, int y) const noexcept;
		float GetUxx (int x, int y) const noexcept;
		float GetUxy (int x, int y) const noexcept;
		float GetUyy (int x, int y) const noexcept;
		bool GetMask (int x, int y) const noexcept;

	protected:
		// Assign values to the 1-pixel image border.
		void AssignDirichletImageBorder () noexcept;
		void AssignNeumannImageBorder () noexcept;
		
		// Assign values to the 1-pixel mask border.
		void AssignDirichletMaskBorder ();
		void AssignNeumannMaskBorder () noexcept;
		
		// This function recomputes the boundary values when Neumann conditions
		// are used.  If a derived class overrides this, it must call the
		// base-class OnPreUpdate first.
		  void OnPreUpdate () noexcept override;
		
		// Iterate over all the pixels and call OnUpdate(x,y) for each pixel that
		// is not masked out.
		  void OnUpdate ()  override; 
		
		// If a derived class overrides this, it must call the base-class
		// OnPostUpdate last.  The base-class function swaps the buffers for the
		// next pass.
		  void OnPostUpdate () noexcept override;
		
		// The per-pixel processing depends on the PDE algorithm.  The (x,y) must
		// be in padded coordinates: 1 <= x <= xbound and 1 <= y <= ybound.
		virtual void OnUpdate (int x, int y) = 0;
		
		// Copy source data to temporary storage.
		void LookUp5 (int x, int y) noexcept;
		void LookUp9 (int x, int y) noexcept;
		
		// Image parameters.
		int mXBound, mYBound;
		float mXSpacing;       // dx
		float mYSpacing;       // dy
		float mInvDx;          // 1/dx
		float mInvDy;          // 1/dy
		float mHalfInvDx;      // 1/(2*dx)
		float mHalfInvDy;      // 1/(2*dy)
		float mInvDxDx;        // 1/(dx*dx)
		float mFourthInvDxDy;  // 1/(4*dx*dy)
		float mInvDyDy;        // 1/(dy*dy)
		
		// Temporary storage for 3x3 neighborhood.  In the notation m_fUxy, the
		// x and y indices are in {m,z,p}, referring to subtract 1 (m), no change
		// (z), or add 1 (p) to the appropriate index.
		float mUmm, mUzm, mUpm;
		float mUmz, mUzz, mUpz;
		float mUmp, mUzp, mUpp;
		
		// Successive iterations toggle between two buffers.
		float** mSrc;
		float** mDst;
		bool** mMask;
	};
}
#include STSTEM_WARNING_POP
#endif
