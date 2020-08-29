// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:55)

#ifndef IMAGICS_FILTERS_PDE_FILTER3_H
#define IMAGICS_FILTERS_PDE_FILTER3_H

#include "Imagics/ImagicsDll.h"

#include "PdeFilter.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Imagics
{
	class IMAGICS_DEFAULT_DECLARE PdeFilter3 : public PdeFilter
	{
	public:
		// Abstract base class.
		PdeFilter3 (int xBound, int yBound, int zBound, float xSpacing,float ySpacing, float zSpacing, const float* data,const bool* mask, float borderValue, ScaleType scaleType);
		
		  ~PdeFilter3 ();
		PdeFilter3(const PdeFilter3&) = default;
		PdeFilter3& operator=(const PdeFilter3&) = default;
		PdeFilter3(PdeFilter3&&) = default;
		PdeFilter3& operator=(PdeFilter3&&) = default;
		
		// Member access.  The internal 2D images for "data" and "mask" are
		// copies of the inputs to the constructor but padded with a 1-pixel
		// thick border to support filtering on the image boundary.  These images
		// are of size (xbound+2)-by-(ybound+2)-by-(zbound+2).  The inputs (x,y,z)
		// to GetData and GetMask are constrained to 0 <= x < xbound,
		// 0 <= y < ybound, and 0 <= z < zbound.  The correct lookups into the
		// padded arrays are handled internally.
		int GetXBound () const noexcept;
		int GetYBound () const noexcept;
		int GetZBound () const noexcept;
		float GetXSpacing () const noexcept;
		float GetYSpacing () const noexcept;
		float GetZSpacing () const noexcept;
		
		// Voxel access and derivative estimation.  The lookups into the padded
		// data are handled correctly.  The estimation involves only the
		// 3-by-3-by-3 neighborhood of (x,y,z), where 0 <= x < xbound,
		// 0 <= y < ybound, and 0 <= z < zbound.  [If larger neighborhoods are
		// desired at a later date, the padding and associated code must be
		// adjusted accordingly.]
		float GetU (int x, int y, int z) const noexcept;
		float GetUx (int x, int y, int z) const noexcept;
		float GetUy (int x, int y, int z) const noexcept;
		float GetUz (int x, int y, int z) const noexcept;
		float GetUxx (int x, int y, int z) const noexcept;
		float GetUxy (int x, int y, int z) const noexcept;
		float GetUxz (int x, int y, int z) const noexcept;
		float GetUyy (int x, int y, int z) const noexcept;
		float GetUyz (int x, int y, int z) const noexcept;
		float GetUzz (int x, int y, int z) const noexcept;
		bool GetMask (int x, int y, int z) const noexcept;
		
	protected:
		// Assign values to the 1-voxel image border.
		void AssignDirichletImageBorder () noexcept;
		void AssignNeumannImageBorder () noexcept;
		
		// Assign values to the 1-voxel mask border.
		void AssignDirichletMaskBorder () ;
		void AssignNeumannMaskBorder () noexcept;
		
		// This function recomputes the boundary values when Neumann conditions
		// are used.  If a derived class overrides this, it must call the
		// base-class OnPreUpdate first.
		  void OnPreUpdate () noexcept override;
		
		// Iterate over all the pixels and call OnUpdate(x,y,z) for each voxel
		// that is not masked out.
		  void OnUpdate () override;
		
		// If a derived class overrides this, it must call the base-class
		// OnPostUpdate last.  The base-class function swaps the buffers for the
		// next pass.
                  void OnPostUpdate() noexcept override;
		
		// The per-pixel processing depends on the PDE algorithm.  The (x,y,z)
		// must be in padded coordinates: 1 <= x <= xbound, 1 <= y <= ybound, and
		// 1 <= z <= zbound.
		virtual void OnUpdate (int x, int y, int z) = 0;
		
		// Copy source data to temporary storage.
		void LookUp7 (int x, int y, int z) noexcept;
		void LookUp27 (int x, int y, int z) noexcept;
		
		// Image parameters.
		int mXBound, mYBound, mZBound;
		float mXSpacing;       // dx
		float mYSpacing;       // dy
		float mZSpacing;       // dz
		float mInvDx;          // 1/dx
		float mInvDy;          // 1/dy
		float mInvDz;          // 1/dz
		float mHalfInvDx;      // 1/(2*dx)
		float mHalfInvDy;      // 1/(2*dy)
		float mHalfInvDz;      // 1/(2*dz)
		float mInvDxDx;        // 1/(dx*dx)
		float mFourthInvDxDy;  // 1/(4*dx*dy)
		float mFourthInvDxDz;  // 1/(4*dx*dz)
		float mInvDyDy;        // 1/(dy*dy)
		float mFourthInvDyDz;  // 1/(4*dy*dz)
		float mInvDzDz;        // 1/(dz*dz)

		// Temporary storage for 3x3x3 neighborhood.
		float mUmmm, mUzmm, mUpmm;
		float mUmzm, mUzzm, mUpzm;
		float mUmpm, mUzpm, mUppm;
		float mUmmz, mUzmz, mUpmz;
		float mUmzz, mUzzz, mUpzz;
		float mUmpz, mUzpz, mUppz;
		float mUmmp, mUzmp, mUpmp;
		float mUmzp, mUzzp, mUpzp;
		float mUmpp, mUzpp, mUppp;

		// Successive iterations toggle between two buffers.
		float*** mSrc;
		float*** mDst;
		bool*** mMask;
	};
}
#include STSTEM_WARNING_POP
#endif // IMAGICS_FILTERS_PDE_FILTER3_H
