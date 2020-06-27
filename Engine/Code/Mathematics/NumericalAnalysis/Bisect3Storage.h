// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 12:47)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_H

#include "Mathematics/MathematicsDll.h"

#include "NumericalAnalysisFwd.h"
#include "Flags/BisectStorageType.h"

#include <type_traits>

namespace Mathematics
{ 
	template <typename Real>
	class Bisect3Storage : private boost::noncopyable
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Bisect3Storage<Real>;
		using Bisect3Root = Bisect3Root<Real>;
		using Bisect3RootPtr = std::shared_ptr<Bisect3Root>;
		using Bisect3 = Bisect3<Real>;
		using Bisect3Node = Bisect3Node<Real>;

	public:
		explicit Bisect3Storage(const Bisect3& bisect);

		CLASS_INVARIANT_DECLARE;

		bool TestEightCornerValues(Real beginPointX, Real beginPointY, Real beginPointZ,
								   Real endPointX, Real endPointY, Real endPointZ);

		bool TestEdgeValues();

		const Bisect3RootPtr GetBisect3RootPtr() const;

		void SetStorageValue(Real firstValue, Real secondValue, Real thirdValue, Bisect3StorageType type);

		void SetStorageValue(Bisect3Node* node);

		Real GetBeginPointX() const;
		Real GetBeginPointY() const;
		Real GetBeginPointZ() const;
		Real GetEndPointX() const;
		Real GetEndPointY() const;
		Real GetEndPointZ() const;
		Real GetMidpointX() const;
		Real GetMidpointY() const;
		Real GetMidpointZ() const;

		Real GetBeginXBeginYBeginZFirstValue() const;
		Real GetEndXBeginYBeginZFirstValue() const;
		Real GetBeginXEndYBeginZFirstValue() const;
		Real GetEndXEndYBeginZFirstValue() const;

		Real GetBeginXBeginYEndZFirstValue() const;
		Real GetEndXBeginYEndZFirstValue() const;
		Real GetBeginXEndYEndZFirstValue() const;
		Real GetEndXEndYEndZFirstValue() const;

		Real GetBeginXBeginYBeginZSecondValue() const;
		Real GetEndXBeginYBeginZSecondValue() const;
		Real GetBeginXEndYBeginZSecondValue() const;
		Real GetEndXEndYBeginZSecondValue() const;

		Real GetBeginXBeginYEndZSecondValue() const;
		Real GetEndXBeginYEndZSecondValue() const;
		Real GetBeginXEndYEndZSecondValue() const;
		Real GetEndXEndYEndZSecondValue() const;

		Real GetBeginXBeginYBeginZThirdValue() const;
		Real GetEndXBeginYBeginZThirdValue() const;
		Real GetBeginXEndYBeginZThirdValue() const;
		Real GetEndXEndYBeginZThirdValue() const;

		Real GetBeginXBeginYEndZThirdValue() const;
		Real GetEndXBeginYEndZThirdValue() const;
		Real GetBeginXEndYEndZThirdValue() const;
		Real GetEndXEndYEndZThirdValue() const;

		Real GetBeginXBeginYMidZFirstValue() const;
		Real GetEndXBeginYMidZFirstValue() const;
		Real GetBeginXEndYMidZFirstValue() const;
		Real GetEndXEndYMidZFirstValue() const;

		Real GetBeginXMidYBeginZFirstValue() const;
		Real GetEndXMidYBeginZFirstValue() const;
		Real GetBeginXMidYEndZFirstValue() const;
		Real GetEndXMidYEndZFirstValue() const;

		Real GetMidXBeginYBeginZFirstValue() const;
		Real GetMidXEndYBeginZFirstValue() const;
		Real GetMidXBeginYEndZFirstValue() const;
		Real GetMidXEndYEndZFirstValue() const;

		Real GetBeginXBeginYMidZSecondValue() const;
		Real GetEndXBeginYMidZSecondValue() const;
		Real GetBeginXEndYMidZSecondValue() const;
		Real GetEndXEndYMidZSecondValue() const;

		Real GetBeginXMidYBeginZSecondValue() const;
		Real GetEndXMidYBeginZSecondValue() const;
		Real GetBeginXMidYEndZSecondValue() const;
		Real GetEndXMidYEndZSecondValue() const;

		Real GetMidXBeginYBeginZSecondValue() const;
		Real GetMidXEndYBeginZSecondValue() const;
		Real GetMidXBeginYEndZSecondValue() const;
		Real GetMidXEndYEndZSecondValue() const;

		Real GetBeginXBeginYMidZThirdValue() const;
		Real GetEndXBeginYMidZThirdValue() const;
		Real GetBeginXEndYMidZThirdValue() const;
		Real GetEndXEndYMidZThirdValue() const;

		Real GetBeginXMidYBeginZThirdValue() const;
		Real GetEndXMidYBeginZThirdValue() const;
		Real GetBeginXMidYEndZThirdValue() const;
		Real GetEndXMidYEndZThirdValue() const;

		Real GetMidXBeginYBeginZThirdValue() const;
		Real GetMidXEndYBeginZThirdValue() const;
		Real GetMidXBeginYEndZThirdValue() const;
		Real GetMidXEndYEndZThirdValue() const;

		Real GetBeginXMidYMidZFirstValue() const;
		Real GetMidXBeginYMidZFirstValue() const;
		Real GetMidXMidYBeginZFirstValue() const;
		Real GetEndXMidYMidZFirstValue() const;
		Real GetMidXEndYMidZFirstValue() const;
		Real GetMidXMidYEndZFirstValue() const;

		Real GetBeginXMidYMidZSecondValue() const;
		Real GetMidXBeginYMidZSecondValue() const;
		Real GetMidXMidYBeginZSecondValue() const;
		Real GetEndXMidYMidZSecondValue() const;
		Real GetMidXEndYMidZSecondValue() const;
		Real GetMidXMidYEndZSecondValue() const;

		Real GetBeginXMidYMidZThirdValue() const;
		Real GetMidXBeginYMidZThirdValue() const;
		Real GetMidXMidYBeginZThirdValue() const;
		Real GetEndXMidYMidZThirdValue() const;
		Real GetMidXEndYMidZThirdValue() const;
		Real GetMidXMidYEndZThirdValue() const;

		Real GetMidXMidYMidZFirstValue() const;
		Real GetMidXMidYMidZSecondValue() const;
		Real GetMidXMidYMidZThirdValue() const;

	private:
		bool ZeroTest(Real x, Real y, Real z, Bisect3StorageType type);

	private:
		const Bisect3& m_Bisect;

		// 顶点和中点的位置。
		Real m_BeginPointX;
		Real m_EndPointX;
		Real m_MidpointX;
		Real m_BeginPointY;
		Real m_EndPointY;
		Real m_MidpointY;
		Real m_BeginPointZ;
		Real m_EndPointZ;
		Real m_MidpointZ;

		// 顶点
		Real m_FirstBeginXBeginYBeginZ;
		Real m_FirstEndXBeginYBeginZ;
		Real m_FirstBeginXEndYBeginZ;
		Real m_FirstEndXEndYBeginZ;
		Real m_FirstBeginXBeginYEndZ;
		Real m_FirstEndXBeginYEndZ;
		Real m_FirstBeginXEndYEndZ;
		Real m_FirstEndXEndYEndZ;
		Real m_SecondBeginXBeginYBeginZ;
		Real m_SecondEndXBeginYBeginZ;
		Real m_SecondBeginXEndYBeginZ;
		Real m_SecondEndXEndYBeginZ;
		Real m_SecondBeginXBeginYEndZ;
		Real m_SecondEndXBeginYEndZ;
		Real m_SecondBeginXEndYEndZ;
		Real m_SecondEndXEndYEndZ;
		Real m_ThirdBeginXBeginYBeginZ;
		Real m_ThirdEndXBeginYBeginZ;
		Real m_ThirdBeginXEndYBeginZ;
		Real m_ThirdEndXEndYBeginZ;
		Real m_ThirdBeginXBeginYEndZ;
		Real m_ThirdEndXBeginYEndZ;
		Real m_ThirdBeginXEndYEndZ;
		Real m_ThirdEndXEndYEndZ;

		// 边
		Real m_FirstBeginXBeginYMidZ;
		Real m_FirstEndXBeginYMidZ;
		Real m_FirstBeginXEndYMidZ;
		Real m_FirstEndXEndYMidZ;

		Real m_FirstBeginXMidYBeginZ;
		Real m_FirstEndXMidYBeginZ;
		Real m_FirstBeginXMidYEndZ;
		Real m_FirstEndXMidYEndZ;

		Real m_FirstMidXBeginYBeginZ;
		Real m_FirstMidXEndYBeginZ;
		Real m_FirstMidXBeginYEndZ;
		Real m_FirstMidXEndYEndZ;

		Real m_SecondBeginXBeginYMidZ;
		Real m_SecondEndXBeginYMidZ;
		Real m_SecondBeginXEndYMidZ;
		Real m_SecondEndXEndYMidZ;

		Real m_SecondBeginXMidYBeginZ;
		Real m_SecondEndXMidYBeginZ;
		Real m_SecondBeginXMidYEndZ;
		Real m_SecondEndXMidYEndZ;

		Real m_SecondMidXBeginYBeginZ;
		Real m_SecondMidXEndYBeginZ;
		Real m_SecondMidXBeginYEndZ;
		Real m_SecondMidXEndYEndZ;

		Real m_ThirdBeginXBeginYMidZ;
		Real m_ThirdEndXBeginYMidZ;
		Real m_ThirdBeginXEndYMidZ;
		Real m_ThirdEndXEndYMidZ;

		Real m_ThirdBeginXMidYBeginZ;
		Real m_ThirdEndXMidYBeginZ;
		Real m_ThirdBeginXMidYEndZ;
		Real m_ThirdEndXMidYEndZ;

		Real m_ThirdMidXBeginYBeginZ;
		Real m_ThirdMidXEndYBeginZ;
		Real m_ThirdMidXBeginYEndZ;
		Real m_ThirdMidXEndYEndZ;

		// 面
		Real m_FirstBeginXMidYMidZ;
		Real m_FirstMidXBeginYMidZ;
		Real m_FirstMidXMidYBeginZ;
		Real m_FirstEndXMidYMidZ;
		Real m_FirstMidXEndYMidZ;
		Real m_FirstMidXMidYEndZ;

		Real m_SecondBeginXMidYMidZ;
		Real m_SecondMidXBeginYMidZ;
		Real m_SecondMidXMidYBeginZ;
		Real m_SecondEndXMidYMidZ;
		Real m_SecondMidXEndYMidZ;
		Real m_SecondMidXMidYEndZ;

		Real m_ThirdBeginXMidYMidZ;
		Real m_ThirdMidXBeginYMidZ;
		Real m_ThirdMidXMidYBeginZ;
		Real m_ThirdEndXMidYMidZ;
		Real m_ThirdMidXEndYMidZ;
		Real m_ThirdMidXMidYEndZ;

		// 中心
		Real m_FirstMidXMidYMidZ;
		Real m_SecondMidXMidYMidZ;
		Real m_ThirdMidXMidYMidZ;

		Bisect3RootPtr m_Bisect3RootPtr;
	};

	using Bisect3Storagef = Bisect3Storage<float>;
	using Bisect3Storaged = Bisect3Storage<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_H
