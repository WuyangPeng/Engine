// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/30 16:23)

#ifndef IMAGICS_RASTER_DRAWING_FAST_MARCH_H
#define IMAGICS_RASTER_DRAWING_FAST_MARCH_H

#include "Imagics/ImagicsDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/DataTypes/MinHeapDetail.h"

namespace Imagics
{
	class IMAGICS_HIDDEN_DECLARE FastMarch
	{
	public:
		// Abstract base class.
		virtual ~FastMarch ();
		
		// Member access.
		 void SetTime (int i, float time);
		 float GetTime (int i) const;
		 int GetQuantity () const;
		void GetTimeExtremes (float& minValue, float& maxValue) const;
		
		// Image element classification.
		bool IsValid (int i) const;
		bool IsTrial (int i) const;
		bool IsFar (int i) const;
		bool IsZeroSpeed (int i) const;
		bool IsInterior (int i) const;
		void GetInterior (std::vector<int>& interior) const;
		virtual void GetBoundary (std::vector<int>& boundary) const = 0;
		virtual bool IsBoundary (int i) const = 0;
		
		// Run one step of the fast marching algorithm.
		virtual void Iterate () = 0;
		
	protected:
		// Constructors.
		FastMarch (int quantity, const float* speeds,const std::vector<int>& seeds);
		
		FastMarch (int quantity, const float speed, const std::vector<int>& seeds);
		
		// Called by the constructors.
		void Initialize (int quantity, const std::vector<int>& seeds);
		void InitializeSpeed (const float* speeds);
		void InitializeSpeed (const float speed);
		
		int mQuantity;
		float* mInvSpeeds;
		float* mTimes;
		CoreTools::MinHeap<int, float> mHeap;
		int* mTrials;
	};
}
#endif // IMAGICS_RASTER_DRAWING_FAST_MARCH_H
