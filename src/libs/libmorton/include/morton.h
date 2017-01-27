#pragma once

// This file will always contain #define clauses to the fastest Morton encoding/decoding implementation
// IF you just want to use the fastest method to encode/decode morton codes, include this header.

#include "morton2D.h"
#include "morton3D.h"
#include "morton_BMI.h"

//// ENCODE
//inline uint_fast32_t morton2D_32_encode(const uint_fast16_t x, const uint_fast16_t y);
//inline uint_fast64_t morton2D_64_encode(const uint_fast32_t x, const uint_fast32_t y);
//inline uint_fast32_t morton3D_32_encode(const uint_fast16_t x, const uint_fast16_t y, const uint_fast16_t z);
//inline uint_fast64_t morton3D_64_encode(const uint_fast32_t x, const uint_fast32_t y, const uint_fast32_t z);
//
//// DECODE
//inline void morton2D_32_decode(const uint_fast32_t morton, uint_fast16_t& x, uint_fast16_t& y);
//inline void morton2D_64_decode(const uint_fast64_t morton, uint_fast32_t& x, uint_fast32_t& y);
//inline void morton3D_32_decode(const uint_fast32_t morton, uint_fast16_t& x, uint_fast16_t& y, uint_fast16_t& z);
//inline void morton3D_64_decode(const uint_fast64_t morton, uint_fast32_t& x, uint_fast32_t& y, uint_fast32_t& z);

// Functions under this are stubs which will always point to fastest implementation at the moment
//-----------------------------------------------------------------------------------------------

// ENCODING
#if defined(__BMI2__) || __AVX2__
inline uint_fast32_t morton2D_32_encode(const uint_fast16_t x, const uint_fast16_t y) {
	return m2D_e_BMI<uint_fast32_t, uint_fast16_t>(x, y);
}
inline uint_fast64_t morton2D_64_encode(const uint_fast32_t x, const uint_fast32_t y) {
	return m2D_e_BMI<uint_fast64_t, uint_fast32_t>(x, y);
}
inline uint_fast32_t morton3D_32_encode(const uint_fast16_t x, const uint_fast16_t y, const uint_fast16_t z) {
	return m3D_e_BMI<uint_fast32_t, uint_fast16_t>(x, y, z);
}
inline uint_fast64_t morton3D_64_encode(const uint_fast32_t x, const uint_fast32_t y, const uint_fast32_t z) {
	return m3D_e_BMI<uint_fast64_t, uint_fast32_t>(x, y, z);
}
#else
inline uint_fast32_t morton2D_32_encode(const uint_fast16_t x, const uint_fast16_t y) {
	return m2D_e_sLUT<uint_fast32_t, uint_fast16_t>(x, y);
}
inline uint_fast64_t morton2D_64_encode(const uint_fast32_t x, const uint_fast32_t y) {
	return m2D_e_sLUT<uint_fast64_t, uint_fast32_t>(x, y);
}
inline uint_fast32_t morton3D_32_encode(const uint_fast16_t x, const uint_fast16_t y, const uint_fast16_t z) {
	return m3D_e_sLUT<uint_fast32_t, uint_fast16_t>(x, y, z);
}
inline uint_fast64_t morton3D_64_encode(const uint_fast32_t x, const uint_fast32_t y, const uint_fast32_t z) {
	return m3D_e_sLUT<uint_fast64_t, uint_fast32_t>(x, y, z);
}
#endif

// DECODING
#if defined(__BMI2__) || __AVX2__
inline void morton2D_32_decode(const uint_fast32_t morton, uint_fast16_t& x, uint_fast16_t& y) {
	m2D_d_BMI<uint_fast32_t, uint_fast16_t>(morton, x, y);
}
inline void morton2D_64_decode(const uint_fast64_t morton, uint_fast32_t& x, uint_fast32_t& y) {
	m2D_d_BMI<uint_fast64_t, uint_fast32_t>(morton, x, y);
}
inline void morton3D_32_decode(const uint_fast32_t morton, uint_fast16_t& x, uint_fast16_t& y, uint_fast16_t& z) {
	m3D_d_BMI<uint_fast32_t, uint_fast16_t>(morton, x, y, z);
}
inline void morton3D_64_decode(const uint_fast64_t morton, uint_fast32_t& x, uint_fast32_t& y, uint_fast32_t& z) {
	m3D_d_BMI<uint_fast64_t, uint_fast32_t>(morton, x, y, z);
}
#else
inline void morton2D_32_decode(const uint_fast32_t morton, uint_fast16_t& x, uint_fast16_t& y) {
	m2D_d_sLUT<uint_fast32_t, uint_fast16_t>(morton, x, y);
}
inline void morton2D_64_decode(const uint_fast64_t morton, uint_fast32_t& x, uint_fast32_t& y) {
	m2D_d_sLUT<uint_fast64_t, uint_fast32_t>(morton, x, y);
}
inline void morton3D_32_decode(const uint_fast32_t morton, uint_fast16_t& x, uint_fast16_t& y, uint_fast16_t& z) {
	m3D_d_sLUT<uint_fast32_t, uint_fast16_t>(morton, x, y, z);
}
inline void morton3D_64_decode(const uint_fast64_t morton, uint_fast32_t& x, uint_fast32_t& y, uint_fast32_t& z) {
	m3D_d_sLUT<uint_fast64_t, uint_fast32_t>(morton, x, y, z);
}
#endif