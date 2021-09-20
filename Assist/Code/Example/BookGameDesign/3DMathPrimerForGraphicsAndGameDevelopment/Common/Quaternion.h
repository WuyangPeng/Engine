/////////////////////////////////////////////////////////////////////////////
//
// 3D Math Primer for Games and Graphics Development
//
// Quaternion.h - Declarations for class Quaternion
//
// Visit gamemath.com for the latest version of this file.
//
// For more details, see Quaternion.cpp
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __QUATERNION_H_INCLUDED__
#define __QUATERNION_H_INCLUDED__

namespace ThreeDMathPrimerForGraphicsAndGameDevelopment
{
	class Vector3;
	class EulerAngles;

	//---------------------------------------------------------------------------
	// class Quaternion
	//
	// Implement a quaternion, for purposes of representing an angular
	// displacement (orientation) in 3D.

	class Quaternion
	{
	public:

		// Public data

			// The 4 values of the quaternion.  Normally, it will not
			// be necessary to manipulate these directly.  However,
			// we leave them public, since prohibiting direct access
			// makes some operations, such as file I/O, unnecessarily
			// complicated.

		float w, x, y, z;

		// Public operations

			// Set to identity

		void identity() noexcept
		{
			w = 1.0f; x = y = z = 0.0f;
		}

		// Setup the quaternion to a specific rotation

		void setToRotateAboutX(float theta) noexcept;
		void setToRotateAboutY(float theta) noexcept;
		void setToRotateAboutZ(float theta) noexcept;
		void setToRotateAboutAxis(const Vector3& axis, float theta) noexcept;

		// Setup to perform object<->inertial rotations,
		// given orientation in Euler angle format

		void setToRotateObjectToInertial(const EulerAngles& orientation) noexcept;
		void setToRotateInertialToObject(const EulerAngles& orientation) noexcept;

		// Cross product

		Quaternion operator*(const Quaternion& a) const noexcept;

		// Multiplication with assignment, as per C++ convention

		Quaternion& operator*=(const Quaternion& a) noexcept;

		// Normalize the quaternion.

		void normalize() noexcept;

		// Extract and return the rotation angle and axis.

		float getRotationAngle() const noexcept;
		Vector3	getRotationAxis() const noexcept;
	};

	// A global "identity" quaternion constant

	extern const Quaternion kQuaternionIdentity;

	// Quaternion dot product.

	extern float dotProduct(const Quaternion& a, const Quaternion& b) noexcept;

	// Spherical linear interpolation

	extern Quaternion slerp(const Quaternion& p, const Quaternion& q, float t) noexcept;

	// Quaternion conjugation

	extern Quaternion conjugate(const Quaternion& q) noexcept;

	// Quaternion exponentiation

	extern Quaternion pow(const Quaternion& q, float exponent) noexcept;
}
/////////////////////////////////////////////////////////////////////////////
#endif // #ifndef __QUATERNION_H_INCLUDED__
