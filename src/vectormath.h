#ifndef VECTORMATH_H
#define VECTORMATH_H

struct Vec3d {
    float x;
    float y;
    float z;
};

struct Quat {
    float qr;
    float qi;
    float qj;
    float qk;

    Quat conj() {
        return struct quat{.qr = this->qr, .qi = -this->qi, .qj = -this->qj, .qk = -this->qk}
    };

    Vec3d apply() {

    }
};


#endif // VECTORMATH_H
