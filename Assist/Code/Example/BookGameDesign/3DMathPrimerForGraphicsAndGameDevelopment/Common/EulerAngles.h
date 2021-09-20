/////////////////////////////////////////////////////////////////////////////
//
// 3D Math Primer for Games and Graphics Development
//
// EulerAngles.h - Declarations for class EulerAngles
//
// Visit gamemath.com for the latest version of this file.
//
// For more details, see EulerAngles.cpp
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __EULERANGLES_H_INCLUDED__
#define __EULERANGLES_H_INCLUDED__

namespace ThreeDMathPrimerForGraphicsAndGameDevelopment
{
	// Forward declarations

	class Quaternion;
	class Matrix4x3;
	class RotationMatrix;

	//---------------------------------------------------------------------------
	// class EulerAngles
	//
	// This class represents a heading-pitch-bank Euler angle triple.

	class EulerAngles
	{
	public:

		// Public data

			// Straightforward representation.  Store the three angles, in
			// radians

		float heading = 0.0f;
		float pitch = 0.0f;
		float bank = 0.0f;

		// Public operations

			// Default constructor does nothing

		EulerAngles() noexcept
		{
		}

		void doNothing() noexcept
		{

		}

		// Construct from three values

		constexpr EulerAngles(float h, float p, float b) noexcept
			:heading(h), pitch(p), bank(b)
		{
		}

		// Set to identity triple (all zeros)

		void identity() noexcept
		{
			pitch = bank = heading = 0.0f;
		}

		// Determine "canonical" Euler angle triple

		void canonize() noexcept;

		// Convert the quaternion to Euler angle format.  The input quaternion
		// is assumed to perform the rotation from object-to-inertial
		// or inertial-to-object, as indicated.

		void fromObjectToInertialQuaternion(const Quaternion& q) noexcept;
		void fromInertialToObjectQuaternion(const Quaternion& q) noexcept;

		// Convert the transform matrix to Euler angle format.  The input
		// matrix is assumed to perform the transformation from
		// object-to-world, or world-to-object, as indicated.  The
		// translation portion of the matrix is ignored.  The
		// matrix is assumed to be orthogonal.

		void fromObjectToWorldMatrix(const Matrix4x3& m) noexcept;
		void fromWorldToObjectMatrix(const Matrix4x3& m) noexcept;

		// Convert a rotation matrix to Euler Angle form.

		void fromRotationMatrix(const RotationMatrix& m) noexcept;
	};

	// A global "identity" Euler angle constant

	/////////////////////////////////////////////////////////////////////////////
	//
	// global data
	//
	/////////////////////////////////////////////////////////////////////////////

	// The global "identity" Euler angle constant.  Now we may not know exactly
	// when this object may get constructed, in relation to other objects, so
	// it is possible for the object to be referenced before it is initialized.
	// However, on most implementations, it will be zero-initialized at program
	// startup anyway, before any other objects are constructed.	 

	constexpr EulerAngles kEulerAnglesIdentity(0.0f, 0.0f, 0.0f);
}
/////////////////////////////////////////////////////////////////////////////
#endif // #ifndef __EULERANGLES_H_INCLUDED__
