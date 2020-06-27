// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_H

#include "Mathematics/MathematicsDll.h"

#include "NumericalAnalysisFwd.h"
#include "Flags/BisectStorageType.h"

#include <boost/noncopyable.hpp>
#include <type_traits>

namespace Mathematics
{ 
	template <typename Real>
	class Bisect2Storage : private boost::noncopyable
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Bisect2Storage<Real>;
		using Bisect2Root = Bisect2Root<Real>;
		using Bisect2RootPtr = std::shared_ptr<Bisect2Root>;
		using Bisect2 = Bisect2<Real>;
		using Bisect2Node = Bisect2Node<Real>;

	public:
		explicit Bisect2Storage(const Bisect2& bisect);

		CLASS_INVARIANT_DECLARE;

		bool TestFourCornerValues(Real beginPointX, Real beginPointY, Real endPointX, Real endPointY);

		bool TestEdgeValues();

		const Bisect2RootPtr GetBisect2RootPtr() const;

		void SetStorageValue(Real firstValue, Real secondValue, Bisect2StorageType type);

		void SetStorageValue(Bisect2Node* node);

		Real GetBeginPointX() const;
		Real GetBeginPointY() const;
		Real GetEndPointX() const;
		Real GetEndPointY() const;
		Real GetMidpointX() const;
		Real GetMidpointY() const;

		Real GetBeginXAndBeginYFirstValue() const;
		Real GetEndXAndBeginYFirstValue() const;
		Real GetBeginXAndEndYFirstValue() const;
		Real GetEndXAndEndYFirstValue() const;

		Real GetBeginXAndMidYFirstValue() const;
		Real GetEndXAndMidYFirstValue() const;
		Real GetMidXAndBeginYFirstValue() const;
		Real GetMidXAndEndYFirstValue() const;
		Real GetMidXAndMidYFirstValue() const;

		Real GetBeginXAndBeginYSecondValue() const;
		Real GetEndXAndBeginYSecondValue() const;
		Real GetBeginXAndEndYSecondValue() const;
		Real GetEndXAndEndYSecondValue() const;

		Real GetBeginXAndMidYSecondValue() const;
		Real GetEndXAndMidYSecondValue() const;
		Real GetMidXAndBeginYSecondValue() const;
		Real GetMidXAndEndYSecondValue() const;
		Real GetMidXAndMidYSecondValue() const;

	private:
		bool ZeroTest(Real x, Real y, Bisect2StorageType type);

	private:
		const Bisect2& m_Bisect;

		// πÃ∂®¥Ê¥¢,“‘±‹√‚‘⁄µ›πÈ÷–µƒ∂—’ªÀ∫ƒ°£
		Real m_BeginPointX;
		Real m_BeginPointY;
		Real m_EndPointX;
		Real m_EndPointY;
		Real m_MidpointX;
		Real m_MidpointY;

		Real m_FirstBeginXAndBeginY;
		Real m_FirstEndXAndBeginY;
		Real m_FirstBeginXAndEndY;
		Real m_FirstEndXAndEndY;

		Real m_FirstBeginXAndMidY;
		Real m_FirstEndXAndMidY;
		Real m_FirstMidXAndBeginY;
		Real m_FirstMidXAndEndY;
		Real m_FirstMidXAndMidY;

		Real m_SecondBeginXAndBeginY;
		Real m_SecondEndXAndBeginY;
		Real m_SecondBeginXAndEndY;
		Real m_SecondEndXAndEndY;

		Real m_SecondBeginXAndMidY;
		Real m_SecondEndXAndMidY;
		Real m_SecondMidXAndBeginY;
		Real m_SecondMidXAndEndY;
		Real m_SecondMidXAndMidY;

		Bisect2RootPtr m_Bisect2RootPtr;
	};

	using Bisect2Storagef = Bisect2Storage<float>;
	using Bisect2Storaged = Bisect2Storage<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_H
