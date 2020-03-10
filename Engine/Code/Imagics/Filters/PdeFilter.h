// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/30 15:55)

#ifndef IMAGICS_FILTERS_PDE_FILTER_H
#define IMAGICS_FILTERS_PDE_FILTER_H

#include "Imagics/ImagicsDll.h"

namespace Imagics
{
	class IMAGICS_DEFAULT_DECLARE PdeFilter
	{
	public:
		enum IMAGICS_DEFAULT_DECLARE ScaleType
		{
			// The data is processed as is.
			ST_NONE,
			
			// The data range is d in [min,max].  The scaled values are d'.
			
			// d' = (d-min)/(max-min) in [0,1]
			ST_UNIT,
			
			// d' = -1 + 2*(d-min)/(max-min) in [-1,1]
			ST_SYMMETRIC,
			
			// max > -min:  d' = d/max in [min/max,1]
			// max < -min:  d' = -d/min in [-1,-max/min]
			ST_PRESERVE_ZERO
		};
		
		// The abstract base class for all PDE-based filters.
		virtual ~PdeFilter ();
		
		// Member access.
		int GetQuantity () const;
		float GetBorderValue () const;
		ScaleType GetScaleType () const;
		
		// Access to the time step for the PDE solver.
		void SetTimeStep (float timeStep);
		float GetTimeStep () const;
		
		// This function calls OnPreUpdate, OnUpdate, and OnPostUpdate, in that
		// order.
		void Update ();
		
	protected:
		PdeFilter (int quantity, const float* data, float borderValue,ScaleType scaleType);
		
		// The derived classes for 2D and 3D implement this to recompute the
		// boundary values when Neumann conditions are used.  If derived classes
		// built on top of the 2D or 3D classes implement this also, they must
		// call the base-class OnPreUpdate first.
		virtual void OnPreUpdate () = 0;
		
		// The derived classes for 2D and 3D implement this to iterate over the
		// image elements, updating an element only if it is not masked out.
		virtual void OnUpdate () = 0;
		
		// The derived classes for 2D and 3D implement this to swap the buffers
		// for the next pass.  If derived classes built on top of the 2D or 3D
		// classes implement this also, they must call the base-class OnPostUpdate
		// last. 
		virtual void OnPostUpdate () = 0;
		
		// The number of image elements.
		int mQuantity;
		
		// When set to Mathematics::Mathf::sm_MaxReal, Neumann conditions are in use (zero-valued
		// derivatives on the image border).  Dirichlet conditions are used,
		// otherwise (image is constant on the border).
		float mBorderValue;
		
		// This member stores how the image data was transformed during the
		// constructor call.
		ScaleType mScaleType;
		float mMin, mOffset, mScale;
		
		// The time step for the PDE solver.  The stability of an algorithm
		// depends on the magnitude of the time step, but the magnitude itself
		// depends on the algorithm.
		float mTimeStep;
	};
}

#endif // IMAGICS_FILTERS_PDE_FILTER_H
