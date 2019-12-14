#ifndef VECTORMATH_H
#define VECTORMATH_H

struct Vec3d {
    float x;
    float y;
    float z;

    /**
     * @brief neg Negative of a vector
     * @return Negative vector
     */
    Vec3d neg() {
        return {-x, -y, -z};
    }

    /**
     * @brief add Add a vector to the instance
     * @param v Vector that is added
     * @return Sum of the vectors
     */
    Vec3d add(Vec3d v) {
        return {x + v.x, y + v.y, z + v.z};
    }
};

struct Quat {
    float qr;
    float qi;
    float qj;
    float qk;

    /**
     * @brief conj Calculates the conjugate of the quaternion
     * @return The conjugated quationion
     */
    Quat conj() {
        return {qr, -qi, -qj, -qk};
    }

    /**
     * @brief add Add a quaternion
     * @param q Quaternion that is added
     * @return Sum of the quaternions
     */
    Quat add(Quat q){
        return {qr + q.qr, qi + q.qi, qj + q.qj, qk + q.qk};
    }

    /**
     * @brief mult Quaternion multiplication from the right
     * @param q Right operand of the multiplication
     * @return Result of the multiplication
     *
     * Quaternion multiplication is not commutative, i.e. in general, q1*q2
     * is NOT equal to q2*q1. This function multiplies q from the right to the
     * instance.
     */
    Quat mult(Quat q) {
        return {
            -qi * q.qi - qj * q.qj - qk * q.qk + q.qr * qr,
            -qk * q.qj + qj * q.qk + qi * q.qr + q.qi * qr,
             qk * q.qi - qi * q.qk + qj * q.qr + q.qj * qr,
            -qj * q.qi + qi * q.qj + qk * q.qr + q.qk * qr
        };
    }

    /**
     * @brief rotate Rotates v about the quaternion
     * @param v Vector to be rotated
     * @return Rotated vector
     */
    Vec3d rotate(Vec3d v) {
        Quat vv{0.0f, v.x, v.y, v.z};
        Quat r =  mult(vv).mult(conj());
        return {r.qi, r.qj, r.qk};
    }
};


#endif // VECTORMATH_H
