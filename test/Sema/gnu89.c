// RUN: %clang_cc1 %s -std=gnu89 -pedantic -fsyntax-only -verify

int f(int restrict);

void main() {} // expected-warning {{return type of 'main' is not 'int'}} expected-note {{change return type to 'int'}}

// Do not warn about duplicate const declaration specifier as the result of
// typeof in gnu89.
const int c_i;
const typeof(c_i) c_i3; // expected-warning {{extension used}}
