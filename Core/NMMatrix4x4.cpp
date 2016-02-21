/*
-----------------------------------------------------------------
This source file is part of NightMoon

GNU LESSER GENERAL PUBLIC LICENSE
Version 3, 29 June 2007

Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
Everyone is permitted to copy and distribute verbatim copies
of this license document, but changing it is not allowed.


This version of the GNU Lesser General Public License incorporates
the terms and conditions of version 3 of the GNU General Public
License, supplemented by the additional permissions listed below.

0. Additional Definitions.

As used herein, "this License" refers to version 3 of the GNU Lesser
General Public License, and the "GNU GPL" refers to version 3 of the GNU
General Public License.

"The Library" refers to a covered work governed by this License,
other than an Application or a Combined Work as defined below.

An "Application" is any work that makes use of an interface provided
by the Library, but which is not otherwise based on the Library.
Defining a subclass of a class defined by the Library is deemed a mode
of using an interface provided by the Library.

A "Combined Work" is a work produced by combining or linking an
Application with the Library.  The particular version of the Library
with which the Combined Work was made is also called the "Linked
Version".

The "Minimal Corresponding Source" for a Combined Work means the
Corresponding Source for the Combined Work, excluding any source code
for portions of the Combined Work that, considered in isolation, are
based on the Application, and not on the Linked Version.

The "Corresponding Application Code" for a Combined Work means the
object code and/or source code for the Application, including any data
and utility programs needed for reproducing the Combined Work from the
Application, but excluding the System Libraries of the Combined Work.

1. Exception to Section 3 of the GNU GPL.

You may convey a covered work under sections 3 and 4 of this License
without being bound by section 3 of the GNU GPL.

2. Conveying Modified Versions.

If you modify a copy of the Library, and, in your modifications, a
facility refers to a function or data to be supplied by an Application
that uses the facility (other than as an argument passed when the
facility is invoked), then you may convey a copy of the modified
version:

a) under this License, provided that you make a good faith effort to
ensure that, in the event an Application does not supply the
function or data, the facility still operates, and performs
whatever part of its purpose remains meaningful, or

b) under the GNU GPL, with none of the additional permissions of
this License applicable to that copy.

3. Object Code Incorporating Material from Library Header Files.

The object code form of an Application may incorporate material from
a header file that is part of the Library.  You may convey such object
code under terms of your choice, provided that, if the incorporated
material is not limited to numerical parameters, data structure
layouts and accessors, or small macros, inline functions and templates
(ten or fewer lines in length), you do both of the following:

a) Give prominent notice with each copy of the object code that the
Library is used in it and that the Library and its use are
covered by this License.

b) Accompany the object code with a copy of the GNU GPL and this license
document.

4. Combined Works.

You may convey a Combined Work under terms of your choice that,
taken together, effectively do not restrict modification of the
portions of the Library contained in the Combined Work and reverse
engineering for debugging such modifications, if you also do each of
the following:

a) Give prominent notice with each copy of the Combined Work that
the Library is used in it and that the Library and its use are
covered by this License.

b) Accompany the Combined Work with a copy of the GNU GPL and this license
document.

c) For a Combined Work that displays copyright notices during
execution, include the copyright notice for the Library among
these notices, as well as a reference directing the user to the
copies of the GNU GPL and this license document.

d) Do one of the following:

0) Convey the Minimal Corresponding Source under the terms of this
License, and the Corresponding Application Code in a form
suitable for, and under terms that permit, the user to
recombine or relink the Application with a modified version of
the Linked Version to produce a modified Combined Work, in the
manner specified by section 6 of the GNU GPL for conveying
Corresponding Source.

1) Use a suitable shared library mechanism for linking with the
Library.  A suitable mechanism is one that (a) uses at run time
a copy of the Library already present on the user's computer
system, and (b) will operate properly with a modified version
of the Library that is interface-compatible with the Linked
Version.

e) Provide Installation Information, but only if you would otherwise
be required to provide such information under section 6 of the
GNU GPL, and only to the extent that such information is
necessary to install and execute a modified version of the
Combined Work produced by recombining or relinking the
Application with a modified version of the Linked Version. (If
you use option 4d0, the Installation Information must accompany
the Minimal Corresponding Source and Corresponding Application
Code. If you use option 4d1, you must provide the Installation
Information in the manner specified by section 6 of the GNU GPL
for conveying Corresponding Source.)

5. Combined Libraries.

You may place library facilities that are a work based on the
Library side by side in a single library together with other library
facilities that are not Applications and are not covered by this
License, and convey such a combined library under terms of your
choice, if you do both of the following:

a) Accompany the combined library with a copy of the same work based
on the Library, uncombined with any other library facilities,
conveyed under the terms of this License.

b) Give prominent notice with the combined library that part of it
is a work based on the Library, and explaining where to find the
accompanying uncombined form of the same work.

6. Revised Versions of the GNU Lesser General Public License.

The Free Software Foundation may publish revised and/or new versions
of the GNU Lesser General Public License from time to time. Such new
versions will be similar in spirit to the present version, but may
differ in detail to address new problems or concerns.

Each version is given a distinguishing version number. If the
Library as you received it specifies that a certain numbered version
of the GNU Lesser General Public License "or any later version"
applies to it, you have the option of following the terms and
conditions either of that published version or of any later version
published by the Free Software Foundation. If the Library as you
received it does not specify a version number of the GNU Lesser
General Public License, you may choose any version of the GNU Lesser
General Public License ever published by the Free Software Foundation.

If the Library as you received it specifies that a proxy can decide
whether future versions of the GNU Lesser General Public License shall
apply, that proxy's public statement of acceptance of any version is
permanent authorization for you to choose that version for the
Library.
-----------------------------------------------------------------
*/

#include "NMMatrix4x4.h"

namespace NightMoon
{
    const NMMatrix4x4 NMMatrix4x4::zero = NMMatrix4x4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    const NMMatrix4x4 NMMatrix4x4::identity = NMMatrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

    NMMatrix4x4::NMMatrix4x4(void)
        :m00(1.0f), m01(0), m02(0), m03(0),
        m10(0), m11(1.0f), m12(0), m13(0),
        m20(0), m21(0), m22(1.0f), m23(0),
        m30(0), m31(0), m32(0), m33(1.0f)
    {
    }

    NMMatrix4x4::NMMatrix4x4(const Float &fm00, const Float &fm01, const Float &fm02, const Float &fm03,
        const Float &fm10, const Float &fm11, const Float &fm12, const Float &fm13,
        const Float &fm20, const Float &fm21, const Float &fm22, const Float &fm23,
        const Float &fm30, const Float &fm31, const Float &fm32, const Float &fm33)
        :m00(fm00), m01(fm01), m02(fm02), m03(fm03),
        m10(fm10), m11(fm11), m12(fm12), m13(fm13),
        m20(fm20), m21(fm21), m22(fm22), m23(fm23),
        m30(fm30), m31(fm31), m32(fm32), m33(fm33)
    {
    }

    NMMatrix4x4::NMMatrix4x4(const NMMatrix4x4 &src)
        :m00(src.m00), m01(src.m01), m02(src.m02), m03(src.m03),
        m10(src.m10), m11(src.m11), m12(src.m12), m13(src.m13),
        m20(src.m20), m21(src.m21), m22(src.m21), m23(src.m21),
        m30(src.m30), m31(src.m31), m32(src.m32), m33(src.m33)
    {
    }

    Bool NMMatrix4x4::operator == (const NMMatrix4x4 &m)
    {
        return (this->m00 == m.m00) && (this->m01 == m.m01) && (this->m02 == m.m02) && (this->m03 == m.m03) &&
            (this->m10 == m.m10) && (this->m11 == m.m11) && (this->m12 == m.m12) && (this->m13 == m.m13) &&
            (this->m20 == m.m20) && (this->m21 == m.m21) && (this->m22 == m.m22) && (this->m23 == m.m23) &&
            (this->m30 == m.m30) && (this->m31 == m.m31) && (this->m32 == m.m32) && (this->m33 == m.m33);
    }

    Bool NMMatrix4x4::operator != (const NMMatrix4x4 &m)
    {
        return !((this->m00 == m.m00) && (this->m01 == m.m01) && (this->m02 == m.m02) && (this->m03 == m.m03) &&
            (this->m10 == m.m10) && (this->m11 == m.m11) && (this->m12 == m.m12) && (this->m13 == m.m13) &&
            (this->m20 == m.m20) && (this->m21 == m.m21) && (this->m22 == m.m22) && (this->m23 == m.m23) &&
            (this->m30 == m.m30) && (this->m31 == m.m31) && (this->m32 == m.m32) && (this->m33 == m.m33));
    }

    NMMatrix4x4& NMMatrix4x4::operator = (const NMMatrix4x4 &m)
    {
        std::memcpy(this->data, m.data, sizeof(Float)* 16);
        return (*this);
    }

    Float& NMMatrix4x4::operator () (const size_t &column, const size_t &row)
    {
        return this->data[column * 4 + row];
    }

    Float NMMatrix4x4::operator () (const size_t &column, const size_t &row) const
    {
        return this->data[column * 4 + row];
    }

    NMMatrix4x4 operator + (const NMMatrix4x4 &lhs, const NMMatrix4x4 &rhs)
    {
        return NMMatrix4x4(
            lhs.m00 + rhs.m00, lhs.m01 + rhs.m01, lhs.m02 + rhs.m02, lhs.m03 + rhs.m03,
            lhs.m10 + rhs.m10, lhs.m11 + rhs.m11, lhs.m12 + rhs.m12, lhs.m13 + rhs.m13,
            lhs.m20 + rhs.m20, lhs.m21 + rhs.m21, lhs.m22 + rhs.m22, lhs.m23 + rhs.m23,
            lhs.m30 + rhs.m30, lhs.m31 + rhs.m31, lhs.m32 + rhs.m32, lhs.m33 + rhs.m33);
    }

    NMMatrix4x4 operator - (const NMMatrix4x4 &lhs, const NMMatrix4x4 &rhs)
    {
        return NMMatrix4x4(
            lhs.m00 - rhs.m00, lhs.m01 - rhs.m01, lhs.m02 - rhs.m02, lhs.m03 - rhs.m03,
            lhs.m10 - rhs.m10, lhs.m11 - rhs.m11, lhs.m12 - rhs.m12, lhs.m13 - rhs.m13,
            lhs.m20 - rhs.m20, lhs.m21 - rhs.m21, lhs.m22 - rhs.m22, lhs.m23 - rhs.m23,
            lhs.m30 - rhs.m30, lhs.m31 - rhs.m31, lhs.m32 - rhs.m32, lhs.m33 - rhs.m33);
    }

    NMMatrix4x4 operator * (const NMMatrix4x4 &m, const Float &val)
    {
        return NMMatrix4x4(
            m.m00 * val, m.m01 * val, m.m02 * val, m.m03 * val,
            m.m10 * val, m.m11 * val, m.m12 * val, m.m13 * val,
            m.m20 * val, m.m21 * val, m.m22 * val, m.m23 * val,
            m.m30 * val, m.m31 * val, m.m32 * val, m.m33 * val);
    }

    NMMatrix4x4 operator * (const Float &val, const NMMatrix4x4 &m)
    {
        return NMMatrix4x4(
            m.m00 * val, m.m01 * val, m.m02 * val, m.m03 * val,
            m.m10 * val, m.m11 * val, m.m12 * val, m.m13 * val,
            m.m20 * val, m.m21 * val, m.m22 * val, m.m23 * val,
            m.m30 * val, m.m31 * val, m.m32 * val, m.m33 * val);
    }

    NMVector3 operator * (const NMMatrix4x4 &m, const NMVector3 &v)
    {
        // The initial w component is considered to be 1.0 for 3D vector,
        // and all the three components should divided by the w.

        // equals: float inv_w = 1.0f / (m.m30 * v[0] + m.m31 * v[1] + m.m32 * v[2] + m.m33 * 1);
        Float inv_w = 1.0f / (m.m30 * v[0] + m.m31 * v[1] + m.m32 * v[2] + m.m33);

        return NMVector3(
            (m.m00 * v[0] + m.m01 * v[1] + m.m02 * v[2]) * inv_w,
            (m.m10 * v[0] + m.m11 * v[1] + m.m12 * v[2]) * inv_w,
            (m.m20 * v[0] + m.m21 * v[1] + m.m22 * v[2]) * inv_w);
    }

    NMVector4 operator * (const NMMatrix4x4 &m, const NMVector4 &v)
    {
        return NMVector4(
            m.m00 * v[0] + m.m01 * v[1] + m.m02 * v[2] + m.m03 * v[3],
            m.m10 * v[0] + m.m11 * v[1] + m.m12 * v[2] + m.m13 * v[3],
            m.m20 * v[0] + m.m21 * v[1] + m.m22 * v[2] + m.m23 * v[3],
            m.m30 * v[0] + m.m31 * v[1] + m.m32 * v[2] + m.m33 * v[3]);
    }

    NMMatrix4x4 operator * (const NMMatrix4x4 &lhs, const NMMatrix4x4 &rhs)
    {
        // Logic
        //           n
        // C[i][j] = Σ a[i][k]b[k][j]
        //          k=0

        return NMMatrix4x4(
            lhs.m00 * rhs.m00 + lhs.m01 * rhs.m10 + lhs.m02 * rhs.m20 + lhs.m03 * rhs.m30,
            lhs.m00 * rhs.m01 + lhs.m01 * rhs.m11 + lhs.m02 * rhs.m21 + lhs.m03 * rhs.m31,
            lhs.m00 * rhs.m02 + lhs.m01 * rhs.m12 + lhs.m02 * rhs.m22 + lhs.m03 * rhs.m32,
            lhs.m00 * rhs.m03 + lhs.m01 * rhs.m13 + lhs.m02 * rhs.m23 + lhs.m03 * rhs.m33,

            lhs.m10 * rhs.m00 + lhs.m11 * rhs.m10 + lhs.m12 * rhs.m20 + lhs.m13 * rhs.m30,
            lhs.m10 * rhs.m01 + lhs.m11 * rhs.m11 + lhs.m12 * rhs.m21 + lhs.m13 * rhs.m31,
            lhs.m10 * rhs.m02 + lhs.m11 * rhs.m12 + lhs.m12 * rhs.m22 + lhs.m13 * rhs.m32,
            lhs.m10 * rhs.m03 + lhs.m11 * rhs.m13 + lhs.m12 * rhs.m23 + lhs.m13 * rhs.m33,

            lhs.m20 * rhs.m00 + lhs.m21 * rhs.m10 + lhs.m22 * rhs.m20 + lhs.m23 * rhs.m30,
            lhs.m20 * rhs.m01 + lhs.m21 * rhs.m11 + lhs.m22 * rhs.m21 + lhs.m23 * rhs.m31,
            lhs.m20 * rhs.m02 + lhs.m21 * rhs.m12 + lhs.m22 * rhs.m22 + lhs.m23 * rhs.m32,
            lhs.m20 * rhs.m03 + lhs.m21 * rhs.m13 + lhs.m22 * rhs.m23 + lhs.m23 * rhs.m33,

            lhs.m30 * rhs.m00 + lhs.m31 * rhs.m10 + lhs.m32 * rhs.m20 + lhs.m33 * rhs.m30,
            lhs.m30 * rhs.m01 + lhs.m31 * rhs.m11 + lhs.m32 * rhs.m21 + lhs.m33 * rhs.m31,
            lhs.m30 * rhs.m02 + lhs.m31 * rhs.m12 + lhs.m32 * rhs.m22 + lhs.m33 * rhs.m32,
            lhs.m30 * rhs.m03 + lhs.m31 * rhs.m13 + lhs.m32 * rhs.m23 + lhs.m33 * rhs.m33);
    }

    void NMMatrix4x4::operator += (const NMMatrix4x4 &m)
    {
        this->m00 += m.m00;
        this->m01 += m.m01;
        this->m02 += m.m02;
        this->m03 += m.m03;

        this->m10 += m.m10;
        this->m11 += m.m11;
        this->m12 += m.m12;
        this->m13 += m.m13;

        this->m20 += m.m20;
        this->m21 += m.m21;
        this->m22 += m.m22;
        this->m23 += m.m23;

        this->m30 += m.m30;
        this->m31 += m.m31;
        this->m32 += m.m32;
        this->m33 += m.m33;
    }

    void NMMatrix4x4::operator -= (const NMMatrix4x4 &m)
    {
        this->m00 -= m.m00;
        this->m01 -= m.m01;
        this->m02 -= m.m02;
        this->m03 -= m.m03;

        this->m10 -= m.m10;
        this->m11 -= m.m11;
        this->m12 -= m.m12;
        this->m13 -= m.m13;

        this->m20 -= m.m20;
        this->m21 -= m.m21;
        this->m22 -= m.m22;
        this->m23 -= m.m23;

        this->m30 -= m.m30;
        this->m31 -= m.m31;
        this->m32 -= m.m32;
        this->m33 -= m.m33;
    }

    void NMMatrix4x4::operator *= (const Float &val)
    {
        this->m00 *= val;
        this->m01 *= val;
        this->m02 *= val;
        this->m03 *= val;

        this->m10 *= val;
        this->m11 *= val;
        this->m12 *= val;
        this->m13 *= val;

        this->m20 *= val;
        this->m21 *= val;
        this->m22 *= val;
        this->m23 *= val;

        this->m30 *= val;
        this->m31 *= val;
        this->m32 *= val;
        this->m33 *= val;
    }

    Float NMMatrix4x4::Determinant(const NMMatrix4x4 &m)
    {
        return
            m.m00 * (m.m11 * (m.m22 * m.m33 - m.m32 * m.m23) + m.m21 * (m.m32 * m.m13 - m.m12 * m.m33) + m.m31 * (m.m23 * m.m12 - m.m22 * m.m13)) -
            m.m10 * (m.m01 * (m.m22 * m.m33 - m.m23 * m.m32) + m.m21 * (m.m32 * m.m03 - m.m02 * m.m33) + m.m31 * (m.m23 * m.m02 - m.m22 * m.m03)) +
            m.m20 * (m.m01 * (m.m12 * m.m33 - m.m13 * m.m32) + m.m11 * (m.m32 * m.m03 - m.m02 * m.m33) + m.m31 * (m.m13 * m.m02 - m.m12 * m.m03)) -
            m.m30 * (m.m01 * (m.m12 * m.m23 - m.m13 * m.m22) + m.m11 * (m.m22 * m.m03 - m.m02 * m.m23) + m.m21 * (m.m13 * m.m02 - m.m12 * m.m03));
    }

    NMMatrix4x4 NMMatrix4x4::Inverse(const NMMatrix4x4 &m)
    {
        const Float det = (Determinant(m));
        if (det != 0)
        {
            Float invDet = (1.0f / det);

            const Float _1021_1120 = m.m10 * m.m21 - m.m11 * m.m20;
            const Float _1022_1220 = m.m10 * m.m22 - m.m12 * m.m20;
            const Float _1023_1320 = m.m10 * m.m23 - m.m13 * m.m20;
            const Float _1031_1130 = m.m10 * m.m31 - m.m11 * m.m30;
            const Float _1032_1230 = m.m10 * m.m32 - m.m12 * m.m30;
            const Float _1033_1330 = m.m10 * m.m33 - m.m13 * m.m30;
            const Float _1122_1221 = m.m11 * m.m22 - m.m12 * m.m21;
            const Float _1123_1321 = m.m11 * m.m23 - m.m13 * m.m21;
            const Float _1132_1231 = m.m11 * m.m32 - m.m12 * m.m31;
            const Float _1133_1331 = m.m11 * m.m33 - m.m13 * m.m31;
            const Float _1223_1322 = m.m12 * m.m23 - m.m13 * m.m22;
            const Float _1233_1332 = m.m12 * m.m33 - m.m13 * m.m32;
            const Float _2031_2130 = m.m20 * m.m31 - m.m21 * m.m30;
            const Float _2032_2230 = m.m20 * m.m32 - m.m22 * m.m30;
            const Float _2033_2330 = m.m20 * m.m33 - m.m23 * m.m30;
            const Float _2132_2231 = m.m21 * m.m32 - m.m22 * m.m31;
            const Float _2133_2331 = m.m21 * m.m33 - m.m23 * m.m31;
            const Float _2233_2332 = m.m22 * m.m33 - m.m23 * m.m32;

            return NMMatrix4x4(
                +invDet * (m.m11 * _2233_2332 - m.m12 * _2133_2331 + m.m13 * _2132_2231),
                -invDet * (m.m01 * _2233_2332 - m.m02 * _2133_2331 + m.m03 * _2132_2231),
                +invDet * (m.m01 * _1233_1332 - m.m02 * _1133_1331 + m.m03 * _1132_1231),
                -invDet * (m.m01 * _1223_1322 - m.m02 * _1123_1321 + m.m03 * _1122_1221),

                -invDet * (m.m10 * _2233_2332 - m.m12 * _2033_2330 + m.m13 * _2032_2230),
                +invDet * (m.m00 * _2233_2332 - m.m02 * _2033_2330 + m.m03 * _2032_2230),
                -invDet * (m.m00 * _1233_1332 - m.m02 * _1033_1330 + m.m03 * _1032_1230),
                +invDet * (m.m00 * _1223_1322 - m.m02 * _1023_1320 + m.m03 * _1022_1220),

                +invDet * (m.m10 * _2133_2331 - m.m11 * _2033_2330 + m.m13 * _2031_2130),
                -invDet * (m.m00 * _2133_2331 - m.m01 * _2033_2330 + m.m03 * _2031_2130),
                +invDet * (m.m00 * _1133_1331 - m.m01 * _1033_1330 + m.m03 * _1031_1130),
                -invDet * (m.m00 * _1123_1321 - m.m01 * _1023_1320 + m.m03 * _1021_1120),

                -invDet * (m.m10 * _2132_2231 - m.m11 * _2032_2230 + m.m12 * _2031_2130),
                +invDet * (m.m00 * _2132_2231 - m.m01 * _2032_2230 + m.m02 * _2031_2130),
                -invDet * (m.m00 * _1132_1231 - m.m01 * _1032_1230 + m.m02 * _1031_1130),
                +invDet * (m.m00 * _1122_1221 - m.m01 * _1022_1220 + m.m02 * _1021_1120));
        }
        else
        {
            return m;
        }
    }

    NMMatrix4x4 NMMatrix4x4::Transpose(const NMMatrix4x4 &m)
    {
        return NMMatrix4x4(
            m.m00, m.m10, m.m20, m.m30,
            m.m01, m.m11, m.m21, m.m31,
            m.m02, m.m12, m.m22, m.m32,
            m.m03, m.m13, m.m23, m.m33);
    }

    NMMatrix4x4 NMMatrix4x4::Ortho(const Float &left, const Float &right, const Float &bottom, const Float &top, const Float &zNear, const Float &zFar)
    {
        Float A = right - left;
        Float B = top - bottom;
        Float C = zFar - zNear;
        Float D = right + left;
        Float E = top + bottom;
        Float F = zFar + zNear;

        return NMMatrix4x4(
            2 / A, 0, 0, 0,
            0, 2 / B, 0, 0,
            0, 0, -2 / C, 0,
            -(D / A), -(E / B), (F / C), 1);
    }

    NMMatrix4x4 NMMatrix4x4::Perspective(const Float &fov, const Float &aspect, const Float &zNear, const Float &zFar)
    {
        Float yMax = zNear * tanf(fov * 0.5f);
        Float yMin = -yMax;
        Float xMin = yMin * aspect;
        Float xMax = -xMin;

        return NMMatrix4x4(
            (2.0f * zNear) / (xMax - xMin), 0, 0, 0,
            0, (2.0f * zNear) / (yMax - yMin), 0, 0,
            (xMax + xMin) / (xMax - xMin), (yMax + yMin) / (yMax - yMin), -(zFar + zNear) / (zFar - zNear), -1.0f,
            0, 0, -((2.0f * (zFar * zNear)) / (zFar - zNear)), 0);
    }

    NMMatrix4x4 NMMatrix4x4::ScaleToMatrix(const NMVector3 &scale)
    {
        return NMMatrix4x4(
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            scale.x, scale.y, scale.z, 1.0f);
    }

    NMMatrix4x4 NMMatrix4x4::TRS(const NMVector3 &trans, const NMQuaternion &quat, const NMVector3 &scale)
    {
        // @TODO
        NM_DEBUG_LOG("has not implement yet.");
        return NMMatrix4x4::identity;
    }

}  // namespace NightMoon
