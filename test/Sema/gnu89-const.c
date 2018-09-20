// RUN: %clang_cc1 %s -std=gnu89 -pedantic -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-PEDANTIC %s
// RUN: %clang_cc1 %s -std=gnu89 -fsyntax-only 2>&1 | FileCheck -check-prefix=CHECK-ABSTRUSE %s

// Do not warn about duplicate const declaration specifier as the result of
// typeof in gnu89.
const int c_i;
const typeof(c_i) c_i2;
// CHECK-PEDANTIC: warning: extension used
// CHECK-PEDANTIC: warning: duplicate 'const' declaration specifier
// CHECK-ABSTRUSE-NOT: warning: duplicate 'const' declaration specifier

const const int c_i3;
// CHECK: warning: duplicate 'const' declaration specifier

typedef const int t;
const t c_i4;
// CHECK: warning: duplicate 'const' declaration specifier
