// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 15:31)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_H

#include "Mathematics/MathematicsDll.h"

#include <boost/noncopyable.hpp>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class Bisect2Node : private boost::noncopyable
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Bisect2Node<Real>;
        
    public:
        Bisect2Node (Real x, Real y,Real firstFunctionResult,Real secondFunctionResult);
        ~Bisect2Node ();
        
		CLASS_INVARIANT_DECLARE;
        
        Real GetX() const;
        Real GetY() const;
        Real GetFirstFunctionResult() const;
        Real GetSecondFunctionResult() const;
      
        Bisect2Node* GetXNext();
        Bisect2Node* GetYNext();
		const Bisect2Node* GetXNext() const;
		const Bisect2Node* GetYNext() const;
        
        void AddXNextNode (Real x, Real y,Real firstFunctionResult,Real secondFunctionResult);
        void AddYNextNode (Real x, Real y,Real firstFunctionResult,Real secondFunctionResult);
        void AddXNextNode (Bisect2Node* node);
        void AddYNextNode (Bisect2Node* node);
        
        bool IsFirstFunctionResultSameSign() const;
        bool IsSecondFunctionResultSameSign() const;
        
    private:
        Real m_X;
        Real m_Y;
        Real m_FirstFunctionResult;
        Real m_SecondFunctionResult;
        Bisect2Node* m_XNext;
        Bisect2Node* m_YNext;
        bool m_ReleaseXNext;
        bool m_ReleaseYNext;
    };

	using Bisect2Nodef = Bisect2Node<float>;
	using Bisect2Noded = Bisect2Node<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_NODE_H
