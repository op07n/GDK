#include "Mat4x4.h"

using namespace GDK;
using namespace Math;

//static const
const Mat4x4 Mat4x4::Identity = Mat4x4();

// Constructors
Mat4x4::Mat4x4()
: m00(1.), m01(0.), m02(0.), m03(0.)
, m10(0.), m11(1.), m12(0.), m13(0.)
, m20(0.), m21(0.), m22(1.), m23(0.)
, m30(0.), m31(0.), m32(0.), m33(1.)
{}

Mat4x4::Mat4x4
(
 const float& a00, const float& a01, const float& a02, const float& a03,
 const float& a10, const float& a11, const float& a12, const float& a13,
 const float& a20, const float& a21, const float& a22, const float& a23,
 const float& a30, const float& a31, const float& a32, const float& a33
)
: m00(a00), m01(a01), m02(a02), m03(a03)
, m10(a10), m11(a11), m12(a12), m13(a13)
, m20(a20), m21(a21), m22(a22), m23(a23)
, m30(a30), m31(a31), m32(a32), m33(a33)
{}
