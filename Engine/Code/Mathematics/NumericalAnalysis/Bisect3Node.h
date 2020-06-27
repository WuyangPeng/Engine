// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:47)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_H

#include "Mathematics/MathematicsDll.h"

#include <boost/noncopyable.hpp>
#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class Bisect3Node : private boost::noncopyable
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Bisect3Node<Real>;

	public:
		Bisect3Node(Real x, Real y, Real z, Real firstFunctionResult,
					Real secondFunctionResult, Real thirdFunctionResult);
		~Bisect3Node();

		CLASS_INVARIANT_DECLARE;

		Real GetX() const;
		Real GetY() const;
		Real GetZ() const;
		Real GetFirstFunctionResult() const;
		Real GetSecondFunctionResult() const;
		Real GetThirdFunctionResult() const;

		Bisect3Node* GetXNext();
		Bisect3Node* GetYNext();
		Bisect3Node* GetZNext();
		const Bisect3Node* GetXNext() const;
		const Bisect3Node* GetYNext() const;
		const Bisect3Node* GetZNext() const;

		void AddXNextNode(Real x, Real y, Real z, Real firstFunctionResult,
						  Real secondFunctionResult, Real thirdFunctionResult);
		void AddYNextNode(Real x, Real y, Real z, Real firstFunctionResult,
						  Real secondFunctionResult, Real thirdFunctionResult);
		void AddZNextNode(Real x, Real y, Real z, Real firstFunctionResult,
						  Real secondFunctionResult, Real thirdFunctionResult);
		void AddXNextNode(Bisect3Node* node);
		void AddYNextNode(Bisect3Node* node);
		void AddZNextNode(Bisect3Node* node);

		bool IsFirstFunctionResultSameSign() const;
		bool IsSecondFunctionResultSameSign() const;
		bool IsThirdFunctionResultSameSign() const;

	private:
		Real m_X;
		Real m_Y;
		Real m_Z;
		Real m_FirstFunctionResult;
		Real m_SecondFunctionResult;
		Real m_ThirdFunctionResult;
		Bisect3Node* m_XNext;
		Bisect3Node* m_YNext;
		Bisect3Node* m_ZNext;
		bool m_ReleaseXNext;
		bool m_ReleaseYNext;
		bool m_ReleaseZNext;
	};

	using Bisect3Nodef = Bisect3Node<float>;
	using Bisect3Noded = Bisect3Node<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_NODE_H
